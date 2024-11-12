/*
https://leetcode.com/problems/most-beautiful-item-for-each-query/description/?envType=daily-question&envId=2024-11-12
*/

class Solution {
public:

    int binarySearch(vector<vector<int>>&items, int vals){
        int curmaxbeauty=0, left=0, right=items.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(items[mid][0]>vals){
                right=mid-1;
            } else{
                curmaxbeauty=max(curmaxbeauty, items[mid][1]);
                left=mid+1;
            }
        }
        return curmaxbeauty;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int sz=items.size(), curmaxbeauty=items[0][1];
        for(int i=0; i<sz; ++i){
            curmaxbeauty=max(curmaxbeauty, items[i][1]);
            items[i][1]=curmaxbeauty;
        }
        vector<int>res;
        for(auto &vals: queries){
            res.push_back(binarySearch(items, vals));
        }
        return res;
    }
};