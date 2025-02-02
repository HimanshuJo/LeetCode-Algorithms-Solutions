class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        lengthOfS=len(s)
        lengthOfS = len(s)
        lengthOfSpaces = len(spaces)
        result = []
        currentSpaceIndex = 0
        currentTraversingIndex = 0
        
        for i in range(lengthOfS):
            if currentSpaceIndex < lengthOfSpaces and i == spaces[currentSpaceIndex]:
                result.append(' ')
                currentSpaceIndex += 1
            result.append(s[i])
        
        return ''.join(result)
