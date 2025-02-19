/*
https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2025-02-19
*/

class Solution {

    public static void depthFirstSearch_forStrings(int n, ArrayList<String>allHappyStrings, StringBuilder currentString){
        if(currentString.length()==n){
            allHappyStrings.add(String.valueOf(currentString));
            return;
        }
        if(currentString.length()!=0&&currentString.charAt(currentString.length()-1)!='a'){
            StringBuilder newString=new StringBuilder(String.valueOf(currentString));
            newString.append('a');
            depthFirstSearch_forStrings(n, allHappyStrings, newString);
        } else if(currentString.length()==0){
            StringBuilder newString=new StringBuilder();
            newString.append('a');
            depthFirstSearch_forStrings(n, allHappyStrings, newString);
        }
        if(currentString.length()!=0&&currentString.charAt(currentString.length()-1)!='b'){
            StringBuilder newString=new StringBuilder(String.valueOf(currentString));
            newString.append('b');
            depthFirstSearch_forStrings(n, allHappyStrings, newString);
        } else if(currentString.length()==0){
            StringBuilder newString=new StringBuilder();
            newString.append('b');
            depthFirstSearch_forStrings(n, allHappyStrings, newString);
        }
        if(currentString.length()!=0&&currentString.charAt(currentString.length()-1)!='c'){
            StringBuilder newString=new StringBuilder(String.valueOf(currentString));
            newString.append('c');
            depthFirstSearch_forStrings(n, allHappyStrings, newString);
        } else if(currentString.length()==0){
            StringBuilder newString=new StringBuilder();
            newString.append('c');
            depthFirstSearch_forStrings(n, allHappyStrings, newString);
        }
    }

    ArrayList<String> generateAllHappyStrings(int n){
        ArrayList<String>allHappyStrings=new ArrayList<>();
        StringBuilder currentString=new StringBuilder();
        depthFirstSearch_forStrings(n, allHappyStrings, currentString);
        return allHappyStrings;
    }

    public String getHappyString(int n, int k) {
        ArrayList<String>allHappyStrings=generateAllHappyStrings(n);
        if(allHappyStrings.size()<k) return "";
        Collections.sort(allHappyStrings);
        return allHappyStrings.get(k-1);
    }
}