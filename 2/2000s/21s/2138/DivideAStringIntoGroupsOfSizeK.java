/*
https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/?envType=daily-question&envId=2025-06-22
*/

class Solution {
    public String[] divideString(String s, int k, char fill) {
        ArrayList<String>resultantList=new ArrayList<>();
        int lengthOfS=s.length(), beginIndex=0;
        StringBuilder currentString=new StringBuilder();
        while(true){
            if(beginIndex>=lengthOfS) break;
            if(currentString.length()==k){
                resultantList.add(String.valueOf(currentString));
                currentString=new StringBuilder();
            } else{
                currentString.append(s.charAt(beginIndex));
                beginIndex++;
            }
        }
        while(true){
            if(currentString.length()==0||currentString.length()==k) break;
            currentString.append(fill);
        }
        if(currentString.length()>=1){
            resultantList.add(String.valueOf(currentString));
        }
        String[] resultantArray=new String[resultantList.size()];
        for(int i=0; i<resultantList.size(); ++i){
            resultantArray[i]=resultantList.get(i);
        }
        return resultantArray;
    }
}