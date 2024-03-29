/*
    https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=daily-question&envId=2024-01-30
*/

class Solution {
    public int evalRPN(String[] tokens) {
        int res=0, sz=tokens.length;
        Stack<Integer>stk=new Stack<>();
        HashMap<String, String>mp=new HashMap<>();
        mp.put("+", "+");
        mp.put("-", "-");
        mp.put("*", "*");
        mp.put("/", "/");
        for(int i=0; i<sz; ++i){
            if(!mp.containsKey(tokens[i])){
                stk.push(Integer.parseInt(tokens[i]));
            } else{
                String curtkn=tokens[i];
                int curtp=stk.pop();
                int nxt=stk.pop();
                if(curtkn.equals("+")){
                    stk.push(curtp+nxt);
                } else if(curtkn.equals("-")){
                    stk.push(nxt-curtp);
                } else if(curtkn.equals("*")){
                    stk.push(nxt*curtp);
                } else{
                    if(curtp!=0)
                        stk.push(nxt/curtp);
                    else stk.push(0);
                }
            }
        }
        return stk.peek();
    }
}