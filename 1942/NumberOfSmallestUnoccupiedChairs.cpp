/*
https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/?envType=daily-question&envId=2024-10-11
*/

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<int, int>>accordArrivalTimes;
        int sz=times.size();
        for(int i=0; i<sz; ++i) accordArrivalTimes.push_back({times[i][0], i});
        sort(accordArrivalTimes.begin(), accordArrivalTimes.end());
        priority_queue<int, vector<int>, greater<>>availableChairs_pq;
        for(int i=0; i<sz; ++i) availableChairs_pq.push(i);
        unordered_map<int, int>friendsToChair_mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>accordLeaveTime_pq;
        for(int i=0; i<sz; ++i){
            int currentArrivalTime=accordArrivalTimes[i].first, friendIndex=accordArrivalTimes[i].second;
            while(!accordLeaveTime_pq.empty()&&accordLeaveTime_pq.top().first<=currentArrivalTime){
                int chairToAdd=accordLeaveTime_pq.top().second;
                availableChairs_pq.push(chairToAdd);
                accordLeaveTime_pq.pop();
            }
            friendsToChair_mp[friendIndex]=availableChairs_pq.top();
            accordLeaveTime_pq.push({times[friendIndex][1], availableChairs_pq.top()});
            availableChairs_pq.pop();
        }
        return friendsToChair_mp[targetFriend];
    }
};