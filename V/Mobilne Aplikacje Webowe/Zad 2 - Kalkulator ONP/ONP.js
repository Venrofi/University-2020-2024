var textbox = document.getElementById('formula');
var valueButtons = document.querySelectorAll('.buttons button');
var operatorButtons = document.querySelectorAll('.operators button');

for (let i=0; i < valueButtons.length; i++) {
    valueButtons[i].addEventListener("click", (e) => {
        textbox.value += e.target.value
	});
};

for (let i=0; i < operatorButtons.length; i++) {
    operatorButtons[i].addEventListener("click", (e) => {
        textbox.value += e.target.value
	});
};

function clearAll(){
    if(textbox.value.length > 0) textbox.value = '';
}

function backspace(){
    if(textbox.value.length > 0) textbox.value = textbox.value.slice(0, -1);
}

function ONP(){
    var formula = document.getElementById('formula').value;
    var wynik = document.getElementById('wynik');
    var stos = [];

    if (formula.length === 0) return 0;

    formula = formula.replace(/\s/g, '').split('');

    for (let i = 0; i < formula.length; i++) {
        var element = formula[i];
    
        if (!Number.isNaN(+element)) stos.push(parseFloat(element));
    
        else {
            if (stos.length < 2) {
                wynik.innerHTML = 'Niewystarczająca ilość wartości liczbowych w formule!';
                break;
            }

            var y = stos.pop();
            var x = stos.pop();
            stos.push(eval(x + element + y));
        }
        wynik.innerHTML = Math.round(stos * 100) / 100;
    }

}