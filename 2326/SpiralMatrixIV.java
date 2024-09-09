/*
httpsleetcode.comproblemsspiral-matrix-iv
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] resultantMatrixAsArr=new int[m][n];
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                resultantMatrixAsArr[i][j]=-1;
            }
        }
        ArrayList<Integer>directions=new ArrayList<>();
        for(int i=1; i<=4; ++i){
            directions.add(i);
        }
        int beginIndex=0, currentRow=0, currentColumn=0;
        HashSet<String>seenIndexes=new HashSet<>();
        while(head!=null){
            int currentValue=head.val, currentDirection=directions.get(beginIndex);
            resultantMatrixAsArr[currentRow][currentColumn]=currentValue;
            seenIndexes.add(String.valueOf(currentRow)+"#"+String.valueOf(currentColumn));
            if(currentDirection==1){
                currentColumn++;
                if(seenIndexes.contains(String.valueOf(currentRow)+"#"+String.valueOf(currentColumn))||currentColumn>=n){
                    currentColumn--;
                    currentRow++;
                    beginIndex++;
                    if(beginIndex>=directions.size()){
                        beginIndex=0;
                    }
                }
            } else if(currentDirection==2){
                currentRow++;
                if(seenIndexes.contains(String.valueOf(currentRow)+"#"+String.valueOf(currentColumn))||currentRow>=m){
                    currentRow--;
                    currentColumn--;
                    beginIndex++;
                    if(beginIndex>=directions.size()){
                        beginIndex=0;
                    }
                }
            } else if(currentDirection==3){
                currentColumn--;
                if(seenIndexes.contains(String.valueOf(currentRow)+"#"+String.valueOf(currentColumn))||currentColumn<0){
                    currentColumn++;
                    currentRow--;
                    beginIndex++;
                    if(beginIndex>=directions.size()){
                        beginIndex=0;
                    }
                }
            } else if(currentDirection==4){
                currentRow--;
                if(seenIndexes.contains(String.valueOf(currentRow)+"#"+String.valueOf(currentColumn))||currentRow<0){
                    currentRow++;
                    currentColumn++;
                    beginIndex++;
                    if(beginIndex>=directions.size()){
                        beginIndex=0;
                    }
                }
            }
            head=head.next;
        }
        return resultantMatrixAsArr;
    }
}