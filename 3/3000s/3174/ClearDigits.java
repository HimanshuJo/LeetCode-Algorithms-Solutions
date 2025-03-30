/*
https://leetcode.com/problems/clear-digits/description/?envType=daily-question&envId=2025-02-10
*/

class Solution {

    public static boolean isDigit(HashMap<Character, Character>digits, char ch){
        return digits.containsKey(ch);
    }

    public String clearDigits(String s) {
        int lengthOfS=s.length();
        StringBuilder tempS=new StringBuilder(String.valueOf(s));
        HashMap<Character, Character>digits=new HashMap<>();
        digits.put('0', '0');
        digits.put('1', '1');
        digits.put('2', '2');
        digits.put('3', '3');
        digits.put('4', '4');
        digits.put('5', '5');
        digits.put('6', '6');
        digits.put('7', '7');
        digits.put('8', '8');
        digits.put('9', '9');
        while(true){
            if(lengthOfS==0) break;
            boolean isDigitAvailable=false;
            int indexOfFirstDigit=-1;
            for(int i=0; i<lengthOfS; ++i){
                if(isDigit(digits, tempS.charAt(i))){
                    tempS.setCharAt(i, '#');
                    indexOfFirstDigit=i;
                    isDigitAvailable=true;
                    break;
                }
            }
            if(isDigitAvailable){
                if(indexOfFirstDigit-1>=0){
                    for(int i=indexOfFirstDigit-1; i>=0; --i){
                        if(!isDigit(digits, tempS.charAt(i))){
                            tempS.setCharAt(i, '#');
                            break;
                        }
                    }
                }
            }
            if(!isDigitAvailable) break;
            tempS=new StringBuilder(String.valueOf(tempS).replaceAll("#", ""));
            lengthOfS=tempS.length();
        }
        return String.valueOf(tempS);
    }
}