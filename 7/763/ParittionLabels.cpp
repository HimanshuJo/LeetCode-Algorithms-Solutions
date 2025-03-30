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
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>lastIndicesOfChars_mp;
        int sz=s.size();
        for(int i=0; i<sz; ++i){
            lastIndicesOfChars_mp[s[i]]=i;
        }
        vector<int>res;
        int currentMaxLastPos=0, startSplit=0;
        for(int i=0; i<sz; ++i){
            char curr=s[i];
            int lstPosOfCurr=lastIndicesOfChars_mp[curr];
            currentMaxLastPos=max(currentMaxLastPos, lstPosOfCurr);
            if(currentMaxLastPos==i){
                res.push_back((i-startSplit)+1);
                startSplit=i+1;
            }
        }
        return res;
    }
};