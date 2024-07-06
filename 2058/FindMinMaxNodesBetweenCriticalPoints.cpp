/*
https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/?envType=daily-question&envId=2024-07-05
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>all, cp;
        while(head!=nullptr){
            all.push_back(head->val);
            head=head->next;
        }
        int sz=all.size();
        for(int i=1; i<sz; ++i){
            if(i+1<=sz-1){
                if(all[i]>all[i-1]&&all[i]>all[i+1]){
                    cp.push_back(i+1);
                } else if(all[i]<all[i-1]&&all[i]<all[i+1]){
                    cp.push_back(i+1);
                }
            }
        }
        vector<int>res;
        int curmin=INT_MAX, curmax=INT_MIN;
        if(cp.size()>=2){
	        sort(cp.begin(), cp.end());
            curmax=max(curmax, abs(cp[0]-cp[cp.size()-1]));
            for(int i=0; i<cp.size(); ++i){
                if(i+1<=cp.size()-1)
                    curmin=min(curmin, abs(cp[i]-cp[i+1]));
            }
        }
        res.push_back(curmin==INT_MAX?-1:curmin);
        res.push_back(curmax==INT_MIN?-1:curmax);
        return res;
    }
};