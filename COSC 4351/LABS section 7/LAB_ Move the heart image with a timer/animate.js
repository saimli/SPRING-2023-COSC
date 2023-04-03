let timerId = null;
let imgX = 0;
let imgY = 0;
let centerX, centerY;

window.addEventListener("DOMContentLoaded", function() {
   document.addEventListener("click", startAnimation);
});

function startAnimation(e) {

   // Get mouse coordinates
   let clickX = e.clientX;
   let clickY = e.clientY;  
   
   // Stop previous animation if it exists
   if (timerId !== null) {
      clearInterval(timerId);
      timerId = null; // added this line
   }
   
   // Start new animation
   timerId = setInterval(() => {
      moveImage(clickX, clickY);
      if (imgX === centerX && imgY === centerY) {
         clearInterval(timerId);
         timerId = null; // added this line
      }
   }, 10);
}

function moveImage(x, y) {
   const img = document.querySelector("img");
            
   // Determine location of image
   imgX = parseInt(img.style.left); // removed the let keyword
   imgY = parseInt(img.style.top); // removed the let keyword

   if (isNaN(imgX)) {
      imgX = 0;
   }
   if (isNaN(imgY)) {
      imgY = 0;
   }

   // Determine (x,y) coordinates that center the image 
   // around the clicked (x, y) coords
   centerX = Math.round(x - (img.width / 2));
   centerY = Math.round(y - (img.height / 2));

   // Move 1 pixel in both directions toward the click
   if (imgX < centerX) {
      imgX++;
   }
   else if (imgX > centerX) {
      imgX--;
   }
   
   if (imgY < centerY) {
      imgY++;
   }
   else if (imgY > centerY) {
      imgY--;
   }
   
   img.style.left = imgX + "px";
   img.style.top = imgY + "px";
}
