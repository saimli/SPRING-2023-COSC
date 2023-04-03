const directions = {
   UP: 'up',
   DOWN: 'down',
   LEFT: 'left',
   RIGHT: 'right'
}

window.addEventListener("load", function () {
   const canvas = document.querySelector("canvas");

   // Draw 4 frogs facing different directions
   const context = canvas.getContext("2d");
   context.resetTransform(); // Reset the context transformation
   drawFrog(canvas, 50, 50, directions.UP);
   context.resetTransform(); // Reset the context transformation
   drawFrog(canvas, 180, 50, directions.DOWN);   
   context.resetTransform(); // Reset the context transformation
   drawFrog(canvas, 50, 180, directions.LEFT);
   context.resetTransform(); // Reset the context transformation
   drawFrog(canvas, 180, 180, directions.RIGHT);
});

function drawFrog(canvas, x, y, direction = directions.UP) {   
   const context = canvas.getContext("2d");
   const frogImg = document.querySelector("img");

   switch (direction) {
      case directions.DOWN:
         context.translate(x+52.5,y+42);
         context.rotate(Math.PI); // Rotate 180 degrees to face down
         context.translate(x-232.5-180,y-50-92);
         break;
       case directions.LEFT:
         context.translate(x+52.5,y+42);
         context.rotate(-Math.PI / 2); // Rotate 90 degrees counterclockwise to face left
         context.translate(x-102.5-50,y-180-222);
         break;
       case directions.RIGHT:
         context.translate(x+52.5,y+42);
         context.rotate(Math.PI / 2); // Rotate 90 degrees clockwise to face right
         context.translate(x-232.5-180,y-180-222);
         break;
   }

   context.drawImage(frogImg, x, y);

   // Necessary so next call to drawFrog isn't rotated or translated
   context.resetTransform();
}
