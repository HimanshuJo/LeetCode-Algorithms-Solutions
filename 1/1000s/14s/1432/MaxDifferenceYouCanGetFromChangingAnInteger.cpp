/*
https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/?envType=daily-question&envId=2025-06-15
*/

class Solution {
public:
    int maxDiff(int num) {
        string tochk=to_string(num), tochk2=tochk;
        sort(tochk2.begin(), tochk2.end());
        int sz=tochk.size(), maxNum=INT_MIN, minNum=INT_MAX;
        for(int i=sz-1; i>=0; --i){
            char curr=tochk2[i];
            for(int i2=0; i2<=9; ++i2){
                string nwtofrm="";
                for(int i3=0; i3<sz; ++i3){
                    if(tochk[i3]!=curr){
                        nwtofrm+=tochk[i3];
                    } else nwtofrm+=to_string(i2);
                }
                if(stoi(nwtofrm)>=1&&nwtofrm[0]!='0'){
                    maxNum=max(maxNum, stoi(nwtofrm));
                    minNum=min(minNum, stoi(nwtofrm));
                }
            }
        }
        return maxNum-minNum;
    }
};