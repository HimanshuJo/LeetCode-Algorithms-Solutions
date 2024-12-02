class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        lengthOfSentence=len(sentence)
        currentIndex=1
        currentString=""
        for i in range(0, lengthOfSentence, 1):
            if currentString==searchWord:
                return currentIndex
            currentChar=sentence[i]
            if currentChar==' ':
                currentString=""
                currentIndex+=1
            else:
                currentString+=currentChar
        if currentString==searchWord:
            return currentIndex
        return -1
