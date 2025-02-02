/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/description/?envType=daily-question&envId=2024-07-02
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        for(auto &vals: nums1){
            auto itr=find(nums2.begin(), nums2.end(), vals);
            if(itr!=nums2.end()){
                res.push_back(vals);
                int idx=itr-nums2.begin();
                nums2[idx]=-1;
            }
        }
        return res;
    }
};