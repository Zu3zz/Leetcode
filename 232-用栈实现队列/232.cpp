class MyQueue {
public:
    // 执行时间为0ms 主要用到两个stack 一个为sin 一个为sout
    // 当需要push的时候 正常使用stack的push操作将操作数push进sin里
    // 当需要执行pop操作时，使用temp和res记录中间变量的值
    /** Initialize your data structure here. */
    stack<int> sin;
    stack<int> sout;
    int res;
    int temp;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        sin.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(sout.empty()){
            while(!sin.empty()){
                temp = sin.top();
                sout.push(temp);
                sin.pop();
            }
            res = sout.top();
            sout.pop();
            return res;
        }
        else{
            res = sout.top();
            sout.pop();
            return res;
        }
        
    }
    
    /** Get the front element. */
    int peek() {
        if(!sout.empty()){
            res = sout.top();
        }
        else if (!sin.empty()){
            while(!sin.empty()){
                temp = sin.top();
                sout.push(temp);
                sin.pop();
            }
            res = sout.top();
        }
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return sin.empty() && sout.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */