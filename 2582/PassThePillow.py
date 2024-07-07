# https://leetcode.com/problems/pass-the-pillow/description/?envType=daily-question&envId=2024-07-06

class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        if time < n:
            return time+1
        storingTimeTemporary=time
        entireQueue=[]
        begin=1
        end=n
        hasCompletedCurrentQueue=False
        while(1):
            if time<0:
                break
            if begin==end:
                hasCompletedCurrentQueue=True
            elif begin==1:
                hasCompletedCurrentQueue=False
            entireQueue.append(begin)
            if hasCompletedCurrentQueue==True:
                begin-=1
            else:
                begin+=1
            time-=1
        return entireQueue[storingTimeTemporary]
