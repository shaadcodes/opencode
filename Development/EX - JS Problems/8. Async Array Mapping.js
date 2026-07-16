// 8. Async Array Mapping:
//    Write an asynchronous function that takes an array of numbers and returns a new array of Promises where each number is multiplied by 2 after a delay of 500 milliseconds.

let arrayOfNumbers = [2, 6, 32, 44, 67, 89, 90, 12, 5, 22];

function multiplyByTwo(array) {
  return array.map((number) => {
    return new Promise((resolve) => {
      setTimeout(() => {
        resolve(number * 2);
      }, 500);
    });
  });
}

let arrayOfPromises = multiplyByTwo(arrayOfNumbers);

console.log(arrayOfPromises);

Promise.all(arrayOfPromises)
  .then((resolvedValues) => {
    console.log(resolvedValues);
  })
  .catch((error) => {
    console.log(error);
  });
