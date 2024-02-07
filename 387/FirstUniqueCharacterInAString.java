/*
https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05
*/

class Solution {

    boolean customFind(String s, char ch, int idx){
        int sz=s.length();
        if(idx>=sz) return false;
        for(int i=0; i<sz; ++i){
            if(i!=idx&&s.charAt(i)==ch) return true;
        }
        return false;
    }

    public int firstUniqChar(String s) {
        int sz=s.length();
        for(int i=0; i<sz; ++i){
            boolean flag=customFind(s, s.charAt(i), i);
            if(!flag) return i;
        }
        return -1;
    }
}