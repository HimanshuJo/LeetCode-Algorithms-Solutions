/*
https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=daily-question&envId=2024-01-29
*/

public class MyQueue {

    private Stack<int>stk1;
    private Stack<int>stk2;

    public MyQueue() {
        stk1=new Stack<int>();
        stk2=new Stack<int>();
    }
    
    public void Push(int x) {
        stk1.Push(x);
    }
    
    public int Pop() {
        while(stk2.Count!=0){
            stk2.Pop();
        }
        while(stk1.Count!=0){
            stk2.Push(stk1.Pop());
        }
        int res=stk2.Pop();
        while(stk2.Count!=0){
            stk1.Push(stk2.Pop());
        }
        return res;
    }
    
    public int Peek() {
        while(stk2.Count!=0){
            stk2.Pop();
        }
        while(stk1.Count!=0){
            stk2.Push(stk1.Pop());
        }
        int res=stk2.Peek();
        while(stk2.Count!=0){
            stk1.Push(stk2.Pop());
        }
        return res;
    }
    
    public bool Empty() {
        return stk1.Count==0;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.Push(x);
 * int param_2 = obj.Pop();
 * int param_3 = obj.Peek();
 * bool param_4 = obj.Empty();
 */