/*
https://leetcode.com/problems/lexicographically-smallest-generated-string/description/?envType=daily-question&envId=2026-03-31
*/

class Solution {
    public String generateString(String str1, String str2) {
        int n=str1.length(), m=str2.length();
        StringBuilder word=new StringBuilder();
        for(int i=0; i<n+m-1; ++i){
            word.append('a');
        }
        ArrayList<Integer>fixed=new ArrayList<>();
        for(int i=0; i<n+m-1; ++i){
            fixed.add(0);
        }
        for(int i=0; i<n; ++i){
            if(str1.charAt(i)=='T'){
                for(int j=i; j<i+m; ++j){
                    if(fixed.get(j)==1&&str2.charAt(j-i)!=word.charAt(j)) return "";
                    else{
                        word.setCharAt(j, str2.charAt(j-i));
                        fixed.set(j, 1);
                    }
                }
            }
        }
        for(int i=0; i<n; ++i){
            if(str1.charAt(i)=='F'){
                int idx=-1;
                boolean flag=false;
                for(int j=i+m-1; j>=i; --j){
                    if(str2.charAt(j-i)!=word.charAt(j)){
                        flag=true;
                    }
                    if(idx==-1&&fixed.get(j)==0){
                        idx=j;
                    }
                }
                if(flag) continue;
                else if(idx!=-1){
                    word.setCharAt(idx, 'b');
                } else return "";
            }
        }
        return String.valueOf(word);
    }
}