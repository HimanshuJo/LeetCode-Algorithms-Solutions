/*
https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2024-05-29
*/

class Solution {

    public static String addOneToS(String s){
        StringBuilder finalStringAfterAddingOne=new StringBuilder(s);
        int lengthOfS=s.length();
        for(int index=lengthOfS-1; index>=0; --index){
            if(s.charAt(index)=='0'){
                finalStringAfterAddingOne.setCharAt(index, '1');
                return String.valueOf(finalStringAfterAddingOne);
            } else finalStringAfterAddingOne.setCharAt(index, '0');
        }
        finalStringAfterAddingOne.insert(0, '1');
        return String.valueOf(finalStringAfterAddingOne);
    }

    public static boolean isLastDigitInSOdd(int lastDigitInS){
        if(lastDigitInS==1) return true;
        return false;
    }

    public int numSteps(String s) {
        int numberStepsToReduceSToOne=0;
        while(!s.equals("1")){
            int lastDigitInS=s.charAt(s.length()-1)-'0';
            if(isLastDigitInSOdd(lastDigitInS)){
                String newS=addOneToS(s);
                s=new String(newS);
            } else{
                StringBuilder newS=new StringBuilder(s);
                newS.deleteCharAt(newS.length()-1);
                s=new String(String.valueOf(newS));
            }
            numberStepsToReduceSToOne++;
        }
        return numberStepsToReduceSToOne;
    }
}