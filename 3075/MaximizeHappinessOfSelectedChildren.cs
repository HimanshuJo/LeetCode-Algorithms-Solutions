/*
https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2024-05-09
*/

public class Solution {
    public long MaximumHappinessSum(int[] happiness, int k) {
        PriorityQueue<int,int>pq=new PriorityQueue<int,int>(Comparer<int>.Create((a, b)=>b-a));
        int hplen=happiness.Length;
        for(int i=0; i<hplen; ++i){
            pq.Enqueue(happiness[i], happiness[i]);
        }
        long res=0, count=1;
        if(pq.Count>=1){
            res+=pq.Dequeue();
            k--;
            while(k>0){
                if(pq.Count>=1){
                    long curr=pq.Dequeue();
                    if(curr-count>0) curr-=count;
                    else curr=0;
                    res+=curr;
                    k--;
                    count++;
                } else break;
            }
        }
        return res;
    }
}