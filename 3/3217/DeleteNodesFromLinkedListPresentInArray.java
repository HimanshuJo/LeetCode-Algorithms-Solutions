/*
https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/?envType=daily-question&envId=2025-11-01
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
    public ListNode modifiedList(int[] nums, ListNode head) {
        HashMap<Integer, Integer>valsInNumsMap=new HashMap<>();
        for(int num: nums){
            valsInNumsMap.put(num, num);
        }
        ArrayList<Integer>allValidNumList=new ArrayList<>();
        while(head!=null){
            int currentValue=head.val;
            if(!valsInNumsMap.containsKey(currentValue)){
                allValidNumList.add(currentValue);
            }
            head=head.next;
        }
        ListNode resultantList=new ListNode(allValidNumList.get(0));
        ListNode tailForResultantList=resultantList;
        int finalSize=allValidNumList.size();
        for(int i=1; i<=finalSize-1; ++i){
            ListNode newNode=new ListNode(allValidNumList.get(i));
            tailForResultantList.next=newNode;
            tailForResultantList=newNode;
        }
        return resultantList;
    }
}