class MyQueue {
    stack<int> input, output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int res=output.top();
        output.pop();
        return res;
    }
    
    int peek() {
        if(output.empty())  // output is empty push element into it
            while(input.size())
            {
                output.push(input.top());
                input.pop();
            }
        return output.top();
    }
    
    bool empty() {
        if(output.empty() && input.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */