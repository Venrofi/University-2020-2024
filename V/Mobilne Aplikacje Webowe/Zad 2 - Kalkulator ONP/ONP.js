var textbox = document.getElementById('formula');
var valueButtons = document.querySelectorAll('.buttons button');
var operatorButtons = document.querySelectorAll('.operators button');
var result = document.getElementById('wynik');

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
    result.innerHTML = '';
}

function backspace(){
    if(textbox.value.length > 0) textbox.value = textbox.value.slice(0, -1);
}

function ONP(){
    var formula = document.getElementById('formula').value;
    var stos = [];

    if (formula.length === 0) return 0;
    formula = formula.replace(/\s/g, '').split('');

    for (let i = 0; i < formula.length; i++) {
        var element = formula[i];
    
        if (!Number.isNaN(+element)) stos.push(parseFloat(element));
    
        else {
            if (stos.length < 2) {
                result.innerHTML = 'Niewystarczająca ilość wartości liczbowych w formule!';
                break;
            }

            var y = stos.pop();
            var x = stos.pop();

            if(y === 0 && element === '/'){
                result.innerHTML = 'W formule występuje dzielenie przez 0!';
                break;
            }
            stos.push(eval(x + element + y));
        }

        if(!Number.isNaN(stos) && stos.length == 1){
            result.innerHTML = Math.round(stos * 100) / 100;
        }
        else{
            result.innerHTML = 'Błędnie skonstruowana formuła!';
        }
    }
}