/*
https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/?envType=daily-question&envId=2025-04-24
*/

class Solution {

    public static boolean isAValidSet(int nwStSize, int sizeToCheck){
        return nwStSize==sizeToCheck;
    }

    public int countCompleteSubarrays(int[] nums) {
        int lengthOfNums=nums.length, resultantCompSubarrays=0;
        HashSet<Integer>distinctEleInNumsSt=new HashSet<>();
        for(int num: nums){
            distinctEleInNumsSt.add(num);
        }
        int sizeToCheck=distinctEleInNumsSt.size();
        for(int i=0; i<lengthOfNums; ++i){
            HashSet<Integer>currentSeenEleSt=new HashSet<>();
            for(int j=i; j<lengthOfNums; ++j){
                currentSeenEleSt.add(nums[j]);
                int nwSizeToCheck=currentSeenEleSt.size();
                if(isAValidSet(nwSizeToCheck, sizeToCheck)) resultantCompSubarrays++;
                else if(nwSizeToCheck>sizeToCheck) break;
            }
        }
        return resultantCompSubarrays;
    }
}