/*
https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/?envType=daily-question&envId=2025-11-17
*/

class Solution {
    
    boolean isValid(int firstIndex, int secondIndex, int k){
        return ((Math.abs(firstIndex-secondIndex))-1>=k);
    }
    
    public boolean kLengthApart(int[] nums, int k) {
        if(k==0) return true;
        int lengthOfNums=nums.length;
        ArrayList<Integer>allIndicesWith1s=new ArrayList<>();
        for(int i=0; i<lengthOfNums; ++i){
            if(nums[i]==1) allIndicesWith1s.add(i);
        }
        int finalLength=allIndicesWith1s.size();
        for(int i=0; i<finalLength; ++i){
            int firstIndex=allIndicesWith1s.get(i);
            for(int j=0; j<finalLength; ++j){
                int secondIndex=allIndicesWith1s.get(j);
                if(firstIndex!=secondIndex){
                    if(!isValid(firstIndex, secondIndex, k)) return false;
                }
            }
        }
        return true;
    }
}