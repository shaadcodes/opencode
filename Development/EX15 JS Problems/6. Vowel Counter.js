// 6. The Vowel Counter:
//    You need to create a function that counts the number of vowels in a given string. Consider both uppercase and lowercase vowels.

let string = "A small farm";

function vowelCounter(string)
{
    const vowels = 'aeiouAEIOU';
    let count = 0;

    for (const character of string)
    {
        if (vowels.includes(character))
            count++;
    }
    return count;
}

console.log(`Number of vowels in "${string}" : ${vowelCounter(string)}`);

