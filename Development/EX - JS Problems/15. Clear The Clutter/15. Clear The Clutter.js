// You have to write a Node.js program to clear clutter inside of a directory and organize the contents of that directory into different folders

// for example, these files become:

// 1. name.jpg
// 2. name.png
// 3. this.pdf
// 4. harry.zip
// 5. Rohan.zip
// 6. cat.jpg
// 7. harry.pdf

// this:
// jpg/name.jpg, jpg/cat.jpg
// png/name.png
// pdf/this.pdf pdf/harry.pdf
// zip/harry.zip zip/Rohan.zip

import fs from "fs/promises";
import fsn from "fs";
import path from "path";

let basePath = `/Users/shaadalamansari/Documents/GitHub/opencode/Development/EX - JS Problems/15. Clear The Clutter/Files`;

let files = await fs.readdir(basePath);

for (const file of files) {
  let extension = file.split(".")[1];
  let oldPath = path.join(basePath, file);
  let newPath = path.join(basePath, extension, file);

  if (file === `.DS_Store` || extension === undefined) continue;

  if (!fsn.existsSync(path.join(basePath, extension))) {
    await fs.mkdir(path.join(basePath, extension));
  }

  await fs.rename(oldPath, newPath);
}
