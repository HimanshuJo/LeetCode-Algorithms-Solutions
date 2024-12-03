class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int sz1=s.size(), sz2=spaces.size(), curspaceidx=0;
        string res="";
        res.reserve(sz1+sz2);
        for(int i=0; i<sz1; ++i){
            if(curspaceidx<sz2&&i==spaces[curspaceidx]){
                res+=' ';
                res+=s[i];
                curspaceidx++;
            } else{
                res+=s[i];
            }
        }
        return res;
    }
};
