function parseScores(scoresString) {
   
    // Your code here

    const scoreStrings = scoresString.split(' ');

    // Filter out any invalid score strings
    const validScoreStrings = scoreStrings.filter(scoreString => {
        const score = parseInt(scoreString);
        return !isNaN(score) && score >= 0 && score <= 100;
    });

    return validScoreStrings;
}

