/*
https://leetcode.com/problems/maximum-odd-binary-number/submissions/1190581163/?envType=daily-question&envId=2024-03-01
*/

function maximumOddBinaryNumber(s: string): string {
    let countOnes:number=0, countZeros:number=0, sz:number=s.length;
    for(let i:number=0; i<sz; ++i){
        if(s[i]=='0'){
            countZeros++;
        } else countOnes++;
    }
    let res:string="";
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