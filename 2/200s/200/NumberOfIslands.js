/*
https://leetcode.com/problems/number-of-islands/description/?envType=daily-question&envId=2024-04-19
*/

/**
 * @param {character[][]} grid
 * @return {number}
 */

var isValid=function(grid, seen, currw, curcol){
    let rws=grid.length, cols=grid[0].length;
    if(currw>=0&&curcol>=0&&currw<=rws-1&&curcol<=cols-1){
        if(grid[currw][curcol]==='1'){
            let tochk=currw.toString()+"#"+curcol.toString();
            if(!seen.has(tochk)){
                seen.add(tochk);
                return true;
            }
        }
    }
    return false;
}

var dfs=function(grid, seen, currw, curcol){
    if(!isValid(grid, seen, currw, curcol)) return;
    dfs(grid, seen, currw+1, curcol);
    dfs(grid, seen, currw-1, curcol);
    dfs(grid, seen, currw, curcol+1);
    dfs(grid, seen, currw, curcol-1);
    return;
}

var numIslands = function(grid) {
    let rws=grid.length, cols=grid[0].length, res=0;
    let seen=new Set();
    for(let i=0; i<rws; ++i){
        for(let j=0; j<cols; ++j){
            if(grid[i][j]==='1'){
                if(!seen.has((i.toString())+"#"+(j.toString()))){
                    res++;
                    dfs(grid, seen, i, j);
                }
            }
        }
    }
    return res;
};