# https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07

class Solution:
    def frequencySort(self, s: str) -> str:
        mp1={}
        sz=len(s)
        for i in range(0, sz, 1):
            if s[i] in mp1:
                mp1[s[i]]=mp1[s[i]]+1
            else:
                mp1[s[i]]=1
        mp2={}
        for key, vals in mp1.items():
            if vals in mp2:
                curlst=mp2[vals]
                curlst.append(key)
                mp2[vals]=curlst
            else:
                curlst=[]
                curlst.append(key)
                mp2[vals]=curlst
        res=""
        for key, vals in mp2.items():
            count=key
            curlst=vals
            curlstsz=len(curlst)
            for i in range(0, curlstsz, 1):
                for j in range(0, count, 1):
                    res+=curlst[i]
        fnres=res[::-1]
        return fnres
        