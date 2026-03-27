/*
https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/?envType=daily-question&envId=2026-03-27
*/

class Solution {

    public static void shiftRight(ArrayList<Integer>matrow, int cols){
        int prevElement=matrow.get(0);
        matrow.set(0, matrow.get(cols-1));
        for(int j=1; j<=cols-1; ++j){
            int nextElement=matrow.get(j);
            matrow.set(j, prevElement);
            prevElement=nextElement;
        }
    }

    public static void shiftLeft(ArrayList<Integer>matrow, int cols){
        int prevElement=matrow.get(cols-1);
        matrow.set(cols-1, matrow.get(0));
        for(int j=cols-2; j>=0; --j){
            int nextElement=matrow.get(j);
            matrow.set(j, prevElement);
            prevElement=nextElement;
        }
    }

    public boolean areSimilar(int[][] mat, int k) {
        int rows=mat.length, cols=mat[0].length;
        ArrayList<ArrayList<Integer>>matClone=new ArrayList<>();
        for(int i=0; i<rows; ++i){
            matClone.add(new ArrayList<>());
            for(int j=0; j<cols; ++j){
                matClone.get(i).add(mat[i][j]);
            }
        }
        while(k-- >0){
            for(int i=0; i<rows; ++i){
                if(i%2==0){
                    shiftLeft(matClone.get(i), cols);
                } else {
                    shiftRight(matClone.get(i), cols);
                }
            }
        }
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(matClone.get(i).get(j)!=mat[i][j]) return false;
            }
        }
        return true;
    }
}