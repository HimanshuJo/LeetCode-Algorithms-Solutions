/*
https://leetcode.com/problems/count-largest-group/description/?envType=daily-question&envId=2025-04-23
*/

class Solution {
public:
    int countLargestGroup(int n) {
        map<int, vector<int>>mp;
        map<int, int>countmp;
        for(int i=1; i<=n; ++i){
            string tochk=to_string(i);
            int sz=tochk.size(), cursm=0;
            for(int j=0; j<sz; ++j){
                cursm+=(tochk[j]-'0');
            }
            mp[cursm].push_back(i);
        }
        for(auto &entries: mp){
            countmp[(entries.second).size()]++;
        }
        auto itr=countmp.end();
        itr--;
        return itr->second;
    }
};