function testsub(subgrid) {
    let flag = true;
    const mapping = {};
    subgrid.forEach((el) => {
        if (el !== '.') {
            if (!mapping[el]) {
                mapping[el] = 1;
            } else {
                flag = false;
            }
        }
    });
    return flag;
}


function sudoku2(grid) {
    let solvable = true;

    // test fils:
    grid.forEach((fil) => {
        const res = testsub(fil);
        if (!res) {
            solvable = false
        }
    });

    // test cols:
    for (let i=0; i<grid.length; i++) {
        let testCols = [];
        for (let j=0; j<grid[i].length; j++) {
            testCols.push(grid[j][i]);
        }
        const res = testsub(testCols);
        if (!res) {
            solvable = false
        }
    }

    // test 3x3 grids:
    for (let a=0; a<grid.length; a+=3) {
        for (let b=0; b<grid.length; b+=3) {
            console.log(a,b);
            let testGrid = [];
            for (var i=a; i<a+3; i++) {
                for (var j=b; j<b+3; j++) {
                    testGrid.push(grid[i][j]);
                }
            }
            const res = testsub(testGrid);
            if (!res) {
                solvable = false
            }
        }
    }
    return solvable;
}

const grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
            ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
            ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
            ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
            ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
            ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
            ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
            ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
            ['.', '.', '.', '5', '.', '.', '.', '7', '.']];


const grid2 = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
            ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
            ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
            ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
            ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
            ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
            ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
            ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
            ['.', '2', '.', '.', '3', '.', '.', '.', '.']]

console.log(sudoku2(grid));
