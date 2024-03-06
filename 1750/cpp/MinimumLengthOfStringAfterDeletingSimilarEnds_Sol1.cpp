/*
https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05
*/

class Solution {
public:
    int minimumLength(string s) {
        int sz=s.length(), left=0, right=sz-1;
        while(left<right){
            char curlft=s[left], currght=s[right];
            if(curlft==currght){
                while(left<=right&&s[left]==curlft){
                    left++;
                }
                while(left<right&&s[right]==currght){
                    right--;
                }
            } else{
                break;
            }
        }
        return right-left+1;
    }
};