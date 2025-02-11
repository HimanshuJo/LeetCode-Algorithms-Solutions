/*
https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=daily-question&envId=2024-07-19
*/

class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        int rows=matrix.length, columns=matrix[0].length;
        List<Integer>resultantListOfLuckyNumbers=new ArrayList<>();
        for(int column=0; column<columns; ++column){
            ArrayList<Integer>currentColumn=new ArrayList<>();
            HashMap<Integer, Integer>numberToRowMapping=new HashMap<>();
            for(int row=0; row<rows; ++row){
                currentColumn.add(matrix[row][column]);
                numberToRowMapping.put(matrix[row][column], row);
            }
            Collections.sort(currentColumn);
            int currentMaxElementInCurrentColumn=currentColumn.get(rows-1);
            int rowToCheck=numberToRowMapping.get(currentMaxElementInCurrentColumn);
            int minElementInRowToCheck=Integer.MAX_VALUE;
            for(int column_=0; column_<columns; ++column_){
                minElementInRowToCheck=Math.min(minElementInRowToCheck, matrix[rowToCheck][column_]);
            }
            if(currentMaxElementInCurrentColumn==minElementInRowToCheck){
                resultantListOfLuckyNumbers.add(minElementInRowToCheck);
            }
        }
        return resultantListOfLuckyNumbers;
    }
}