/*
https://leetcode.com/problems/count-and-say/description/?envType=daily-question&envId=2025-04-18
*/

class Solution {

    private String resultantString;

    public String getResultantString(){
        return this.resultantString;
    }

    public void setResultantString(String resultantString){
        this.resultantString=resultantString;
    }

    public static StringBuilder genNextString(StringBuilder sbf){
        StringBuilder nwString=new StringBuilder();
        int lengthOfSbf=sbf.length(), idx=0;
        while(true){
            if(idx>=lengthOfSbf) break;
            char currentChar=sbf.charAt(idx);
            int currentCount=1;
            while(true){
                if(idx>=lengthOfSbf) break;
                if(idx+1<=lengthOfSbf-1){
                    char nextChar=sbf.charAt(idx+1);
                    if(nextChar!=currentChar){
                        nwString.append(String.valueOf(currentCount));
                        nwString.append(currentChar);
                        ++idx;
                        break;
                    } else{
                        currentCount++;
                        ++idx;
                    }
                } else{
                    nwString.append(String.valueOf(currentCount));
                    nwString.append(currentChar);
                    ++idx;
                    break;
                }
            }
        }
        return nwString;
    }

    public void depthFirstSearch_forStrings(int n, StringBuilder beginString){
        if(n==0){
            setResultantString(String.valueOf(beginString));
            return;
        }
        StringBuilder nextString=genNextString(beginString);
        depthFirstSearch_forStrings(n-1, nextString);
        return;
    }

    public String countAndSay(int n) {
        StringBuilder beginString=new StringBuilder("1");
        depthFirstSearch_forStrings(n-1, beginString);
        return getResultantString();
    }
}