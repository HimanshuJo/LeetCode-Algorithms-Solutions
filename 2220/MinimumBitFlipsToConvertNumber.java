/*
https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/?envType=daily-question&envId=2024-09-11
*/

class Solution {

    public static String convertToBinary(int number){
        StringBuilder numberToString=null;
        if(number==1||number==0){
            numberToString=new StringBuilder(String.valueOf(number));
        } else{
            numberToString=new StringBuilder("");
            while(number!=1){
                int quotient=number/2, remainder=number%2;
                numberToString.append(String.valueOf(remainder));
                number=quotient;
            }
            numberToString.append("1");
        }
        while(numberToString.length()!=32){
            numberToString.append("0");
        }
        return String.valueOf(numberToString.reverse());
    }

    public int minBitFlips(int start, int goal) {
        String startInBinaryRepresentation=convertToBinary(start);
        String goalInBinaryRepresentation=convertToBinary(goal);
        int resultantMininumBitFlips=0, length=startInBinaryRepresentation.length(), beginIndex=0;
        while(true){
            if(beginIndex>=length) break;
            if(startInBinaryRepresentation.charAt(beginIndex)!=goalInBinaryRepresentation.charAt(beginIndex)){
                resultantMininumBitFlips++;
            }
            beginIndex++;
        }
        return resultantMininumBitFlips;
    }
}