/*
https://leetcode.com/problems/design-a-stack-with-increment-operation/submissions/1406973986/?envType=daily-question&envId=2024-09-30
*/

class CustomStack {

    public ArrayList<Integer>resultantStack;
    public int maximumAllocatedSize;

    public CustomStack(int maxSize) {
        resultantStack=new ArrayList<>();
        maximumAllocatedSize=maxSize;
    }
    
    public void push(int x) {
        if(resultantStack.size()<maximumAllocatedSize){
            resultantStack.add(x);
        }
    }
    
    public int pop() {
        if(resultantStack.size()==0) return -1;
        int requiredIndex=resultantStack.size()-1;
        int numberToRemove=resultantStack.get(requiredIndex);
        resultantStack.remove(requiredIndex);
        return numberToRemove;
    }
    
    public void increment(int k, int val) {
        int stackCurrentSize=resultantStack.size();
        if(stackCurrentSize<k){
            for(int i=0; i<stackCurrentSize; ++i){
                resultantStack.set(i, resultantStack.get(i)+val);
            }
        } else{
            int currentCount=0;
            for(int i=0; i<stackCurrentSize; ++i){
                resultantStack.set(i, resultantStack.get(i)+val);
                currentCount++;
                if(currentCount==k) break;
            }
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */