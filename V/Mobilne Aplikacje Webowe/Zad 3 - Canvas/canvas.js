const header = document.querySelector('header');
const main = document.querySelector('main');
const footer = document.querySelector('footer');
const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');

let painting = false;
let lineWidth = 10;

window.addEventListener('load', () =>{
    // Canvas: width = window - 4px border, height: window - 2rem - header - footer 
    canvas.height = window.innerHeight - header.offsetHeight - footer.offsetHeight - 32;
    canvas.width = window.innerWidth - 4;
})

window.addEventListener('resize', () => {
    canvas.height = window.innerHeight - header.offsetHeight - footer.offsetHeight - 32;
    canvas.width = window.innerWidth - 4;
})

canvas.addEventListener('mousedown', startPosition)
canvas.addEventListener('mouseup', endPosition)
canvas.addEventListener('mousemove', draw)

function startPosition(e){
    painting = true;
    draw(e);
}

function endPosition(){
    painting = false;
    ctx.beginPath();
}

function draw(e){
    if(!painting) return;

    ctx.lineWidth = lineWidth;
    ctx.lineCap = 'round';

    ctx.lineTo(e.clientX, e.clientY - header.offsetHeight);
    ctx.stroke();
    ctx.beginPath();
    ctx.moveTo(e.clientX, e.clientY - header.offsetHeight);
}

