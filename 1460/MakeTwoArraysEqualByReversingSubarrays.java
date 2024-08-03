/*
https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/?envType=daily-question&envId=2024-08-03
*/

class Solution {

    public static void performReverseOfSubarray(int[] arr, int beginIndex, int endIndex){
        int lengthToCover=(endIndex-beginIndex)+1;
        int[] temporaryArray=new int[lengthToCover];
        int start=0;
        for(int i=endIndex; i>=beginIndex; --i){
            temporaryArray[start++]=arr[i];
        }
        start=0;
        for(int i=beginIndex; i<=endIndex; ++i){
            arr[i]=temporaryArray[start++];
        }
    }

    public boolean canBeEqual(int[] target, int[] arr) {
        int lengthOfTarget=target.length;
        for(int i=0; i<lengthOfTarget; ++i){
            if(target[i]!=arr[i]){
                if(i+1>=lengthOfTarget) return false;
                int j=i, beginIndex=i;
                boolean isNumberFoundInRestArray=false;
                while(true){
                    if(j>=lengthOfTarget) break;
                    if(arr[j]==target[i]){
                        isNumberFoundInRestArray=true;
                        break;
                    }
                    j++;
                }
                if(!isNumberFoundInRestArray) return false;
                performReverseOfSubarray(arr, beginIndex, j);
            }
        }
        for(int i=0; i<lengthOfTarget; ++i){
            if(arr[i]!=target[i]) return false;
        }
        return true;
    }
}