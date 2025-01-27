/*
https://leetcode.com/problems/course-schedule-iv/description/?envType=daily-question&envId=2025-01-27
*/

class Solution {
public:

    void bfs(int numCourses, vector<vector<int>>&gr, map<int, vector<int>>&parentsMap, int root){
        queue<int>q;
        set<int>seen;
        q.push(root);
        seen.insert(root);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto curr=q.front();
                q.pop();
                if(gr[curr].size()>=1){
                    for(auto &vals: gr[curr]){
                        auto itr=parentsMap.find(vals);
                        if(itr!=parentsMap.end()){
                            auto currvec=parentsMap[vals];
                            currvec.push_back(curr);
                            parentsMap[vals]=currvec;
                        } else{
                            parentsMap[vals].push_back(curr);
                        }
                        if(seen.find(vals)==seen.end()){
                            seen.insert(vals);
                            q.push(vals);
                        }
                    }
                }
            }
        }
        for(int i=0; i<numCourses; ++i){
            if(seen.find(i)==seen.end()){
                q.push(i);
            }
        }
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto curr=q.front();
                q.pop();
                if(gr[curr].size()>=1){
                    for(auto &vals: gr[curr]){
                        auto itr=parentsMap.find(vals);
                        if(itr!=parentsMap.end()){
                            auto currvec=parentsMap[vals];
                            currvec.push_back(curr);
                            parentsMap[vals]=currvec;
                        } else{
                            parentsMap[vals].push_back(curr);
                        }
                        if(seen.find(vals)==seen.end()){
                            seen.insert(vals);
                            q.push(vals);
                        }
                    }
                }
            }
        }
        return;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>gr(numCourses);
        vector<int>rootCheck(numCourses, -1);
        for(auto &preqEntr: prerequisites){
            gr[preqEntr[0]].push_back(preqEntr[1]);
            rootCheck[preqEntr[1]]++;
        }
        int root=-1;
        for(int i=0; i<numCourses; ++i){
            if(rootCheck[i]==-1){
                root=i;
                break;
            }
        }
        map<int, vector<int>>parentsMap;
        bfs(numCourses, gr, parentsMap, root);
        for(int i=0; i<numCourses; ++i){
            auto itr=parentsMap.find(i);
            if(itr==parentsMap.end()){
                parentsMap[i].push_back(-1);
            }
        }
        vector<bool>res;
        for(auto &quer: queries){
            int curpar=quer[0], curchild=quer[1];
            bool flag=false;
            auto tochkvec=parentsMap[curchild];
            auto itr=find(tochkvec.begin(), tochkvec.end(), curpar);
            if(itr!=tochkvec.end()){
                flag=true;
            } else{
                vector<int>temp_=tochkvec;
                set<int>seen;
                while(true){
                    if(temp_.size()==0) break;
                    if(temp_.size()==1&&temp_[0]==-1) break;
                    vector<int>torep;
                    for(auto &vecentr: temp_){
                        auto newvec=parentsMap[vecentr];
                        auto secitr=find(newvec.begin(), newvec.end(), curpar);
                        if(secitr!=newvec.end()){
                            flag=true;
                            break;
                        }
                        for(auto &nwvecentr: newvec){
                            if(seen.find(nwvecentr)==seen.end()){
                                seen.insert(nwvecentr);
                                torep.push_back(nwvecentr);
                            }
                        }
                    }
                    if(flag) break;
                    temp_=torep;
                }
            }
            res.push_back(flag);
        }
        return res;
    }
};