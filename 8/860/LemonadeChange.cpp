/*
https://leetcode.com/problems/lemonade-change/description/?envType=daily-question&envId=2024-08-15
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int>mp;
        for(auto &vals: bills){
            if(vals>5){
                int rem=vals-5;
                if(rem>=20){
                    if(mp.find(20)!=mp.end()){
                        int count=mp[20];
                        while(true){
                            if(count==0||rem==0) break;
                            if(rem-20>=0){
                                rem-=20;
                                count--;
                                mp[20]--;
                            } else break;
                        }
                    }
                }
                if(rem>=10){
                    if(mp.find(10)!=mp.end()){
                        int count=mp[10];
                        while(true){
                            if(count==0||rem==0) break;
                            if(rem-10>=0){
                                rem-=10;
                                count--;
                                mp[10]--;
                            } else break;
                        }
                    }
                }
                if(rem>=5){
                    if(mp.find(5)!=mp.end()){
                        int count=mp[5];
                        while(true){
                            if(count==0||rem==0) break;
                            if(rem-5>=0){
                                rem-=5;
                                count--;
                                mp[5]--;
                            } else break;
                        }
                    }
                }
                if(rem!=0) return false;
                mp[vals]++;
            } else{
                mp[5]++;
            }
        }
        return true;
    }
};