/*
https://leetcode.com/problems/find-the-pivot-integer/description/?envType=daily-question&envId=2024-03-13
*/

function isValid(num:number, maxLim:number):boolean{
    let ttlsm:number=Math.floor(maxLim*(maxLim+1))/2, 
        lftsm:number=Math.floor(num*(num+1))/2, 
        rghtsm:number=(ttlsm-lftsm)+num;
    return lftsm===rghtsm;
}

function pivotInteger(n: number): number {
    for(let i:number=1; i<=n; ++i){
        if(isValid(i, n)) return i;
    }
    return -1;
};