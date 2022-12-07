let drawingNames = [];
let drawingThumbnails = [];
const existingDrawings = document.querySelector('.existingDrawings');

window.onload = () => {
  getExistingPaintings();
  // window.setInterval(getExistingPaintings, 1000);
};

function getExistingPaintings() {
  const xhr = new XMLHttpRequest();
  
  xhr.onreadystatechange = () => {
    if (xhr.readyState !== 4) return;

    if (xhr.status === 200 || xhr.status === 304) {
        try {
            const responseData = JSON.parse(xhr.responseText)?.data;
            responseData.forEach((element) =>{
                drawingNames.push(element.name);
                drawingThumbnails.push(element.thumbnail);
            });
            renderDrawings(drawingNames);
        } catch (error) {
            console.error(error);
        }
    }
  };
  xhr.open("GET", "./php/getData.php", true);
  xhr.setRequestHeader("Content-Type", " application/json");
  xhr.send();
}

function newPainting(){
    sessionStorage.drawingID = drawingNames.length;
    console.log('ID:', sessionStorage.drawingID);
    // window.open('canvas.html', '_self');
}

function openExistingPainting(){
    sessionStorage.drawingID = this.dataset.drawingID;
    window.open('canvas.html', '_self');
}

function renderDrawings(drawingNames){
    if(drawingNames.length < 1) return;
    
    drawingNames.forEach((painting, index) =>{
        let newDrawing = document.createElement('div');
        newDrawing.classList.add('drawing');
        newDrawing.id = `drawing-${index}`;

        const a = document.createElement('a');
        a.href = '#';

        const p = document.createElement('p');
        p.textContent = painting;

        const image = document.createElement('img');
        image.src = drawingThumbnails[index];
        image.alt = 'Thumbnail of the drawing..';

        const button = document.createElement('button');
        button.dataset.drawingID = index;
        button.innerText = 'Otwórz rysunek';
        button.onclick = openExistingPainting;
        
        existingDrawings.appendChild(newDrawing);
        newDrawing.appendChild(a);
        newDrawing.appendChild(p);
        newDrawing.appendChild(image);
        newDrawing.appendChild(button);
    });
}