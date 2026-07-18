// 9. The Asynchronous Shopper:
//    Imagine you are building an online shopping application. Write an asynchronous function called placeOrder that simulates placing an order and returns a promise. The promise should resolve with an order confirmation message after a random delay.

function randomDelay() {
  return Math.floor(0 + Math.random() * 5001);
}

function placeOrder() {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve("Order Confirmed!");
    }, randomDelay());
  });
}

let orderPromise = placeOrder();

console.log(orderPromise);

orderPromise.then((resolvedValues) => {
  console.log(resolvedValues);
});
