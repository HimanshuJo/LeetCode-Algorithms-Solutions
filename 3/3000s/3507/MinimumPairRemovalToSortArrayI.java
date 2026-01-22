/*
https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/?envType=daily-question&envId=2026-01-22
*/

class Pair{

    public int first;

    public int second;

    public Pair(int first, int second){
        this.first=first;
        this.second=second;
    }
}

class Solution {

    public boolean isAlreadySorted(int[] nums){
        int[] numsToCheck=new int[nums.length];
        for(int i=0; i<nums.length; ++i){
            numsToCheck[i]=nums[i];
        }
        Arrays.sort(numsToCheck);
        return Arrays.equals(numsToCheck, nums);
    }

    public int minimumPairRemoval(int[] nums) {
        int lengthOfNums=nums.length, resultantNumberOfOperations=0;
        while(true){
            if(isAlreadySorted(nums)) break;
            TreeMap<Integer, ArrayList<Pair>>sumIndicesMap=new TreeMap<>();
            for(int i=0; i<lengthOfNums; ++i){
                if(i+1<=lengthOfNums-1){
                    int currentPairSum=nums[i]+nums[i+1];
                    if(sumIndicesMap.containsKey(currentPairSum)){
                        ArrayList<Pair>currentPairLst=sumIndicesMap.get(currentPairSum);
                        Pair newPair=new Pair(i, i+1);
                        currentPairLst.add(newPair);
                        sumIndicesMap.put(currentPairSum, currentPairLst);
                    } else{
                        ArrayList<Pair>newPairLst=new ArrayList<>();
                        Pair newPair=new Pair(i, i+1);
                        newPairLst.add(newPair);
                        sumIndicesMap.put(currentPairSum, newPairLst);
                    }
                }
            }
            Integer lowestSum=sumIndicesMap.firstKey();
            ArrayList<Pair>allIndicesForLowestSum=sumIndicesMap.get(lowestSum);
            Pair pairToCheck=allIndicesForLowestSum.get(0);
            int firstIndex=pairToCheck.first, secondIndex=pairToCheck.second;
            int[] newNums=new int[lengthOfNums-1];
            int beginIndex=0, indexForNewNums=0;
            while(true){
                if(beginIndex>=lengthOfNums) break;
                if(beginIndex==firstIndex){
                    newNums[indexForNewNums]=lowestSum;
                    beginIndex+=2;
                } else{
                    newNums[indexForNewNums]=nums[beginIndex++];
                }
                indexForNewNums++;
            }
            nums=newNums;
            lengthOfNums=nums.length;
            resultantNumberOfOperations++;
        }
        return resultantNumberOfOperations;
    }
}