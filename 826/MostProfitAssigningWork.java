/*
https://leetcode.com/problems/most-profit-assigning-work/description/?envType=daily-question&envId=2024-06-18
*/

class CustomComparator implements Comparator<Pair>{

    @Override
    public int compare(Pair A, Pair B){
        return Integer.compare(A.getFirst(), B.getFirst());
    }
}

class Pair{

    public int first;

    public int second;

    Pair(int first, int second){
        this.first=first;
        this.second=second;
    }

    public int getFirst(){
        return this.first;
    }

    public int getSecond(){
        return this.second;
    }
}

class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        ArrayList<Pair>difficultyProfitCombination=new ArrayList<>();
        ArrayList<Pair>profitDifficultyCombination=new ArrayList<>();
        int difficultyProfitLength=difficulty.length, resultantMaxProfit=0;
        for(int i=0; i<difficultyProfitLength; ++i){
            difficultyProfitCombination.add(new Pair(difficulty[i], profit[i]));
            profitDifficultyCombination.add(new Pair(profit[i], difficulty[i]));
        }
        Collections.sort(difficultyProfitCombination, new CustomComparator());
        Collections.sort(profitDifficultyCombination, new CustomComparator());
        int workerLength=worker.length;
        for(int i=0; i<workerLength; ++i){
            int currentWorkerLimit=worker[i], traversalIndexInFirstList=0;
            boolean isAnyDifficultyProfitCombinationValid=false;
            while(traversalIndexInFirstList<=difficultyProfitLength-1){
                if(difficultyProfitCombination.get(traversalIndexInFirstList).getFirst()<=currentWorkerLimit){
                    if(!isAnyDifficultyProfitCombinationValid){
                        isAnyDifficultyProfitCombinationValid=true;
                    }
                    traversalIndexInFirstList++;
                } else break;
            }
            int currentCollectedProfit=0;
            if(isAnyDifficultyProfitCombinationValid){
                if(traversalIndexInFirstList>=1) traversalIndexInFirstList--;
                currentCollectedProfit=difficultyProfitCombination.get(traversalIndexInFirstList).getSecond();
            }
            int traversalIndexInSecondList=0;
            while(traversalIndexInSecondList<=difficultyProfitLength-1){
                if(profitDifficultyCombination.get(traversalIndexInSecondList).getSecond()<=currentWorkerLimit){
                    currentCollectedProfit=Math.max(currentCollectedProfit, profitDifficultyCombination.get(traversalIndexInSecondList).getFirst());
                }
                traversalIndexInSecondList++;
            }
            resultantMaxProfit+=currentCollectedProfit;
        }
        return resultantMaxProfit;
    }
}