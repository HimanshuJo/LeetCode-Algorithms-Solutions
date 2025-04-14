/*
https://leetcode.com/problems/largest-divisible-subset/?envType=daily-question&envId=2025-04-06
*/

class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int lengthOfNums=nums.length;
        int[] dynamicProgrammingTable=new int[lengthOfNums];
        int[] prevIndex=new int[lengthOfNums];
        for(int i=0; i<lengthOfNums; ++i){
            dynamicProgrammingTable[i]=1;
            prevIndex[i]=-1;
        }
        int maxIndex=0;
        for(int i=1; i<lengthOfNums; ++i){
            for(int j=0; j<i; ++j){
                if(nums[i]%nums[j]==0){
                    if(dynamicProgrammingTable[j]+1>dynamicProgrammingTable[i]){
                        dynamicProgrammingTable[i]=dynamicProgrammingTable[j]+1;
                        prevIndex[i]=j;
                    }
                }
            }
            if(dynamicProgrammingTable[i]>dynamicProgrammingTable[maxIndex]){
                maxIndex=i;
            }
        }
        List<Integer>resultantSubsetList=new ArrayList<>();
        while(maxIndex!=-1){
            resultantSubsetList.add(nums[maxIndex]);
            maxIndex=prevIndex[maxIndex];
        }
        return resultantSubsetList;
    }
}