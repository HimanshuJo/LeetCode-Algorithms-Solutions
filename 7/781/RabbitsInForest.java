/*
https://leetcode.com/problems/rabbits-in-forest/description/?envType=daily-question&envId=2025-04-20
*/

class Solution {
    public int numRabbits(int[] answers) {
        int lengthOfAnswers=answers.length, resultantMinNumRabbits=0;
        HashMap<Integer, Integer>frequencyMap=new HashMap<>();
        for(int i=0; i<lengthOfAnswers; ++i){
            if(frequencyMap.containsKey(answers[i])){
                frequencyMap.put(answers[i], frequencyMap.get(answers[i])+1);
            } else frequencyMap.put(answers[i], 1);
        }
        for(Map.Entry<Integer, Integer>entries: frequencyMap.entrySet()){
            int currentPossGroupSize=entries.getKey()+1, numRabbitsSayingCurrCount=entries.getValue();
            int totalPossRabsForCurrentGroup=(numRabbitsSayingCurrCount+currentPossGroupSize-1)/currentPossGroupSize;
            resultantMinNumRabbits+=(currentPossGroupSize*totalPossRabsForCurrentGroup);
        }
        return resultantMinNumRabbits;
    }
}