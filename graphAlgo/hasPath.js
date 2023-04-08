// const hasPath = (graph,src, dst) =>{
//     if(src==dst)    return true;

//     for(let neighbor of graph[src]){
//         if(hasPath(graph,neighbor,dst)) return true;
//     }
//     return false;
// };

// breadthfast solution . 

const hasPath = (graph,src,dst) => {
    const queue = [src];
    while(queue.length>0){
        const current = queue.shift(); 
        if(current==dst)    return true; 
        for(let neighbor of graph[current]){
            queue.push(neighbor); 
        }
    }
    return false; 
}