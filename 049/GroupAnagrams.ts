/*
https://leetcode.com/problems/group-anagrams/description/?envType=daily-question&envId=2024-02-06
*/

function groupAnagrams(strs: string[]): string[][] {
    let sz:number=strs.length;
    let mp:Map<string, number[]>=new Map();
    for(let i:number=0; i<sz; ++i){
        let tmp:string=strs[i];
        let sortedtmp:string=tmp.split('').sort().join('');
        if(mp.has(sortedtmp)){
            let curarr:number[]=mp.get(sortedtmp);
            curarr.push(i);
            mp.set(sortedtmp, curarr);
        } else mp.set(sortedtmp, [i]);
    }
    let res:string[][]=[];
    for(let [key, vals] of mp){
        let curres:string[]=[];
        let curmpvec=vals;
        let curentrysz:number=curmpvec.length;
        for(let i:number=0; i<curentrysz; ++i){
            curres.push(strs[curmpvec[i]]);
        }
        res.push(curres);
    }
    return res;
};