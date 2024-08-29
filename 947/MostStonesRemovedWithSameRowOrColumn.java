/*
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/?envType=daily-question&envId=2024-08-29
*/

class Solution {

    public static void depthFirstSearch_forGraphs(ArrayList<ArrayList<Integer>>graph, HashSet<Integer>seenNodes, int currentNode){
        seenNodes.add(currentNode);
        ArrayList<Integer>currentListOfNodes=graph.get(currentNode);
        for(int i=0; i<currentListOfNodes.size(); ++i){
            int currentNeighbor=currentListOfNodes.get(i);
            if(!seenNodes.contains(currentNeighbor)){
                depthFirstSearch_forGraphs(graph, seenNodes, currentNeighbor);
            }
        }
        return;
    }

    public int removeStones(int[][] stones) {
        int lengthOfStones=stones.length;
        ArrayList<ArrayList<Integer>>graph=new ArrayList<>();
        for(int i=0; i<=lengthOfStones; ++i){
            graph.add(new ArrayList<>());
        }
        for(int i=0; i<lengthOfStones-1; ++i){
            for(int j=i+1; j<lengthOfStones; ++j){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]){
                    graph.get(i).add(j);
                    graph.get(j).add(i);
                }
            }
        }
        HashSet<Integer>seenNodes=new HashSet<>();
        int numberOfConnectedComponents=0;
        for(int i=0; i<lengthOfStones; ++i){
            if(!seenNodes.contains(i)){
                depthFirstSearch_forGraphs(graph, seenNodes, i);
                numberOfConnectedComponents++;
            }
        }
        return lengthOfStones-numberOfConnectedComponents;
    }
}