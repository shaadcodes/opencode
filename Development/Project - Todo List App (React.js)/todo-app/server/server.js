import express from "express";
import mongoose from "mongoose";
import cors from "cors";
import dotenv from "dotenv";

dotenv.config();
const app = express();
app.use(cors());
app.use(express.json());

let isConnected = false;

const connectToDB = async () => {
  if (isConnected) return;
  try {
    const db = await mongoose.connect(process.env.MONGO_URI);
    isConnected = db.connections[0].readyState === 1;
    console.log("Connected to MongoDB!");
  } catch (error) {
    console.error("MongoDB connection error: ", error);
    throw error;
  }
};

app.use(async (req, res, next) => {
  try {
    await connectToDB();
    next();
  } catch (error) {
    return res
      .status(500)
      .json({ error: "DB connection failed", details: error.message });
  }
});

const taskSchema = new mongoose.Schema(
  {
    text: { type: String, required: true },
    completed: { type: Boolean, default: false },
  },
  { timestamps: true },
);

const todo = mongoose.model("Todo", taskSchema);

app.get(`/api/todos`, async (req, res) => {
  try {
    const todos = await todo.find().sort({ createdAt: -1 });
    res.status(200).json(todos);
  } catch (error) {
    console.error("GET /api/todos failed: ", error);
    res.status(500).json({
      message: "Database query failed",
      error: error.message,
    });
  }
});

app.post(`/api/todos`, async (req, res) => {
  const newTask = new todo({ text: req.body.text });
  const saved = await newTask.save();
  res.json(saved);
});

app.put(`/api/todos/:id`, async (req, res) => {
  const updated = await todo.findByIdAndUpdate(req.params.id, req.body, {
    returnDocument: "after",
  });
  res.json(updated);
});

app.delete(`/api/todos/:id`, async (req, res) => {
  const deleted = await todo.findByIdAndDelete(req.params.id);
  res.json(deleted);
});

const PORT = process.env.PORT || 5000;
if (process.env.NODE_ENV !== "production") {
  app.listen(PORT, () =>
    console.log(`Server is listening on port: ${PORT}...`),
  );
}

export default app;
