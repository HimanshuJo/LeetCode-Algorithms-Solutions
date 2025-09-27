/*
https://leetcode.com/problems/fruit-into-baskets/?envType=daily-question&envId=2025-08-04
*/

class Solution {
    public int totalFruit(int[] fruits) {
        int lengthOfFruits=fruits.length, left=0, right=0, resultantMaxFruits=Integer.MIN_VALUE;
        HashMap<Integer, Integer>basketMap=new HashMap<>();
        for(; right<lengthOfFruits; ++right){
            if(basketMap.containsKey(fruits[right])){
                basketMap.put(fruits[right], basketMap.get(fruits[right])+1);
            } else basketMap.put(fruits[right], 1);
            while(true){
                if(basketMap.size()<=2) break;
                basketMap.put(fruits[left], basketMap.get(fruits[left])-1);
                if(basketMap.get(fruits[left])==0){
                    basketMap.remove(fruits[left]);
                }
                left++;
            }
            resultantMaxFruits=Math.max(resultantMaxFruits, (right-left)+1);
        }
        return resultantMaxFruits;
    }
}
