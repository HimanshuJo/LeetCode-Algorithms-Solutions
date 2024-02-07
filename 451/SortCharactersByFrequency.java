/*
https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07
*/

class Solution {
    public String frequencySort(String s) {
        HashMap<Character, Integer>mp1=new HashMap<>();
        int sz=s.length();
        for(int i=0; i<sz; ++i){
            if(mp1.containsKey(s.charAt(i))){
                mp1.put(s.charAt(i), mp1.get(s.charAt(i))+1);
            } else mp1.put(s.charAt(i), 1);
        }
        TreeMap<Integer, List<Character>>mp2=new TreeMap<>();
        for(Map.Entry<Character, Integer>entries: mp1.entrySet()){
            if(mp2.containsKey(entries.getValue())){
                List<Character>curlst=mp2.get(entries.getValue());
                curlst.add(entries.getKey());
                mp2.put(entries.getValue(), curlst);
            } else{
                List<Character>curlst=new ArrayList<>();
                curlst.add(entries.getKey());
                mp2.put(entries.getValue(), curlst);
            }
        }
        StringBuilder res=new StringBuilder();
        for(Map.Entry<Integer, List<Character>>entries: mp2.entrySet()){
            int count=entries.getKey();
            List<Character>curlst=entries.getValue();
            int curlstsz=curlst.size();
            for(int i=0; i<curlstsz; ++i){
                for(int j=0; j<count; ++j){
                    res.append(curlst.get(i));
                }
            }
        }
        return String.valueOf(res.reverse());
    }
}