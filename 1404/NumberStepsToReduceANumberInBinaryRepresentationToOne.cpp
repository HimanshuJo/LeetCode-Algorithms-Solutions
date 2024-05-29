/*
https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2024-05-29
*/

class Solution {
public:

    string addOneToBinaryString(string &binaryStr) {
        string result = binaryStr;
        int n = result.length();
        for (int i = n - 1; i >= 0; --i) {
            if (result[i] == '0') {
                result[i] = '1';
                return result;
            } else {
                result[i] = '0';
            }
        }
        result.insert(result.begin(), '1');
        return result;
    }

    int numSteps(string s) {
        int res=0;
        while(true){
            if(s=="1") break;
            int lstdgt=s[s.size()-1]-'0';
            if(lstdgt==1){
                s=addOneToBinaryString(s);
            } else s.pop_back();
            res++;
        }
        return res;
    }
};
