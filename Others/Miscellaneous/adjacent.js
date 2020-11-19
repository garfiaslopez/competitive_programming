function adjacentElementsProduct(inputArray) {
    let max = undefined;
    inputArray.forEach((number, index) => {
        if (index < inputArray.length - 1) {
            const m = number * inputArray[index + 1];
            if (m > max || max === undefined) {
                max = m;
            }
        }
    });
    return max;
}

const inputArray = [
    3,
    6,
    -2,
    -5,
    7,
    3
];
console.log(adjacentElementsProduct(inputArray));
