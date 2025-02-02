/*
https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=daily-question&envId=2024-01-29
*/

class MyQueue {

    private queueList:number[];

    constructor() {
        this.queueList=[];
    }

    push(x: number): void {
        this.queueList.push(x);
    }

    pop(): number {
        let topEle:number=this.queueList[0];
        this.queueList.shift();
        return topEle;
    }

    peek(): number {
        let topEle:number=this.queueList[0];
        return topEle;
    }

    empty(): boolean {
        return this.queueList.length===0;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */