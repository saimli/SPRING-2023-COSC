// HTML for the up, down, and done buttons
const upButtonHtml = '<button class="upBtn">&uarr;</button>';
const downButtonHtml = '<button class="downBtn">&darr;</button>';
const doneButtonHtml = '<button class="doneBtn">&#x2713;</button>';

window.addEventListener("DOMContentLoaded", function() {
   const addBtn = document.querySelector("#addBtn");
   addBtn.addEventListener("click", addBtnClick);
   
   const newItemText = document.querySelector("#newItemText");
   newItemText.addEventListener("keypress", function(event) {
      if (event.which === 13) {
         addBtnClick();
      }
   });
});

function addBtnClick() {
   const itemText = document.querySelector("#newItemText").value.trim();

   // Don't add empty strings
   if (itemText.length !== 0) {
      addItem(itemText);

      // Clear text and put focus back in text input
      document.querySelector("#newItemText").value = "";
      document.querySelector("#newItemText").focus();
   } 
}

function addItem(item) {      
   // Create a new <li> for the list
   const newItem = document.createElement("li");
   const newItemText = document.createElement("span");
   newItemText.textContent = item;
   newItem.appendChild(newItemText);

   // Up button moves item up one spot
   const upButton = document.createElement("button");
   upButton.classList.add("upBtn");
   upButton.innerHTML = "&uarr;";
   upButton.addEventListener("click", function() {
      const index = Array.from(this.parentElement.parentNode.children).indexOf(this.parentElement);
      moveItem(index, index - 1); 
   });
   
   // Down button moves item down one spot
   const downButton = document.createElement("button");
   downButton.classList.add("downBtn");
   downButton.innerHTML = "&darr;";
   downButton.addEventListener("click", function() {
      const index = Array.from(this.parentElement.parentNode.children).indexOf(this.parentElement);
      moveItem(index, index + 1); 
   });
      
   // Add click hander for done button
   const doneButton = document.createElement("button");
   doneButton.classList.add("doneBtn");
   doneButton.innerHTML = "&#x2713;";
   doneButton.addEventListener("click", function() {
      // Remove item from list
      const index = Array.from(this.parentElement.parentNode.children).indexOf(this.parentElement);
      removeItem(index);
   });

   // Add all buttons to the new item, and add new item to list
   newItem.appendChild(upButton);
   newItem.appendChild(downButton);
   newItem.appendChild(doneButton);
   document.querySelector("ol").appendChild(newItem);   
}

function moveItem(fromIndex, toIndex) {
   // TODO: Complete the function

   const curr = document.querySelectorAll("ol li")[fromIndex];

   if(fromIndex > toIndex)
   {
       if(toIndex !== -1)
       {
           document.querySelector("ol").insertBefore(curr, document.querySelectorAll("ol li")[toIndex]);
       }
   }
   else
   {
       if(fromIndex !== document.querySelectorAll("ol li").length - 1)
       {
           document.querySelector("ol").insertBefore(curr, document.querySelectorAll("ol li")[toIndex + 1]);
       }
   }
   
}

function removeItem(index) {
   // TODO: Complete the function
   $("ol").children().eq(index).remove();
   
}