/*
https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2024-03-06
*/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    let st=new Set();
    while(head!==null){
        if(st.has(head)) return true;
        st.add(head);
        head=head.next;
    }
    return false;
};