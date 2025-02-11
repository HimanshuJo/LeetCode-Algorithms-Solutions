/*
https://leetcode.com/problems/design-a-stack-with-increment-operation/submissions/1406973986/?envType=daily-question&envId=2024-09-30
*/

class CustomStack {
public:

    vector<int>resStack;
    int sz;

    CustomStack(int maxSize) {
        sz=maxSize;
    }
    
    void push(int x) {
        if(resStack.size()<sz)
            resStack.push_back(x);
    }
    
    int pop() {
        if(resStack.size()==0) return -1;
        int res=resStack.back();
        resStack.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        if(resStack.size()<k){
            for(auto &vals: resStack) vals+=val;
        } else{
            int count=0;
            for(int i=0; i<resStack.size(); ++i){
                resStack[i]+=val;
                count++;
                if(count==k) break;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */