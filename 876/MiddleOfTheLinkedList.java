/*
https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07
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
    public ListNode middleNode(ListNode head) {
        List<Integer>all=new LinkedList<>();
        ListNode tmp=head, anthtmp=head;
        while(head!=null){
            all.add(head.val);
            head=head.next;
        }
        int sz=all.size(), count=sz/2;
        while(count-- >0){
            anthtmp=anthtmp.next;
        }
        return anthtmp;
    }
}