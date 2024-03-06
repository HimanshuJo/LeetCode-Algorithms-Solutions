/*
https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2024-03-06
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

function hasCycle(head: ListNode | null): boolean {
    let st:Set<ListNode>=new Set();
    while(head!==null){
        if(st.has(head)) return true;
        st.add(head);
        head=head.next;
    }
    return false;
};