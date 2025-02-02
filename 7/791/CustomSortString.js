/*
https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11
*/

/**
 * @param {string} order
 * @param {string} s
 * @return {string}
 */
var customSortString = function(order, s) {
    let szordr=order.length, szs=s.length;
    let seenidxs=new Set();
    let res="";
    for(let i=0; i<szordr; ++i){
        for(let j=0; j<szs; ++j){
            if(!seenidxs.has(j)){
                if(s[j]===order[i]){
                    res+=order[i];
                    seenidxs.add(j);
                }
            }
        }
    }
    for(let i=0; i<szs; ++i){
        if(!seenidxs.has(i)){
            res+=s[i];
        }
    }
    return res;
};