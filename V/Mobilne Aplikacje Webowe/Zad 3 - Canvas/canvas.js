const header = document.querySelector('header');
const footer = document.querySelector('footer');
const lineWidthInput = document.querySelector('#lineWidth');
const lineWidthOutput = document.querySelector('#displayLineWidth');
const lineColorInput = document.querySelector('#lineColor');
const allDrawTypeButtons = document.querySelectorAll('.drawTypeButtons button');

const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');

let painting = false;
let isDrawing = false;
let straightDrawing = false;
let startX, startY, mouseX, mouseY = 0;
let existingLines = [];

window.addEventListener('load', () =>{
    // Canvas height: window - 2rem - header - footer 
    canvas.height = window.innerHeight - header.offsetHeight - footer.offsetHeight - 32;
    canvas.width = window.innerWidth;
    ctx.lineCap = 'round';
})

window.addEventListener('resize', () => {
    canvas.height = window.innerHeight - header.offsetHeight - footer.offsetHeight - 32;
    canvas.width = window.innerWidth;
})

lineWidthInput.oninput = () => lineWidthOutput.innerHTML = lineWidthInput.value; 

canvas.addEventListener('mousedown', startPosition)
// canvas.addEventListener('mousemove', currentPosition)
canvas.addEventListener('mouseup', endPosition)

function setCurve(){
    allDrawTypeButtons.forEach((button) => {button.classList.remove('active')});
    allDrawTypeButtons[0].classList.toggle('active')
    canvas.addEventListener('mousemove', draw)
    straightDrawing = false
}

function setStraight(){
    allDrawTypeButtons.forEach((button) => {button.classList.remove('active')});
    allDrawTypeButtons[1].classList.toggle('active')
    canvas.removeEventListener('mousemove', draw)
    canvas.onmousemove = currentPosition;
    straightDrawing = true
}

function setCircle(){
    allDrawTypeButtons.forEach((button) => {button.classList.remove('active')});
    allDrawTypeButtons[2].classList.toggle('active')
}

function setRectangle(){
    allDrawTypeButtons.forEach((button) => {button.classList.remove('active')});
    allDrawTypeButtons[3].classList.toggle('active')
}

function startPosition(e){
    if(e.button !== 0) return //Check if the Left Mouse button was clicked

    if(!straightDrawing){
        painting = true;
        draw(e);
    }
    else{
        if (!isDrawing) {
            startX = e.clientX;
            startY = e.clientY - header.offsetHeight;
            
            isDrawing = true;
        }
        
        drawStraight();
    }
}

function currentPosition(e){
    mouseX = e.clientX;
    mouseY = e.clientY - header.offsetHeight;
    
    if (isDrawing) {
        drawStraight();
    }
}

function endPosition(e){
    if(!straightDrawing){
        painting = false;
        ctx.beginPath();
    }
    else{
        if (isDrawing) {
            existingLines.push({
                startX: startX,
                startY: startY,
                endX: mouseX,
                endY: mouseY
            });
            console.log(existingLines);
            
            isDrawing = false;
        }
        
        drawStraight();
    }
}

function draw(e){
    if(!painting) return;

    ctx.lineWidth = lineWidthInput.value;
    ctx.fillStyle = lineColorInput.value;
    ctx.strokeStyle = lineColorInput.value;

    ctx.lineTo(e.clientX, e.clientY - header.offsetHeight);
    ctx.stroke();
    ctx.beginPath();
    ctx.moveTo(e.clientX, e.clientY - header.offsetHeight);
}

function drawStraight(){
    ctx.lineWidth = lineWidthInput.value;
    ctx.fillStyle = lineColorInput.value;
    ctx.strokeStyle = lineColorInput.value;

    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.beginPath();
				
    for (let i = 0; i < existingLines.length; ++i) {
        let line = existingLines[i];
        ctx.moveTo(line.startX,line.startY);
        ctx.lineTo(line.endX,line.endY);
    }

    ctx.stroke();
				
    if (isDrawing) {
        ctx.strokeStyle = "grey";
        ctx.beginPath();
        ctx.moveTo(startX, startY);
        ctx.lineTo(mouseX, mouseY);
        ctx.stroke();
    }
}

function resetCanvas(){
    painting, isDrawing, straightDrawing = false;
    startX, startY, mouseX, mouseY = 0;
    existingLines = [];
    ctx.clearRect(0, 0, canvas.width, canvas.height);
}