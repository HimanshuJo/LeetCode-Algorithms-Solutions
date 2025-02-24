/*
https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2024-08-09
*/

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rws=grid.size(), cols=grid[0].size(), res=0;
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(i+2<=rws-1&&j+2<=cols-1){
                    set<int>seen;
                    int smtochk=0;
                    bool flag=false;
                    for(int k=i; k<=i+2; ++k){
                        if(grid[k][j]>9||grid[k][j]<=0){
                            flag=true;
                            break;
                        }
                        smtochk+=grid[k][j];
                    }
                    if(!flag){
                        for(int l=j; l<=j+2; ++l){
                            int smtochk2=0;
                            for(int k=i; k<=i+2; ++k){
                                if(grid[k][l]>9||grid[k][l]<=0){
                                    flag=true;
                                    break;
                                }
                                smtochk2+=grid[k][l];
                            }
                            if(smtochk2!=smtochk){
                                flag=true;
                                break;
                            }
                        }
                        if(!flag){
                            int smtochk3=0, smtochk4=0;
                            smtochk3+=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                            smtochk4+=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
                            if(smtochk3!=smtochk||smtochk4!=smtochk){
                                flag=true;
                                continue;
                            }
                            if(!flag){
                                for(int k=i; k<=i+2; ++k){
                                    int cursm=0;
                                    for(int l=j; l<=j+2; ++l){
                                        if(seen.find(grid[k][l])!=seen.end()||(grid[k][l]>9)||(grid[k][l]<=0)){
                                            flag=true;
                                            break;
                                        }
                                        seen.insert(grid[k][l]);
                                        cursm+=grid[k][l];
                                    }
                                    if(cursm!=smtochk){
                                        flag=true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if(!flag) res++;
                }
            }
        }
        return res;
    }
};