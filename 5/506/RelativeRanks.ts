/*
https://leetcode.com/problems/relative-ranks/submissions/1252524434/?envType=daily-question&envId=2024-05-08
*/

function binarySearch(score, val){
    let left:number=0, right:number=score.length-1, sz:number=score.length;
    while(left<=right){
        let mid:number=left+(right-left)//2;
        if(score[mid]===val) return sz-mid;
        else if(score[mid]>val) right=mid-1;
        else left=mid+1;
    }
    return -1;
}

function findRelativeRanks(score: number[]): string[] {
    let tmp:number[]=[];
    let score_sz:number=score.length;
    for(let i:number=0; i<score_sz; ++i){
        tmp.push(score[i]);
    }
    tmp.sort((A, B)=>(A-B));
    let rnkNdMdl_dict:Map<number, string>=new Map();
    let idx:number=score_sz-1;
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
    let res:string[]=[];
    for(let i:number=0; i<score_sz; ++i){
        if(rnkNdMdl_dict.has(score[i])){
            res.push(rnkNdMdl_dict.get(score[i]));
        } else{
            let flag_idx=binarySearch(tmp, score[i]);
            res.push(flag_idx.toString());
        }
    }
    return res;
};