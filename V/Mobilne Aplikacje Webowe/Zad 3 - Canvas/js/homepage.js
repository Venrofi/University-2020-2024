const existingDrawings = document.querySelector('.existingDrawings');
let drawingNames = [];
let drawingThumbnails = [];
let existingData = {};

window.onload = getExistingDrawings();

function getExistingDrawings() {
  const xhr = new XMLHttpRequest();
  
  xhr.onreadystatechange = () => {
    if (xhr.readyState !== 4) return;

    if (xhr.status === 200 || xhr.status === 304) {
        try {
            existingData = JSON.parse(xhr.responseText)?.data;
            existingData.forEach((element) =>{
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

function newDrawing(){
    sessionStorage.drawingID = drawingNames.length;
    console.log('ID:', sessionStorage.drawingID);

    let name = Date();
    name = name.replace(/\s/g, '');
    name = name.slice(12, 20);
    name = 'Nowy Rysunek_' + name;

    const xhr = new XMLHttpRequest();
    xhr.onreadystatechange = () => {
        if (xhr.readyState == 4 && xhr.status == 200) {
            console.log('New Drawing!', Date());
            window.open('canvas.html', '_self')
        }
    };
    xhr.open("POST", "./php/addNewDrawing.php", true);
    xhr.setRequestHeader("Content-type", "application/json");
    xhr.send('{"lines":[]' + 
        ',"thumbnail":""' + 
        ',"name":"' + name +
        '"}');
}

function openExistingDrawings(){
    sessionStorage.drawingID = this.dataset.drawingID;
    window.open('canvas.html', '_self');
}

function renderDrawings(drawingNames){
    if(drawingNames.length < 1) return;
    
    drawingNames.forEach((drawing, index) =>{
        let newDrawing = document.createElement('div');
        newDrawing.classList.add('drawing');
        newDrawing.id = `drawing-${index}`;

        const a = document.createElement('a');
        a.href = '#';

        const p = document.createElement('p');
        p.textContent = drawing;

        const image = document.createElement('img');
        image.src = drawingThumbnails[index];
        image.alt = 'Thumbnail of the drawing..';

        const button = document.createElement('button');
        button.dataset.drawingID = index;
        button.innerText = 'Otwórz rysunek';
        button.onclick = openExistingDrawings;
        
        existingDrawings.appendChild(newDrawing);
        newDrawing.appendChild(a);
        newDrawing.appendChild(p);
        newDrawing.appendChild(image);
        newDrawing.appendChild(button);
    });
}