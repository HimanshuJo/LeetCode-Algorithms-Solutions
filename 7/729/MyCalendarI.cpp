/*
https://leetcode.com/problems/my-calendar-i/description/?envType=daily-question&envId=2024-09-26
*/

class MyCalendar {
public:

    map<int, int>mp;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto nextEvent=mp.upper_bound(start);
        if(nextEvent!=mp.end()&&nextEvent->first<end){
            return false;
        }
        if(nextEvent!=mp.begin()){
            auto prevEvent=prev(nextEvent);
            if(prevEvent->second>start) return false;
        }
        mp[start]=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */