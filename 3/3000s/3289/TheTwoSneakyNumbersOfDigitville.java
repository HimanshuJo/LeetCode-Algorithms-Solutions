/*
https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/?envType=daily-question&envId=2025-10-31
*/

import java.util.Map;

class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        ArrayList<Integer>resultantList=new ArrayList<>();
        HashMap<Integer, Integer>numbersCountMap=new HashMap<>();
        int lengthOfNums=nums.length;
        for(int i=0; i<lengthOfNums; ++i){
            if(numbersCountMap.containsKey(nums[i])){
                int currentCount=numbersCountMap.get(nums[i]);
                numbersCountMap.put(nums[i], currentCount+1);
            } else numbersCountMap.put(nums[i], 1);
        }
        for(Map.Entry<Integer, Integer>numbersCountMapEntries: numbersCountMap.entrySet()){
            if(numbersCountMapEntries.getValue()>=2){
                resultantList.add(numbersCountMapEntries.getKey());
            }
        }
        int finalSize=resultantList.size();
        int[] resultantArray=new int[finalSize];
        for(int i=0; i<finalSize; ++i){
            resultantArray[i]=resultantList.get(i);
        }
        return resultantArray;
    }
}