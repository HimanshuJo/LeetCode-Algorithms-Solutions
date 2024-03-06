/*
https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05
*/

class Solution {
public:

    int dfs(string &s, int left, int right){
        if(left>=right||s[left]!=s[right]) return right-left+1;
        if(s[left]==s[right]){
            char tochk=s[left];
            while(left<=right&&s[left]==tochk){
                left++;
            }
            while(left<=right&&s[right]==tochk){
                right--;
            }
            return dfs(s, left, right);
        }
        return right-left+1;
    }

    int minimumLength(string s) {
        int sz=s.length(), left=0, right=sz-1;
        return dfs(s, left, right);
    }
};