/*
https://leetcode.com/problems/decode-the-slanted-ciphertext/?envType=daily-question&envId=2026-04-04
*/

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int lengthOfText=encodedText.length(), cols=lengthOfText/rows;
        string res="";
        for(int startCol=0; startCol<cols; ++startCol){
            int i=0, j=startCol;
            while(i<rows&&j<cols){
                res+=encodedText[i*cols+j];
                ++i, ++j;
            }
        }
        while(!res.empty()&&res.back()==' '){
            res.pop_back();
        }
        return res;
    }
};