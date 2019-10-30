function sortByHeight(a) {
    const sorted = [];
    for (let i=0;i<a.length;i++) {
        if (a[i] != -1) {
            sorted.push(a[i]);
        }
    }
    sorted.sort((a, b) => (a - b));
    const newArray = [];
    for (let i=0;i<a.length;i++) {
        if (a[i] == -1) {
            newArray.push(-1);
        } else{
            newArray.push(sorted.shift());
        }
    }
    return newArray;
}

const a = [-1, 150, 190, 170, -1, -1, 160, 180];

console.log(sortByHeight(a));
