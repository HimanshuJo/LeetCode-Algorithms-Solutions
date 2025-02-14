/*
https://leetcode.com/problems/largest-local-values-in-a-matrix/description/?envType=daily-question&envId=2024-05-12
*/

/**
 * @param {number[][]} grid
 * @return {number[][]}
 */
var largestLocal = function(grid) {
    let rws=grid.length, cols=grid[0].length;
    let reslst=[];
    for(let i=0; i<rws; ++i){
        let curr=[];
        for(let j=0; j<cols; ++j){
            if(i+2<=rws-1&&j+2<=cols-1){
                let curmax=(1e8+7)*(-1);
                for(let k=i; k<i+3; ++k){
                    for(let l=j; l<j+3; ++l){
                        curmax=Math.max(curmax, grid[k][l]);
                    }
                }
                curr.push(curmax);
            } else break;
        }
        if(curr.length>=1) reslst.push(curr);
    }
    return reslst;
};