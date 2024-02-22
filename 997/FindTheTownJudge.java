/*
https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22
*/

class Solution {

    public boolean binarySearch(ArrayList<Integer>arrl, int val){
        Collections.sort(arrl);
        int left=0, right=arrl.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(arrl.get(mid)==val) return true;
            else if(arrl.get(mid)>val){
                right=mid-1;
            } else left=mid+1;
        }
        return false;
    }

    public boolean find(ArrayList<Integer>arrl, int val){
        return binarySearch(arrl, val);
    }

    public int findJudge(int n, int[][] trust) {
        int sz=trust.length;
        if(sz==0){
            if(n!=1) return -1;
            return 1;
        }
        TreeMap<Integer, ArrayList<Integer>>pplsmp=new TreeMap<>();
        for(int i=0; i<sz; ++i){
            if(pplsmp.containsKey(trust[i][0])){
                ArrayList<Integer>curr=pplsmp.get(trust[i][0]);
                curr.add(trust[i][1]);
                pplsmp.put(trust[i][0], curr);
            } else{
                ArrayList<Integer>nw=new ArrayList<>();
                nw.add(trust[i][1]);
                pplsmp.put(trust[i][0], nw);
            }
        }
        for(int i=1; i<=n; ++i){
            if(!pplsmp.containsKey(i)){
                boolean flag1=false;
                for(int j=1; j<=n; ++j){
                    if(j!=i){
                        if(pplsmp.containsKey(j)){
                            ArrayList<Integer>arrl=pplsmp.get(j);
                            boolean flag2=find(arrl, i);
                            if(!flag2){
                                flag1=true;
                                break;
                            }
                        } else{
                            flag1=true;
                            break;
                        }
                    }
                }
                if(!flag1) return i;
            }
        }
        return -1;
    }
}