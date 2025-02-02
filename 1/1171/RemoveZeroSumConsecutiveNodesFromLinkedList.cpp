/*
https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/submissions/1201407067/?envType=daily-question&envId=2024-03-12
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int>all;
        while(head!=nullptr){
            all.push_back(head->val);
            head=head->next;
        }
        int sz=all.size();
        while(true){
            int bgn=-1, end=-1;
            bool flag=false;
            for(int i=0; i<sz; ++i){
                int cursm=0;
                for(int j=i; j<sz; ++j){
                    cursm+=all[j];
                    if(cursm==0){
                        flag=true;
                        bgn=i, end=j;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag){
                for(int i=bgn; i<=end; ++i){
                    all[i]=INT_MIN;
                }
                all.erase(remove(all.begin(), all.end(), INT_MIN), all.end());
                sz=all.size();
            } else break;
        }
        if(all.size()==0) return nullptr;
        ListNode *res=new ListNode(all[0]);
        ListNode *nxt=res;
        for(int i=1; i<all.size(); ++i){
            nxt->next=new ListNode(all[i]);
            nxt=nxt->next;
        }
        return res;
    }
};