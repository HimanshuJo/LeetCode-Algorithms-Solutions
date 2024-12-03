class Solution {
    public String addSpaces(String s, int[] spaces) {
        int lengthOfS=s.length(), 
            lengthOfSpaces=spaces.length, 
            requiredLength=lengthOfS+lengthOfSpaces,
            currentSpaceIndex=0, currentTrvIndex=0;
        StringBuilder result=new StringBuilder();
        for(int i=0; i<requiredLength; ++i){
            result.append(' ');
        }
        for(int i=0; i<lengthOfS; ++i){
            char currentChar=s.charAt(i);
            if(currentSpaceIndex<lengthOfSpaces&&i==spaces[currentSpaceIndex]){
                currentTrvIndex++;
                result.setCharAt(currentTrvIndex, currentChar);
                currentSpaceIndex++;
                currentTrvIndex++;
            } else{
                result.setCharAt(currentTrvIndex, currentChar);
                currentTrvIndex++;
            }
        }
        return String.valueOf(result);
    }
}
