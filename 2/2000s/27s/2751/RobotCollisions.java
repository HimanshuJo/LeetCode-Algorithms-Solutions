/*
https://leetcode.com/problems/robot-collisions/?envType=daily-question&envId=2026-04-01
*/

class CustomComparator implements Comparator<Tuple>{

    @Override
    public int compare(Tuple A, Tuple B){
        return Integer.compare(A.first, B.first);
    }
}

class CustomComparator2 implements Comparator<Pair>{

    @Override
    public int compare(Pair A, Pair B){
        return Integer.compare(A.first, B.first);
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

class Tuple{

    public int first;

    public int second;

    public char third;

    public int fourth;

    Tuple(int first, int second, char third, int fourth){
        this.first=first;
        this.second=second;
        this.third=third;
        this.fourth=fourth;
    }

    public void setSecond(int second){
        this.second=second;
    }
}


class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        ArrayList<Tuple>robots=new ArrayList<>();
        int lengthOfPositions=positions.length;
        for(int i=0; i<lengthOfPositions; ++i){
            robots.add(new Tuple(positions[i], healths[i], directions.charAt(i), i));
        }
        Collections.sort(robots, new CustomComparator());
        Stack<Integer>stackForIndices=new Stack<>();
        for(int i=0; i<lengthOfPositions; ++i){
            Tuple currentTuple=robots.get(i);
            int currentPosition=currentTuple.first,
                currentHealth=currentTuple.second;
            char currentDirection=currentTuple.third;
            int currentIndex=currentTuple.fourth;
            if(currentDirection=='R'){
                stackForIndices.push(i);
            } else{
                while(!stackForIndices.isEmpty()&&currentHealth>0){
                    int indexToProcess=stackForIndices.peek();
                    Tuple nextTuple=robots.get(indexToProcess);
                    int nextPosition=nextTuple.first, nextHealth=nextTuple.second;
                    char nextDirection=nextTuple.third;
                    if(nextHealth<currentHealth){
                        nextHealth=0;
                        currentHealth-=1;
                        currentTuple.setSecond(currentHealth);
                        robots.set(i, currentTuple);
                        nextTuple.setSecond(nextHealth);
                        robots.set(indexToProcess, nextTuple);
                        stackForIndices.pop();
                    } else if(nextHealth==currentHealth){
                        nextHealth=0;
                        currentHealth=0;
                        currentTuple.setSecond(currentHealth);
                        robots.set(i, currentTuple);
                        nextTuple.setSecond(nextHealth);
                        robots.set(indexToProcess, nextTuple);
                        stackForIndices.pop();
                        break;
                    } else{
                        currentHealth=0;
                        nextHealth-=1;
                        currentTuple.setSecond(currentHealth);
                        robots.set(i, currentTuple);
                        nextTuple.setSecond(nextHealth);
                        robots.set(indexToProcess, nextTuple);
                        break;
                    }
                }
            }
        }
        ArrayList<Pair>survivors=new ArrayList<>();
        for(int i=0; i<robots.size(); ++i){
            Tuple current=robots.get(i);
            if(current.second>0){
                survivors.add(new Pair(current.fourth, current.second));
            }
        }
        Collections.sort(survivors, new CustomComparator2());
        List<Integer>resultantList=new ArrayList<>();
        for(int i=0; i<survivors.size(); ++i){
            resultantList.add(survivors.get(i).second);
        }
        return resultantList;
    }
}