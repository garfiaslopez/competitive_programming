var groupAnagrams = function(strs) {
    const mapping = {};
    strs.forEach((e) => {
        const key = e.split("").sort().join("");
        if (mapping[key]) {
            mapping[key].push(e)
        } else {
            mapping[key] = [e];
        }
    });
    console.log(mapping);
    return Object.keys(mapping).map((k) => (mapping[k]));
};

console.log(groupAnagrams(["cab","tin","pew","duh","may","ill","buy","bar","max","doc"]));
