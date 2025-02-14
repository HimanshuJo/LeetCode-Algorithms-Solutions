/*
https://leetcode.com/problems/sort-the-jumbled-numbers/description/?envType=daily-question&envId=2024-07-24
*/

class CustomPair {
public:
    int var1;
    int var2;
    int var3;

public:
    CustomPair(int var1, int var2, int var3){
        this->var1=var1;
        this->var2=var2;
        this->var3=var3;
    }
};

class CustomComparator{
    public:

    bool operator()(const CustomPair A, const CustomPair B){
        if(A.var1==B.var1){
            return A.var3<B.var3;
        }
        return A.var1<B.var1;
    }
};

class Solution {
public:

    void trimPrexficZeros(string &str){
        int sz=str.size(), idx=0;
        while(true){
            if(str[idx]!='0') break;
            str[idx]='#';
            idx++;
            if(idx>=sz) break;
        }
        str.erase(remove(str.begin(), str.end(), '#'), str.end());
        if(str.size()==0) str="0";
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<CustomPair>vec;
        int sz=nums.size();
        for(int i=0; i<sz; ++i){
            int curnum=nums[i];
            string tochk=to_string(curnum);
            string tofrm="";
            for(auto &ch: tochk){
                tofrm+=to_string(mapping[(ch-'0')]);
            }
            trimPrexficZeros(tofrm);
            int nwint=stoi(tofrm);
            CustomPair pr(stoi(tofrm), curnum, i);
            vec.push_back(pr);
        }
        sort(vec.begin(), vec.end(), CustomComparator());
        vector<int>res;
        for(auto &vals: vec){
            res.push_back(vals.var2);
        }
        return res;
    }
};