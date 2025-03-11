/*
https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/?envType=daily-question&envId=2025-03-11
*/

class Solution {
public:

    bool hasAllReqChars(int freqArr[]){
        return freqArr[0]>=1&&freqArr[1]>=1&&freqArr[2]>=1;
    }

    // TC: O(n)
    int numberOfSubstrings(string s) {
        int sz=s.size(), left=0, right=0, res=0;
        int freqArr[3];
        freqArr[0]=0, freqArr[1]=0, freqArr[2]=0;
        while(right<sz){
            char curr=s[right];
            freqArr[curr-'a']++;
            /*
                Checking all further extentions that can be made from the current valid string
                if after removing a char from the left window, the string is still valid, then
                we can still count the number of extentions
            */
            while(hasAllReqChars(freqArr)){
                res+=(sz-right);
                char atLeft=s[left];
                freqArr[atLeft-'a']--;
                left++;
            }
            right++;
        }
        return res;
    }
};
