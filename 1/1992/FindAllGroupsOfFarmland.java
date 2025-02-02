/*
https://leetcode.com/problems/find-all-groups-of-farmland/description/?envType=daily-question&envId=2024-04-20
*/

class Pair{

    public int first;
    public int second;

    public Pair(){};

    public Pair(int first, int second){
        this.first=first;
        this.second=second;
    }
}

class Solution {

    boolean isValid(int[][] land, int rws, int cols, HashSet<String>seen, int currw, int curcol){
        if(currw>=0&&curcol>=0&&currw<=rws-1&&curcol<=cols-1){
            if(land[currw][curcol]==1){
                String tochk=String.valueOf(currw)+"#"+String.valueOf(curcol);
                if(!seen.contains(tochk)){
                    return true;
                }
            }
        }
        return false;
    }

    public void dfs(int[][] land, int rws, int cols, HashSet<String>seen, int currw, int curcol,
                    ArrayList<Pair>curr){
        if(!isValid(land, rws, cols, seen, currw, curcol)) return;
        else{
            String tochk=String.valueOf(currw)+"#"+String.valueOf(curcol);
            seen.add(tochk);
            curr.add(new Pair(currw, curcol));
        }
        dfs(land, rws, cols, seen, currw+1, curcol, curr);
        dfs(land, rws, cols, seen, currw-1, curcol, curr);
        dfs(land, rws, cols, seen, currw, curcol+1, curr);
        dfs(land, rws, cols, seen, currw, curcol-1, curr);
        return;
    }

    public int[][] findFarmland(int[][] land) {
        int rws=land.length, cols=land[0].length;
        ArrayList<ArrayList<Integer>>res=new ArrayList<>();
        HashSet<String>seen=new HashSet<>();
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(land[i][j]==1){
                    String tochk=String.valueOf(i)+"#"+String.valueOf(j);
                    if(!seen.contains(tochk)){
                        ArrayList<Pair>curr=new ArrayList<>();
                        dfs(land, rws, cols, seen, i, j, curr);
                        Collections.sort(curr, new Comparator<Pair>() {
                            @Override
                            public int compare(Pair p1, Pair p2) {
                                return Integer.compare(p1.first, p2.first);
                            }
                        });
                        ArrayList<Integer>curres=new ArrayList<>();
                        curres.add(curr.get(0).first);
                        curres.add(curr.get(0).second);
                        curres.add(curr.get(curr.size()-1).first);
                        curres.add(curr.get(curr.size()-1).second);
                        res.add(curres);
                    }
                }
            }
        }
        int fnresln=res.size(), fnrescolln=4;
        int[][] fnresarr=new int[fnresln][fnrescolln];
        for(int i=0; i<fnresln; ++i){
            for(int j=0; j<4; ++j){
                fnresarr[i][j]=res.get(i).get(j);
            }
        }
        return fnresarr;
    }
}