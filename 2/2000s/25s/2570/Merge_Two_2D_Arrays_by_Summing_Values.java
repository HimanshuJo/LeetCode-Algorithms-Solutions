/*
https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/?envType=daily-question&envId=2025-03-02
*/

class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int lengthOfNums1=nums1.length, lengthOfNums2=nums2.length;
        ArrayList<ArrayList<Integer>>resultantList=new ArrayList<>();
        TreeMap<Integer, Integer>idToValueMap=new TreeMap<>();
        for(int i=0; i<lengthOfNums1; ++i){
            if(idToValueMap.containsKey(nums1[i][0])){
                int currentValue=idToValueMap.get(nums1[i][0]);
                idToValueMap.put(nums1[i][0], currentValue+nums1[i][1]);
            } else idToValueMap.put(nums1[i][0], nums1[i][1]);
        }
        for(int i=0; i<lengthOfNums2; ++i){
            if(idToValueMap.containsKey(nums2[i][0])){
                int currentValue=idToValueMap.get(nums2[i][0]);
                idToValueMap.put(nums2[i][0], currentValue+nums2[i][1]);
            } else idToValueMap.put(nums2[i][0], nums2[i][1]);
        }
        for(Map.Entry<Integer, Integer>entries: idToValueMap.entrySet()){
            ArrayList<Integer>listToAdd=new ArrayList<>();
            listToAdd.add(entries.getKey());
            listToAdd.add(entries.getValue());
            resultantList.add(listToAdd);
        }
        int[][] resultantArray=new int[resultantList.size()][2];
        for(int i=0; i<resultantList.size(); ++i){
            resultantArray[i][0]=resultantList.get(i).get(0);
            resultantArray[i][1]=resultantList.get(i).get(1);
        }
        return resultantArray;
    }
}

/*
Time Complexity: O((N1+N2)log(N1+N2))

Copying the (id, value) pairs from the array nums1 into the ordered map will take O(N1log⁡N1) time, 
as the insert operation in an ordered map has a time complexity of O(log⁡N).

Similarly, iterating through the pairs in the array nums2 to either add new entries 
or update existing values in the map will take O(N2log⁡N2).

Finally, iterating over the entries in the map and copying them to the mergedArray list takes 
O((N1+N2)log⁡(N1+N2)). Therefore, the overall time complexity of the algorithm is O((N1+N2)log⁡(N1+N2)).

-------

Space Complexity: O(N1+N2)

We will store each entry in the map keyToSum, and thus there can be at most (N1+N2) entries if both arrays have unique entries.

Space used to generate the output is generally not considered as part of the space complexity. 
Thus, the total space complexity is equal to O(N1+N2).
*/