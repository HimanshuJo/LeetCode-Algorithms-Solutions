/*
https://leetcode.com/problems/fruit-into-baskets/description/?envType=daily-question&envId=2025-08-04
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int sz=fruits.size(), left=0, right=0, res=INT_MIN;
        unordered_map<int, int>mp;
        for(; right<sz; ++right){
            mp[fruits[right]]++;
            while(true){
                if(mp.size()<=2) break;
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            res=max(res, (right-left)+1);
        }
        return res;
    }
};
