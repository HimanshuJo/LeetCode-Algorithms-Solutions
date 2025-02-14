/*
https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/?envType=daily-question&envId=2024-10-14
*/

class CustomComparator implements Comparator<Double>{
    @Override
    public int compare(Double A, Double B){
        return Double.compare(B, A);
    }
}

class Solution {
    public long maxKelements(int[] nums, int k) {
        int lengthOfNums=nums.length;
        double finalScore=0.0;
        PriorityQueue<Double>maxHeapPQ=new PriorityQueue<>(new CustomComparator());
        for(int i=0; i<lengthOfNums; ++i){
            maxHeapPQ.add((double)nums[i]);
        }
        while(k-- >0){
            double currentMaxElement=maxHeapPQ.poll();
            finalScore+=currentMaxElement;
            double newValue=Math.ceil(currentMaxElement/3);
            maxHeapPQ.add(newValue);
        }
        return (long)finalScore;
    }
}