/*
https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10
*/

class Solution {
    public int minOperations(String[] logs) {
        int currentDepthInTheDirectory=0, resultantMinOperationRequired=0, lengthOfLogs=logs.length;
        for(int i=0; i<lengthOfLogs; ++i){
            String currentLog=logs[i];
            int lengthOfCurrentLog=currentLog.length();
            if(currentLog.equals("./")) continue;
            else if(currentLog.charAt(lengthOfCurrentLog-1)=='/'&&
                    currentLog.charAt(lengthOfCurrentLog-2)=='.'&&
                    currentLog.charAt(lengthOfCurrentLog-3)=='.'){
                currentDepthInTheDirectory=Math.max(currentDepthInTheDirectory-1, 0);
            } else currentDepthInTheDirectory++;
        }
        while(currentDepthInTheDirectory>=1){
            resultantMinOperationRequired++;
            currentDepthInTheDirectory--;
        }
        return resultantMinOperationRequired;
    }
}