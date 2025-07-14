/*
https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/?envType=daily-question&envId=2025-07-14
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

    int toDecimal(StringBuilder str){
        int lengthOfStr=str.length(), finalDecimal=0, beginPower=lengthOfStr-1;
        for(int i=0; i<lengthOfStr; ++i){
            finalDecimal+=(str.charAt(i)-'0')*(1<<beginPower);
            beginPower--;
        }
        return finalDecimal;
    }

    public int getDecimalValue(ListNode head) {
        StringBuilder headAsString=new StringBuilder();
        while(head!=null){
            headAsString.append(String.valueOf(head.val));
            head=head.next;
        }
        return toDecimal(headAsString);
    }
}