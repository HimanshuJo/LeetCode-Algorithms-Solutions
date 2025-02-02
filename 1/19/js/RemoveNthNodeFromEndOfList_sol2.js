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
    let countOfAllNodes=0, idx=0, pointer=0;
    let tmp=head;
    while(tmp!==null){
        countOfAllNodes++;
        tmp=tmp["next"];
    }
    idx=countOfAllNodes-n;
    if(pointer==idx){
        if(countOfAllNodes===1) return null;
        else return head["next"];
    }
    let fnres=head;
    while(fnres!==null){
        if(pointer+1===idx){
            let curnextnext=fnres["next"]["next"];
            fnres["next"]=curnextnext;
        }
        fnres=fnres["next"];
        pointer++;
    }
    return head;
};