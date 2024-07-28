/*
https://leetcode.com/problems/second-minimum-time-to-reach-destination/?envType=daily-question&envId=2024-07-28
*/

class CustomComparator implements Comparator<Pair>{
    @Override
    public int compare(Pair A, Pair B){
        return Integer.compare(A.first, B.first);
    }
}

class Pair{
    public int first;
    public int second;

    Pair(int first, int second){
        this.first=first;
        this.second=second;
    }
}

class Solution {
    public int secondMinimum(int n, int[][] edges, int time, int change) {
        ArrayList<ArrayList<Integer>>graph=new ArrayList<>();
        for(int i=0; i<=n; ++i){
            graph.add(new ArrayList<>());
        }
        for(int[] edge: edges){
            int currentSource=edge[0], currentDestination=edge[1];
            graph.get(currentSource).add(currentDestination);
            graph.get(currentDestination).add(currentSource);
        }
        int[] distance1=new int[n+1];
        int[] distance2=new int[n+1];
        int[] frequenceOfEachNode=new int[n+1];
        for(int i=0; i<=n; ++i){
            distance1[i]=Integer.MAX_VALUE;
            distance2[i]=Integer.MAX_VALUE;
            frequenceOfEachNode[i]=0;
        }
        distance1[1]=0;
        PriorityQueue<Pair>priorityQueue=new PriorityQueue<>(new CustomComparator());
        priorityQueue.add(new Pair(0, 1));
        while(!priorityQueue.isEmpty()){
            int sizeOfPriorityQueue=priorityQueue.size();
            while(sizeOfPriorityQueue-- >0){
                Pair currentDistanceNodePair=priorityQueue.poll();
                int timetaken=currentDistanceNodePair.first, node=currentDistanceNodePair.second;
                frequenceOfEachNode[node]++;
                if(node==n&&frequenceOfEachNode[node]==2){
                    return timetaken;
                }
                if((timetaken/change)%2!=0){
                    timetaken=change*(timetaken/change+1)+time;
                } else{
                    timetaken+=time;
                }
                int sizeOfNeighbors=graph.get(node).size();
                for(int i=0; i<sizeOfNeighbors; ++i){
                    int currentNeighbor=graph.get(node).get(i);
                    if(frequenceOfEachNode[currentNeighbor]==2) continue;
                    if(distance1[currentNeighbor]>timetaken){
                        distance2[currentNeighbor]=distance1[currentNeighbor];
                        distance1[currentNeighbor]=timetaken;
                        priorityQueue.add(new Pair(timetaken, currentNeighbor));
                    } else if(distance2[currentNeighbor]>timetaken&&distance1[currentNeighbor]!=timetaken){
                        distance2[currentNeighbor]=timetaken;
                        priorityQueue.add(new Pair(timetaken, currentNeighbor));
                    }
                }
            }
        }
        return 0;
    }
}