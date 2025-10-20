/*
https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/?envType=daily-question&envId=2025-10-08
*/

class Solution {

    public static boolean isValid(int currentPortion, long minPotionRequired){
        return currentPortion>=minPotionRequired;
    }

    public static int binarySearch(int[] portions, long minPotionRequired){
        int left=0, right=portions.length-1;
        int resultantIndex=right+1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValid(portions[mid], minPotionRequired)){
                resultantIndex=mid;
                right=mid-1;
            } else left=mid+1;
        }
        return resultantIndex;
    }

    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        Arrays.sort(potions);
        int lengthOfSpells=spells.length, lengthOfPotions=potions.length;
        int[] res=new int[lengthOfSpells];
        for(int i=0; i<lengthOfSpells; ++i){
            int currentSpell=spells[i];
            long minPotionRequired=(success+currentSpell-1)/currentSpell;
            int firstValidIndex=binarySearch(potions, minPotionRequired);
            res[i]=(firstValidIndex==lengthOfPotions)?0:(lengthOfPotions-firstValidIndex);
        }
        return res;
    }
}