/*
https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/?envType=daily-question&envId=2024-05-07
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode DoubleIt(ListNode head) {
        List<int>all=new List<int>();
        List<int>fn=new List<int>();
        while(head!=null){
            all.Add(head.val);
            head=head.next;
        }
        List<int>sec=new List<int>();
        int sz=all.Count, curcarry=0;
        for(int i=0; i<sz; ++i){
            sec.Add(all[i]);
        }
        for(int i=sz-1; i>=0; --i){
            int cursm=all[i]+sec[i]+curcarry;
            if(i>0){
                curcarry=cursm/10;
                cursm%=10;
            }
            fn.Add(cursm);
        }
        fn.Reverse();
        string lntomk="";
        foreach(var vals in fn){
            lntomk+=vals.ToString();
        }
        int fnsz=lntomk.Length;
        ListNode root=new ListNode(lntomk[0]-'0');
        ListNode nxt=root;
        for(int i=1; i<fnsz; ++i){
            ListNode nwNode=new ListNode(lntomk[i]-'0');
            nxt.next=nwNode;
            nxt=nxt.next;
        }
        return root;
    }
}