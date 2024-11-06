/*
https://leetcode.com/problems/find-if-array-can-be-sorted/description/?envType=daily-question&envId=2024-11-06
*/

class Solution {
public:

    string toBinary(int number){
        string res="";
        while(number!=1){
            int quo=number/2, rem=number%2;
            res+=to_string(rem);
            number=quo;
        }
        res+="1";
        return res;
    }

    bool isValid(int first, int second){
        string bnfirst=toBinary(first), bnsecond=toBinary(second);
        int count1=0, count2=0;
        for(auto &ch: bnfirst){
            if(ch=='1') count1++;
        }
        for(auto &ch: bnsecond){
            if(ch=='1') count2++;
        }
        return count1==count2;
    }

    bool canSortArray(vector<int>& nums) {
        int sz=nums.size();
        vector<int>temp=nums;
        sort(temp.begin(), temp.end());
        for(int i=0; i<sz; ++i){
            if(i-1>=0){
                for(int j=i; j>0; --j){
                    int &curr=nums[j], &prev=nums[j-1];
                    if(curr<prev){
                        if(isValid(curr, prev)){
                            swap(curr, prev);
                        }
                    }
                }
            }
        }
        return nums==temp;
    }
};