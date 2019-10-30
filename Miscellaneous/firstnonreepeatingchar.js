function firstNotRepeatingCharacter(str) {
    let map = {};
    // count the times the char is on the array.
    str.split("").forEach((s,i) => {
        if (map[s]) {
            map[s] = { count: map[s].count + 1, index: i};
        } else {
            map[s] = { count: 1, index: i};
        }
    });

    var result = '_';
    var lower = str.length;
    Object.keys(map).forEach((key) => {
        if (map[key].count === 1) {
            if (map[key].index < lower) {
                lower = map[key].index;
                result = key;
            }
        }
    });
    return result;
}

var stringToTest = "abacabad";

firstNotRepeatingCharacter(stringToTest);
