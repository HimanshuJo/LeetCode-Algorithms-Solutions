/*
https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/submissions/1201407067/?envType=daily-question&envId=2024-03-12
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
    public ListNode removeZeroSumSublists(ListNode head) {
        ArrayList<Integer>all=new ArrayList<>();
        while(head!=null){
            all.add(head.val);
            head=head.next;
        }
        int sz=all.size();
        while(true){
            int bgn=-1, end=-1;
            boolean flag=false;
            for(int i=0; i<sz; ++i){
                int cursm=0;
                for(int j=i; j<sz; ++j){
                    cursm+=all.get(j);
                    if(cursm==0){
                        flag=true;
                        bgn=i;
                        end=j;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag){
                for(int i=bgn; i<=end; ++i){
                    all.set(i, Integer.MIN_VALUE);
                }
                Iterator itr=all.iterator();
                while(itr.hasNext()){
                    if((int)itr.next()==Integer.MIN_VALUE){
                        itr.remove();
                    }
                }
                sz=all.size();
            } else break;
        }
        if(all.size()==0) return null;
        ListNode res=new ListNode(all.get(0));
        ListNode nxt=res;
        for(int i=1; i<all.size(); ++i){
            nxt.next=new ListNode(all.get(i));
            nxt=nxt.next;
        }
        return res;
    }
}