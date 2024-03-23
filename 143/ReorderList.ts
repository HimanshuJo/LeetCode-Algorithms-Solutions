/*
https://leetcode.com/problems/reorder-list/description/?envType=daily-question&envId=2024-03-23
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

/**
 Do not return anything, modify head in-place instead.
 */
function reorderList(head: ListNode | null): void {
    if(head.next===null) return;
    let res:ListNode|null=head;
    let anthhead:ListNode|null=head;
    let all:number[]=[];
    while(anthhead!==null){
        all.push(anthhead.val);
        anthhead=anthhead.next;
    }
    let sz:number=all.length, left:number=1, right:number=sz-2, count:number=0;
    let tmpres:ListNode=res;
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