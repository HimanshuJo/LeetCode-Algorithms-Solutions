/*
https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=daily-question&envId=2024-07-23
*/

class Solution {
    public int[] frequencySort(int[] nums) {
        HashMap<Integer, Integer>numberToItsCountMap=new HashMap<>();
        TreeMap<Integer, ArrayList<Integer>>numbersWithFollowingCount=new TreeMap<>();
        int lengthOfNums=nums.length;
        for(int i=0; i<lengthOfNums; ++i){
            if(numberToItsCountMap.containsKey(nums[i])){
                numberToItsCountMap.put(nums[i], numberToItsCountMap.get(nums[i])+1);
            } else numberToItsCountMap.put(nums[i], 1);
        }
        for(Map.Entry<Integer, Integer>entry: numberToItsCountMap.entrySet()){
            if(numbersWithFollowingCount.containsKey(entry.getValue())){
                ArrayList<Integer>currentList=numbersWithFollowingCount.get(entry.getValue());
                currentList.add(entry.getKey());
                numbersWithFollowingCount.put(entry.getValue(), currentList);
            } else{
                ArrayList<Integer>currentList=new ArrayList<>();
                currentList.add(entry.getKey());
                numbersWithFollowingCount.put(entry.getValue(), currentList);
            }
        }
        ArrayList<Integer>resultantListWithRequiredSorting=new ArrayList<>();
        for(Map.Entry<Integer, ArrayList<Integer>>entry: numbersWithFollowingCount.entrySet()){
            if(entry.getValue().size()>=2){
                Collections.sort(entry.getValue());
                int sizeOfCurrentList=entry.getValue().size();
                for(int i=sizeOfCurrentList-1; i>=0; --i){
                    for(int j=0; j<entry.getKey(); ++j){
                        resultantListWithRequiredSorting.add(entry.getValue().get(i));
                    }
                }
            } else{
                for(int j=0; j<entry.getKey(); ++j){
                    resultantListWithRequiredSorting.add(entry.getValue().get(entry.getValue().size()-1));
                }
            }
        }
        int[] finalArray=new int[resultantListWithRequiredSorting.size()];
        for(int i=0; i<resultantListWithRequiredSorting.size(); ++i){
            finalArray[i]=resultantListWithRequiredSorting.get(i);
        }
        return finalArray;
    }
}