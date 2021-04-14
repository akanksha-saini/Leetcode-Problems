/*
Implement a last in first out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal queue (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue), as long as you use only a queue's standard operations.
 

Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]
*/


class MyStack {
public:
    queue<int> q1;
	queue<int> q2;
	int cs;
    /** Initialize your data structure here. */
    MyStack() {
       cs = 0; 
    }
    
    /** Push element val onto stack. */
    void push(int val) {
        cs++;
			
			//if both q1,q2 are empty
			if(q1.empty() && q2.empty())
			{
				q1.push(val);
			}
			else if(!q1.empty())
			   q1.push(val);
			
			else
			  q2.push(val);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty() && q2.empty())
			   return -1;
			
			cs--;
			if(!q1.empty())
			{
				//access last element
			   while(q1.size() > 1)
			   {
			   int x  = q1.front();
			   q2.push(x);
			   q1.pop();	
			  }
               int x  = q1.front(); 
			   q1.pop();
               return x; 
			}
			else if(!q2.empty())
			{
				while(q2.size() > 1)
				{
					int x = q2.front();
					q1.push(x);
					q2.pop();
				}
                int x = q2.front();
				q2.pop();
                return x;
			}
        return -1;
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty() && q2.empty())
			   return -1;
			
			cs--;
			if(!q1.empty())
			{
				//access last element
			   while(q1.size() > 1)
			   {
			   int x  = q1.front();
			   q2.push(x);
			   q1.pop();	
			  }
			   int x  = q1.front();
			   q2.push(x);
			   q1.pop();
			   return x;
			}
			else if(!q2.empty())
			{
				while(q2.size() > 1)
				{
					int x = q2.front();
					q1.push(x);
					q2.pop();
				}
			   int x  = q2.front();
			   q1.push(x);
			   q2.pop();
			   return x;
			}
        return -1;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q1.empty() && q2.empty())
			  return true;
			return false; 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
