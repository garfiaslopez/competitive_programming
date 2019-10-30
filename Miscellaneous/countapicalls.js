class Node {
    constructor(index) {
        this.times = 1;
        this.order = index;
        this.child = {};
    }
    add() {
        this.times += 1;
    }
    addChild(key, node) {
        this.child[key] = node;
    }
}

function countAPI(calls) {
    let MapCalls = {};
    calls.forEach((call, index) => {
        const keys = call.substring(1,call.length).split('/');
        const p = keys[0];
        const s = keys[1];
        const m = keys[2];

        if (!MapCalls[p]) {
            MapCalls[p] = new Node(index);
        } else {
            MapCalls[p].add();
        }

        if (!MapCalls[p].child[s]) {
            MapCalls[p].addChild(s, new Node(index));
        } else {
            MapCalls[p].child[s].add();
        }

        if (!MapCalls[p].child[s].child[m]) {
            MapCalls[p].child[s].addChild(m, new Node(index));
        } else {
            MapCalls[p].child[s].child[m].add();
        }
    });
    const callsToReturn = [];

    Object.keys(MapCalls).forEach((p) => {
        console.log(p);
        Object.keys(MapCalls[p].child).forEach((s) => {
            console.log(s);
            Object.keys(MapCalls[p].child[s].child).forEach((m) => {
                console.log(m);
            });
        });
    });


    return callsToReturn;
}

const calls = [
        "/project1/subproject1/method1",
        "/project2/subproject1/method1",
        "/project1/subproject1/method1",
        "/project1/subproject2/method1",
        "/project1/subproject1/method2",
        "/project1/subproject2/method1",
        "/project2/subproject1/method1",
        "/project1/subproject2/method1"
]

console.log(countAPI(calls));
