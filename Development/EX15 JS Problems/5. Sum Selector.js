// 5. The Sum Selector:
//    You are working on a function that should sum all numbers in an array until it encounters a negative number. Write a function that performs this summation

let array = [25, -76, 44, 32, 87, 90, 21, 12, 87, 55];

function sumTillNegative(array)
{
    let sum = 0;

    for (const number of array)
    {
        if (number < 0)
        {
            break;
        }
        else
        {
            sum += number;
        }
    }

    return sum;
}

console.log(sumTillNegative(array));