const header = document.querySelector('header');
const footer = document.querySelector('footer');
const lineWidthInput = document.querySelector('#lineWidth');
const lineWidthOutput = document.querySelector('#displayLineWidth');
const lineColorInput = document.querySelector('#lineColor');
const allDrawTypeButtons = document.querySelectorAll('.drawTypeButtons button');

const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');

let isDrawing = false;
let drawType = '';
let startX, startY, mouseX, mouseY = 0;
let existingLines = [];
let pointsOfCurve = [];
let circleRadius = 0;

window.addEventListener('load', () =>{
    // Canvas height: window - 2rem - header - footer 
    canvas.height = window.innerHeight - header.offsetHeight - footer.offsetHeight - 32;
    canvas.width = window.innerWidth;
    ctx.lineCap = 'round';
})

window.addEventListener('resize', () => {
    canvas.height = window.innerHeight - header.offsetHeight - footer.offsetHeight - 32;
    canvas.width = window.innerWidth;
    ctx.lineCap = 'round';

    drawExistingLines();  
})

lineWidthInput.oninput = () => lineWidthOutput.innerHTML = lineWidthInput.value; 

canvas.addEventListener('mousedown', startPosition, {passive: true, capture: true})
canvas.addEventListener('mousemove', currentPosition, {passive: true, capture: true})
canvas.addEventListener('mouseup', endPosition, {passive: true, capture: true})

function setCurve(){
    allDrawTypeButtons.forEach((button) => {button.classList.remove('active')});
    allDrawTypeButtons[0].classList.toggle('active')
    
    isDrawing = false;
    startX, startY, mouseX, mouseY = 0;
    pointsOfCurve = [];
    drawType = 'curve';
}

function setStraight(){
    allDrawTypeButtons.forEach((button) => {button.classList.remove('active')});
    allDrawTypeButtons[1].classList.toggle('active')

    isDrawing = false;
    startX, startY, mouseX, mouseY = 0;
    drawType = 'straight';
}

function setCircle(){
    allDrawTypeButtons.forEach((button) => {button.classList.remove('active')});
    allDrawTypeButtons[2].classList.toggle('active');
    
    isDrawing = false;
    startX, startY, mouseX, mouseY = 0;
    circleRadius = 0;
    drawType = 'circle';
}

function setRectangle(){
    allDrawTypeButtons.forEach((button) => {button.classList.remove('active')});
    allDrawTypeButtons[3].classList.toggle('active');
    
    isDrawing = false;
    startX, startY, mouseX, mouseY = 0;
    drawType = 'rectangle';
}

function startPosition(e){
    if(e.button !== 0) return //Check if the Left Mouse button was clicked

    startX = e.clientX;
    startY = e.clientY - header.offsetHeight;

    switch(drawType) {
        case 'curve':
            isDrawing = true;
            draw(e);
            break;

        case 'straight':
            isDrawing = true;
            drawStraight();
            break;

        case 'circle':
            isDrawing = true;
            drawCircle();
            break;

        case 'rectangle':
            console.log('Drawing Rectangle..')
            break;

        default:
            console.error('Wrong draw type..')
    }
}

function currentPosition(e){
    mouseX = e.clientX;
    mouseY = e.clientY - header.offsetHeight;
    // console.log(`Start: ${startX}, ${startY} Current: ${mouseX}, ${mouseY}`);

    if (!isDrawing) return;

    switch(drawType) {
        case 'curve':
            draw(e);
            break;

        case 'straight':
            drawStraight();
            break;

        case 'circle':
            drawCircle();
            break;

        case 'rectangle':
            console.log('Drawing Rectangle..')
            break;

        default:
            console.log('Wrong draw type..')
    }
}

function endPosition(e){
    switch(drawType) {
        case 'curve':
            isDrawing = false;
            ctx.beginPath();
            existingLines.push(pointsOfCurve);
            pointsOfCurve = [];
            break;

        case 'straight':
            if (isDrawing) {
                existingLines.push({
                    startX: startX,
                    startY: startY,
                    endX: mouseX,
                    endY: mouseY,
                    color: ctx.strokeStyle,
                    width: ctx.lineWidth,
                    type: 'straight'
                });            
                isDrawing = false;
            }
            drawStraight();
            ctx.beginPath();
            break;

        case 'circle':
            if (isDrawing) {
                existingLines.push({
                    startX: startX,
                    startY: startY,
                    color: ctx.strokeStyle,
                    width: ctx.lineWidth,
                    radius: circleRadius,
                    type: 'circle'
                });            
                isDrawing = false;
            }
            drawCircle();
            ctx.beginPath();
            break;
            
        case 'rectangle':
            console.log('Drawing Rectangle..')
            break;

        default:
            console.log('Wrong draw type..')
    }
    console.log(existingLines);
    console.log(canvas.toDataURL());
}

function draw(e){
    if(!isDrawing) return;

    ctx.lineWidth = lineWidthInput.value;
    ctx.strokeStyle = lineColorInput.value;

    ctx.lineTo(e.clientX, e.clientY - header.offsetHeight);
    ctx.stroke();
    ctx.beginPath();
    ctx.moveTo(e.clientX, e.clientY - header.offsetHeight);

    pointsOfCurve.push({
        startX: e.clientX,
        startY: e.clientY - header.offsetHeight,
        endX: e.clientX,
        endY: e.clientY - header.offsetHeight,
        color: ctx.strokeStyle,
        width: ctx.lineWidth
    });
}

function drawStraight(){    
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    
    drawExistingLines();
    
    ctx.lineWidth = lineWidthInput.value;
				
    if (isDrawing) {
        ctx.strokeStyle = "grey";
        ctx.beginPath();
        ctx.moveTo(startX, startY);
        ctx.lineTo(mouseX, mouseY);
        ctx.stroke();
    }
    
    ctx.strokeStyle = lineColorInput.value;
}

function drawCircle(){
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    
    drawExistingLines();
    
    ctx.lineWidth = lineWidthInput.value;
				
    if (isDrawing) {
        ctx.strokeStyle = "grey";
        ctx.beginPath();

        circleRadius = Math.sqrt((mouseX - startX)**2 + (mouseY - startY)**2);
        ctx.arc(startX, startY, circleRadius, 0, 2 * Math.PI, false);
        ctx.stroke();
    }
    
    ctx.strokeStyle = lineColorInput.value;
}

function resetCanvas(){
    isDrawing = false;
    startX, startY, mouseX, mouseY = 0;
    existingLines = [];
    pointsOfCurve = [];
    ctx.clearRect(0, 0, canvas.width, canvas.height);
}

function drawExistingLines(){
    existingLines.forEach(line => {
        ctx.beginPath();

        if(Array.isArray(line)){
            ctx.lineWidth = line[0].width;
            ctx.strokeStyle = line[0].color;
            
            for (let i = 0; i < line.length - 1; ++i) {
                ctx.moveTo(line[i].endX, line[i].endY);
                ctx.lineTo(line[i + 1].endX, line[i + 1].endY);
                ctx.stroke();
            }
        }
        else{
            ctx.lineWidth = line.width;
            ctx.strokeStyle = line.color;

            if(line?.type === 'straight'){
                ctx.moveTo(line.startX, line.startY);
                ctx.lineTo(line.endX, line.endY);
                ctx.stroke();
            }

            if(line?.type === 'circle'){
                console.log('Hello from circle rendering')
                ctx.arc(line.startX, line.startY, line.radius, 0, 2 * Math.PI, false);
                ctx.stroke();
            }
        }
    });
    
    ctx.lineWidth = lineWidthInput.value;
    ctx.strokeStyle = lineColorInput.value;
}