/*
https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/?envType=daily-question&envId=2024-05-07
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
    ListNode* doubleIt(ListNode* head) {
        vector<int>all, fn;
        while(head!=nullptr){
            all.push_back(head->val);
            head=head->next;
        }
        vector<int>sec=all;
        int sz=all.size(), curcarry=0;
        for(int i=sz-1; i>=0; --i){
            int cursm=all[i]+sec[i];
            if(i>0){
                cursm+=curcarry;
                curcarry=cursm/10;
                cursm%=10;
                fn.push_back(cursm);
            } else{
                cursm+=curcarry;
                fn.push_back(cursm);
            }
        }
        reverse(fn.begin(), fn.end());
        string lntomk="";
        for(auto &vals: fn){
            lntomk+=to_string(vals);
        }
        int fnsz=lntomk.size();
        ListNode *root=new ListNode(lntomk[0]-'0');
        ListNode *nxt=root;
        for(int i=1; i<fnsz; ++i){
            ListNode *nwNode=new ListNode(lntomk[i]-'0');
            nxt->next=nwNode;
            nxt=nxt->next;
        }
        return root;
    }
};