function parseScores(scoresString) {
    return scoresString.split(" ").filter(score => score >= 0 && score <= 100);
  }
  
  function buildDistributionArray(scoresArray) {
    const distribution = [0, 0, 0, 0, 0];
    for (let i = 0; i < scoresArray.length; i++) {
      const score = parseInt(scoresArray[i]);
      if (score >= 90) {
        distribution[0]++;
      } else if (score >= 80) {
        distribution[1]++;
      } else if (score >= 70) {
        distribution[2]++;
      } else if (score >= 60) {
        distribution[3]++;
      } else {
        distribution[4]++;
      }
    }
    return distribution;
  }
  
  function setTableContent(userInput) {
    const scoresArray = parseScores(userInput);
    const distributionArray = buildDistributionArray(scoresArray);
    const table = document.getElementById("distributionTable");
  
    // If there are no scores, create a single cell with the "No graph to display" message
    if (scoresArray.length === 0) {
    //   table.innerHTML = "<tr><td>No graph to display</td></tr>";
      return; // exit the function early
    }
  else{
    if (userInput.length === 0) {
        table.innerHTML = "<tr><td>No graph to display</td></tr>";
          return; // exit the function early
        }
    
    
    // If there are scores, create the table with the graph and labels
    let row1 = "<tr>";
    let row2 = "<tr>";
    let row3 = "<tr>";
    for (let i = 0; i < distributionArray.length; i++) {
      const height = distributionArray[i] * 10;
      row1 += `<td><div style="height:${height}px" class="bar${i}"></div></td>`;
      row2 += `<td class="gradeLabel">${String.fromCharCode(65+i)}</td>`;
      row3 += `<td class="gradeCount">${distributionArray[i]}</td>`;
    }
    row1 += "</tr>";
    row2 += "</tr>";
    row3 += "</tr>";
    table.innerHTML = row1 + row2 + row3;}
    
  }
  
  
  
  function bodyLoaded() {
    setTableContent("45 78 98 83 86 99 90 59");
  }
  