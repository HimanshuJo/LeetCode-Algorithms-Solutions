/*
https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2024-03-08
*/

class Solution {
    public int maxFrequencyElements(int[] nums) {
        HashMap<Integer, Integer>mp1=new HashMap<>();
        TreeMap<Integer, ArrayList<Integer>>mp2=new TreeMap<>(Collections.reverseOrder());
        int sz=nums.length;
        for(int i=0; i<sz; ++i){
            if(mp1.containsKey(nums[i])){
                mp1.put(nums[i], mp1.get(nums[i])+1);
            } else mp1.put(nums[i], 1);
        }
        for(Map.Entry<Integer, Integer>entry: mp1.entrySet()){
            if(mp2.containsKey(entry.getValue())){
                ArrayList<Integer>curr=mp2.get(entry.getValue());
                curr.add(entry.getKey());
                mp2.put(entry.getValue(), curr);
            } else{
                ArrayList<Integer>nwarl=new ArrayList<>();
                nwarl.add(entry.getKey());
                mp2.put(entry.getValue(), nwarl);
            }
        }
        for(Map.Entry<Integer, ArrayList<Integer>>entry: mp2.entrySet()){
            return entry.getKey()*entry.getValue().size();
        }
        return -1;
    }
}