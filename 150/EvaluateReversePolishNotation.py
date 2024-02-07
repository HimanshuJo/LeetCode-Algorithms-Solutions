# https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=daily-question&envId=2024-01-30

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        res=0
        stk=[]
        mp={}
        mp["+"]="+"
        mp["-"]="-"
        mp["*"]="*"
        mp["/"]="/"
        sz=len(tokens)
        for i in range(0, sz, 1):
            if tokens[i] not in mp:
                stk.append(int(tokens[i]))
            else:
                curtkn=tokens[i]
                curtp=stk[len(stk)-1]
                del(stk[len(stk)-1])
                nxt=stk[len(stk)-1]
                del(stk[len(stk)-1])
                if curtkn=="+":
                    stk.append(curtp+nxt)
                elif curtkn=="-":
                    stk.append(nxt-curtp)
                elif curtkn=="*":
                    stk.append(nxt*curtp)
                else:
                    stk.append(int(nxt/curtp))
        return stk[len(stk)-1]
        