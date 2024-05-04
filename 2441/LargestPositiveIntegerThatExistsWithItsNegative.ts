/*
https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=daily-question&envId=2024-05-02
*/

function customSearch(nums:number[], val:number):boolean{
    let left:number=0, right:number=nums.length-1;
    while(left<=right){
        if(nums[left++]===-val) return true;
        else if(nums[right--]===-val) return true;
    }
    return false;
}

function findMaxK(nums: number[]): number {
    nums.sort((A, B)=>(A-B));
    let sz:number=nums.length;
    for(let i:number=sz-1; i>=0; --i){
        let curr:number=nums[i];
        if(curr>=0){
            let flag:boolean=customSearch(nums, curr);
            if(flag===true) return curr;
        }
    }
    return -1;
};