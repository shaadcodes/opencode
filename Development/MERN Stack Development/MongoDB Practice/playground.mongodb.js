use("CRUD-Operations");

// CREATE

// db.createCollection(`Courses`);
// db.Courses.insertOne({
//     Name: "Web Development Free",
//     Price: 0,
//     Assignments: 12,
//     Projects: 8
// })

// db.Courses.insertMany([
//   {
//     name: "Introduction to HTML & CSS",
//     price: 0,
//     assignments: 5,
//     projects: 2,
//   },
//   {
//     name: "JavaScript Fundamentals",
//     price: 0,
//     assignments: 10,
//     projects: 4,
//   },
//   {
//     name: "Mastering CSS Flexbox & Grid",
//     price: 0,
//     assignments: 6,
//     projects: 3,
//   },
//   {
//     name: "Advanced JavaScript & ES6+",
//     price: 19,
//     assignments: 12,
//     projects: 5,
//   },
//   {
//     name: "React.js Essentials",
//     price: 29,
//     assignments: 15,
//     projects: 6,
//   },
//   {
//     name: "Node.js & Express Backend Basics",
//     price: 25,
//     assignments: 10,
//     projects: 4,
//   },
//   {
//     name: "MongoDB & Mongoose Masterclass",
//     price: 20,
//     assignments: 8,
//     projects: 3,
//   },
//   {
//     name: "Full-Stack MERN Boot Camp",
//     price: 99,
//     assignments: 25,
//     projects: 10,
//   },
//   {
//     name: "Tailwind CSS Responsive Design",
//     price: 0,
//     assignments: 7,
//     projects: 3,
//   },
//   {
//     name: "Next.js Production Ready Applications",
//     price: 49,
//     assignments: 14,
//     projects: 5,
//   },
//   {
//     name: "RESTful API Design & Architecture",
//     price: 15,
//     assignments: 9,
//     projects: 2,
//   },
//   {
//     name: "Git & GitHub Workflow for Teams",
//     price: 0,
//     assignments: 4,
//     projects: 1,
//   },
//   {
//     name: "TypeScript for Modern Web Dev",
//     price: 35,
//     assignments: 11,
//     projects: 4,
//   },
//   {
//     name: "UI/UX Design Basics for Developers",
//     price: 0,
//     assignments: 8,
//     projects: 4,
//   },
//   {
//     name: "Web Security & Authentication (JWT)",
//     price: 39,
//     assignments: 10,
//     projects: 3,
//   },
// ]);

// READ

// let freeCourses = db.Courses.find({price: 0});
// let numberOfFreeCourses = freeCourses.count();
// // console.log(`There are ${numberOfFreeCourses} free courses available\n`, freeCourses);

// UPDATE

// db.Courses.updateOne({price: 0}, {$set:{price: 10}});

// numberOfFreeCourses = freeCourses.count();
// console.log(`There are ${numberOfFreeCourses} free courses available\n`, freeCourses);

// DELETE

// let lowProjects = db.Courses.find({projects: 1});
// console.log(lowProjects);

// Output : 
// {
//   cursorHasMore: false,
//   documents: [
//     {
//       _id: ObjectId('6a573e2012bc0bce01200ded'),
//       name: 'Git & GitHub Workflow for Teams',
//       price: 0,
//       assignments: 4,
//       projects: 1
//     }
//   ]
// }

// db.Courses.deleteOne({projects: 1});

// console.log(db.Courses.find());
