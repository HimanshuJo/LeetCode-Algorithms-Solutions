/*
https://leetcode.com/problems/reverse-linked-list/description/?envType=daily-question&envId=2024-03-21
*/

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    let prev=null;
    while(head!==null){
        let curnext=head.next;
        head.next=prev
        prev=head
        head=curnext;
    }
    return prev;
};