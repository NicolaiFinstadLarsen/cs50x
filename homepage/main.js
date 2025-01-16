/* When the user clicks on the button,
toggle between hiding and showing the dropdown content */
function myFunction() {
    document.getElementById("myDropdown").classList.toggle("show");
  }

  // Close the dropdown menu if the user clicks outside of it
  window.onclick = function(event) {
    if (!event.target.matches('.dropbtn')) {
      let dropdowns = document.getElementsByClassName("dropdown-content");
      for (let i = 0; i < dropdowns.length; i++) {
        let openDropdown = dropdowns[i];
        if (openDropdown.classList.contains('show')) {
          openDropdown.classList.remove('show');
        }
      }
    }
  }

function appendToOutput(text) {
  const output = document.getElementById('output');
  const newLine = document.createElement('p'); // New paragraph to get newline
  newLine.textContent = text;
  output.appendChild(newLine);
  output.scrollTop = output.scrollHeight; // Scroll to the bottom
}

function calc(num) {
    if (num === 1) {
        appendToOutput("We always end at 1");
        return;
    }

    if (num % 2 === 0) { // Even case
        const newNum = num / 2;
        appendToOutput(`Even: ${num}/2 = ${newNum}`);
        calc(newNum);
    } else { // Odd case
        const newNum = num * 3 + 1;
        appendToOutput(`Odd: 3*${num}+1 = ${newNum}`);
        calc(newNum);
    }
}

function startCalc() {
    const input = document.getElementById('userInput').value;
    const x = parseInt(input, 10);

    const output = document.getElementById('output');
    output.innerHTML = ''; // Clear previous output

    if (isNaN(x) || x <= 0) {
        appendToOutput("Error: Please enter a positive whole number.");
        return;
    }

    calc(x);
}
