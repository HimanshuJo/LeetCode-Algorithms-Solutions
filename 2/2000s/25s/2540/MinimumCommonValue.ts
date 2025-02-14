/*
https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09
*/

function getCommon(nums1: number[], nums2: number[]): number {
    let mp:Map<number, number>=new Map();
    let sz:number=nums1.length, sz2:number=nums2.length;
    for(let i:number=0; i<sz; ++i){
        if(mp.has(nums1[i])){
            mp.set(nums1[i], mp.get(nums1[i])+1);
        } else mp.set(nums1[i], 1);
    }
    for(let i:number=0; i<sz2; ++i){
        if(mp.has(nums2[i])) return nums2[i];
    }
    return -1;
};