# https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/?envType=daily-question&envId=2024-03-18

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:

        def custom_comparator(points):
            return points[1]

        if len(points)==0:
            return 0
        sorted_points=sorted(points, key=custom_comparator)
        arrows=1
        curend=sorted_points[0][1]
        sz=len(sorted_points)
        for i in range(1, sz, 1):
            if sorted_points[i][0]>curend:
                arrows+=1
                curend=sorted_points[i][1]
        return arrows