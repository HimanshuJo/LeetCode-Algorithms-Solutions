/*
https://leetcode.com/problems/relative-ranks/submissions/1252524434/?envType=daily-question&envId=2024-05-08
*/

/**
 * @param {number[]} score
 * @return {string[]}
 */

var binarySearch=function(score, val){
    let left=0, right=score.length-1, sz=score.length;
    while(left<=right){
        let mid=left+(right-left)//2;
        if(score[mid]===val) return sz-mid;
        else if(score[mid]>val) right=mid-1;
        else left=mid+1;
    }
    return -1;
}

var findRelativeRanks = function(score) {
    let tmp=[];
    let score_sz=score.length;
    for(let i=0; i<score_sz; ++i){
        tmp.push(score[i]);
    }
    tmp.sort((A, B)=>(A-B));
    let rnkNdMdl_dict=new Map();
    let idx=score_sz-1;
    if(score_sz>=1){
        rnkNdMdl_dict.set(tmp[idx], "Gold Medal");
    }
    if(score_sz>=2){
        idx--;
        rnkNdMdl_dict.set(tmp[idx], "Silver Medal");
    }
    if(score_sz>=3){
        idx--;
        rnkNdMdl_dict.set(tmp[idx], "Bronze Medal");
    }
    let res=[];
    for(let i=0; i<score_sz; ++i){
        if(rnkNdMdl_dict.has(score[i])){
            res.push(rnkNdMdl_dict.get(score[i]));
        } else{
            let flag_idx=binarySearch(tmp, score[i]);
            res.push(flag_idx.toString());
        }
    }
    return res;
};