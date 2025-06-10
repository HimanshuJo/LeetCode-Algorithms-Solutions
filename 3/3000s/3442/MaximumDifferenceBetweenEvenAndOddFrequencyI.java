/*
https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/?envType=daily-question&envId=2025-06-10
*/

class Solution {
    public int maxDifference(String s) {
        TreeMap<Character, Integer>charToCountMap=new TreeMap<>();
        int lengthOfS=s.length();
        for(int i=0; i<lengthOfS; ++i){
            char currentChar=s.charAt(i);
            if(charToCountMap.containsKey(currentChar)){
                int curCount=charToCountMap.get(currentChar);
                curCount++;
                charToCountMap.put(currentChar, curCount);
            } else{
                charToCountMap.put(currentChar, 1);
            }
        }
        TreeMap<Integer, ArrayList<Character>>countToCharsMap=new TreeMap<>();
        for(Map.Entry<Character, Integer>entries: charToCountMap.entrySet()){
            char currentChar=entries.getKey();
            int currentCount=entries.getValue();
            if(countToCharsMap.containsKey(currentCount)){
                ArrayList<Character>currentList=countToCharsMap.get(currentCount);
                currentList.add(currentChar);
                countToCharsMap.put(currentCount, currentList);
            } else{
                ArrayList<Character>nwList=new ArrayList<>();
                nwList.add(currentChar);
                countToCharsMap.put(currentCount, nwList);
            }
        }
        ArrayList<Integer>odds=new ArrayList<>();
        ArrayList<Integer>evens=new ArrayList<>();
        for(Map.Entry<Integer, ArrayList<Character>>entries: countToCharsMap.entrySet()){
            int currentCount=entries.getKey();
            if(currentCount%2!=0){
                odds.add(currentCount);
            } else evens.add(currentCount);
        }
        return odds.get(odds.size()-1)-evens.get(0);
    }
}