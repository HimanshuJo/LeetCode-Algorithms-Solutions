/*
https://leetcode.com/problems/relative-sort-array/description/?envType=daily-question&envId=2024-06-11
*/

class Pair{

    private boolean isElementPresent;
    private int indexOfTheElement;

    Pair(boolean isElementPresent, int indexOfTheElement){
        this.isElementPresent=isElementPresent;
        this.indexOfTheElement=indexOfTheElement;
    }

    public boolean getIsElementPresent(){
        return this.isElementPresent;
    }

    public int getIndexOfTheElement(){
        return this.indexOfTheElement;
    }
}


class Solution {

    public static Pair searchElementInArr1(int[] arr1, int valueToBeSearched){
        int arr1Length=arr1.length;
        for(int arr1Index=0; arr1Index<arr1Length; ++arr1Index){
            if(arr1[arr1Index]==valueToBeSearched) return new Pair(true, arr1Index);
        }
        return new Pair(false, -1);
    }

    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int arr1Length=arr1.length, arr2Length=arr2.length;
        int[] resultantSortedArray=new int[arr1Length];
        int initialTraversalIndex=0;
        for(int arr2Index=0; arr2Index<arr2Length; ++arr2Index){
            int currentElementInArr2=arr2[arr2Index];
            while(true){
                Pair searchForCurrentElementInArr1=searchElementInArr1(arr1, currentElementInArr2);
                if(searchForCurrentElementInArr1.getIsElementPresent()!=false){
                    int indexOfTheFoundedElement=searchForCurrentElementInArr1.getIndexOfTheElement();
                    arr1[indexOfTheFoundedElement]=-1;
                    resultantSortedArray[initialTraversalIndex++]=currentElementInArr2;
                } else break;
            }
        }
        Arrays.sort(arr1);
        for(int arr1Index=0; arr1Index<arr1Length; ++arr1Index){
            if(arr1[arr1Index]!=-1) resultantSortedArray[initialTraversalIndex++]=arr1[arr1Index];
        }
        return resultantSortedArray;
    }
}