import express, { response } from "express";
import mongoose from "mongoose";
import cors from "cors";
import { error, log } from "node:console";

const app = express();
app.use(cors());
app.use(express.json());

mongoose
  .connect("mongodb://127.0.0.1:27017/Company")
  .then(() => console.log(`Connected to DB!`))
  .catch((error) => console.error(`Error Connecting to DB, Error: `, error));

const dataSchema = new mongoose.Schema({
  name: String,
  salary: Number,
  language: String,
  city: String,
  isManager: Boolean,
});

const employee = mongoose.model("employee", dataSchema);

app.get("/generate", async (req, res) => {
  try {
    const data = await employee.find();
    res.json(data);
  } catch (error) {
    res.status(500).json({ message: error.message });
  }
});

app.post("/generate", async (req, res) => {
  const newData = new employee({
    name: req.body.name,
    salary: req.body.salary,
    language: req.body.language,
    city: req.body.city,
    isManager: req.body.isManager,
  });

  try {
    const savedData = await newData.save();
    res.status(201).json(savedData);
  } catch (error) {
    res.send(400).json({ message: error.message });
  }
});

app.listen(5001, () => {
  console.log(`PORT: 5001, Backend is listening...`);
});
