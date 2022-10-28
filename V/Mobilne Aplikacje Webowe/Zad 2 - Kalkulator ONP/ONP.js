var mainTextbox = document.getElementById('numberInput');
var primeTextbox = document.querySelector('.prime-decomp');
var primeSumTextbox = document.querySelector('.prime-sum');

var valueButtons = document.querySelectorAll('.buttons button');
var operatorButtons = document.querySelectorAll('.operators button');

var stackView = document.getElementById('stack');
var errorText = document.getElementById('error');

var stack = [];
const maxNumber = Number.MAX_SAFE_INTEGER;
const maxNumberForDecomp = Math.pow(2,25);
var newNumber = true;

document.body.addEventListener("keypress", (e) => {
    e.preventDefault();

    valueButtons.forEach(button => {
        let inputValue = mainTextbox.value;
        
        // if(button.value === e.key && newNumber === true) {
        //     if(inputValue.length > 0 && inputValue <= maxNumber) {
        //         stack.push(inputValue);
        //         stackView.innerHTML = '';
        //         stack.forEach(element => {
        //             if(stackView.innerHTML === '') stackView.innerHTML += `Stos: ${element}`;
        //             else stackView.innerHTML += `, ${element}`;
        //         });
        //     }
            
        //     console.log("Number clicked: ", e.key, stack)
        //     mainTextbox.value = e.key;
        //     newNumber = false;
        // }
        console.log(button.value, e.key, newNumber)
        if(button.value === e.key && newNumber === false) inputValue += e.key;
    });

    operatorButtons.forEach(operator => {
        if(operator.value === e.key) calculateONP(operator.value);
    });

    var enterButton = document.querySelector('.calculator button');
    if(enterButton.value === e.key) pushOnStack();
    
    
});

document.body.addEventListener("keyup", (e) => {
    e.preventDefault();
    
    var backspaceButton = document.querySelector('#backspace');
    if(backspaceButton.value === e.key) backspace();
});

valueButtons.forEach(button => {
    button.addEventListener("click", (e) => {
        let inputValue = document.getElementById('numberInput').value;

        if(newNumber === false) mainTextbox.value += e.target.value;

        if(newNumber === true) {
            if(inputValue <= maxNumber) stack.push(inputValue);

            mainTextbox.value = e.target.value;
            newNumber = false;
        }
    });
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

function NWD(a, b){
    if(b === 0) return a;

    return NWD(b, a % b);
}

function swap(a, b){
    stack.push(b);
    return a;
}

function pushOnStack(){
    let inputValue = document.getElementById('numberInput').value;
    if (inputValue.length === 0) return;

    stack.push(parseInt(inputValue));
    newNumber = true;
    // mainTextbox.value = '';
    errorText.innerHTML = '';

    if(stackView.innerHTML === '') stackView.innerHTML += `Stos: ${stack.at(-1)}`;
    else stackView.innerHTML += `, ${stack.at(-1)}`;
}

function calculateONP(operator){
    let inputValue = document.getElementById('numberInput').value;
    var x, y;

    if(inputValue.length === 0 && stack.length < 2) {
        errorText.innerHTML = 'Niewystarczająca ilość wartości liczbowych!';
        return;
    }
    
    if(inputValue.length > 0 && stack.length === 0){
        y = parseInt(inputValue);
        x = parseInt(inputValue);
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
    else if(operator === "SWAP") inputValue = swap(x, y);
    else if(operator === "NWD") inputValue = NWD(x, y);
    else inputValue = Math.round(eval(x + operator + y));

    if(inputValue <= maxNumber) {
        errorText.innerHTML = '';
        mainTextbox.value = inputValue;
        console.log('input po obliczeniu: ', inputValue);
        newNumber = true;
    }
    else {
        mainTextbox.value = '';
        errorText.innerHTML = 'Za duży wynik!';
        primeSumTextbox.innerHTML = '';
        primeTextbox.innerHTML = '';
    }

    stackView.innerHTML = '';
    stack.forEach(element => {
        if(stackView.innerHTML === '') stackView.innerHTML += `Stos: ${element}`;
        else stackView.innerHTML += `, ${element}`;
    });

    if(operator !== "SWAP" && inputValue <= maxNumber){
        primeDecomposition(Math.round(inputValue));
        primeEvenSumDecomposition(Math.round(inputValue));
    }
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

            if (numberOfOccurance > 1) result += `${uniqueDecompNumbers[i]} ^{${numberOfOccurance}} \\cdot `;
            else result += `${uniqueDecompNumbers[i]} \\cdot `;
        }
        result = result.slice(0, -6);
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
    primeSumTextbox.innerHTML = '';

    if (!isNaN(number) && number >= 4 && number % 2 === 0 && number <= maxNumberForDecomp){
        let result = ``;
        
        for(let i=2; i < number; i++){
            if(isPrime(i) && isPrime(number - i)) {
                result = `Rozkład parzystej liczby na sumę liczb pierwszych: \\( ${number} = ${i} + ${number - i} \\)`;
                break;
            }
        }
        primeSumTextbox.innerHTML = result;
        MathJax.typeset();
    }
}