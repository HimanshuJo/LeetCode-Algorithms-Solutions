/*
https://leetcode.com/problems/most-beautiful-item-for-each-query/description/?envType=daily-question&envId=2024-11-12
*/

class Solution {

    public static int binarySearch(int[][] items, int targetValue){
        int currentMaxBeauty=0, left=0, right=items.length-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(items[mid][0]>targetValue){
                right=mid-1;
            } else{
                currentMaxBeauty=Math.max(currentMaxBeauty, items[mid][1]);
                left=mid+1;
            }
        }
        return currentMaxBeauty;
    }

    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items, (array1, array2)->Integer.compare(array1[0], array2[0]));
        int lengthOfItems=items.length;
        int lengthOfQueries=queries.length;
        int[] resultantArray=new int[lengthOfQueries];
        int currentMaxBeauty=items[0][1];
        for(int i=0; i<lengthOfItems; ++i){
            currentMaxBeauty=Math.max(currentMaxBeauty, items[i][1]);
            items[i][1]=currentMaxBeauty;
        }
        for(int i=0; i<lengthOfQueries; ++i){
            resultantArray[i]=binarySearch(items, queries[i]);
        }
        return resultantArray;
    }
}