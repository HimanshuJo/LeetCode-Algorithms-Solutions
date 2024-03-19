/*
https://leetcode.com/problems/task-scheduler/description/?envType=daily-question&envId=2024-03-19
*/

class Solution {
    public int leastInterval(char[] tasks, int n) {
        HashMap<Character, Integer>mp=new HashMap<>();
        int lentsk=tasks.length;
        for(int i=0; i<lentsk; ++i){
            if(mp.containsKey(tasks[i])){
                mp.put(tasks[i], mp.get(tasks[i])+1);
            } else mp.put(tasks[i], 1);
        }
        PriorityQueue<Integer>pq=new PriorityQueue<>((a,b)->(b-a));
        for(Map.Entry<Character, Integer>entry: mp.entrySet()){
            pq.offer(entry.getValue());
        }
        int res=0;
        while(!pq.isEmpty()){
            ArrayList<Integer>curcooldwn=new ArrayList<>();
            for(int i=0; i<=n; ++i){
                if(!pq.isEmpty()){
                    curcooldwn.add(pq.poll()-1);
                }
            }
            int ccdwnsz=curcooldwn.size();
            for(int i=0; i<ccdwnsz; ++i){
                if(curcooldwn.get(i)>0){
                    pq.offer(curcooldwn.get(i));
                }
            }
            res+=pq.isEmpty()?curcooldwn.size():n+1;
        }
        return res;
    }
}