/*
https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01
*/

class Solution {
    public String maximumOddBinaryNumber(String s) {
        int countOnes=0, countZeros=0, sz=s.length();
        for(int i=0; i<sz; ++i){
            if(s.charAt(i)=='0') countZeros++;
            else countOnes++;
        }
        StringBuilder res=new StringBuilder();
        while(countOnes!=1){
            res.append("1");
            countOnes--;
        }
        while(countZeros!=0){
            res.append("0");
            countZeros--;
        }
        res.append("1");
        return String.valueOf(res);
    }
}