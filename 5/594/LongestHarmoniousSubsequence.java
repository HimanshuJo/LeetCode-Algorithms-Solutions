/*
https://leetcode.com/problems/longest-harmonious-subsequence/description/?envType=daily-question&envId=2025-06-30
*/

class Solution {
    public int findLHS(int[] nums) {
        Arrays.sort(nums);
        int lengthOfNums=nums.length, resultantSubseqLength=0;
        for(int i=0; i<lengthOfNums; ++i){
            ArrayList<Integer>currentHarmonList=new ArrayList<>();
            for(int j=i; j<lengthOfNums; ++j){
                if(currentHarmonList.isEmpty()){
                    currentHarmonList.add(nums[j]);
                } else{
                    int numberToCheck=nums[j], currentMaxNumber=currentHarmonList.get(currentHarmonList.size()-1);
                    if(numberToCheck<nums[0]){
                        if(currentMaxNumber-numberToCheck==1){
                            currentHarmonList.add(numberToCheck);
                        }
                    } else if(numberToCheck>currentMaxNumber){
                        if(numberToCheck-currentHarmonList.get(0)==1){
                            currentHarmonList.add(numberToCheck);
                        } else break;
                    } else currentHarmonList.add(numberToCheck);
                }
            }
            int harmonListSize=currentHarmonList.size();
            int currentMaxNumber=currentHarmonList.get(currentHarmonList.size()-1);
            if(currentMaxNumber-currentHarmonList.get(0)==1){
                resultantSubseqLength=Math.max(resultantSubseqLength, harmonListSize);
            }
        }
        return resultantSubseqLength;
    }
}