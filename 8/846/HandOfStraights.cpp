/*
https://leetcode.com/problems/hand-of-straights/description/?envType=daily-question&envId=2024-06-06
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int sz=hand.size();
        sort(hand.begin(), hand.end());
        vector<int>curr;
        curr.push_back(hand[0]);
        hand.erase(hand.begin());
        while(true){
            if(curr.size()==groupSize){
                curr.clear();
                if(hand.empty()) break;
                curr.push_back(hand[0]);
                hand.erase(hand.begin());
                continue;
            } else{
                if(hand.empty()) break;
                auto itr=find(hand.begin(), hand.end(), curr.back()+1);
                if(itr!=hand.end()){
                    curr.push_back(*itr);
                    hand.erase(itr);
                } else return false;
            }
        }
        if(!curr.empty()) return false;
        return true;
    }
};