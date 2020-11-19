function commonCharacterCount(s1, s2) {
    const mapS2 = {};
    for(let i=0; i<s2.length;i++) {
        if (mapS2[s2[i]]){
            mapS2[s2[i]] += 1;
        } else {
            mapS2[s2[i]] = 1;
        }
    }
    let common = 0;
    for(let i=0; i<s1.length;i++) {
        if (mapS2[s1[i]] > 0) {
            common += 1;
            mapS2[s1[i]] -= 1;
        }
    }
    return common;
}

const s1 = "aabcc";
const s2 = "adcaa";
console.log(commonCharacterCount(s1,s2));
