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

class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        PriorityQueue<Pair> pq = new PriorityQueue<>((Pair A, Pair B) -> Double.compare(A.first, B.first));
        int sz=arr.length;
        for(int i=0; i<sz; ++i){
            if(i+1<=sz-1){
                for(int j=i+1; j<sz; ++j){
                    IntPair frfst=new IntPair(arr[i], arr[j]);
                    double frsec=arr[i]/(double)arr[j];
                    pq.add(new Pair(frsec, frfst));
                }
            }
        }
        int[] res=new int[2];
        while(!pq.isEmpty()){
            Pair curr=pq.poll();
            k--;
            if(k==0){
                res[0]=curr.second.first;
                res[1]=curr.second.second;
                break;
            }
        }
        return res;
    }
}