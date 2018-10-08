
function bubbleSort(values) {
    for (let i = values.length - 1; i >= 0; i--) {
        for(let j = 1; j <= i; j++) {
            if(values[j - 1] > values[j]) {
                let temp = values[j - 1];
                values[j - 1] = values[j];
                values[j] = temp;
            }
        }
    }
    return values;
}

console.log(bubbleSort([94, 22, 12, 7, 390, 3, 78]));
