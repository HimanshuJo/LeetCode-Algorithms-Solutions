/*
https://leetcode.com/problems/merge-in-between-linked-lists/description/?envType=daily-question&envId=2024-03-20
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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        int count=0, diff=(b-a)+2;
        ListNode tmplst1=list1, res=tmplst1, tmplst2=list1;
        ListNode tmpl2lst2=list2;
        while(count!=a-1){
            tmplst1=tmplst1.next;
            tmplst2=tmplst2.next;
            count++;
        }
        while(diff!=0){
            tmplst2=tmplst2.next;
            diff--;
        }
        while(tmpl2lst2.next!=null){
            tmpl2lst2=tmpl2lst2.next;
        }
        tmpl2lst2.next=tmplst2;
        tmplst1.next=list2;
        return res;
    }
}