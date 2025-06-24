/*
https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/description/?envType=daily-question&envId=2025-06-24
*/

class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        ArrayList<Integer>resultantKDistantIndices=new ArrayList<>();
        ArrayList<Integer>indicesWithKey=new ArrayList<>();
        int lengthOfNums=nums.length;
        for(int i=0; i<lengthOfNums; ++i){
            if(nums[i]==key){
                indicesWithKey.add(i);
            }
        }
        for(int i=0; i<lengthOfNums; ++i){
            int currentIndex=i;
            int sizeOfIndicesLst=indicesWithKey.size();
            for(int j=0; j<sizeOfIndicesLst; ++j){
                int nxtIndex=indicesWithKey.get(j);
                if(Math.abs(currentIndex-nxtIndex)<=k){
                    resultantKDistantIndices.add(i);
                    break;
                }
            }
        }
        return resultantKDistantIndices;
    }
}