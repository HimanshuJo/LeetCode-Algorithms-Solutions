# https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:

        def binarySearch(arrl, val):
            arrl.sort()
            left=0
            right=len(arrl)-1
            while(left<=right):
                mid=left+(right-left)//2
                if arrl[mid]==val:
                    return True
                elif arrl[mid]>val:
                    right=mid-1
                else:
                    left=mid+1
            return False

        def find(arrl, val):
            res=binarySearch(arrl, val)
            return res

        sz=len(trust)
        if sz==0:
            if n!=1:
                return -1
            return 1
        pplsmp={}
        for i in range(0, sz, 1):
            if trust[i][0] in pplsmp:
                vec=pplsmp[trust[i][0]]
                vec.append(trust[i][1])
                pplsmp[trust[i][0]]=vec
            else:
                pplsmp[trust[i][0]]=[]
                pplsmp[trust[i][0]].append(trust[i][1])
        for i in range(1, n+1, 1):
            if i not in pplsmp:
                flag1=False
                for j in range(1, n+1, 1):
                    if j!=i:
                        if j in pplsmp:
                            arrl=pplsmp[j]
                            flag2=find(arrl, i)
                            if(flag2==False):
                                flag1=True
                                break
                        else:
                            flag1=True
                            break
                if flag1==False:
                    return i
        return -1