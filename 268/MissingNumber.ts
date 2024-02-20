/*
https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20
*/

function binarySearch(nums:number[], val:number):boolean{
    let left:number=0, right:number=nums.length-1;
    while(left<=right){
        let mid:number=Math.floor(left+(right-left)/2);
        if(nums[mid]===val) return true;
        else if(nums[mid]>val){
            right=mid-1;
        } else left=mid+1;
    }
    return false;
};

function find(nums:number[], val:number):boolean{
    return binarySearch(nums, val);
};

function missingNumber(nums: number[]): number {
    nums.sort((A, B)=>(A-B));
    let sz:number=nums.length;
    for(let i:number=0; i<=sz; ++i){
        let flag:boolean=find(nums, i);
        if(flag===false) return i;
    }
    return -1;
};