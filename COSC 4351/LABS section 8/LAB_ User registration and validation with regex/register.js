function checkForm() {
  const name = document.getElementById('fullName');
  const email = document.getElementById('email');
  const password = document.getElementById('password');
  const passwordConfirm = document.getElementById('passwordConfirm');
  const error = document.getElementById('formErrors');
  error.innerHTML += '<ul>'

  const validations = [
    { condition: !name.value, message: 'Missing full name.', element: name },
    { condition: !email.value || !/^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,5}$/.test(email.value), message: 'Invalid or missing email address.', element: email },
    { condition: password.value.length < 10 || password.value.length > 20, message: 'Password must be between 10 and 20 characters.', element: password },
    { condition: !/[a-z]/.test(password.value), message: 'Password must contain at least one lowercase character.', element: password },
    { condition: !/[A-Z]/.test(password.value), message: 'Password must contain at least one uppercase character.', element: password },
    { condition: !/[0-9]/.test(password.value), message: 'Password must contain at least one digit.', element: password },
    { condition: password.value != passwordConfirm.value, message: 'Password and confirmation password don\'t match.', element: [passwordConfirm, password] }
  ];
  
  let errorsFound = false;
  let errorMessage = '<ul>';
  validations.forEach(validation => {
    if (validation.condition) {
      errorsFound = true;
      errorMessage += `<li>${validation.message}</li>`;
      if (Array.isArray(validation.element)) {
        validation.element.forEach(element => element.classList.add('error'));
      } else {
        validation.element.classList.add('error');
      }
    }
  });
  errorMessage += '</ul>';
  
  error.innerHTML = errorMessage;
  if (errorsFound) {
    error.classList.remove('hide');
  } else {
    error.classList.add('hide');
    [name, email, password, passwordConfirm].forEach(element => element.classList.remove('error'));
  }
  


}

document.getElementById("submit").addEventListener("click", function(event) {
  checkForm();

  // Prevent default form action. DO NOT REMOVE THIS LINE
  event.preventDefault();
});