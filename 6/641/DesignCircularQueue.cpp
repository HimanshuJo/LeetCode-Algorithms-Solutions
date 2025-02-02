/*
https://leetcode.com/problems/design-circular-deque/?envType=daily-question&envId=2024-09-28
*/

class MyCircularDeque {
public:

    vector<int>queue;
    int finalSize;

    MyCircularDeque(int k) {
        finalSize=k;
    }
    
    bool insertFront(int value) {
        if(queue.size()==finalSize) return false;
        if(queue.size()>=1){
            queue.insert(queue.begin(), value);
            return true;
        }
        queue.push_back(value);
        return true;
    }
    
    bool insertLast(int value) {
        if(queue.size()==finalSize) return false;
        queue.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(queue.size()>=1){
            queue.erase(queue.begin());
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(queue.size()>=1){
            queue.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(queue.size()>=1) return queue[0];
        return -1;
    }
    
    int getRear() {
        if(queue.size()>=1) return queue[queue.size()-1];
        return -1;
    }
    
    bool isEmpty() {
        return queue.empty();
    }
    
    bool isFull() {
        return queue.size()==finalSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */