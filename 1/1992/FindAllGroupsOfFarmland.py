# https://leetcode.com/problems/find-all-groups-of-farmland/description/?envType=daily-question&envId=2024-04-20

class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:

        def isValid(land, rws, cols, seen, currw, curcol):
            if currw>=0 and curcol>=0 and currw<=rws-1 and curcol<=cols-1:
                if land[currw][curcol]==1:
                    tochk=str(currw)+"#"+str(curcol)
                    if tochk not in seen:
                        return True
            return False

        def dfs(land, rws, cols, seen, currw, curcol, curr):
            if isValid(land, rws, cols, seen, currw, curcol)==False:
                return
            else:
                tochk=str(currw)+"#"+str(curcol)
                seen.add(tochk)
                tmp=[currw, curcol]
                curr.append(tmp)
            dfs(land, rws, cols, seen, currw+1, curcol, curr)
            dfs(land, rws, cols, seen, currw-1, curcol, curr)
            dfs(land, rws, cols, seen, currw, curcol+1, curr)
            dfs(land, rws, cols, seen, currw, curcol-1, curr)
            return

        rws=len(land)
        cols=len(land[0])
        res=[]
        seen=set()
        for i in range(0, rws, 1):
            for j in range(0, cols, 1):
                if land[i][j]==1:
                    tochk=str(i)+"#"+str(j)
                    if tochk not in seen:
                        curr=[]
                        dfs(land, rws, cols, seen, i, j, curr)
                        sorted_pairs=sorted(curr, key=lambda x: x[0])
                        curres=[]
                        curres.append(sorted_pairs[0][0])
                        curres.append(sorted_pairs[0][1])
                        curres.append(sorted_pairs[len(curr)-1][0])
                        curres.append(sorted_pairs[len(curr)-1][1])
                        res.append(curres)
        fnresln=len(res)
        fnrescolln=4
        fnresarr=[]
        for i in range(0, fnresln, 1):
            fnresarr.append([])
            for j in range(0, 4, 1):
                fnresarr[i].append(res[i][j])
        return fnresarr