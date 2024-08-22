/*
https://leetcode.com/problems/number-complement/description/?envType=daily-question&envId=2024-08-22
*/

class Solution {
public:

    int toDec(string str){
        int sz=str.size(), pwr=sz-1;
        long long res=0;
        for(int i=0; i<sz; ++i){
            res+=(str[i]-'0')*pow(2, pwr--);
        }
        return res;
    }

    string toBinary(int num){
        if(num==0) return "0";
        string bn="";
        while(num!=1){
            int rem=num%2, quo=num/2;
            num=quo;
            bn+=to_string(rem);
        }
        bn+="1";
        reverse(bn.begin(), bn.end());
        return bn;
    }

    int findComplement(int num) {
        string tobn=toBinary(num);
        string complimnt="";
        for(int i=0; i<tobn.size(); ++i){
            if(tobn[i]=='1') complimnt+="0";
            else complimnt+="1";
        }
        return toDec(complimnt);
    }
};