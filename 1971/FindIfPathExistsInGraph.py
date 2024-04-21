# https://leetcode.com/problems/find-if-path-exists-in-graph/description/?envType=daily-question&envId=2024-04-21

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:

        def dfs(source, destination, gr, seen, flag):
            if source==destination:
                flag[0]=True
                return
            curgrsz=len(gr[source])
            for i in range(0, curgrsz, 1):
                nei=gr[source][i]
                if nei not in seen:
                    seen.add(nei)
                    dfs(nei, destination, gr, seen, flag)
            return

        gr=[]
        for i in range(0, n, 1):
            gr.append([])
        sz=len(edges)
        for i in range(0, sz, 1):
            gr[edges[i][0]].append(edges[i][1])
            gr[edges[i][1]].append(edges[i][0])
        seen=set()
        flag=[]
        flag.append(False)
        seen.add(source)
        dfs(source, destination, gr, seen, flag)
        return flag[0]