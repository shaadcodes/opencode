import mongoose from "mongoose";
import express from "express";
import { todo } from "./models/todoapp.js";

await mongoose.connect("mongodb://localhost:27017/");

const app = express();
const port = 3000;

app.get('/', (req, res) => {
  const newTodo = new todo({title: `First Todo`, description: `Description of first todo`, isDone: false});
  newTodo.save();
  res.send("Hello World!");
});

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`);
});