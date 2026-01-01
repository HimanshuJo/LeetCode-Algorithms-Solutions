/*
https://leetcode.com/problems/plus-one/description/?envType=daily-question&envId=2026-01-01
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz=digits.size(), carry=0;
        for(int i=sz-1; i>=0; --i){
            if(i==sz-1){
                if(digits[i]+1>=10){
                    int lastdig=(digits[i]+1)%10, firstdig=(digits[i]+1)/10;
                    digits[i]=lastdig;
                    carry=firstdig;
                } else{
                    digits[i]+=1;
                }
            } else{
                if(digits[i]+carry>=10){
                    int lastdig=(digits[i]+carry)%10, firstdig=(digits[i]+carry)/10;
                    digits[i]=lastdig;
                    carry=firstdig;
                } else{
                    digits[i]+=carry;
                    carry=0;
                }
            }
        }
        vector<int>res;
        if(carry!=0) res.push_back(carry);
        for(auto &vals: digits) res.push_back(vals);
        return res;
    }
};