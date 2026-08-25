import express from "express";
import mongoose from "mongoose";
import cors from "cors";

const app = express();

app.use(cors());
app.use(express.json());

mongoose
  .connect("mongodb://127.0.0.1:27017/courseCatalogueDB")
  .then(() => console.log(`Connected to MongoDB!\n`))
  .catch((error) => console.log(`Can't connect to DataBase!, Error: `, error));

// Schema Definition
const courseCatalogueSchema = new mongoose.Schema({
  name: String,
  price: Number,
  assignments: Number,
  projects: Number,
});

const course = mongoose.model(`course`, courseCatalogueSchema);

// Get Request Integration
app.get("/course", async (req, res) => {
  try {
    const courses = await course.find();
    res.json(courses);
  } catch (error) {
    res.status(500).json({ message: error.message });
  }
});

// Post Request Integration
app.post("/course", async (req, res) => {
  const newCourse = new course({
    name: req.body.name,
    price: req.body.price,
    assignments: req.body.assignments,
    projects: req.body.projects,
  });

  try {
    const savedCourse = await newCourse.save();
    res.status(201).json(savedCourse);
  } catch (error) {
    res.status(400).json({ message: error.message });
  }
});

app.listen(5001, () => console.log(`PORT: 5001 - Backend is listening...`))