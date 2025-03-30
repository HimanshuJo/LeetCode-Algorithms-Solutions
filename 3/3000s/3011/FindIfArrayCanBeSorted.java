/*
https://leetcode.com/problems/find-if-array-can-be-sorted/description/?envType=daily-question&envId=2024-11-06
*/

class Solution {

    public String toBinary(int number){
        StringBuilder resultantBinary=new StringBuilder();
        while(number!=1){
            int quotient=number/2, remainder=number%2;
            resultantBinary.append(remainder);
            number=quotient;
        }
        resultantBinary.append("1");
        return String.valueOf(resultantBinary);
    }

    public void swap(int[] array, int firstIndex, int secondIndex){
        int temporary=array[firstIndex];
        array[firstIndex]=array[secondIndex];
        array[secondIndex]=temporary;
    }

    public boolean isAValidPair(int firstNumber, int secondNumber){
        String binaryFirst=toBinary(firstNumber);
        String binarySecond=toBinary(secondNumber);
        int lengthFirst=binaryFirst.length(), lengthSecond=binarySecond.length(), countSetBits1=0, countSetBits2=0;
        for(int i=0; i<lengthFirst; ++i){
            if(binaryFirst.charAt(i)=='1') countSetBits1++;
        }
        for(int i=0; i<lengthSecond; ++i){
            if(binarySecond.charAt(i)=='1') countSetBits2++;
        }
        return countSetBits1==countSetBits2;
    }

    public boolean canSortArray(int[] nums) {
        int lengthOfNums=nums.length;
        int[] temporary=new int[lengthOfNums];
        for(int i=0; i<lengthOfNums; ++i) temporary[i]=nums[i];
        Arrays.sort(temporary);
        for(int i=0; i<lengthOfNums; ++i){
            if(i-1>=0){
                for(int j=i; j>0; --j){
                    int current=nums[j], previous=nums[j-1];
                    if(current<previous){
                        if(isAValidPair(current, previous)){
                            swap(nums, j, j-1);
                        }
                    }
                }
            }
        }
        return Arrays.equals(nums, temporary);
    }
}