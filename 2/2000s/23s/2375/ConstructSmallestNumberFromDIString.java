/*
https://leetcode.com/problems/construct-smallest-number-from-di-string/description/?envType=daily-question&envId=2025-02-18
*/

class Solution {

    public static boolean isValidPermutation(String pattern, StringBuilder currentPattern){
        int lengthOfPattern=pattern.length();
        for(int i=0; i<lengthOfPattern; ++i){
            if(pattern.charAt(i)=='I'){
                if(currentPattern.charAt(i)-'0'>currentPattern.charAt(i+1)-'0') return false;
            } else{
                if(currentPattern.charAt(i)-'0'<currentPattern.charAt(i+1)-'0') return false;
            }
        }
        return true;
    }

    public static void depthFirstSearch_forStrings(String pattern, int lengthOfPattern, StringBuilder currentPattern,
    ArrayList<String>allPermutations, ArrayList<Boolean>seenNumbers){
        if(currentPattern.length()==lengthOfPattern+1){
            if(isValidPermutation(pattern, currentPattern)){
                allPermutations.add(String.valueOf(currentPattern));
            }
            return;
        }
        for(int i=1; i<=lengthOfPattern+1; ++i){
            if(seenNumbers.get(i)==false){
                seenNumbers.set(i, true);
                currentPattern.append(i);
                depthFirstSearch_forStrings(pattern, lengthOfPattern, currentPattern, allPermutations, seenNumbers);
                currentPattern.deleteCharAt(currentPattern.length()-1);
                seenNumbers.set(i, false);
            }
        }
        return;
    }

    ArrayList<String> generateAllPermutations(String pattern){
        int lengthOfPattern=pattern.length();
        StringBuilder currentPattern=new StringBuilder();
        ArrayList<String>allPermutations=new ArrayList<>();
        ArrayList<Boolean>seenNumbers=new ArrayList<>();
        for(int i=0; i<=lengthOfPattern+1; ++i){
            seenNumbers.add(false);
        }
        depthFirstSearch_forStrings(pattern, lengthOfPattern, currentPattern, allPermutations, seenNumbers);
        return allPermutations;
    }

    public String smallestNumber(String pattern) {
        ArrayList<String>allPossiblePermutations=generateAllPermutations(pattern);
        Collections.sort(allPossiblePermutations);
        return allPossiblePermutations.get(0);
    }
}