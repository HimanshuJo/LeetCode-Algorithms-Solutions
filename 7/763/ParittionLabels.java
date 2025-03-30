/*
https://leetcode.com/problems/partition-labels/description/?envType=daily-question&envId=2025-03-30
*/

/*
Time complexity: O(n)

The algorithm iterates through the string twice. 
The first loop takes O(n) time to store the index of the last occurrence of each character 
in the lastOccurrence array. 

The second loop, also running in O(n) time, determines the partitions by tracking the end of 
each partition using the lastOccurrence array. Since both loops are linear and independent, 
the overall time complexity is O(n).
*/

/*
Space complexity: O(k)

In the general case, the space required is proportional to the number of distinct letters in s. 
Thus, for an arbitrary alphabet (a set of distinct values) of size k, 
the space complexity of the algorithm is O(k).

The partitionSizes array, which stores the lengths of the partitions, is part of the output 
and is not included in the space complexity analysis, since it is required by the problem statement.
*/
class Solution {
    public List<Integer> partitionLabels(String s) {
        HashMap<Character, Integer>lastIndicesOfCharsMap=new HashMap<>();
        int lengthOfS=s.length();
        for(int i=0; i<lengthOfS; ++i){
            lastIndicesOfCharsMap.put(s.charAt(i), i);
        }
        ArrayList<Integer>resultantListWithSizes=new ArrayList<>();
        int currentMaxLastPosition=0, startOfCurrentSplit=0;
        for(int i=0; i<lengthOfS; ++i){
            char currentChar=s.charAt(i);
            int lastPositionOfCurr=lastIndicesOfCharsMap.get(currentChar);
            currentMaxLastPosition=Math.max(currentMaxLastPosition, lastPositionOfCurr);
            if(currentMaxLastPosition==i){
                resultantListWithSizes.add((i-startOfCurrentSplit)+1);
                startOfCurrentSplit=i+1;
            }
        }
        return resultantListWithSizes;
    }
}