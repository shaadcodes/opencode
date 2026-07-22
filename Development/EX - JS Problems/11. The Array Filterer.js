// 11. The Array Filterer:
//     You are building a search feature for your e-commerce site. Write a function named filterProducts that takes an array of product objects and a filter criterion. The function should return a new array containing only the products that match the filter criterion.

function filterProducts(arrayOfProducts, filterCriteria) {
  let newArray = [{}];

  for (const product of arrayOfProducts) {
    if (product.category === filterCriteria) console.log(product);
  }
}

let arrayOfProducts = [
  { name: "Pencil", category: "School Essentials" },

  { name: "Rug", category: "Home" },

  { name: "Tub", category: "Bathroom" },

  { name: "Light Bulb", category: "Home" },

  { name: "Erasers", category: "School Essentials" },

  { name: "Water Bottle", category: "School Essentials" },

  { name: "Mop", category: "Home" },

  { name: "Bucket", category: "Bathroom" },

  { name: "Uniform", category: "School Essentials" },

  { name: "Bag", category: "School Essentials" },

  { name: "Waterjet", category: "Bathroom" },

  { name: "Electric Socket", category: "Home" },
];

filterProducts(arrayOfProducts, "School Essentials");
