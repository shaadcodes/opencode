const baseUrl: string = "http://127.0.0.1:5001/generate";

const generateButton = document.getElementById("generate") as HTMLButtonElement | null;
const messageBox = document.getElementById("messageBox") as HTMLDivElement | null;

const nameArray: string[] = [
  "Sami",
  "Rahul",
  "Paul",
  "Harry",
  "Christina",
  "Savitri",
  "Jacko",
];

const salaryArray: number[] = [
  10000, 12000, 8500, 14500, 21000, 35000, 8000, 50000, 32000,
];

const languageArray: string[] = [
  "Python",
  "C++",
  "Ruby",
  "Go",
  "JavaScript",
  "Java",
  "HTML",
  "Rust",
];

const cityArray: string[] = [
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

interface GeneratedData {
  name: string;
  salary: number;
  language: string;
  city: string;
  isManager: boolean | number;
}

document.addEventListener("DOMContentLoaded", () => {
  if (!generateButton || !messageBox) {
    console.error("Required DOM elements were not found.");
    return;
  }

  generateButton.addEventListener("click", async () => {
    messageBox.innerHTML = '';
    
    try {
      const response = await fetch(baseUrl, {
        method: "POST",
        headers: {
          "Content-type": "application/json",
        },
        body: JSON.stringify(generateData()),
      });

      if (!response.ok) {
        throw new Error(`HTTP error! status: ${response.status}`);
      }

      const savedData: GeneratedData = await response.json();
      console.log(`Data Saved Successfully!`);

      const isManagerText: string = savedData.isManager ? "is a Manager" : "is not a Manager";
      
      const savedInfo = document.createElement("div");
      savedInfo.className = "savedInfo";
      savedInfo.innerHTML = `
        <p>Details added for <strong>${savedData.name}</strong> having salary <strong>$${savedData.salary}</strong> living in <strong>${savedData.city}</strong> having experience in <strong>${savedData.language}</strong>, current status <strong>${isManagerText}</strong></p>
      `;
      
      messageBox.appendChild(savedInfo);
    } catch (error) {
      console.error(`Error saving data!, Error: `, error);
    }
  });
});

function generateData(): GeneratedData {
  const generatedData: GeneratedData = {
    name: nameArray[randomizer(nameArray.length)],
    salary: salaryArray[randomizer(salaryArray.length)],
    language: languageArray[randomizer(languageArray.length)],
    city: cityArray[randomizer(cityArray.length)],
    isManager: randomizer(2), 
  };

  return generatedData;
}

function randomizer(maxValue: number): number {
  return Math.floor(0 + Math.random() * maxValue);
}