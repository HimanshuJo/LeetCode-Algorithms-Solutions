/*
https://leetcode.com/problems/relative-sort-array/description/?envType=daily-question&envId=2024-06-11
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>res;
        set<int>seen;
        for(auto &vals: arr2){
            while(true){
                auto itr=find(arr1.begin(), arr1.end(), vals);
                if(itr!=arr1.end()){
                    int idx=itr-arr1.begin();
                    arr1[idx]=-1;
                    res.push_back(vals);
                } else break;
            }
        }
        sort(arr1.begin(), arr1.end());
        for(int i=0; i<arr1.size(); ++i){
            if(arr1[i]!=-1) res.push_back(arr1[i]);
        }
        return res;
    }
};