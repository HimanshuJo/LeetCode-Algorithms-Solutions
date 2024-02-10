/*
https://leetcode.com/problems/palindromic-substrings/description/?envType=daily-question&envId=2024-02-10
*/

class Solution {

    public boolean isPalindrome(String str){
        int left=0, right=str.length()-1;
        while(left<=right){
            if(str.charAt(left++)!=str.charAt(right--)) return false;
        }
        return true;
    }

    public int countSubstrings(String s) {
        int sz=s.length(), res=0;
        for(int i=0; i<sz; ++i){
            StringBuilder curr=new StringBuilder();
            for(int j=i; j<sz; ++j){
                curr.append(s.charAt(j));
                if(isPalindrome(String.valueOf(curr))) res++;
            }
        }
        return res;
    }
}