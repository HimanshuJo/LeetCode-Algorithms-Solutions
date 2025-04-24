/*
https://leetcode.com/problems/count-largest-group/description/?envType=daily-question&envId=2025-04-23
*/

class Solution {
    public int countLargestGroup(int n) {
        TreeMap<Integer, ArrayList<Integer>>sumNumbersMap=new TreeMap<>();
        TreeMap<Integer, Integer>countsMap=new TreeMap<>();
        for(int i=1; i<=n; ++i){
            String toProcessStr=String.valueOf(i);
            int lengthOfStr=toProcessStr.length(), currentSum=0;
            for(int j=0; j<lengthOfStr; ++j){
                currentSum+=(toProcessStr.charAt(j)-'0');
            }
            if(sumNumbersMap.containsKey(currentSum)){
                ArrayList<Integer>currentList=sumNumbersMap.get(currentSum);
                currentList.add(i);
                sumNumbersMap.put(currentSum, currentList);
            } else{
                ArrayList<Integer>currentList=new ArrayList<>();
                currentList.add(i);
                sumNumbersMap.put(currentSum, currentList);
            }
        }
        for(Map.Entry<Integer, ArrayList<Integer>>entries: sumNumbersMap.entrySet()){
            int currentSize=entries.getValue().size();
            if(countsMap.containsKey(currentSize)){
                countsMap.put(currentSize, countsMap.get(currentSize)+1);
            } else countsMap.put(currentSize, 1);
        }
        int biggestKey=countsMap.lastKey();
        return countsMap.get(biggestKey);
    }
}