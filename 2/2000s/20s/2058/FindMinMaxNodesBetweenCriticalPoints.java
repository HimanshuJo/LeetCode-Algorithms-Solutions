/*
https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/?envType=daily-question&envId=2024-07-05
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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        ArrayList<Integer>listOfAllNodes=new ArrayList<>();
        while(head!=null){
            listOfAllNodes.add(head.val);
            head=head.next;
        }
        int sizeOfListAllNodes=listOfAllNodes.size();
        ArrayList<Integer>listOfAllCriticalPoints=new ArrayList<>();
        for(int i=1; i<sizeOfListAllNodes; ++i){
            if(i+1<=sizeOfListAllNodes-1){
                if(listOfAllNodes.get(i)>listOfAllNodes.get(i-1)&&listOfAllNodes.get(i)>listOfAllNodes.get(i+1)){
                    listOfAllCriticalPoints.add(i+1);
                } else if(listOfAllNodes.get(i)<listOfAllNodes.get(i-1)&&listOfAllNodes.get(i)<listOfAllNodes.get(i+1)){
                    listOfAllCriticalPoints.add(i+1);
                }
            }
        }
        int[] resultantListOfMinMaxDistCriticalPoints=new int[2];
        int currentMinDistance=Integer.MAX_VALUE, currentMaxDistance=Integer.MIN_VALUE;
        int sizeOfListCriticalPoints=listOfAllCriticalPoints.size();
        if(sizeOfListCriticalPoints>=2){
            Collections.sort(listOfAllCriticalPoints);
            currentMaxDistance=Math.max(currentMaxDistance, Math.abs(listOfAllCriticalPoints.get(0)-listOfAllCriticalPoints.get(sizeOfListCriticalPoints-1)));
            for(int i=0; i<sizeOfListCriticalPoints; ++i){
                if(i+1<=sizeOfListCriticalPoints-1){
                    currentMinDistance=Math.min(currentMinDistance, Math.abs(listOfAllCriticalPoints.get(i)-listOfAllCriticalPoints.get(i+1)));
                }
            }
        }
        resultantListOfMinMaxDistCriticalPoints[0]=currentMinDistance==Integer.MAX_VALUE?-1:currentMinDistance;
        resultantListOfMinMaxDistCriticalPoints[1]=currentMaxDistance==Integer.MIN_VALUE?-1:currentMaxDistance;
        return resultantListOfMinMaxDistCriticalPoints;
    }
}