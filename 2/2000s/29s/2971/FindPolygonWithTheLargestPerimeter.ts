/*
https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15
*/

function largestPerimeter(nums: number[]): number {
    nums.sort((A, B)=>(A-B));
    let sz:number=nums.length;
    for(let i:number=sz-1; i>=2; --i){
        let curval:number=nums[i], cursm:number=0;
        for(let j:number=0; j<i; ++j){
            cursm+=nums[j];
        }
        if(cursm>curval) return cursm+curval;
    }
    return -1;
};