$(function () {
   $("#fetchQuotesBtn").click(function () {
      // Get selected topic and count from drop-down lists
      const selectedTopic = $("#topicSelection option:selected").val();
      const selectedCount = $("#countSelection option:selected").val();
      fetchQuotes(selectedTopic, selectedCount);
   });
});

function fetchQuotes(topic, count) {
   $.ajax({
     url: `https://wp.zybooks.com/quotes.php?topic=${topic}&count=${count}`,
     dataType: "json",
     success: function(data) {
       let html = "<ol>";
       if (Array.isArray(data)) {
         data.forEach(function(quote) {
           html += `<li>${quote.quote} - ${quote.source}</li>`;
         });
         html += "</ol>";
         $("#quotes").html(html);
       } else {
         $("#quotes").html(`Topic '${topic}' not found`);
       }
     },
     error: function(jqXHR, textStatus, errorThrown) {
       $("#quotes").html(`Error: ${errorThrown}`);
     }
   });
 }
 