function calcWordFrequencies() {
   const input = prompt("Enter paragraph")
   const freq = {}
   const words = input.split(" ")


    // Loop through each word and update its frequency in the freq object
    for (let i = 0; i < words.length; i++) {
    const word = words[i];
    freq[word] = (freq[word] || 0) + 1;
    }


    // Loop through the freq object and output each word and its frequency to the console
    for (let word in freq) {
        console.log(`${word} ${freq[word]}`);
    }
}