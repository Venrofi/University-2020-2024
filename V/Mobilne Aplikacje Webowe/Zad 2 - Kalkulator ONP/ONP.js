var mainTextbox = document.getElementById('numberInput');
var primeTextbox = document.querySelector('.prime-decomp');
var primeSumTextbox = document.querySelector('.prime-sum');

var valueButtons = document.querySelectorAll('.buttons button');
var operatorButtons = document.querySelectorAll('.operators button');

var stackView = document.getElementById('stack');
var errorText = document.getElementById('error');

var stack = [];

document.body.addEventListener("keyup", (e) => {
    e.preventDefault();
    console.log(e.key);

    valueButtons.forEach(button => {
        if(button.value === e.key) mainTextbox.value += e.key;
    });

    operatorButtons.forEach(operator => {
        if(operator.value === e.key) calculateONP(operator.value);
    });

    var enterButton = document.querySelector('.calculator button');
    if(enterButton.value === e.key) pushOnStack();
    
    var backspaceButton = document.querySelector('#backspace');
    if(backspaceButton.value === e.key) backspace();

});

valueButtons.forEach(button => {
    button.addEventListener("click", (e) => mainTextbox.value += e.target.value );
});

operatorButtons.forEach(operator => {
    operator.addEventListener("click", () => calculateONP(operator.value) );
});

function clearAll(){
    if(mainTextbox.value.length > 0) mainTextbox.value = '';
    stackView.innerHTML = '';
    errorText.innerHTML = '';
    primeTextbox.innerHTML = '';
    primeSumTextbox.innerHTML = '';
    stack = [];
}

function backspace(){
    if(mainTextbox.value.length > 0) mainTextbox.value = mainTextbox.value.slice(0, -1);
}

function pushOnStack(){
    let inputValue = document.getElementById('numberInput').value;
    if (inputValue.length === 0) return;

    stack.push(parseInt(inputValue));
    mainTextbox.value = '';
    errorText.innerHTML = '';

    if(stackView.innerHTML === '') stackView.innerHTML += `Stos: ${stack.at(-1)}`;
    else stackView.innerHTML += `, ${stack.at(-1)}`;
}

function calculateONP(operator){
    let inputValue = document.getElementById('numberInput').value;
    var x, y;

    if(inputValue.length === 0 && stack.length < 2 || inputValue.length > 0 && stack.length === 0) {
        errorText.innerHTML = 'Niewystarczająca ilość wartości liczbowych!';
        return;
    }

    if(inputValue.length === 0 && stack.length > 1){
        y = stack.pop();
        x = stack.pop();
    }

    if(inputValue.length > 0 && stack.length > 0){
        y = parseInt(inputValue);
        x = stack.pop();
    }

    if(y === 0 && operator === '/'){
        errorText.innerHTML = 'W formule występuje dzielenie przez 0!';
        stackView.innerHTML = '';

        stack.forEach(element => {
            if(stackView.innerHTML === '') stackView.innerHTML += `Stos: ${element}`;
            else stackView.innerHTML += `, ${element}`;
        });
        return;
    }

    if(operator ==='^') inputValue = eval(x ** y);
    else inputValue = Math.round(eval(x + operator + y));

    mainTextbox.value = inputValue;

    stackView.innerHTML = '';
    stack.forEach(element => {
        if(stackView.innerHTML === '') stackView.innerHTML += `Stos: ${element}`;
        else stackView.innerHTML += `, ${element}`;
    });

    primeDecomposition(Math.round(inputValue));
    primeEvenSumDecomposition(Math.round(inputValue));
}

function primeDecomposition(number){
    if (!isNaN(number) && number > 1){
        let result = `Rozkład na liczby pierwsze: \\( ${number} = `;
        let i = 2;
        let e = Math.floor(Math.sqrt(number));
        let decompNumbers = [];

        while (i <= e) {
            while ((number % i) == 0) {
                decompNumbers.push(i);

                number = Math.floor(number / i);
                e = Math.floor(Math.sqrt(number));
            }
            i++;
        }
        if (number > 1) decompNumbers.push(number);

        let uniqueDecompNumbers = [... new Set(decompNumbers)];

        for(let i=0; i < uniqueDecompNumbers.length; i++){
            let numberOfOccurance = decompNumbers.filter((v) => (v === uniqueDecompNumbers[i])).length;

            if (numberOfOccurance > 1) result += `${uniqueDecompNumbers[i]} ^{${numberOfOccurance}} *`;
            else result += `${uniqueDecompNumbers[i]} *`;
        }

        result = result.slice(0, -1);
        result += '\\)';

        primeTextbox.innerHTML = result;
        MathJax.typeset();
    }
}

function isPrime(number){
    if(number <= 1) return false;

    for(let i=2; i < number; i++){
        if(number % i == 0) return false;
    }
    return true;
}

function primeEvenSumDecomposition(number){
    if (!isNaN(number) && number >= 4 && number % 2 === 0){
        let result = ``;
        
        for(let i=2; i < number; i++){
            if(isPrime(i) && isPrime(number - i)) {
                result = `Rozkład parzystej liczby na sumę liczb pierwszych: \\( ${number} = ${i} + ${number - i} \\)`;
            }
        }
        primeSumTextbox.innerHTML = result;
        MathJax.typeset();
    }
}

/*
    ✅1. Zamiast "Oblicz" jest "Enter"
    ✅2. W inpucie wprowadzamy liczbę, po kliknięciu "Enter" input się czyści, wartość trafia do stosu. Można wprowadzać nieskończoną ilość elementów do stostu.
    ✅3. Po kliknięciu operatora bierze on dwa górne elementy ze stosu i generuje wynik. 
    4. Dodać kolejne operatory NWD i SWAP: bierze dwie górne liczby ze stosu i oblicza NWD / zamienia miejscami
    ✅5. Dodać widoczny stos z boku strony: mniejsze opacity, wymagane tylko top3 pozycje stosu.
    ✅6. Jeśli w inpucie jest liczba to bierze ją i pierwszą liczbę ze stosu do kalkulacji po wciśnięciu operatora. Jeśli jest pusty to bierze dwie liczby ze stosu.
*/