/*
https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/?envType=daily-question&envId=2024-05-07
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
    public ListNode doubleIt(ListNode head) {
        ArrayList<Integer>all=new ArrayList<>();
        ArrayList<Integer>fn=new ArrayList<>();
        while(head!=null){
            all.add(head.val);
            head=head.next;
        }
        ArrayList<Integer>sec=new ArrayList<>();
        int sz=all.size(), curcarry=0;
        for(int i=0; i<sz; ++i){
            sec.add(all.get(i));
        }
        for(int i=sz-1; i>=0; --i){
            int cursm=all.get(i)+sec.get(i)+curcarry;
            if(i>0){
                curcarry=cursm/10;
                cursm%=10;
            }
            fn.add(cursm);
        }
        Collections.reverse(fn);
        StringBuilder lntomk=new StringBuilder();
        int fnsz=fn.size();
        for(int i=0; i<fnsz; ++i){
            lntomk.append(String.valueOf(fn.get(i)));
        }
        int lntomklen=lntomk.length();
        ListNode root=new ListNode(lntomk.charAt(0)-'0');
        ListNode nxt=root;
        for(int i=1; i<lntomklen; ++i){
            ListNode nwNode=new ListNode(lntomk.charAt(i)-'0');
            nxt.next=nwNode;
            nxt=nxt.next;
        }
        return root;
    }
}