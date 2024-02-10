/*
https://leetcode.com/problems/palindromic-substrings/description/?envType=daily-question&envId=2024-02-10
*/

class Solution {
public:

    bool isPalindrome(string &str){
        int left=0, right=str.size()-1;
        while(left<=right){
            if(str[left++]!=str[right--]) return false;
        }
        return true;
    }

    int countSubstrings(string s) {
        int sz=s.size(), res=0;
        for(int i=0; i<sz; ++i){
            string curr="";
            for(int j=i; j<sz; ++j){
                curr+=s[j];
                if(isPalindrome(curr)) res++;
            }
        }
        return res;
    }
};