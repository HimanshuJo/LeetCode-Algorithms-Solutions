/*
https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11
*/

function customSortString(order: string, s: string): string {
    let szordr:number=order.length, szs:number=s.length;
    let seenidxs:Set<number>=new Set();
    let res:string="";
    for(let i:number=0; i<szordr; ++i){
        for(let j:number=0; j<szs; ++j){
            if(!seenidxs.has(j)){
                if(s[j]===order[i]){
                    res+=order[i];
                    seenidxs.add(j);
                }
            }
        }
    }
    for(let i:number=0; i<szs; ++i){
        if(!seenidxs.has(i)){
            res+=s[i];
        }
    }
    return res;
};