/*
https://leetcode.com/problems/map-of-highest-peak/description/?envType=daily-question&envId=2025-01-22
*/

class Pair{
    public int first;
    public int second;

    public Pair(int first, int second){
        this.first=first;
        this.second=second;
    }
}

class Solution {

    public static boolean areValidCoordinates(int rows, int columns, int currentRow, int currentColumn){
        return currentRow>=0&&currentColumn>=0&&currentRow<=rows-1&&currentColumn<=columns-1;
    }

    public int[][] highestPeak(int[][] isWater) {
        int rows=isWater.length, columns=isWater[0].length;
        int[][] resultantHeightMat=new int[rows][columns];
        for(int i=0; i<rows; ++i){
            for(int j=0; j<columns; ++j){
                resultantHeightMat[i][j]=-1;
            }
        }
        int[][] directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        LinkedList<Pair>queue=new LinkedList<>();
        for(int i=0; i<rows; ++i){
            for(int j=0; j<columns; ++j){
                if(isWater[i][j]==1){
                    resultantHeightMat[i][j]=0;
                    queue.add(new Pair(i, j));
                }
            }
        }
        int beginHeight=1;
        while(!queue.isEmpty()){
            int currentQueueSize=queue.size();
            while(currentQueueSize-- >0){
                Pair currentPair=queue.pollFirst();
                int currentRow=currentPair.first, currentColumn=currentPair.second;
                for(int[] direction: directions){
                    int newRow=currentRow+direction[0], newColumn=currentColumn+direction[1];
                    if(areValidCoordinates(rows, columns, newRow, newColumn)){
                        if(resultantHeightMat[newRow][newColumn]==-1){
                            resultantHeightMat[newRow][newColumn]=beginHeight;
                            queue.add(new Pair(newRow, newColumn));
                        }
                    }
                }
            }
            beginHeight++;
        }
        return resultantHeightMat;
    }
}