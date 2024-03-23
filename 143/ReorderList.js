/*
https://leetcode.com/problems/reorder-list/description/?envType=daily-question&envId=2024-03-23
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
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
    if(head.next===null) return;
    let res=head;
    let anthhead=head;
    let all=[];
    while(anthhead!==null){
        all.push(anthhead.val);
        anthhead=anthhead.next;
    }
    let sz=all.length, left=1, right=sz-2, count=0;
    let tmpres=res;
    tmpres.next=new ListNode(all[sz-1]);
    tmpres=tmpres.next;
    while(left<=right){
        if(count%2===0){
            tmpres.next=new ListNode(all[left++]);
        } else{
            tmpres.next=new ListNode(all[right--]);
        }
        tmpres=tmpres.next;
        count++;
    }
};