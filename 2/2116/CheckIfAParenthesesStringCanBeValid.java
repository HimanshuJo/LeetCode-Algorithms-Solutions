/*
https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/?envType=daily-question&envId=2025-01-12
*/

class Solution {
    public boolean canBeValid(String s, String locked) {
        int lengthOfS=s.length();
        if(lengthOfS%2!=0) return false;
        Stack<Integer>openBracketsStack=new Stack<>();
        Stack<Integer>unlockedIndicesStack=new Stack<>();
        for(int i=0; i<lengthOfS; ++i){
            if(locked.charAt(i)=='0'){
                unlockedIndicesStack.push(i);
            } else if(s.charAt(i)=='('){
                openBracketsStack.push(i);
            } else{
                if(!openBracketsStack.empty()){
                    openBracketsStack.pop();
                } else if(!unlockedIndicesStack.empty()){
                    unlockedIndicesStack.pop();
                } else return false;
            }
        }
        while(!openBracketsStack.empty()&&!unlockedIndicesStack.empty()&&openBracketsStack.peek()<unlockedIndicesStack.peek()){
            openBracketsStack.pop();
            unlockedIndicesStack.pop();
        }
        if(!openBracketsStack.empty()) return false;
        return true;
    }
}