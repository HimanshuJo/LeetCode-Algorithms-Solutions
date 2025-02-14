/*
https://leetcode.com/problems/find-the-pivot-integer/description/?envType=daily-question&envId=2024-03-13
*/

/**
 * @param {number} n
 * @return {number}
 */

var isValid=function(num, maxLim){
    let ttlsm=Math.floor(maxLim*(maxLim+1))/2, lftsm=Math.floor(num*(num+1))/2, rghtsm=(ttlsm-lftsm)+num;
    return lftsm===rghtsm;
}

var pivotInteger = function(n) {
    for(let i=1; i<=n; ++i){
        if(isValid(i, n)) return i;
    }
    return -1;
};