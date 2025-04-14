/*
https://leetcode.com/problems/count-symmetric-integers/description/?envType=daily-question&envId=2025-04-11
*/

class Solution {

    public static boolean isASymmetricInteger(int val){
        String toCheckString=String.valueOf(val);
        int lengthOfStr=toCheckString.length();
        if(lengthOfStr%2!=0) return false;
        int halfLength=lengthOfStr/2, sumLeft=0, sumRight=0, i=0, j=halfLength;
        while(true){
            if(i>=halfLength||j>=lengthOfStr) break;
            sumLeft+=(toCheckString.charAt(i++)-'0');
            sumRight+=(toCheckString.charAt(j++)-'0');
        }
        return sumLeft==sumRight;
    }

    public int countSymmetricIntegers(int low, int high) {
        int resultantSymmNums=0;
        while(low<=high){
            if(isASymmetricInteger(low)){
                resultantSymmNums++;
            }
            if(low==high) break;
            if(isASymmetricInteger(high)){
                resultantSymmNums++;
            }
            low++;
            high--;
        }
        return resultantSymmNums;
    }
}