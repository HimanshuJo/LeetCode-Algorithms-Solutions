/*
https://leetcode.com/problems/k-th-smallest-prime-fraction/description/?envType=daily-question&envId=2024-05-10
*/

class IntPair{

    public int first;
    public int second;

    public IntPair(int first, int second){
        this.first=first;
        this.second=second;
    }
}

class Pair{

    public double first;
    public IntPair second;

    public Pair(double first, IntPair second){
        this.first=first;
        this.second=second;
    }
}

public class Solution {
    public int[] KthSmallestPrimeFraction(int[] arr, int k) {
        PriorityQueue<Pair, double>pq=new PriorityQueue<Pair, double>();
        int sz=arr.Length;
        for(int i=0; i<sz; ++i){
            if(i+1<=sz-1){
                for(int j=i+1; j<sz; ++j){
                    IntPair frfst=new IntPair(arr[i], arr[j]);
                    double frsec=arr[i]/(double)arr[j];
                    pq.Enqueue(new Pair(frsec, frfst), frsec);
                }
            }
        }
        int[] res=new int[2];
        int pqcount=pq.Count;
        while(pqcount!=0){
            Pair curr=pq.Dequeue();
            k--;
            if(k==0){
                res[0]=curr.second.first;
                res[1]=curr.second.second;
                break;
            }
            pqcount=pq.Count;
        }
        return res;
    }
}