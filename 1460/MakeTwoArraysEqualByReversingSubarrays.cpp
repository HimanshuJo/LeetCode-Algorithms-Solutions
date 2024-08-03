/*
https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/?envType=daily-question&envId=2024-08-03
*/

class Solution {
public:

    void performeReverse(vector<int>&arr, int bgn, int end){
        vector<int>tmp;
        for(int i=end; i>=bgn; --i){
            tmp.push_back(arr[i]);
        }
        int idx=0;
        for(int i=bgn; i<=end; ++i){
            arr[i]=tmp[idx++];
        }
    }

    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int sz=target.size();
        for(int i=0; i<sz; ++i){
            if(target[i]!=arr[i]){
                if(i+1>=sz) return false;
                int j=i, bgn=i;
                bool flag=false;
                while(true){
                    if(j>=sz) break;
                    if(arr[j]==target[i]){
                        flag=true;
                        break;
                    }
                    j++;
                }
                if(!flag) return false;
                performeReverse(arr, bgn, j);
            }
        }
        return arr==target;
    }
};