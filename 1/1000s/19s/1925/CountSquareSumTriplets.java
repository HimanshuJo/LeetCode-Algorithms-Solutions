/*
https://leetcode.com/problems/count-square-sum-triples/?envType=daily-question&envId=2025-12-08
*/

class Solution {
    public int countTriples(int n) {
        int resultantSquareTriplets=0;
        HashMap<Integer, Integer>squareNumMapping=new HashMap<>();
        for(int i=1; i<=n; ++i){
            squareNumMapping.put(i*i, i);
        }
        for(int i=1; i<=n; ++i){
            if(i+1<=n){
                for(int j=i+1; j<=n; ++j){
                    int valToFind=(i*i)+(j*j);
                    if(squareNumMapping.containsKey(valToFind)){
                        int valToCheck=squareNumMapping.get(valToFind);
                        if(valToCheck!=i&&valToCheck!=j){
                            resultantSquareTriplets++;
                        }
                    }
                }
            }
        }
        return resultantSquareTriplets*2;
    }
}