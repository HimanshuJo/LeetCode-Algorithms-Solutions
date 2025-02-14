/*
https://leetcode.com/problems/largest-local-values-in-a-matrix/description/?envType=daily-question&envId=2024-05-12
*/

public class Solution {
    public int[][] LargestLocal(int[][] grid) {
        int rws=grid.Length, cols=grid[0].Length;
        List<List<int>>reslst=new List<List<int>>();
        for(int i=0; i<rws; ++i){
            List<int>curr=new List<int>();
            for(int j=0; j<cols; ++j){
                if(i+2<=rws-1&&j+2<=cols-1){
                    int curmax=int.MinValue;
                    for(int k=i; k!=i+3; ++k){
                        for(int l=j; l!=j+3; ++l){
                            curmax=Math.Max(curmax, grid[k][l]);
                        }
                    }
                    curr.Add(curmax);
                } else break;
            }
            if(curr.Count>=1){
                reslst.Add(curr);
            }
        }
        int[][] fnres=new int[reslst.Count][];
        for(int i=0; i<reslst.Count; ++i){
            int[] curarr=new int[reslst[i].Count];
            for(int j=0; j<reslst[i].Count; ++j){
                curarr[j]=reslst[i][j];
            }
            fnres[i]=curarr;
        }
        return fnres;
    }
}