/*
https://leetcode.com/problems/reverse-prefix-of-word/description/?envType=daily-question&envId=2024-05-01
*/

function reversePrefix(word: string, ch: string): string {
    let res:string="";
    let sz:number=word.length, idxtogt:number=0;
    while(true){
        if(idxtogt==sz||(word[idxtogt]===ch)) break;
        idxtogt++;
    }
    if(idxtogt>=sz) return word;
    for(let i:number=idxtogt; i>=0; --i){
        res+=word[i];
    }
    if(idxtogt+1<=sz-1){
        for(let i:number=idxtogt+1; i<sz; ++i){
            res+=word[i];
        }
    }
    return res;
};