/*
https://leetcode.com/problems/merge-nodes-in-between-zeros/description/?envType=daily-question&envId=2024-07-04
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
    public ListNode mergeNodes(ListNode head) {
        ArrayList<Integer>listOfAllNodesInHead=new ArrayList<>();
        ArrayList<Integer>listWithSumOfAllMergedNodes=new ArrayList<>();
        while(head!=null){
            listOfAllNodesInHead.add(head.val);
            head=head.next;
        }
        int beginIndex=1, currentSumOfNodesBetweenZeros=0, sizeOfListAllNodes=listOfAllNodesInHead.size();
        while(true){
            if(beginIndex>=sizeOfListAllNodes) break;
            if(listOfAllNodesInHead.get(beginIndex)==0){
                listWithSumOfAllMergedNodes.add(currentSumOfNodesBetweenZeros);
                currentSumOfNodesBetweenZeros=0;
            } else{
                currentSumOfNodesBetweenZeros+=listOfAllNodesInHead.get(beginIndex);
            }
            beginIndex++;
        }
        ListNode resultantHead=new ListNode(listWithSumOfAllMergedNodes.get(0));
        ListNode tailForResultantHead=resultantHead;
        int sizeOfSumOfAllMergedNodes=listWithSumOfAllMergedNodes.size();
        for(int i=1; i<sizeOfSumOfAllMergedNodes; ++i){
            ListNode newNode=new ListNode(listWithSumOfAllMergedNodes.get(i));
            tailForResultantHead.next=newNode;
            tailForResultantHead=tailForResultantHead.next;
        }
        return resultantHead;
    }
}