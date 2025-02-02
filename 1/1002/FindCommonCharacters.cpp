/*
https://leetcode.com/problems/find-common-characters/description/?envType=daily-question&envId=2024-06-05
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>res;
        string bgn=words[0];
        for(auto &ch: bgn){
            bool flag=false;
            vector<int>allidxs;
            for(int i=1; i<words.size(); ++i){
                string curr=words[i];
                auto itr=curr.find(ch);
                if(itr!=string::npos){
                    int curidx=itr;
                    allidxs.push_back(curidx);
                } else{
                    flag=true;
                    break;
                }
            }
            if(!flag){
                string toad="";
                toad+=ch;
                res.push_back(toad);
                for(int i=1; i<words.size(); ++i){
                    words[i][allidxs[i-1]]='#';
                }
            }
        }
        return res;
    }
};