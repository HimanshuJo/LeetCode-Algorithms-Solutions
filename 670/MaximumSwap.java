/*
https://leetcode.com/problems/maximum-swap/description/?envType=daily-question&envId=2024-10-17
*/

class Solution {

    public static void swap(StringBuilder str, int left, int right){
        char temp=str.charAt(left);
        str.setCharAt(left, str.charAt(right));
        str.setCharAt(right, temp);
    }

    public int maximumSwap(int num) {
        StringBuilder numToString=new StringBuilder(String.valueOf(num));
        int lengthOfNumString=numToString.length(), resultantMaximumValue=Integer.MIN_VALUE;
        for(int i=0; i<lengthOfNumString; ++i){
            int left=i, right=lengthOfNumString-1;
            while(left<=right){
                StringBuilder stringToCheck=new StringBuilder(numToString);
                swap(stringToCheck, left, right);
                int numToCheck=Integer.parseInt(String.valueOf(stringToCheck));
                resultantMaximumValue=Math.max(resultantMaximumValue, numToCheck);
                right--;
            }
        }
        return resultantMaximumValue;
    }
}