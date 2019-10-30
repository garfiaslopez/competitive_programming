function testIncreasing(a){
    for (var i=0; i<a.length - 1; i++) {
        if (!(i < a.length-1 && a[i] < a[i+1])) {
            return false;
        }
    }
    return true;
}

function almostIncreasingSequence2(sequence) {
    for (var i=0; i< sequence.length; i++) {
        const copy = JSON.parse(JSON.stringify(sequence));
        copy.splice(i,1);
        if (testIncreasing(copy)) {
            return true;
        }
    }
    return false;
}

function almostIncreasingSequence(sequence) {
    var found = false;
    for (var i = 0; i < sequence.length; i++) {
        if (sequence[i] <= sequence[i - 1]) {
            if (found) {
                return false;
            }
            found = true;
            if (i === 1 || i + 1 === sequence.length) {
                continue;
            } else if (sequence[i] > sequence[i - 2]) {
                sequence[i - 1] = sequence[i - 2];
            } else if (sequence[i - 1] >= sequence[i + 1]) {
                return false;
            }
        }
    }
    return true;
}

const sequence = [1,2,3];

console.log(almostIncreasingSequence(sequence));
