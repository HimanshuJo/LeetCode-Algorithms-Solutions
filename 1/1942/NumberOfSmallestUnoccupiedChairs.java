/*
https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/?envType=daily-question&envId=2024-10-11
*/

class CustomComparatorForArrivalsAndLeaving implements Comparator<Pair>{

    @Override
    public int compare(Pair A, Pair B){
        return A.first-B.first;
    }
}

class Pair{

    public int first;

    public int second;

    Pair(int first, int second){
        this.first=first;
        this.second=second;
    }
}

class Solution {
    public int smallestChair(int[][] times, int targetFriend) {
        ArrayList<Pair>timesAsPerArrival=new ArrayList<>();
        int sizeOfTimes=times.length;
        for(int i=0; i<sizeOfTimes; ++i){
            timesAsPerArrival.add(new Pair(times[i][0], i));
        }
        Collections.sort(timesAsPerArrival, new CustomComparatorForArrivalsAndLeaving());
        PriorityQueue<Integer>availableChairsPQueue=new PriorityQueue<>();
        for(int i=0; i<sizeOfTimes; ++i){
            availableChairsPQueue.add(i);
        }
        HashMap<Integer, Integer>friendsToChairMapping=new HashMap<>();
        PriorityQueue<Pair>accordingLeaveTimePQueue=new PriorityQueue<>(new CustomComparatorForArrivalsAndLeaving());
        for(int i=0; i<sizeOfTimes; ++i){
            int currentArrivalTime=timesAsPerArrival.get(i).first, friendsIndex=timesAsPerArrival.get(i).second;
            while(!accordingLeaveTimePQueue.isEmpty()&&accordingLeaveTimePQueue.peek().first<=currentArrivalTime){
                int chairToAdd=accordingLeaveTimePQueue.peek().second;
                availableChairsPQueue.add(chairToAdd);
                accordingLeaveTimePQueue.poll();
            }
            friendsToChairMapping.put(friendsIndex, availableChairsPQueue.peek());
            accordingLeaveTimePQueue.add(new Pair(times[friendsIndex][1], availableChairsPQueue.poll()));
        }
        return friendsToChairMapping.get(targetFriend);
    }
}