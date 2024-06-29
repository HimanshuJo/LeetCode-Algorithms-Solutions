/*
https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/?envType=daily-question&envId=2024-06-29
*/

class Solution {

    public static boolean isCurrentNodeAlreadySeen(int parentToBeChecked, ArrayList<Integer>allParentsForNode){
        for(int node=0; node<allParentsForNode.size(); ++node){
            if(allParentsForNode.get(node)==parentToBeChecked) return true;
        }
        return false;
    }

    public static void depthFirstSearch_forGraphs(TreeMap<Integer, ArrayList<Integer>>childToParentsMapping, int currentNode, ArrayList<Integer>allParentsForNode){
        if(!childToParentsMapping.containsKey(currentNode)) return;
        ArrayList<Integer>currentAllParentsForCurrentNode=childToParentsMapping.get(currentNode);
        for(int node=0; node<currentAllParentsForCurrentNode.size(); ++node){
            int parentToBeChecked=currentAllParentsForCurrentNode.get(node);
            if(!isCurrentNodeAlreadySeen(parentToBeChecked, allParentsForNode)){
                allParentsForNode.add(parentToBeChecked);
                depthFirstSearch_forGraphs(childToParentsMapping, parentToBeChecked, allParentsForNode);
            }
        }
        return;
    }

    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        TreeMap<Integer, ArrayList<Integer>>childToParentsMapping=new TreeMap<>();
        for(int[] currentEdge: edges){
            int currentChild=currentEdge[1], currentParent=currentEdge[0];
            if(childToParentsMapping.containsKey(currentChild)){
                ArrayList<Integer>currentAllParentsForCurrentChild=childToParentsMapping.get(currentChild);
                currentAllParentsForCurrentChild.add(currentParent);
                childToParentsMapping.put(currentChild, currentAllParentsForCurrentChild);
            } else{
                ArrayList<Integer>currentAllParentsForCurrentChild=new ArrayList<>();
                currentAllParentsForCurrentChild.add(currentParent);
                childToParentsMapping.put(currentChild, currentAllParentsForCurrentChild);
            }
        }
        List<List<Integer>>resultantListOfAncestorsForAllNodes=new ArrayList<>();
        for(int node=0; node<n; ++node){
            ArrayList<Integer>allParentsForNode=new ArrayList<>();
            depthFirstSearch_forGraphs(childToParentsMapping, node, allParentsForNode);
            Collections.sort(allParentsForNode);
            resultantListOfAncestorsForAllNodes.add(allParentsForNode);
        }
        return resultantListOfAncestorsForAllNodes;
    }
}