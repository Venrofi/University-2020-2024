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

window.addEventListener('load', initialCanvas);

window.addEventListener('resize', () => {
    initialCanvas();
    drawExistingLines();  
    ctx.beginPath();
})

window.addEventListener('orientationchange', () => {
    initialCanvas();
    drawExistingLines();  
    ctx.beginPath();
})

lineWidthInput.oninput = () => lineWidthOutput.innerHTML = lineWidthInput.value; 

canvas.addEventListener('mousedown', startPosition, {passive: true, capture: true})
canvas.addEventListener('mousemove', currentPosition, {passive: true, capture: true})
canvas.addEventListener('mouseup', endPosition, {passive: true, capture: true})

canvas.addEventListener('touchstart', startPosition)
canvas.addEventListener('touchmove', currentPosition)
canvas.addEventListener('touchend', endPosition)

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
    e.preventDefault();

    startX = e.clientX;
    startY = e.clientY - header.offsetHeight;
    console.log(e);
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
            isDrawing = true;
            drawRectangle();
            break;

        default:
            console.error('Wrong draw type..')
    }
}

function currentPosition(e){
    e.preventDefault();

    mouseX = e.clientX;
    mouseY = e.clientY - header.offsetHeight;
    // console.log(`Start: ${startX}, ${startY} Current: ${mouseX}, ${mouseY}`);
    console.log(e, startX, startY, mouseX, mouseY);

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
            drawRectangle();
            break;

        default:
            console.log('Wrong draw type..')
    }
}

function endPosition(e){
    e.preventDefault();
    console.log(e);

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
            if (isDrawing) {
                existingLines.push({
                    startX: startX,
                    startY: startY,
                    endX: mouseX,
                    endY: mouseY,
                    color: ctx.strokeStyle,
                    width: ctx.lineWidth,
                    type: 'rectangle'
                });            
                isDrawing = false;
            }
            drawRectangle();
            ctx.beginPath();
            break;

        default:
            console.log('Wrong draw type..')
    }
    // console.log(existingLines);
    // console.log(canvas.toDataURL());
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

function drawRectangle(){
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    
    drawExistingLines();
    
    ctx.lineWidth = lineWidthInput.value;
				
    if (isDrawing) {
        ctx.strokeStyle = "grey";
        ctx.beginPath();
        ctx.rect(startX, startY, mouseX - startX, mouseY - startY);
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

function undoLastDraw(){
    if(existingLines.length > 0) {
        existingLines.pop();
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        drawExistingLines();
        isDrawing = false;
        ctx.beginPath();
    }
}

function initialCanvas(){
    // Canvas height: window - 1rem - header - footer 
    canvas.height = window.innerHeight - header.offsetHeight - footer.offsetHeight - 16;
    canvas.width = window.innerWidth;
    ctx.lineCap = 'round';
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
                ctx.arc(line.startX, line.startY, line.radius, 0, 2 * Math.PI, false);
                ctx.stroke();
            }

            if(line?.type === 'rectangle'){
                ctx.rect(line.startX, line.startY, line.endX - line.startX, line.endY - line.startY)
                ctx.stroke();
            }
        }
    });
    
    ctx.lineWidth = lineWidthInput.value;
    ctx.strokeStyle = lineColorInput.value;
}