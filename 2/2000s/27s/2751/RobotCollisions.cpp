/*
https://leetcode.com/problems/robot-collisions/?envType=daily-question&envId=2026-04-01
*/

class Solution_TLE {
public:

    void eraseOpr(vector<pair<int, pair<int, char>>>&comb){
        auto itr=comb.begin();
        while(itr!=comb.end()){
            if(itr->first==-1){
                comb.erase(itr);
            } else itr++;
        }
    }

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int sz=directions.size(), idx=0;
        vector<pair<int, pair<int, char>>>comb;
        map<int, int>mp;
        for(int i=0; i<sz; ++i){
            comb.push_back(make_pair(positions[i], make_pair(healths[i], directions[i])));
            mp[positions[i]]=i;
        }
        sort(comb.begin(), comb.end());
        while(true){
            if(idx>=sz||idx+1>=sz) break;
            int curpos=comb[idx].first;
            char curdir=comb[idx].second.second, nxtdir=comb[idx+1].second.second;
            if(curdir=='R'&&nxtdir=='L'){
                int Rhealth=comb[idx].second.first, Lhealth=comb[idx+1].second.first;
                if(Rhealth==Lhealth){
                    comb[idx].first=-1;
                    comb[idx+1].first=-1;
                    eraseOpr(comb);
                } else if(Rhealth>Lhealth){
                    comb[idx+1].first=-1;
                    comb[idx].second.first-=1;
                    eraseOpr(comb);
                } else{
                    comb[idx].first=-1;
                    comb[idx+1].second.first-=1;
                    eraseOpr(comb);
                }
                idx=0;
                sz=comb.size();
            } else idx++;
        }
        vector<pair<int, int>>tmppr;
        int maxIdx=-1;
        for(auto &vals: comb){
            int curpos=vals.first, curhealth=vals.second.first;
            tmppr.push_back({mp[curpos], curhealth});
            maxIdx=max(maxIdx, mp[curpos]);
        }
        vector<int>res;
        res.resize(maxIdx+1, -1);
        for(auto &vals: tmppr){
            res[vals.first]=vals.second;
        }
        res.erase(remove(res.begin(), res.end(), -1), res.end());
        return res;
    }
};

// ------- ####### -------

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<tuple<int, int, char, int>>robots;
        int sz=positions.size();
        for(int i=0; i<sz; ++i){
            robots.push_back(make_tuple(positions[i], healths[i], directions[i], i));
        }
        sort(robots.begin(), robots.end());
        stack<int>stk;
        for(int i=0; i<sz; ++i){
            auto &itr=robots[i];
            int &currPosition=get<0>(itr), &currHealth=get<1>(itr);
            char &currDirection=get<2>(itr);
            int &currIdx=get<3>(itr);
            if(currDirection=='R'){
                stk.push(i);
            } else{
                while(!stk.empty()&&currHealth>0){
                    int idxToProcess=stk.top();
                    auto &itr2=robots[idxToProcess];
                    int &nxtPosition=get<0>(itr2), &nxtHealth=get<1>(itr2);
                    char &nxtDirection=get<2>(itr2);
                    if(nxtHealth<currHealth){
                        nxtHealth=0;
                        currHealth-=1;
                        stk.pop();
                    } else if(nxtHealth==currHealth){
                        nxtHealth=0;
                        currHealth=0;
                        stk.pop();
                        break;
                    } else{
                        currHealth=0;
                        nxtHealth-=1;
                        break;
                    }
                }
            }
        }
        vector<pair<int, int>>survivors;
        for(auto &vals: robots){
            int health=get<1>(vals);
            if(health>0){
                survivors.push_back({get<3>(vals), get<1>(vals)});
            }
        }
        sort(survivors.begin(), survivors.end());
        vector<int>res;
        for(auto &vals: survivors){
            res.push_back(vals.second);
        }
        return res;
    }
};