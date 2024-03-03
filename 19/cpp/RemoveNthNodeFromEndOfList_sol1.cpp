/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<int>all;
        while(head!=nullptr){
            all.push_back(head->val);
            head=head->next;
        }
        int todel=all.size()-n;
        auto itr=all.begin()+todel;
        all.erase(itr);
        if(all.size()>=1){
            ListNode *res=new ListNode(all[0]);
            ListNode *nxt=res;
            for(int i=1; i<all.size(); ++i){
                ListNode *nw=new ListNode(all[i]);
                nxt->next=nw;
                nxt=nxt->next;
            }
            return res;
        }
        return nullptr;
    }
};