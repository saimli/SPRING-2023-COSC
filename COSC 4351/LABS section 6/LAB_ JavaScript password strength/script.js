// Your solution goes here 
function isStrongPassword(password)
{
    const lengthRegex = /.{8,}/;   
    const uppercaseRegex = /[A-Z]/;   
    const noPasswordRegex = /^(?!.*password).*$/i;



    const islong = lengthRegex.test(password);
    const uppercase = uppercaseRegex.test(password);
    const passwordtest = noPasswordRegex.test(password);

    return islong && uppercase && passwordtest;



}