/*
https://leetcode.com/problems/reverse-linked-list/description/?envType=daily-question&envId=2024-03-21
*/

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function reverseList(head: ListNode | null): ListNode | null {
    let prev:ListNode|null=null;
    while(head!==null){
        let curnext:ListNode=head.next;
        head.next=prev;
        prev=head;
        head=curnext;
    }
    return prev;
};