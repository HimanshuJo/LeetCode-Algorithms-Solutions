/*
https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09
*/

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var getCommon = function(nums1, nums2) {
    let mp=new Map();
    let sz=nums1.length, sz2=nums2.length;
    for(let i=0; i<sz; ++i){
        if(mp.has(nums1[i])){
            mp.set(nums1[i], mp.get(nums1[i])+1);
        } else mp.set(nums1[i], 1);
    }
    for(let i=0; i<sz2; ++i){
        if(mp.has(nums2[i])) return nums2[i];
    }
    return -1;
};