/*
https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2024-09-06
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
        boolean alreadySeenFirstValidNode=false;
        ListNode resultantList=new ListNode(nums[0]);
        ListNode tailForResultantList=resultantList;
        HashMap<Integer, Integer>valuesInNumsMapping=new HashMap<>();
        int lengthOfNums=nums.length;
        for(int i=0; i<lengthOfNums; ++i){
            valuesInNumsMapping.put(nums[i], nums[i]);
        }
        while(head!=null){
            int currentHeadValue=head.val;
            if(!valuesInNumsMapping.containsKey(currentHeadValue)){
                if(!alreadySeenFirstValidNode){
                    resultantList=new ListNode(currentHeadValue);
                    tailForResultantList=resultantList;
                    alreadySeenFirstValidNode=true;
                } else{
                    ListNode newNode=new ListNode(currentHeadValue);
                    tailForResultantList.next=newNode;
                    tailForResultantList=tailForResultantList.next;
                }
            }
            head=head.next;
        }
        return resultantList;
    }
}