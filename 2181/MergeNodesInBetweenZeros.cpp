/*
https://leetcode.com/problems/merge-nodes-in-between-zeros/description/?envType=daily-question&envId=2024-07-04
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
    ListNode* mergeNodes(ListNode* head) {
        vector<int>all, fn;
        while(head!=nullptr){
            all.push_back(head->val);
            head=head->next;
        }
        int idx=1;
        int cursm=0;
        while(true){
            if(idx>=all.size()) break;
            if(all[idx]==0){
                fn.push_back(cursm);
                cursm=0;
                idx++;
            } else{
                cursm+=all[idx];
                idx++;
            }
        }
        ListNode *res=new ListNode(fn[0]);
        ListNode *tail=res;
        for(int i=1; i<=fn.size()-1; ++i){
            ListNode *nwNode=new ListNode(fn[i]);
            tail->next=nwNode;
            tail=tail->next;
        }
        return res;
    }
};