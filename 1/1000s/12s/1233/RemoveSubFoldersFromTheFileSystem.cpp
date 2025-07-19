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

// ####### ------- #######

class Solution2 {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string>res;
        for(auto &paths: folder){
            if(res.size()>=1){
                string curbck=res.back();
                string tochk=paths.substr(0, curbck.size());
                if(tochk!=curbck||paths[curbck.size()]!='/'){
                    res.push_back(paths);
                }
            } else{
                res.push_back(paths);
            }
        }
        return res;
    }
};

// ####### ------- #######

class CustomComparator{
    public:
    bool operator()(const string &A, const string &B){
        return A.length()<B.length();
    }
};

class Solution_TLE {
public:

    bool isSub(string par, string tochk){
        int sz=tochk.size(), idx=1;
        string tofrm="";
        tofrm+=tochk[0];
        for(; idx<=sz-1; ){
            tofrm+=tochk[idx];
            if(tofrm==par) return true;
            ++idx;
            while(true){
                if(tochk[idx]=='/') break;
                tofrm+=tochk[idx];
                idx++;
                if(idx>=sz) break;
            }
            if(tofrm==par) return true;
        }
        return false;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), CustomComparator());
        for(int i=0; i<folder.size(); ++i){
            string curr=folder[i];
            for(int j=0; j<folder.size(); ++j){
                if(i!=j){
                    string next=folder[j];
                    if(isSub(curr, next)){
                        folder[j]="#";
                    }
                }
            }
            folder.erase(remove(folder.begin(), folder.end(), "#"), folder.end());
        }
        return folder;
    }
};