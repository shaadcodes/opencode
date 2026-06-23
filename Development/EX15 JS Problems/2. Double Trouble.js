// 2. The Double Trouble:
//    You are tasked with writing a function that doubles each element in an array. However, there's a catch: if the array contains consecutive duplicate elements, only double one of them.

let arr = [21, 63, 33, 82, 45, 98, 98, 72, 20, 55];

function doubleTrouble(array)
{
    for (let index = 0; index < array.length; index++) {
        const element = array[index];
        if (element === array[index+1])
            continue;
        array[index] = element * 2;
    }
}

doubleTrouble(arr);

console.log(arr);