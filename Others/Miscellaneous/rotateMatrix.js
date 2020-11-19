function rotateImage(a) {
    var b = [];
    // initialize b:
    for (var i=0; i<a.length; i++) {
        b[i] = [];
    }
    const max = a.length-1;
    for (var j=max; j>=0; j--) {
        for (var i=0; i<=max; i++) {
            b[j][max - i] = a[i][j];
        }
    }
    return b;
}

const a1 = [
    [1, 2],
    [3, 4],
];

const a = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];

const ab = [
    [1,   2,  3,  4],
    [5,   6,  7,  8],
    [9,  10, 11, 12],
    [13, 14, 15, 16]
];


rotateImage(ab);
