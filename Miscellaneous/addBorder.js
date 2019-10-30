function addBorder(picture) {
    const newMatrix = [];
    const newWidth = picture[0].length + 2;
    const newHeigth = picture.length + 2;
    // initialice newMatrix
    for (var i = 0; i < newHeigth; i++) {
        newMatrix[i] = new Array(newWidth);
    }
    // process matrix
    for (let i = 0; i < newHeigth; i++) {
        for (let j = 0; j < newWidth; j++) {
            if (i == 0 || i == newHeigth - 1) {
                newMatrix[i][j] = '*';
            } else if (j == 0 || j == newWidth - 1) {
                newMatrix[i][j] = '*';
            } else {
                newMatrix[i][j] = picture[i - 1][j - 1];
            }
        }
    }
    // join string for out.
    for (var i = 0; i < newHeigth; i++) {
        newMatrix[i] = newMatrix[i].join('');
    }
    return newMatrix;
}

const picture = ["abc", "ded"];

console.log(addBorder(picture));
