// 13. The Shopping Cart Totalizer:
//     You are working on an e-commerce website, and you need to calculate the total cost of items in the shopping cart. Implement a function named calculateTotal that takes an array of products with prices and quantities and returns the total cost.

let products = [
    {name: "Chair", price: 900, quantity: 5},
    {name: "Table", price: 1000, quantity: 1},
    {name: "Water Cooler", price: 300, quantity: 1},
    {name: "Light Bulb", price: 350, quantity: 8},
    {name: "Laptop Stand", price: 400, quantity: 2},
    {name: "Fan", price: 1200, quantity: 3},
    {name: "Mop", price: 120, quantity: 1},
    {name: "Sticky Tape", price: 80, quantity: 1}
]

function calculateTotal(arrayOfProducts)
{
    return arrayOfProducts.reduce((accumulator, currentProduct) => {
        return accumulator + (currentProduct.price * currentProduct.quantity);
    }, 0)
}

console.log(calculateTotal(products));