function checkForm() {
   // Get form elements
   const fullName = document.getElementById("fullName");
   const email = document.getElementById("email");
   const password = document.getElementById("password");
   const passwordConfirm = document.getElementById("passwordConfirm");
   const formErrors = document.getElementById("formErrors");
   
   // Reset borders to default
   fullName.style.border = "1px solid #aaa";
   email.style.border = "1px solid #aaa";
   password.style.border = "1px solid #aaa";
   passwordConfirm.style.border = "1px solid #aaa";
   
   // Reset form errors
   formErrors.innerHTML = "";
   formErrors.style.display = "none";
   
   // Validate full name
   if (fullName.value.trim().length < 1) {
     formErrors.innerHTML += "<li>Missing full name.</li>";
     fullName.style.border = "2px solid red";
   }
   
   // Validate email
   const emailPattern = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,5}$/;
   if (!emailPattern.test(email.value.trim())) {
     formErrors.innerHTML += "<li>Invalid or missing email address.</li>";
     email.style.border = "2px solid red";
   }
   
   // Validate password length
   if (password.value.trim().length < 10 || password.value.trim().length > 20) {
     formErrors.innerHTML += "<li>Password must be between 10 and 20 characters.</li>";
     password.style.border = "2px solid red";
   }
   
   // Validate password contains lowercase character
   const lowercasePattern = /[a-z]/;
   if (!lowercasePattern.test(password.value)) {
     formErrors.innerHTML += "<li>Password must contain at least one lowercase character.</li>";
     password.style.border = "2px solid red";
   }
   
   // Validate password contains uppercase character
   const uppercasePattern = /[A-Z]/;
   if (!uppercasePattern.test(password.value)) {
     formErrors.innerHTML += "<li>Password must contain at least one uppercase character.</li>";
     password.style.border = "2px solid red";
   }
   
   // Validate password contains digit
   const digitPattern = /\d/;
   if (!digitPattern.test(password.value)) {
     formErrors.innerHTML += "<li>Password must contain at least one digit.</li>";
     password.style.border = "2px solid red";
   }
   
   // Validate password and confirm password match
   if (password.value.trim() !== passwordConfirm.value.trim()) {
     formErrors.innerHTML += "<li>Password and confirmation password don't match.</li>";
     password.style.border = "2px solid red";
     passwordConfirm.style.border = "2px solid red";
   }
   
   // Display errors if any
   if (formErrors.innerHTML !== "") {
     formErrors.style.display = "block";
   }
 }
 
 // Register click event for submit button
 document.getElementById("submit").addEventListener("click", function(event) {
   checkForm();
   
   // Prevent default form action
   event.preventDefault();
 });
 