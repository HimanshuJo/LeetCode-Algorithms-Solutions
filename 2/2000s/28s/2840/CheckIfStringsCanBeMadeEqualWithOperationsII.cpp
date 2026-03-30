/*
https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/?envType=daily-question&envId=2026-03-30
*/

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int sz=s1.length();
        vector<int>countEvenS1(127, 0), countEvenS2(127, 0), countOddS1(127, 0), countOddS2(127, 0);
        for(int i=0; i<sz; ++i){
            if(i%2==0){
                countEvenS1[s1[i]-'a']++;
                countEvenS2[s2[i]-'a']++;
            } else{
                countOddS1[s1[i]-'a']++;
                countOddS2[s2[i]-'a']++;
            }
        }
        for(int i=0; i<127; ++i){
            if(countEvenS1[i]!=countEvenS2[i]||(countOddS1[i]!=countOddS2[i])) return false;
        }
        return true;
    }
};