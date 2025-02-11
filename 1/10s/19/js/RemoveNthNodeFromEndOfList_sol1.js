/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03
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
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let all=[]
    while(head!==null){
        all.push(head.val);
        head=head.next;
    }
    let todel=all.length-n;
    all.splice(todel, 1);
    if(all.length>=1){
        let res=new ListNode(all[0], null);
        let nxt=res;
        for(let i=1; i<all.length; ++i){
            let nw=new ListNode(all[i], null);
            nxt["next"]=nw;
            nxt=nxt["next"];
        }
        return res;
    }
    return null;
};