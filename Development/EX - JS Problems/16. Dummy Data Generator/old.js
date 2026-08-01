const baseUrl = `http://127.0.0.1:5001/generate`;
const generateButton = document.getElementById("generate");
const messageBox = document.getElementById("messageBox");
const nameArray = [
  "Sami",
  "Rahul",
  "Paul",
  "Harry",
  "Christina",
  "Savitri",
  "Jacko",
];
const salaryArray = [
  10000, 12000, 8500, 14500, 21000, 35000, 8000, 50000, 32000,
];
const languageArray = [
  "Python",
  "C++",
  "Ruby",
  "Go",
  "JavaScript",
  "Java",
  "HTML",
  "Rust",
];
const cityArray = [
  "Kanpur",
  "Lucknow",
  "Gurgaon",
  "Noida",
  "Delhi",
  "Mumbai",
  "Jaipur",
  "Bengaluru",
  "Chennai",
];

document.addEventListener("DOMContentLoaded", async () => {
  generateButton.addEventListener("click", () => {
    messageBox.innerHTML = '';
    fetch(baseUrl, {
      method: "POST",
      headers: {
        "Content-type": "application/json",
      },
      body: JSON.stringify(generateData()),
    })
      .then((response) => response.json())
      .then((savedData) => {
        console.log(`Data Saved Successfully!`);
        let isManager = '';
        if(savedData.isManager)
        {
          isManager = `is a Manager`;
        }
        else
        {
          isManager = `is not a Manager`;
        }
        const savedInfo = document.createElement("div");
        savedInfo.className = "savedInfo";
        savedInfo.innerHTML = `
          <p>Details added for <strong>${savedData.name}</strong> having salary <strong>$${savedData.salary}</strong> living in <strong>${savedData.city}</strong> having experience in <strong>${savedData.language}</strong>, current status <strong>${isManager}</strong></p>
        `;
        messageBox.appendChild(savedInfo);
      })
      .catch((error) => console.error(`Error saving data!, Error: `, error));
  });
});

function generateData() {
  const generatedData = {
    name: nameArray[randomizer(nameArray.length)],
    salary: salaryArray[randomizer(salaryArray.length)],
    language: languageArray[randomizer(languageArray.length)],
    city: cityArray[randomizer(cityArray.length)],
    isManager: randomizer(2),
  };

  return generatedData;
}

function randomizer(maxValue) {
  return Math.floor(0 + Math.random() * maxValue);
}
