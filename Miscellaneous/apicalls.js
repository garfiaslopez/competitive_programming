class Node {
    constructor() {
        this.times = 0;
        this.order = 0;
        this.child = null;
    }
    add(call, index) {
        this.times += 1;
        if (!this.order) {
            this.order = index;
        }

    }
}

function countAPI(calls) {
    let projects = {};

    calls.forEach((c, i) => {
        const elements = c.substring(1,c.length).split('/');
        console.log(elements);
        elements.forEach((el, pos) => {
            console.log(el,pos);
        });
    });
    return {};
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
];

console.log(countAPI(calls));


//
//
// projects[elements[0]] = {
//     times: projects[elements[0]].times ? projects[elements[0]].times += 1 : 1,
//     index: projects[elements[0]].index ? projects[elements[0]].index : i,
//     sub_projects: {
//         times: projects[elements[0]].sub_projects[elements[1]].times ? projects[elements[0]].sub_projects[elements[1]].times += 1 : 1,
//         index: projects[elements[0]].sub_projects[elements[1]].index ? projects[elements[0]].sub_projects[elements[1]].index : i,
//         methods: {
//             times: projects[elements[0]].sub_projects[elements[1]].methods[elements[2]].times ? projects[elements[0]].sub_projects[elements[1]].methods[elements[2]].times += 1 : 1,
//             index: projects[elements[0]].sub_projects[elements[1]].methods[elements[2]].index ? projects[elements[0]].sub_projects[elements[1]].methods[elements[2]].index : i,
//         }
//     }
// }
