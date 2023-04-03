function drawTriangle(size) {
   for(let i = 1; i<=size; i++)
   {
     let row = '';

     for(let j = 1; j<=i; j++)
     {
      row += '*';
     }

     console.log(row);
   }

   // console.log(size)
   
   // Your solution goes here
   
}