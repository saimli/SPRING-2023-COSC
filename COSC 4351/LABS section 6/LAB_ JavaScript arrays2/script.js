// Put your solution here
function divideArray(array)
{
const evenNums = [];
  const oddNums = [];

  // Divide the numbers into even and odd arrays
  for (const num of array) {
    if (num % 2 === 0) {
      evenNums.push(num);
    } else {
      oddNums.push(num);
    }
  }

  // Sort the even and odd arrays
  evenNums.sort((a, b) => a - b);
  oddNums.sort((a, b) => a - b);

  // Output the sorted arrays to the console
  console.log("Even numbers:");
  if(evenNums.length == 0){
    console.log("None");
  }
  else{for(const i of evenNums)
    {
      console.log(i)
    }
  }
  
  console.log("Odd numbers:");
  if(oddNums.length == 0){
    console.log("None");
  }
  else{for(const i of oddNums)
    {
      console.log(i)
    }}
  
} 
