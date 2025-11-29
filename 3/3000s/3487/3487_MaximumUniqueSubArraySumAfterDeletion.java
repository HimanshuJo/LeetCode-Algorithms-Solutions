/*
https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/?envType=daily-question&envId=2025-07-25
*/

class Solution {
    public int maxSum(int[] nums) {
        int resultantMaxSum=0, maxNumber=Integer.MIN_VALUE;
        HashSet<Integer>uniqueNumbers=new HashSet<>();
        for(int num: nums){
            uniqueNumbers.add(num);
            maxNumber=Math.max(maxNumber, num);
        }
        boolean isAnyPositive=false;
        Iterator itr=uniqueNumbers.iterator();
        while(itr.hasNext()){
            int curNumber=(int)itr.next();
            if(curNumber>=0){
                isAnyPositive=true;
                resultantMaxSum+=curNumber;
            }
        }
        if(!isAnyPositive) return maxNumber;
        return resultantMaxSum;
    }
}
