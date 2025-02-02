# https://leetcode.com/problems/count-number-of-teams/description/?envType=daily-question&envId=2024-07-29

class Solution:
    def numTeams(self, rating: List[int]) -> int:
        lengthOfRating=len(rating)
        resultantNumberOfTeams=0
        for i in range(0, lengthOfRating, 1):
            curr=rating[i]
            if i+1<=lengthOfRating-1:
                for j in range(i+1, lengthOfRating, 1):
                    next=rating[j]
                    if next>curr:
                        if j+1<=lengthOfRating-1:
                            for k in range(j+1, lengthOfRating, 1):
                                if rating[k]>next:
                                    resultantNumberOfTeams+=1
                    elif next<curr:
                        if j+1<=lengthOfRating-1:
                            for k in range(j+1, lengthOfRating, 1):
                                if rating[k]<next:
                                    resultantNumberOfTeams+=1
        return resultantNumberOfTeams