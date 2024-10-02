/*
https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2024-10-02
*/

class Solution {

    public int lowerBound(ArrayList<Integer>allRequiredNumbers, int numToSearch){
        int left=0, right=allRequiredNumbers.size()-1, resultantIndex=left;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(allRequiredNumbers.get(mid)==numToSearch){
                resultantIndex=mid;
                right=mid-1;
            } else if(allRequiredNumbers.get(mid)>numToSearch){
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        return resultantIndex;
    }

    public int[] arrayRankTransform(int[] arr) {
        TreeSet<Integer>uniqueIntegersInArr=new TreeSet<>();
        int lengthOfArr=arr.length;
        for(int i=0; i<lengthOfArr; ++i){
            uniqueIntegersInArr.add(arr[i]);
        }
        ArrayList<Integer>allRequiredNumbers=new ArrayList<>();
        Iterator setIntegersItr=uniqueIntegersInArr.iterator();
        while(setIntegersItr.hasNext()){
            allRequiredNumbers.add((Integer) setIntegersItr.next());
        }
        ArrayList<Integer>resultantList=new ArrayList<>();
        for(int i=0; i<lengthOfArr; ++i){
            int requiredIndex=lowerBound(allRequiredNumbers, arr[i]);
            resultantList.add(requiredIndex+1);
        }
        int[] resultantArray=new int[resultantList.size()];
        for(int i=0; i<resultantList.size(); ++i){
            resultantArray[i]=resultantList.get(i);
        }
        return resultantArray;
    }
}