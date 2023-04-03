window.addEventListener("DOMContentLoaded", domLoaded);

function domLoaded() {
  const cInput = document.getElementById("cInput");
  const fInput = document.getElementById("fInput");
  const convertButton = document.getElementById("convertButton");
  const errorMessage = document.getElementById("errorMessage");
  const image = document.getElementById("weatherImage");

  // Register input event handler for cInput
  cInput.addEventListener("input", () => {
    if (cInput.value !== "") {
      fInput.value = "";
    }
  });

  // Register input event handler for fInput
  fInput.addEventListener("input", () => {
    if (fInput.value !== "") {
      cInput.value = "";
    }
  });

  // Register click event handler for convertButton
  convertButton.addEventListener("click", () => {
    let celsius;
    let fahrenheit;

    if (cInput.value !== "") {
      celsius = parseFloat(cInput.value);
      if (isNaN(celsius)) {
        errorMessage.innerHTML = `${cInput.value} is not a number`;
        return;
      }
      fahrenheit = (celsius * 9/5) + 32;
      fInput.value = Math.round(fahrenheit);
      if (fahrenheit < 32) {
        image.src = "cold.png";
      } else if (fahrenheit >= 32 && fahrenheit <= 50) {
        image.src = "cool.png";
      } else {
        image.src = "warm.png";
      }
    } else if (fInput.value !== "") {
      fahrenheit = parseFloat(fInput.value);
      if (isNaN(fahrenheit)) {
        errorMessage.innerHTML = `${fInput.value} is not a number`;
        return;
      }
      celsius = (fahrenheit - 32) * 5/9;
      cInput.value = Math.round(celsius);
      if (fahrenheit < 32) {
        image.src = "cold.png";
      } else if (fahrenheit >= 32 && fahrenheit <= 50) {
        image.src = "cool.png";
      } else {
        image.src = "warm.png";
      }
    }

    errorMessage.innerHTML = "";
  });
}


function convertCtoF(degreesCelsius) {
   // TODO: Complete the function
   const cels = degreesCelsius;
   far = (cels * (9/5) + 32);
   return far;
}

function convertFtoC(degreesFahrenheit) {
   // TODO: Complete the function
   const far = degreesFahrenheit;
   cels = ((far - 32) * 5/9);
   return cels;
}
