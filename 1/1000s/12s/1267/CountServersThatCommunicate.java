/*
https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23
*/

class Solution {

    public static void depthFirstSearch_forMatrices(int[][] grid, int rows, int columns, HashSet<String>seenCoordinates, int currentRow, int currentColumn, ArrayList<Integer>currentServersCount){
        for(int j=0; j<columns; ++j){
            if(grid[currentRow][j]==1){
                String tocheck=String.valueOf(currentRow)+"#"+String.valueOf(j);
                if(!seenCoordinates.contains(tocheck)){
                    currentServersCount.set(0, currentServersCount.get(0)+1);
                    seenCoordinates.add(tocheck);
                    depthFirstSearch_forMatrices(grid, rows, columns, seenCoordinates, currentRow, j, currentServersCount);
                }
            }
        }
        for(int i=0; i<rows; ++i){
            if(grid[i][currentColumn]==1){
                String tocheck=String.valueOf(i)+"#"+String.valueOf(currentColumn);
                if(!seenCoordinates.contains(tocheck)){
                    currentServersCount.set(0, currentServersCount.get(0)+1);
                    seenCoordinates.add(tocheck);
                    depthFirstSearch_forMatrices(grid, rows, columns, seenCoordinates, i, currentColumn, currentServersCount);
                }
            }
        }
    }

    public int countServers(int[][] grid) {
        int rows=grid.length, columns=grid[0].length, resultantServersCount=0;
        HashSet<String>seenCoordinates=new HashSet<>();
        for(int i=0; i<rows; ++i){
            for(int j=0; j<columns; ++j){
                if(grid[i][j]==1){
                    ArrayList<Integer>currentServersCount=new ArrayList<>();
                    currentServersCount.add(1);
                    seenCoordinates.add(String.valueOf(i)+"#"+String.valueOf(j));
                    depthFirstSearch_forMatrices(grid, rows, columns, seenCoordinates, i, j, currentServersCount);
                    if(currentServersCount.get(0)>1) resultantServersCount+=currentServersCount.get(0);
                }
            }
        }
        return resultantServersCount;
    }
}