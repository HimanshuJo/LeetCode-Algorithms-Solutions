/*
https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/?envType=daily-question&envId=2024-06-29
*/

/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[][]}
 */

var isCurrentNodeAlreadySeen=function(allParentsForNode, parentToBeChecked){
    for(let node=0; node<allParentsForNode.length; ++node){
        if(allParentsForNode[node]==parentToBeChecked) return true;
    }
    return false;
}

var depthFirstSearch_forGraphs=function(childToParentsMapping, currentNode, allParentsForNode){
    if(!childToParentsMapping.has(currentNode)){
        return;
    }
    let currentAllParentsForCurrentNode=childToParentsMapping.get(currentNode);
    for(let node=0; node<currentAllParentsForCurrentNode.length; ++node){
        let parentToBeChecked=currentAllParentsForCurrentNode[node];
        if(!isCurrentNodeAlreadySeen(allParentsForNode, parentToBeChecked)){
            allParentsForNode.push(parentToBeChecked);
            depthFirstSearch_forGraphs(childToParentsMapping, parentToBeChecked, allParentsForNode);
        }
    }
    return;
}

var getAncestors = function(n, edges) {
    let childToParentsMapping=new Map();
    for(let i=0; i<edges.length; ++i){
        let currentEdge=edges[i], currentChild=currentEdge[1], currentParent=currentEdge[0];
        if(childToParentsMapping.has(currentChild)){
            let currentAllParentsForCurrentChild=childToParentsMapping.get(currentChild);
            currentAllParentsForCurrentChild.push(currentParent);
            childToParentsMapping.set(currentChild, currentAllParentsForCurrentChild);
        } else{
            let currentAllParentsForCurrentChild=[];
            currentAllParentsForCurrentChild.push(currentParent);
            childToParentsMapping.set(currentChild, currentAllParentsForCurrentChild);
        }
    }
    let resultantListOfAncestorsForAllNodes=[];
    for(let node=0; node<n; ++node){
        let allParentsForNode=[];
        depthFirstSearch_forGraphs(childToParentsMapping, node, allParentsForNode);
        allParentsForNode.sort((A, B)=>(A-B));
        resultantListOfAncestorsForAllNodes.push(allParentsForNode);
    }
    return resultantListOfAncestorsForAllNodes;
};