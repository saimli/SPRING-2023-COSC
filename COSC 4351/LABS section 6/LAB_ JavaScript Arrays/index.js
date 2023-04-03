function calcWordFrequencies() {
    const input = prompt("Enter a list of words separated by spaces:");
  
    // Split the input into an array of words
    const words = input.split(" ");
  
    // Create an object to store the frequency of each word
    const freq = {};
  
    // Loop through each word and update its frequency in the freq object
    for (let i = 0; i < words.length; i++) {
      const word = words[i];
      freq[word] = (freq[word] || 0) + 1;
    }
  
    // Loop through the words array and output each occurrence of a word and its frequency to the console
  for (let i = 0; i < words.length; i++) {
    const word = words[i];
    console.log(`${word} ${freq[word]}`);
  }
}