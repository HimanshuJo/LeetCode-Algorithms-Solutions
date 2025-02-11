# https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=daily-question&envId=2024-07-08

class Solution:
    def findTheWinner(self, n: int, k: int) -> int:

        def removeFriendThatIsLost(currentListOfAllFriendsInGame, friendToRemove):
            return [friend for friend in currentListOfAllFriendsInGame if friend!=friendToRemove]

        indexToBegin=0
        currentListOfAllFriendsInGame=[]
        for i in range(1, n+1, 1):
            currentListOfAllFriendsInGame.append(i)
        while(1):
            if len(currentListOfAllFriendsInGame)==1:
                break
            currentListOfAllFriendsInGame[(indexToBegin+k-1)%len(currentListOfAllFriendsInGame)]=-1
            indexToBegin=(indexToBegin+k-1)%len(currentListOfAllFriendsInGame)
            currentListOfAllFriendsInGame=removeFriendThatIsLost(currentListOfAllFriendsInGame, -1)
        return currentListOfAllFriendsInGame[0]