/*
https://leetcode.com/problems/reorder-list/description/?envType=daily-question&envId=2024-03-23
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
    public void ReorderList(ListNode head) {
        if(head.next==null) return;
        ListNode res=head;
        ListNode anthhead=head;
        List<int>all=new List<int>();
        while(anthhead!=null){
            all.Add(anthhead.val);
            anthhead=anthhead.next;
        }
        int sz=all.Count, left=1, right=sz-2, count=0;
        ListNode tmpres=res;
        tmpres.next=new ListNode(all[sz-1]);
        tmpres=tmpres.next;
        while(left<=right){
            if(count%2==0){
                tmpres.next=new ListNode(all[left++]);
            } else{
                tmpres.next=new ListNode(all[right--]);
            }
            tmpres=tmpres.next;
            count++;
        }
    }
}