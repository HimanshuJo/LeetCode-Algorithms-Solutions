/*
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/?envType=daily-question&envId=2024-03-18
*/

/*
TLE:

class CustomComparator{
    public:
    bool operator()(const vector<int>A, const vector<int>B){
        return A[1]<=B[1];
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), CustomComparator());
        int res=INT_MAX;
        vector<int>allends;
        for(auto &vals: points){
            allends.push_back(vals[1]);
        }
        for(auto &vals: allends){
            int curval=vals;
            int curarrow=1;
            for(auto &pnts: points){
                if(curval>=pnts[0]&&curval<=pnts[1]){
                    continue;
                } else{
                    curval=max(curval, pnts[1]);
                    curarrow++;
                }
            }
            res=min(res, curarrow);
        }
        return res;
    }
};
*/

class CustomComparator{
    public:
    bool operator()(const vector<int>A, const vector<int>B){
        return A[1]<B[1];
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(), points.end(), CustomComparator());
        int arrows=1, curend=points[0][1], sz=points.size();
        if(sz>1){
            for(int i=1; i<sz; ++i){
                if(points[i][0]>curend){
                    arrows++;
                    curend=points[i][1];
                }
            }
        }
        return arrows;
    }
};