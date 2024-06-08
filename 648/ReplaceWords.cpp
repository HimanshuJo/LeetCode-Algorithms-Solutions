/*
https://leetcode.com/problems/replace-words/description/?envType=daily-question&envId=2024-06-07
*/

class Solution {
public:

    vector<string> splitAtSpaces(string &sentence){
        int sz=sentence.size(), idx=0;
        string curr="";
        vector<string>res;
        while(idx<=sz-1){
            curr+=sentence[idx];
            idx++;
            if(sentence[idx]==' '){
                res.push_back(curr);
                curr="";
                idx++;
            }
        }
        if(curr.length()>=1){
            res.push_back(curr);
        }
        return res;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        int sz=dictionary.size();
        vector<string>words=splitAtSpaces(sentence);
        string res="";
        for(auto &vals: words){
            int curvalslen=vals.length(), idx=0;
            string curfrmstr="";
            bool flag=false;
            while(true){
                if(idx>=curvalslen) break;
                curfrmstr+=vals[idx];
                auto itr=find(dictionary.begin(), dictionary.end(), curfrmstr);
                if(itr!=dictionary.end()){
                    flag=true;
                    string toad=*itr;
                    res+=toad;
                    res+=" ";
                    break;
                }
                idx++;
            }
            if(!flag){
                res+=vals;
                res+=" ";
            }
        }
        res.pop_back();
        return res;
    }
};