const header = document.querySelector('header');
const footer = document.querySelector('footer');
const lineWidthInput = document.querySelector('#lineWidth');
const lineColorInput = document.querySelector('#lineColor');
const lineWidthOutput = document.querySelector('#displayLineWidth');
const allDrawTypeButtons = document.querySelectorAll('.drawTypeButtons button');

const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');

let painting = false;
let straightDrawing = false;
let lineWidth = 10;
let startX = 0;
let startY = 0;

window.addEventListener('load', () =>{
    // Canvas height: window - 2rem - header - footer 
    canvas.height = window.innerHeight - header.offsetHeight - footer.offsetHeight - 32;
    canvas.width = window.innerWidth;
})

window.addEventListener('resize', () => {
    canvas.height = window.innerHeight - header.offsetHeight - footer.offsetHeight - 32;
    canvas.width = window.innerWidth;
})

lineWidthInput.oninput = () => lineWidthOutput.innerHTML = lineWidthInput.value; 

canvas.addEventListener('mousedown', startPosition)
canvas.addEventListener('mouseup', endPosition)

function setStraight(){
    allDrawTypeButtons.forEach((button) => {button.classList.remove('active')});
    allDrawTypeButtons[1].classList.toggle('active')
    canvas.removeEventListener('mousemove', draw)
    straightDrawing = true
}

function setCurve(){
    allDrawTypeButtons.forEach((button) => {button.classList.remove('active')});
    allDrawTypeButtons[0].classList.toggle('active')
    canvas.addEventListener('mousemove', draw)
    straightDrawing = false
}

function startPosition(e){
    if(straightDrawing){
        startX = e.clientX;
        startY = e.clientY;
        return;
    }
    painting = true;
    draw(e);
}

function endPosition(e){
    if(straightDrawing){
        drawStraight(e);
        return;
    }
    painting = false;
    ctx.beginPath();
}


function draw(e){
    if(!painting) return;

    ctx.lineCap = 'round';
    ctx.lineWidth = lineWidthInput.value;
    ctx.fillStyle = lineColorInput.value;
    ctx.strokeStyle = lineColorInput.value;

    ctx.lineTo(e.clientX, e.clientY - header.offsetHeight);
    ctx.stroke();
    ctx.beginPath();
    ctx.moveTo(e.clientX, e.clientY - header.offsetHeight);
}

function drawStraight(e){
    ctx.lineWidth = lineWidthInput.value;
    ctx.fillStyle = lineColorInput.value;
    ctx.strokeStyle = lineColorInput.value;

    ctx.beginPath();
    ctx.lineTo(startX, startY - header.offsetHeight);
    
    ctx.lineTo(e.clientX, e.clientY - header.offsetHeight);
    ctx.stroke();
}

function resetCanvas(){
    painting = false;
    ctx.clearRect(0, 0, canvas.width, canvas.height);
}