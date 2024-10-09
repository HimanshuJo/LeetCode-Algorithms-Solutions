/*
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/?envType=daily-question&envId=2024-10-09
*/

class Solution {
    public int minAddToMakeValid(String s) {
        int lengthOfS=s.length(), minMovesRequired=0;
        Stack<Character>stack=new Stack<>();
        for(int i=0; i<lengthOfS; ++i){
            char currentChar=s.charAt(i);
            if(currentChar=='('){
                stack.push(currentChar);
            } else{
                if(stack.empty()){
                    minMovesRequired++;
                } else{
                    stack.pop();
                }
            }
        }
        if(!stack.empty()) minMovesRequired+=stack.size();
        return minMovesRequired;
    }
}