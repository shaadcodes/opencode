// 1. The Magical Sorting Hat:
//    Imagine you are creating a magical sorting hat for a wizard school. Implement a JavaScript function that takes an array of student names and assigns them to one of the four houses (Gryffindor (length less than 6), Hufflepuff(length less than 8), Ravenclaw(length less than 12), or Slytherin(length greater than or equal to 12)) based on the length of their names.


let students = ["Ravi", "Chandan", "Kaif", "Ron", "Holly", "Chandrashekhara", "Gill", "Williamson", "Braddy"];
let studentsAndHouses = {};

for (const student of students)
{
    if (student.length < 6)
    {
        studentsAndHouses[student] = "Gryffindor";
    }
    else if (student.length < 8)
    {
        studentsAndHouses[student] = "Hufflepuff";
    }
    else if (student.length < 12)
    {
        studentsAndHouses[student] = "Ravenclaw";
    }
    else
    {
        studentsAndHouses[student] = "Slytherin";
    }
}

console.log(studentsAndHouses);