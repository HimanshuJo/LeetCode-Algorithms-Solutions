/*
https://leetcode.com/problems/plus-one/description/?envType=daily-question&envId=2026-01-01
*/

class Solution {
    public int[] plusOne(int[] digits) {
        int lengthOfDigits=digits.length, carry=0;
        for(int i=lengthOfDigits-1; i>=0; --i){
            if(i==lengthOfDigits-1){
                if(digits[i]+1>=10){
                    int lastDigit=(digits[i]+1)%10, firstDigit=(digits[i]+1)/10;
                    digits[i]=lastDigit;
                    carry=firstDigit;
                } else digits[i]+=1;
            } else{
                if(digits[i]+carry>=10){
                    int lastDigit=(digits[i]+carry)%10, firstDigit=(digits[i]+carry)/10;
                    digits[i]=lastDigit;
                    carry=firstDigit;
                } else{
                    digits[i]+=carry;
                    carry=0;
                }
            }
        }
        int finalLength=lengthOfDigits;
        boolean isCarry=false;
        if(carry!=0){
            finalLength+=1;
            isCarry=true;
        }
        int[] resultantArray=new int[finalLength];
        int beginIndex=0;
        if(isCarry)
            resultantArray[beginIndex++]=carry;
        for(int i=0; i<lengthOfDigits; ++i){
            resultantArray[beginIndex++]=digits[i];
        }
        return resultantArray;
    }
}