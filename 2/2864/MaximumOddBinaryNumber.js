/*
https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01
*/

/**
 * @param {string} s
 * @return {string}
 */
var maximumOddBinaryNumber = function(s) {
    let countOnes=0, countZeros=0, sz=s.length;
    for(let i=0; i<sz; ++i){
        if(s[i]=='0'){
            countZeros++;
        } else countOnes++;
    }
    let res="";
    while(countOnes!=1){
        res+="1";
        countOnes--;
    }
    while(countZeros!=0){
        res+="0";
        countZeros--;
    }
    res+="1";
    return res;
};