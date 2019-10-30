function makeArrayConsecutive2(statues) {
    var min = statues[0];
    var max = 0;
    var mapping = {};
    var reminds = 0;
    statues.forEach((el) => {
        if (el < min) {
            min = el;
        }
        if (el > max) {
            max = el;
        }
        mapping[el] = true;
    });
    for (var i=min;i<=max;i++) {
        if (mapping[i] !== true) {
            reminds += 1;
        }
    }
    return reminds;
}

console.log(makeArrayConsecutive2([4, 7, 2, 2,3,1]));
