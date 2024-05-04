# https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=daily-question&envId=2024-04-24

class Solution:
    def tribonacci(self, n: int) -> int:
        if n==0:
            return 0
        t0=0
        t1=1
        t2=1
        cursm=1
        while(n>0):
            n-=1
            if n==1 or n==0:
                break
            cursm=t0+t1+t2
            t0=t1
            t1=t2
            t2=cursm
        return cursm