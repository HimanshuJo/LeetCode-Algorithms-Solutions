/*
https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05
*/

class Solution {

    public int dfs(String s, int left, int right){
        if(left>=right||s.charAt(left)!=s.charAt(right)) return right-left+1;
        if(s.charAt(left)==s.charAt(right)){
            char tochk=s.charAt(left);
            while(left<=right&&s.charAt(left)==tochk) left++;
            while(left<=right&&s.charAt(right)==tochk) right--;
            return dfs(s, left, right);
        }
        return right-left+1;
    }

    public int minimumLength(String s) {
        int sz=s.length(), left=0, right=s.length()-1;
        return dfs(s, left, right);
    }
}