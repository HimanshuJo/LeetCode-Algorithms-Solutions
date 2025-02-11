/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        List<int>all=new List<int>();
        while(head!=null){
            all.Add(head.val);
            head=head.next;
        }
        int todel=all.Count-n;
        all.RemoveAt(todel);
        if(all.Count>=1){
            ListNode res=new ListNode(all[0], null);
            ListNode nxt=res;
            for(int i=1; i<all.Count; ++i){
                ListNode nw=new ListNode(all[i]);
                nxt.next=nw;
                nxt=nxt.next;
            }
            return res;
        }
        return null;
    }
}