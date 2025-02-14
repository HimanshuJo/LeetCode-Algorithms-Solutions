/*
https://leetcode.com/problems/reverse-prefix-of-word/description/?envType=daily-question&envId=2024-05-01
*/

/**
 * @param {string} word
 * @param {character} ch
 * @return {string}
 */
var reversePrefix = function(word, ch) {
    let res="";
    let sz=word.length, idxtogt=0;
    while(true){
        if(idxtogt==sz||(word[idxtogt]===ch)) break;
        idxtogt++;
    }
    if(idxtogt>=sz) return word;
    for(let i=idxtogt; i>=0; --i){
        res+=word[i];
    }
    if(idxtogt+1<=sz-1){
        for(let i=idxtogt+1; i<sz; ++i){
            res+=word[i];
        }
    }
    return res;
};