function parseScores(scoresString) {
   return scoresString.split(" ");
   }

   function buildDistributionArray(scoresArray) {
      const distributionArray = [0, 0, 0, 0, 0];
      for (let i = 0; i < scoresArray.length; i++) {
      const score = parseInt(scoresArray[i]);
      if (score >= 90) {
      distributionArray[0]++;
      } else if (score >= 80) {
      distributionArray[1]++;
      } else if (score >= 70) {
      distributionArray[2]++;
      } else if (score >= 60) {
      distributionArray[3]++;
      } else {
      distributionArray[4]++;
      }
      }
      return distributionArray;
      }

      function setTableContent(userInput) {
         const scoresArray = parseScores(userInput);
         const distributionArray = buildDistributionArray(scoresArray);
       
         const firstRow = document.getElementById("firstRow");
         const thirdRow = document.getElementById("thirdRow");
       
         for (let i = 0; i < distributionArray.length; i++) {
           const barHeight = distributionArray[i] * 10;
           const bar = document.createElement("div");
           bar.style.height = `${barHeight}px`;
           bar.className = `bar${i}`;
           const cell = document.createElement("td");
           cell.appendChild(bar);
           firstRow.appendChild(cell);
         }
       
         for (let i = 0; i < distributionArray.length; i++) {
           const cell = document.createElement("td");
           cell.textContent = distributionArray[i];
           thirdRow.appendChild(cell);
         }
       }

// The argument can be changed for testing purposes
setTableContent("45 78 98 83 86 99 90 59");