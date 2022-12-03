window.onload = () => {
  getPagesNamesFromPhp();
  window.setInterval(getPagesNamesFromPhp, 1000);
};

//#region Php communication
function getPagesNamesFromPhp() {
  const xhr = new XMLHttpRequest();
  xhr.onreadystatechange = () => {
    if (xhr.readyState !== 4) return;

    if (xhr.status === 200 || xhr.status === 304) {
        try {
            const readyResponse = JSON.parse(this.response);
            pages.length = 0;
            for (let i in readyResponse) {
                pages.push(readyResponse[i]);
            }
            createButtons(readyResponse);
        } catch (error) {
            console.error(error);
        }
    }
  };
  xhr.open("GET", "./php/getPagesNames.php", true);
  xhr.setRequestHeader("Content-Type", " application/json");
  xhr.send();
}

function sendNamesToPhp() {
  const xhr = new XMLHttpRequest();
  xhr.open("POST", "./php/sendPagesNames.php", true);
  xhr.setRequestHeader("Content-type", "application/json");
  xhr.onreadystatechange = () => {
    //Call a function when the state changes.
    if (xhr.readyState == 4 && xhr.status == 200) {}
  };
  xhr.send(JSON.stringify(pages));
}

function newPainting(){
    window.open('canvas.html', '_self');
}