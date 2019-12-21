class MyQueue {
  private Stack<Integer> inStack;
  private Stack<Integer> outStack;
  /** Initialize your data structure here. */
  public MyQueue() {
      inStack = new Stack<>();
      outStack = new Stack<>();
  }
  
  /** Push element x to the back of queue. */
  public void push(int x) {
      inStack.push(x);
  }
  
  /** Removes the element from in front of queue and returns that element. */
  public int pop() {
      checkOutStack();
      return outStack.pop();
  }
  
  /** Get the front element. */
  public int peek() {
      checkOutStack();
      return outStack.peek();
  }
  
  /** Returns whether the queue is empty. */
  public boolean empty() {
      return inStack.isEmpty() && outStack.isEmpty();
  }
  private void checkOutStack(){
      if(outStack.isEmpty()){
          while(!inStack.isEmpty()){
              outStack.push(inStack.pop());
          }
      }
  }
}

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue obj = new MyQueue();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.peek();
* boolean param_4 = obj.empty();
*/