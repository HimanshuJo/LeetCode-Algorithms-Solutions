/*
https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/?envType=daily-question&envId=2024-10-19
*/

class Solution {

    public static String reverseString(String str){
        StringBuilder reversedString=new StringBuilder();
        int lengthOfStr=str.length();
        for(int i=lengthOfStr-1; i>=0; --i){
            reversedString.append(str.charAt(i));
        }
        return String.valueOf(reversedString);
    }

    public static String invertString(String str){
        StringBuilder resultantInvertedString=new StringBuilder();
        int lengthOfStr=str.length();
        for(int i=0; i<lengthOfStr; ++i){
            if(str.charAt(i)=='1') resultantInvertedString.append("0");
            else resultantInvertedString.append("1");
        }
        return String.valueOf(resultantInvertedString);
    }

    public char findKthBit(int n, int k) {
        ArrayList<String>allStringsUntilN=new ArrayList<>();
        StringBuilder previousString=new StringBuilder("0");
        int count=1;
        allStringsUntilN.add(String.valueOf(previousString));
        while(count!=n){
            String invertedPrev=invertString(String.valueOf(previousString));
            String reversedString=reverseString(invertedPrev);
            StringBuilder nextString=new StringBuilder();
            nextString.append(previousString);
            nextString.append("1");
            nextString.append(reversedString);
            allStringsUntilN.add(String.valueOf(nextString));
            previousString=nextString;
            count++;
        }
        return allStringsUntilN.get(n-1).charAt(k-1);
    }
}