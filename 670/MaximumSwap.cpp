/*
https://leetcode.com/problems/maximum-swap/description/?envType=daily-question&envId=2024-10-17
*/

class Solution {
public:
    int maximumSwap(int num) {
        string nmstr=to_string(num);
        int sz=nmstr.size(), res=INT_MIN;
        for(int i=0; i<sz; ++i){
            int left=i, right=sz-1;
            while(left<=right){
                string tochk=nmstr;
                char &atlft=tochk[left], &atright=tochk[right];
                swap(atlft, atright);
                int tochknm=stoi(tochk);
                res=max(res, tochknm);
                right--;
            }
        }
        return res;
    }
};