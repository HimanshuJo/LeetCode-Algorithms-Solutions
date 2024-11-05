/*
https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/?envType=daily-question&envId=2024-10-25
*/

class CustomComparator{

    public:
    bool operator()(string A, string B){
        return A.size()<B.size();
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), CustomComparator());
        set<string>seen;
        vector<string>res;
        for(auto &vals: folder){
            if(seen.find(vals)!=seen.end()) continue;
            else{
                int sz=vals.size(), idx=0;
                string curr="";
                curr+=vals[0];
                idx++;
                bool flag=false;
                while(idx<=sz-1){
                    while(true){
                        if(idx>=sz) break;
                        if(vals[idx]=='/'){
                            if(seen.find(curr)!=seen.end()){
                                flag=true;
                                break;
                            }
                            curr+="/";
                            idx++;
                            break;
                        }
                        curr+=vals[idx];
                        idx++;
                    }
                    if(flag) break;
                }
                if(!flag){
                    res.push_back(vals);
                    seen.insert(vals);
                }
            }
        }
        return res;
    }
};