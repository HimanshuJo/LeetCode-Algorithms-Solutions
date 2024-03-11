/*
https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11
*/

public class Solution {
    public string CustomSortString(string order, string s) {
        int szordr=order.Length, szs=s.Length;
        HashSet<int>seenidxs=new HashSet<int>();
        string res="";
        for(int i=0; i<szordr; ++i){
            for(int j=0; j<szs; ++j){
                if(!seenidxs.Contains(j)){
                    if(s[j]==order[i]){
                        res+=order[i];
                        seenidxs.Add(j);
                    }
                }
            }
        }
        for(int i=0; i<szs; ++i){
            if(!seenidxs.Contains(i)){
                res+=s[i];
            }
        }
        return res;
    }
}