/*
https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/?envType=daily-question&envId=2025-07-07
*/

class Solution {
    public int maxEvents(int[][] events) {
        Arrays.sort(events, (A, B)->Integer.compare(A[0], B[0]));
        PriorityQueue<Integer>minHeap=new PriorityQueue<>((A, B)->(A-B));
        int lengthOfEvents=events.length, beginIndex=0, maxDay=0, finalMaxEvents=0;
        for(int[] event: events){
            maxDay=Math.max(maxDay, event[1]);
        }
        for(int curDay=1; curDay<=maxDay; ++curDay){
            while(beginIndex<lengthOfEvents&&events[beginIndex][0]==curDay){
                minHeap.add(events[beginIndex++][1]);
            }
            while(!minHeap.isEmpty()&&minHeap.peek()<curDay){
                minHeap.poll();
            }
            if(!minHeap.isEmpty()){
                minHeap.poll();
                finalMaxEvents++;
            }
        }
        return finalMaxEvents;
    }
}