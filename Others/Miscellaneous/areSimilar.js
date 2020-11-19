function areSimilar(a, b) {
    let swaped = false;
    let firstNotEqual = false;
    let a_ = 0;
    let b_ = 0;
    for (let i = 0; i < a.length; i++) {
        if (a[i] !== b[i]) {
            if (swaped)
                return false;
            if (!firstNotEqual) {
                a_ = a[i];
                b_ = b[i];
                firstNotEqual = true;
            } else {
                if (a_ === b[i] && b_ === a[i]) {
                    swaped = true;
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}

const a = [1, 2, 2]
const b = [2, 1, 1]

console.log(areSimilar(a, b));
