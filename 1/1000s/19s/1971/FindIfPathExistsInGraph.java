/*
https://leetcode.com/problems/find-if-path-exists-in-graph/description/?envType=daily-question&envId=2024-04-21
*/

class Solution {

    public void dfs(int source, int destination, ArrayList<ArrayList<Integer>>gr, HashSet<Integer>seen,
                    boolean[] flag){
        if(source==destination){
            flag[0]=true;
            return;
        }  
        int curgrsz=gr.get(source).size();        
        for(int i=0; i<curgrsz; ++i){
            int nei=gr.get(source).get(i);
            if(!seen.contains(nei)){
                seen.add(nei);
                dfs(nei, destination, gr, seen, flag);
            }
        }
        return;          
    }

    public boolean validPath(int n, int[][] edges, int source, int destination) {
        ArrayList<ArrayList<Integer>>gr=new ArrayList<>();
        for(int i=0; i<n; ++i){
            gr.add(new ArrayList<Integer>());
        }
        int sz=edges.length;
        for(int i=0; i<sz; ++i){
            gr.get(edges[i][0]).add(edges[i][1]);
            gr.get(edges[i][1]).add(edges[i][0]);
        }
        HashSet<Integer>seen=new HashSet<>();
        boolean[] flag=new boolean[1];
        flag[0]=false;
        seen.add(source);
        dfs(source, destination, gr, seen, flag);
        return flag[0];
    }
}