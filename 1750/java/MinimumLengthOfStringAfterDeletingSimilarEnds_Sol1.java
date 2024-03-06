/*
https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05
*/

class Solution {
    public int minimumLength(String s) {
        int sz=s.length(), left=0, right=sz-1;
        while(left<right){
            char curlft=s.charAt(left), currght=s.charAt(right);
            if(curlft==currght){
                while(left<=right&&s.charAt(left)==curlft) left++;
                while(left<=right&&s.charAt(right)==currght) right--;
            } else break;
        }
        return right-left+1;
    }
}