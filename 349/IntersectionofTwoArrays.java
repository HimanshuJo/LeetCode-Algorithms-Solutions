/*
https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=daily-question&envId=2024-03-10
*/

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
       HashSet<Integer>st=new HashSet<>();
       HashMap<Integer, Integer>mp=new HashMap<>();
       for(int nums: nums1){
           if(mp.containsKey(nums)){
               mp.put(nums, mp.get(nums)+1);
           } else mp.put(nums, 1);
       }
       for(int nums: nums2){
           if(mp.containsKey(nums)){
               st.add(nums);
           }
       }
       int fnsz=st.size();
       int[] res=new int[fnsz];
       int idx=0;
       Iterator itr=st.iterator();
       while(itr.hasNext()){
           res[idx++]=(int)itr.next();
       }
       return res; 
    }
}