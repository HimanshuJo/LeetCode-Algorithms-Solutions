/*
https://leetcode.com/problems/path-with-maximum-probability/description/?envType=daily-question&envId=2024-08-31
*/

class Pair{

    public double first;
    public int second;

    Pair(double first, int second){
        this.first=first;
        this.second=second;
    }
}

class Solution {

    public static double djikstra(int n, int[][] edges, double[] succProb, int start_node, int end_node, ArrayList<ArrayList<Integer>>graph, TreeMap<String, Double>edgesToProbabilitiesMap){
        PriorityQueue<Pair>priorityQueue=new PriorityQueue<>(new Comparator<Pair>(){
            @Override
            public int compare(Pair A, Pair B){
                return Double.compare(B.first, A.first);
            }
        });
        priorityQueue.add(new Pair(1.0, start_node));
        double[] currentMaximumProbabilites=new double[n+1];
        for(int i=0; i<=n; ++i){
            currentMaximumProbabilites[i]=0.0;
        }
        while(!priorityQueue.isEmpty()){
            int currentSize=priorityQueue.size();
            while(currentSize-- >0){
                Pair currentPair=priorityQueue.remove();
                if(currentPair.second==end_node) return currentPair.first;
                ArrayList<Integer>currentNeighborList=graph.get(currentPair.second);
                for(int i=0; i<currentNeighborList.size(); ++i){
                    int currentNeighbor=currentNeighborList.get(i);
                    double newProbability=currentPair.first*edgesToProbabilitiesMap.get(String.valueOf(currentPair.second)+" "+currentNeighbor);
                    if(newProbability>currentMaximumProbabilites[currentNeighbor]){
                        currentMaximumProbabilites[currentNeighbor]=newProbability;
                        priorityQueue.add(new Pair(newProbability, currentNeighbor));
                    }
                }
            }
        }
        return 0.0;
    }

    public double maxProbability(int n, int[][] edges, double[] succProb, int start_node, int end_node) {
        ArrayList<ArrayList<Integer>>graph=new ArrayList<>();
        for(int i=0; i<=n; ++i){
            graph.add(new ArrayList<>());
        }
        TreeMap<String, Double>edgesToProbabilitiesMap=new TreeMap<>();
        int beginIndex=0, lengthOfEdges=edges.length;
        for(int i=0; i<lengthOfEdges; ++i){
            graph.get(edges[i][0]).add(edges[i][1]);
            graph.get(edges[i][1]).add(edges[i][0]);
            edgesToProbabilitiesMap.put(String.valueOf(edges[i][0])+" "+String.valueOf(edges[i][1]), succProb[beginIndex]);
            edgesToProbabilitiesMap.put(String.valueOf(edges[i][1])+" "+String.valueOf(edges[i][0]), succProb[beginIndex++]);
        }
        return djikstra(n, edges, succProb, start_node, end_node, graph, edgesToProbabilitiesMap);
    }
}