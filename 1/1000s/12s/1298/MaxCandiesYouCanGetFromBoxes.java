/*
https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/?envType=daily-question&envId=2025-06-03
*/

class Solution {
    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        int lengthOfStatus=status.length, resultantCandies=0;
        boolean[] availableBoxes=new boolean[lengthOfStatus];
        boolean[] canOpenBox=new boolean[lengthOfStatus];
        boolean[] seenBoxes=new boolean[lengthOfStatus];
        LinkedList<Integer>llOfBoxes=new LinkedList<>();
        for(int i=0; i<lengthOfStatus; ++i){
            availableBoxes[i]=false;
            canOpenBox[i]=false;
            seenBoxes[i]=false;
            if(status[i]==1){
                canOpenBox[i]=true;
            }
        }
        for(int iniBoxes: initialBoxes){
            availableBoxes[iniBoxes]=true;
            if(canOpenBox[iniBoxes]){
                resultantCandies+=candies[iniBoxes];
                seenBoxes[iniBoxes]=true;
                llOfBoxes.add(iniBoxes);
            }
        }
        while(llOfBoxes.size()>=1){
            int currentLLSize=llOfBoxes.size();
            while(currentLLSize-- >0){
                int currentBox=llOfBoxes.pollFirst();
                for(int currKey: keys[currentBox]){
                    canOpenBox[currKey]=true;
                    if(!seenBoxes[currKey]&&availableBoxes[currKey]){
                        resultantCandies+=candies[currKey];
                        seenBoxes[currKey]=true;
                        llOfBoxes.add(currKey);
                    }
                }
                for(int curContBox: containedBoxes[currentBox]){
                    availableBoxes[curContBox]=true;
                    if(!seenBoxes[curContBox]&&canOpenBox[curContBox]){
                        resultantCandies+=candies[curContBox];
                        seenBoxes[curContBox]=true;
                        llOfBoxes.add(curContBox);
                    }
                }
            }
        }
        return resultantCandies;
    }
}