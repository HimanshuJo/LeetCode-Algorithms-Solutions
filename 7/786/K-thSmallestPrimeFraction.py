# https://leetcode.com/problems/k-th-smallest-prime-fraction/description/?envType=daily-question&envId=2024-05-10

import heapq

class IntPair:
    def __init__(self, first, second):
        self.first=first
        self.second=second

class Pair:
    def __init__(self, first, second):
        self.first=first
        self.second=second

class PriorityQueue:
    def __init__(self):
        self.heap = []

    def push(self, priority, value):
        heapq.heappush(self.heap, (priority, value))

    def pop(self):
        return heapq.heappop(self.heap)[1]

    def peek(self):
        return self.heap[0][1].second if self.heap else None

    def size(self):
        return len(self.heap)

class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        pq=PriorityQueue()
        sz=len(arr)
        for i in range(0, sz, 1):
            if i+1<=sz-1:
                for j in range(i+1, sz, 1):
                    frfst=IntPair(arr[i], arr[j])
                    frsec=arr[i]/arr[j]
                    nwPr=Pair(frsec, frfst)
                    pq.push(frsec, nwPr)
        res=[]
        while(pq.size()>0):
            curr=pq.pop()
            k-=1
            if k==0:
                res.append(curr.second.first)
                res.append(curr.second.second)
                break
        return res