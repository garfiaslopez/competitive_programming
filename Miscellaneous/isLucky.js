function isLucky(n) {
    const numbers = String(n).split('');
    let first = 0;
    let second = 0;
    for (let i=0; i<numbers.length; i++) {
        if (i<(numbers.length/2)) {
            first += Number(numbers[i]);
        } else {
            second += Number(numbers[i]);
        }
    }
    return first == second;
}

const n = 111111;

console.log(isLucky(n));
