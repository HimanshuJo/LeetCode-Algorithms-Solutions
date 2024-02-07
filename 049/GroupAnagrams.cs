/*
https://leetcode.com/problems/group-anagrams/description/?envType=daily-question&envId=2024-02-06
*/

public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        int sz=strs.Length;
        Dictionary<string, List<int>>mp=new Dictionary<string, List<int>>();
        for(int i=0; i<sz; ++i){
            string tmp=strs[i];
            char[] tmpchararr=tmp.ToCharArray();
            Array.Sort(tmpchararr);
            string sortedtmp=new string(tmpchararr);
            if(mp.ContainsKey(sortedtmp)){
                List<int>sortedtmpvals=mp[sortedtmp];
                sortedtmpvals.Add(i);
            } else{
                List<int>nwlist=new List<int>();
                nwlist.Add(i);
                mp[sortedtmp]=nwlist;
            }
        }
        IList<IList<string>>res=new List<IList<string>>();
        foreach((string key, List<int>vals) in mp){
            IList<string>curres=new List<string>();
            List<int>curmpvec=vals;
            int curentrysz=curmpvec.Count;
            for(int i=0; i<curentrysz; ++i){
                curres.Add(strs[curmpvec[i]]);
            }
            res.Add(curres);
        }
        return res;
    }
}