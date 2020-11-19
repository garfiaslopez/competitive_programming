function allLongestStrings(inputArray) {
    let toReturn = [];
    let maxCurrent = inputArray[0].length;
    for (let i = 0; i < inputArray.length; i++) {
        if (inputArray[i].length > maxCurrent) {
            maxCurrent = inputArray[i].length;
        }
    }
    for (let i = 0; i < inputArray.length; i++) {
        if (inputArray[i].length === maxCurrent) {
            toReturn.push(inputArray[i]);
        }
    }
    return toReturn;
}

const inputArray = ["aba", "aa", "ad", "vcd", "aba"];

console.log(allLongestStrings(inputArray));
