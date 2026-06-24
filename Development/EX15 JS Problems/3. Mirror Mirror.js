// 3. The Mirror Mirror:
//    Imagine you have a string, and you need to create a new string that is a mirror image of the original. Write a function that appends the reversed version of the original string to itself.

let string = "successful";

function reverseString(string)
{
    for (let index = string.length - 1; index >= 0; index--) {
        const element = string[index];
        string += element;
    }
    return string;
}

console.log(reverseString(string));