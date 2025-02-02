/*
https://leetcode.com/problems/student-attendance-record-ii/description/?envType=daily-question&envId=2024-05-26
*/


class Solution {

    public static final int modulo=1000000007;

    long depthFirstSearchTraversal_forIntegers(int n, int currentAbsentCount, int currentLateCount, long[][][] memoization){
        if(currentAbsentCount>=2||currentLateCount>=3) return 0L;
        if(n==0) return 1L;
        if(memoization[n][currentAbsentCount][currentLateCount]!=-1) return memoization[n][currentAbsentCount][currentLateCount];
        long resultWhenStudentPresent=depthFirstSearchTraversal_forIntegers(n-1, currentAbsentCount, 0, memoization);
        long resultWhenStudentAbsent=depthFirstSearchTraversal_forIntegers(n-1, currentAbsentCount+1, 0, memoization);
        long resultWhenStudentConsecutiveDaysLate=depthFirstSearchTraversal_forIntegers(n-1, currentAbsentCount, currentLateCount+1, memoization);
        long totalRecordsEligibleForAward=resultWhenStudentPresent+resultWhenStudentAbsent+resultWhenStudentConsecutiveDaysLate;
        totalRecordsEligibleForAward=totalRecordsEligibleForAward>=modulo?totalRecordsEligibleForAward%=modulo:totalRecordsEligibleForAward;
        memoization[n][currentAbsentCount][currentLateCount]=totalRecordsEligibleForAward;
        return memoization[n][currentAbsentCount][currentLateCount];
    }

    public int checkRecord(int n) {
        long[][][] memoization=new long[n+1][2][3];
        for(int i=0; i<=n; ++i){
            for(int j=0; j<2; ++j){
                for(int k=0; k<3; ++k){
                    memoization[i][j][k]=-1;
                }
            }
        }
        int currentAbsentCount=0, currentLateCount=0;
        return (int)depthFirstSearchTraversal_forIntegers(n, currentAbsentCount, currentLateCount, memoization);
    }
}