/*
https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05
*/

/**
 * @param {string} s
 * @return {number}
 */

var customFind=function(s, ch, idx){
    let sz=s.length;
    if(idx>=sz) return false;
    for(let i=0; i<sz; ++i){
        if(i!=idx&&s[i]==ch) return true;
    }
    return false;
}

var firstUniqChar = function(s) {
    let sz=s.length;
    for(let i=0; i<sz; ++i){
        let flag=customFind(s, s[i], i);
        if(flag===false) return i;
    }
    return -1;
};