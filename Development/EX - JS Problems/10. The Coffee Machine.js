// 10. The Coffee Machine:
//     In your coffee shop application, you need to simulate the process of brewing coffee asynchronously. Write an async function named brewCoffee that takes the type of coffee and returns a promise. The promise should resolve with a message indicating that the coffee is ready after a random delay.

function randomDelay() {
  return Math.floor(0 + Math.random() * 9001);
}

function brewCoffee(typeOfCoffee)
{
    return new Promise((resolve) => {
        setTimeout(() => {
            resolve("Coffee is ready!");
        }, randomDelay());
    })
}

let coffeeType = "Latte";

let brewedCoffee = brewCoffee(coffeeType);

console.log(brewedCoffee);

brewedCoffee.then((resolvedMessage) => {
    console.log(resolvedMessage);
})