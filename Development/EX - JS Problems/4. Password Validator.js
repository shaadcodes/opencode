// 4. The Password Validator:
//    You are building a password validation feature. Create a function that checks if a given password meets the following criteria: at least 8 characters long, contains both uppercase and lowercase letters, and includes at least one digit.

let password = "superpassword1000";

function validatePassword(password)
{
    if (password.length < 8)
        return false;
    
    let hasUppercase = false;
    let hasLowercase = false;
    let hasDigit = false;

    for (const character of password)
    {
        if (character >= 'A' && character <= 'Z') 
            hasUppercase = true;

        if (character >= 'a' && character <= 'z')
            hasLowercase = true;

        if (character >= '0' && character <= '9')
            hasDigit = true;
    }

    return (hasUppercase && hasLowercase && hasDigit);
}

if(validatePassword(password))
{
    console.log("Password Suited!");
}
else
{
    console.log("Unmatched expectations!");
}