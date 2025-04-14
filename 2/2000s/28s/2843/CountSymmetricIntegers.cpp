/*
https://leetcode.com/problems/count-symmetric-integers/description/?envType=daily-question&envId=2025-04-11
*/

class Solution {
public:

    bool isValid(int val){
        string tochk=to_string(val);
        int sz=tochk.size();
        if(sz%2!=0) return false;
        int totrvhf=sz/2, smlft=0, smrght=0;
        for(int i=0; i<totrvhf; ++i){
            smlft+=(tochk[i]-'0');
        }
        for(int i=totrvhf; i<sz; ++i){
            smrght+=(tochk[i]-'0');
        }
        return smlft==smrght;
    }

    int countSymmetricIntegers(int low, int high) {
        int res=0;
        while(low<=high){
            if(isValid(low)){
                res++;
            }
            if(low==high) break;
            if(isValid(high)){
                res++;
            }
            low++, high--;
        }
        return res;
    }
};