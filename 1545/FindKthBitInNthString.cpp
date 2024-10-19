/*
https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/?envType=daily-question&envId=2024-10-19
*/

class Solution {
public:

    string invert(string str){
        string res="";
        for(int i=0; i<str.length(); ++i){
            if(str[i]=='0') res+="1";
            else res+="0";
        }
        return res;
    }

    char findKthBit(int n, int k) {
        vector<string>all;
        string prev="0";
        int count=1;
        all.push_back(prev);
        while(count!=n){
            string invertPrev=invert(prev);
            reverse(invertPrev.begin(), invertPrev.end());
            string next=prev+"1"+invertPrev;
            all.push_back(next);
            prev=next;
            count++;
        }
        return all[n-1][k-1];
    }
};