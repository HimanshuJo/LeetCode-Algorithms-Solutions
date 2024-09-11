/*
https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/?envType=daily-question&envId=2024-09-11
*/

class Solution {
public:

    string toBinary(int number){
        if(number==1||number==0){
            string res=to_string(number);
            while(res.size()!=32){
                res+="0";
            }
            reverse(res.begin(), res.end());
            return res;
        }
        string res="";
        while(number!=1){
            int quo=number/2, rem=number%2;
            res+=to_string(rem);
            number=quo;
        }
        res+="1";
        while(res.size()!=32){
            res+="0";
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int minBitFlips(int start, int goal) {
        string binaryStart=toBinary(start), binaryGoal=toBinary(goal);
        int res=0, sz=binaryStart.size(), idx=0;
        while(true){
            if(idx>=sz) break;
            if(binaryStart[idx]!=binaryGoal[idx]) res++;
            idx++;
        }
        return res;
    }
};