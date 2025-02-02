/*
httpsleetcode.comproblemsspiral-matrix-iv
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>mat(m, vector<int>(n, -1));
        vector<int>dir={1, 2, 3, 4};
        int idx=0, currw=0, currcol=0;
        set<pair<int, int>>seen;
        while(head!=nullptr){
            int curval=head->val, currdir=dir[idx];
            if(currdir==1){
                mat[currw][currcol]=curval;
                seen.insert({currw, currcol});
                currcol++;
                if(seen.find({currw, currcol})!=seen.end()||currcol>=n){
                    currcol--;
                    currw++;
                    idx++;
                    if(idx>=dir.size()){
                        idx=0;
                    }
                }
            } else if(currdir==2){
                mat[currw][currcol]=curval;
                seen.insert({currw, currcol});
                currw++;
                if(seen.find({currw, currcol})!=seen.end()||currw>=m){
                    currw--;
                    currcol--;
                    idx++;
                    if(idx>=dir.size()){
                        idx=0;
                    }
                }
            } else if(currdir==3){
                mat[currw][currcol]=curval;
                seen.insert({currw, currcol});
                currcol--;
                if(seen.find({currw, currcol})!=seen.end()||currcol<0){
                    currcol++;
                    currw--;
                    idx++;
                    if(idx>=dir.size()){
                        idx=0;
                    }
                }
            } else if(currdir==4){
                mat[currw][currcol]=curval;
                seen.insert({currw, currcol});
                currw--;
                if(seen.find({currw, currcol})!=seen.end()||currw<0){
                    currw++;
                    currcol++;
                    idx++;
                    if(idx>=dir.size()){
                        idx=0;
                    }
                }
            }
            head=head->next;
        }
        return mat;
    }
};