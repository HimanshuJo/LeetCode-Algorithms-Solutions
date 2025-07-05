/*
https://leetcode.com/problems/find-lucky-integer-in-an-array/description/?envType=daily-question&envId=2025-07-05
*/

class Solution {

    public static boolean isLucky(int[] arr, int val){
        int freq=0;
        for(int num: arr){
            if(num==val) freq++;
        }
        return freq==val;
    }

    public int findLucky(int[] arr) {
        int lengthOfArr=arr.length;
        TreeSet<Integer>allLuckyNumbers=new TreeSet<>();
        for(int i=0; i<lengthOfArr; ++i){
            if(isLucky(arr, arr[i])){
                allLuckyNumbers.add(arr[i]);
            }
        }
        if(allLuckyNumbers.size()==0) return -1;
        return allLuckyNumbers.last();
    }
}