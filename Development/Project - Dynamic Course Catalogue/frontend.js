const courseContainer = document.getElementById("courseContainer");
const baseUrl = `http://127.0.0.1:5001/course`;

document.addEventListener("DOMContentLoaded", async () => {
  const courseForm = document.getElementById("courseForm");

  courseForm.addEventListener("submit", (event) => {
    event.preventDefault();

    const newCourseData = {
      name: document.getElementById("name").value,
      price: Number(document.getElementById("price").value),
      assignments: Number(document.getElementById("assignments").value),
      projects: Number(document.getElementById("projects").value),
    };

    fetch(baseUrl, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(newCourseData),
    })
      .then((response) => response.json())
      .then((savedCourse) => {
        console.log(`Data saved to DB!`);
        const savedCourseCard = document.createElement("div");
        savedCourseCard.className = `courseCard`;
        savedCourseCard.innerHTML = `
                <h3>${savedCourse.name}</h3>
                <p><strong>Price: </strong> $${savedCourse.price}</p>
                <p><strong>Assignments: </strong>${savedCourse.assignments}</p>
                <p><strong>Projects: </strong>${savedCourse.projects}</p>
        `;
        courseContainer.appendChild(savedCourseCard);
        courseForm.reset();
      })
      .catch((error) => console.error(`Error saving course: `, error));
  });

  fetchCourses();
});

async function fetchCourses() {
  fetch(baseUrl)
    .then((response) => response.json())
    .then((courses) => {
      courseContainer.innerHTML = "";

      courses.forEach((course) => {
        const courseCard = document.createElement("div");
        courseCard.className = `courseCard`;
        courseCard.innerHTML = `
                <h3>${course.name}</h3>
                <p><strong>Price: </strong> $${course.price}</p>
                <p><strong>Assignments: </strong>${course.assignments}</p>
                <p><strong>Projects: </strong>${course.projects}</p>
            `;
        courseContainer.appendChild(courseCard);
      });
    })
    .catch((error) => console.error(`Error Fetching courses: `, error));
}
