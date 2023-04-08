// const deppthFirstPrint=(graph,source)=>{
//     const stack = [source];
//     while(stack.length>0){
//         const current = stack.pop();
//         console.log(current); 
//         for(let neighbor of graph[current]){
//             stack.push(neighbor); 
//         }
//     }
// };


const deppthFirstPrint = (graph,source) => {
    console.log(source); 
    for(let neighbor of graph[source]){
        deppthFirstPrint(graph,neighbor); 
    }  
}
// [] works as an implicit base case. it never iterates through it . so no recursion 

const breadthFirstPrint = (graph,source) => {
    const queue = [ source ];

    while(queue.length>0){
        const current = queue.shift(); //removes from first of an array in js
        console.log(current);
        for(let neighbor of graph[current]){
            queue.push(neighbor);
        }
    }

};

const graph ={
    a: ['b','c'],
    b: ['d'],
    c: ['e'],
    d: ['f'],
    e: [],
    f: []
};

deppthFirstPrint(graph,'a');
console.log('\n'); 
breadthFirstPrint(graph,'a'); 