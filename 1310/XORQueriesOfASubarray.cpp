/*
https://leetcode.com/problems/xor-queries-of-a-subarray/description/?envType=daily-question&envId=2024-09-13
*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>res;
        for(auto &query: queries){
            int left=query[0], right=query[1], curxor=0;
            for(int i=left; i<=right; ++i){
                curxor^=arr[i];
            }
            res.push_back(curxor);
        }
        return res;
    }
};