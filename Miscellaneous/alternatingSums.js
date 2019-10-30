function alternatingSums(a) {
    let sums = [0,0];
    for (let i=0;i<a.length;i++) {
        if (i%2) {
            sums[1] += a[i];
        } else {
            sums[0] += a[i];
        }
    }
    return sums;
}

const a = [50, 60, 60, 45, 70];

console.log(alternatingSums(a));
