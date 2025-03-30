/*
https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/?envType=daily-question&envId=2025-03-21
*/

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, string>suppliesmp;
        for(auto &supply: supplies){
            suppliesmp[supply]=supply;
        }
        int sz=recipes.size();
        vector<string>res;
        set<int>seen;
        int count=101;
        while(count--){
            for(int i=0; i<sz; ++i){
                if(seen.find(i)==seen.end()){
                    string currecipe=recipes[i];
                    vector<string>currnd=ingredients[i];
                    bool flag=false;
                    for(auto &vals: currnd){
                        if(suppliesmp.find(vals)==suppliesmp.end()){
                            flag=true;
                            break;
                        }
                    }
                    if(!flag){
                        suppliesmp[currecipe]=currecipe;
                        res.push_back(currecipe);
                        seen.insert(i);
                    }
                }
            }
        }
        return res;
    }
};
