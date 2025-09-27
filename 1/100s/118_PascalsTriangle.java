/*
https://leetcode.com/problems/pascals-triangle/description/?envType=daily-question&envId=2025-08-01
*/

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>>resultantTriangle=new ArrayList<>();
        List<Integer>firstTriangle=new ArrayList<>();
        firstTriangle.add(1);
        resultantTriangle.add(firstTriangle);
        if(numRows==1) return resultantTriangle;
        List<Integer>secondTriangle=new ArrayList<>();
        secondTriangle.add(1);
        secondTriangle.add(1);
        resultantTriangle.add(secondTriangle);
        if(numRows==2) return resultantTriangle;
        for(int i=2; i<numRows; ++i){
            List<Integer>currentTriangle=new ArrayList<>();
            currentTriangle.add(1);
            List<Integer>prevTriangle=resultantTriangle.get(i-1);
            int j=0;
            while(true){
                if(j+1>=prevTriangle.size()) break;
                int currentSum=prevTriangle.get(j)+prevTriangle.get(j+1);
                currentTriangle.add(currentSum);
                j++;
            }
            currentTriangle.add(1);
            resultantTriangle.add(currentTriangle);
        }
        return resultantTriangle;
    }
}
