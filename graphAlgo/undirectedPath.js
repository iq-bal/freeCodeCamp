// problem link
// https://structy.net/problems/undirected-path

const undirectedPath = (edges,nodeA,nodeB) =>{
    const graph = graphBuilder(edges);
    return hasPath(graph,nodeA,nodeB, new Set());
};

const hasPath = (graph,src,dst,visited)=>{
    if(src==dst)    return true;
    if(visited.has(src))    return false; 

    visited.add(src);

    for(let neighbor of graph[src]){
        if(hasPath(graph,neighbor,dst,visited)) return true;
    }
    return false; 
};


const graphBuilder = (edges) =>{
    const graph = {};

    for(let edge of edges){
        const [a,b] = edge;
        if(!(a in graph))   graph[a]=[];
        if(!(b in graph))   graph[b]=[];
        graph[a].push(b);
        graph[b].push(a); 
    }
}


const edges = [
    ['i', 'j'],
    ['k', 'i'],
    ['m', 'k'],
    ['k', 'l'],
    ['o', 'n']
];

