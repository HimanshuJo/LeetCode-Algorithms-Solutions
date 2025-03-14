/*
https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/?envType=daily-question&envId=2025-03-14
*/

class Solution {
public:

    bool isValid(vector<int>&candies, long long k, int val){
        long long count=0, splits=0;
        for(int i=0; i<candies.size(); ++i){
            if(candies[i]<val) continue;
            count+=candies[i];
            splits+=candies[i]/val;
        }
        return count>=k&&splits>=k;
    }

    int binarySearch(vector<int>&candies, long long k){
        sort(candies.begin(), candies.end());
        int left=1, right=candies[candies.size()-1], res=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValid(candies, k, mid)){
                res=mid;
                left=mid+1;
            } else{
                right=mid-1;
            }
        }
        return res;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        return binarySearch(candies, k);
    }
};
