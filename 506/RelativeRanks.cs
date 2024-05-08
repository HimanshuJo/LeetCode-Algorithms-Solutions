/*
https://leetcode.com/problems/relative-ranks/submissions/1252524434/?envType=daily-question&envId=2024-05-08
*/

public class Solution {

    public int binarySearch(List<int>lst, int val){
        int left=0, right=lst.Count-1, sz=lst.Count;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(lst[mid]==val) return sz-mid;
            else if(lst[mid]>val) right=mid-1;
            else left=mid+1;
        }
        return -1;
    }

    public string[] FindRelativeRanks(int[] score) {
        List<int>tmp=new List<int>();
        int score_sz=score.Length;
        for(int i=0; i<score_sz; ++i){
            tmp.Add(score[i]);
        }
        tmp.Sort((A, B)=>(A-B));
        Dictionary<int, string>rnkNdMdl_dict=new Dictionary<int, string>();
        int idx=score_sz-1;
        if(score_sz>=1){
            rnkNdMdl_dict[tmp[idx]]="Gold Medal";
        }
        if(score_sz>=2){
            idx--;
            rnkNdMdl_dict[tmp[idx]]="Silver Medal";
        }
        if(score_sz>=3){
            idx--;
            rnkNdMdl_dict[tmp[idx]]="Bronze Medal";
        }
        string[] res=new string[score_sz];
        for(int i=0; i<score_sz; ++i){
            if(rnkNdMdl_dict.ContainsKey(score[i])){
                res[i]=rnkNdMdl_dict[score[i]];
            } else{
                int flag_idx=binarySearch(tmp, score[i]);
                res[i]=flag_idx.ToString();
            }
        }
        return res;
    }
}