/*
https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01
*/

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int countOnes=0, countZeros=0;
        for(char &ch: s){
            if(ch=='0') countZeros++;
            else countOnes++;
        }
        string res="";
        while(countOnes!=1){
            res+="1";
            countOnes--;
        }
        while(countZeros!=0){
            res+="0";
            countZeros--;
        }
        res+="1";
        return res;
    }
};