/*
https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/?envType=daily-question&envId=2025-03-02
*/

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int sz1=nums1.size(), sz2=nums2.size();
        vector<vector<int>>res;
        map<int, int>mp;
        for(auto &vals: nums1){
            mp[vals[0]]+=vals[1];
        }
        for(auto &vals: nums2){
            mp[vals[0]]+=vals[1];
        }
        for(auto &mpentries: mp){
            res.push_back({mpentries.first, mpentries.second});
        }
        return res;
    }
};

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

// ------- ******* -------

class Solution_optimal {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int sz1=nums1.size(), sz2=nums2.size();
        vector<vector<int>>res;
        int ptr1, ptr2;
        for(ptr1=0, ptr2=0; ptr1<sz1, ptr2<sz2; ){
            if(ptr1>=sz1||ptr2>=sz2) break;
            if(nums1[ptr1][0]==nums2[ptr2][0]){
                res.push_back({nums1[ptr1][0], nums1[ptr1][1]+nums2[ptr2][1]});
                ptr1++, ptr2++;
            } else if(nums1[ptr1][0]<nums2[ptr2][0]){
                res.push_back({nums1[ptr1][0], nums1[ptr1][1]});
                ptr1++;
            } else{
                res.push_back({nums2[ptr2][0], nums2[ptr2][1]});
                ptr2++;
            }
        }
        while(ptr1<sz1){
            res.push_back({nums1[ptr1][0], nums1[ptr1][1]});
            ptr1++;
        }
        while(ptr2<sz2){
            res.push_back({nums2[ptr2][0], nums2[ptr2][1]});
            ptr2++;
        }
        return res;
    }
};

/*

Time complexity: O(N1+N2)

In the while loop, we either increment one of the two pointers or increment both when the id is the same.

Thus, we will iterate over each pair in the two arrays at most once. 

Also, all operations like insertion in the list is O(1) and hence the total time complexity is equal to O(N1+N2)

-------

Space complexity: O(N1+N2)

No extra space is required apart from the array required to store the result 
which is not considered as part of the space complexity and hence the total space complexity is equal to O(N1+N2).
*/