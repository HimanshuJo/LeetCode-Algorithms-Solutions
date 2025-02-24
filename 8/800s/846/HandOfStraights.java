/*
https://leetcode.com/problems/hand-of-straights/description/?envType=daily-question&envId=2024-06-06
*/

class Solution {

    public int binarySearch(ArrayList<Integer>handList, int neededElement){
        int leftIndex=0, rightIndex=handList.size()-1, indexOfTheNeededElementInCurrentGroupOfCard=-1;
        while(leftIndex<=rightIndex){
            int middleIndex=leftIndex+(rightIndex-leftIndex)/2;
            if(handList.get(middleIndex)==neededElement){
                indexOfTheNeededElementInCurrentGroupOfCard=middleIndex;
                break;
            } else if(handList.get(middleIndex)>neededElement){
                rightIndex=middleIndex-1;
            } else{
                leftIndex=middleIndex+1;
            }
        }
        return indexOfTheNeededElementInCurrentGroupOfCard;
    }

    public boolean isNStraightHand(int[] hand, int groupSize) {
        ArrayList<Integer>handList=new ArrayList<>();
        int sizeOfHand=hand.length;
        Arrays.sort(hand);
        for(int hand_index=0; hand_index<sizeOfHand; ++hand_index){
            handList.add(hand[hand_index]);
        }
        ArrayList<Integer>currentGroupOfCard=new ArrayList<>();
        currentGroupOfCard.add(handList.get(0));
        handList.remove(0);
        while(true){
            if(currentGroupOfCard.size()==groupSize){
                currentGroupOfCard.clear();
                if(handList.isEmpty()) break;
                currentGroupOfCard.add(handList.get(0));
                handList.remove(0);
                continue;
            } else{
                if(handList.isEmpty()) break;
                int neededElement=currentGroupOfCard.get(currentGroupOfCard.size()-1)+1;
                int indexOfTheNeededElementInCurrentGroupOfCard=binarySearch(handList, neededElement);
                if(indexOfTheNeededElementInCurrentGroupOfCard!=-1){
                    currentGroupOfCard.add(handList.get(indexOfTheNeededElementInCurrentGroupOfCard));
                    handList.remove(indexOfTheNeededElementInCurrentGroupOfCard);
                } else return false;
            }
        }
        if(!currentGroupOfCard.isEmpty()) return false;
        return true;
    }
}