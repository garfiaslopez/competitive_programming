function isCryptSolution(crypt, solution) {
    const mapping = {};
    solution.forEach((s) => {
        mapping[s[0]] = s[1];
    });

    let decodeA = '';
    crypt[0].split('').forEach((letter) => {
        decodeA += mapping[letter];
    });

    let decodeB = '';
    crypt[1].split('').forEach((letter) => {
        decodeB += mapping[letter];
    });

    let decodeC = '';
    crypt[2].split('').forEach((letter) => {
        decodeC += mapping[letter];
    });

    if (decodeA.charAt(0) === '0' && decodeA.length > 1 ||
        decodeB.charAt(0) === '0' && decodeB.length > 1 ||
        decodeC.charAt(0) === '0' && decodeC.length > 1
    ){
        return false;
    } else {
        if (Number(decodeA) + Number(decodeB) === Number(decodeC)) {
            return true;
        } else {
            return false;
        }
    }
}

const crypt = ["SEND", "MORE", "MONEY"];

const solution =
            [['O', '0'],
            ['M', '1'],
            ['Y', '2'],
            ['E', '5'],
            ['N', '6'],
            ['D', '7'],
            ['R', '8'],
            ['S', '9']];


const crypt2 = ["TEN", "TWO", "ONE"];

const solution2 = [['O', '1'],
                ['T', '0'],
                ['W', '9'],
                ['E', '5'],
                ['N', '4']];


const crypt3 = ["A",
 "A",
 "A"];

 const solution3 = [["A","0"]];

console.log(isCryptSolution(crypt3, solution3));
