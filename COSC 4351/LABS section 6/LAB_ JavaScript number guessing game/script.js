function playGuessingGame(numToGuess, totalGuesses = 10) {
    let guessCount = 0;
    let guess = "";
    while (guessCount < totalGuesses) {
      guessCount++;
      if (guessCount === 1) {
        guess = prompt("Enter a number between 1 and 100.");
      } else if (guess < numToGuess) {
        guess = prompt(guess + " is too small. Guess a larger number.");
      } else if (guess > numToGuess) {
        guess = prompt(guess + " is too large. Guess a smaller number.");
      } else if (!isNaN(guess)) {
        if (guessCount == 3) {
          return guessCount;
        }
        return guessCount - 1;
      }
      if (guess === null) {
        return 0;
      }
      if (isNaN(guess)) {
        guessCount--;
        guess = prompt("Please enter a number.");
      }
    }
    return 0;
  }
  