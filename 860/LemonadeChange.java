/*
https://leetcode.com/problems/lemonade-change/description/?envType=daily-question&envId=2024-08-15
*/

class Solution {
    public boolean lemonadeChange(int[] bills) {
        HashMap<Integer, Integer>countOfEachBills=new HashMap<>();
        int lengthOfBills=bills.length;
        for(int i=0; i<lengthOfBills; ++i){
            if(bills[i]>5){
                int remainder=bills[i]-5;
                if(remainder>=20){
                    if(countOfEachBills.containsKey(20)){
                        int currentCount=countOfEachBills.get(20);
                        while(true){
                            if(currentCount==0||remainder==0) break;
                            if(remainder-20>=0){
                                remainder-=20;
                                currentCount--;
                                countOfEachBills.put(20, currentCount);
                            } else break;
                        }
                    }
                }
                if(remainder>=10){
                    if(countOfEachBills.containsKey(10)){
                        int currentCount=countOfEachBills.get(10);
                        while(true){
                            if(currentCount==0||remainder==0) break;
                            if(remainder-10>=0){
                                remainder-=10;
                                currentCount--;
                                countOfEachBills.put(10, currentCount);
                            } else break;
                        }
                    }
                }
                if(remainder>=5){
                    if(countOfEachBills.containsKey(5)){
                        int currentCount=countOfEachBills.get(5);
                        while(true){
                            if(currentCount==0||remainder==0) break;
                            if(remainder-5>=0){
                                remainder-=5;
                                currentCount--;
                                countOfEachBills.put(5, currentCount);
                            } else break;
                        }
                    }
                }
                if(remainder!=0) return false;
                if(countOfEachBills.containsKey(bills[i])){
                    countOfEachBills.put(bills[i], countOfEachBills.get(bills[i])+1);
                } else{
                    countOfEachBills.put(bills[i], 1);
                }
            } else{
                if(countOfEachBills.containsKey(5)){
                    int currentCount=countOfEachBills.get(5);
                    countOfEachBills.put(5, currentCount+1);
                } else{
                    countOfEachBills.put(5, 1);
                }
            }
        }
        return true;
    }
}