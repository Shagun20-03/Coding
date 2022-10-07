class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int val) {
        long long value=val;
        if(st.empty()){
            mini=value;
            st.push(value);
        }
        else{
            if(value<mini){    //push modified value
                st.push((1LL*2*value)-mini);
                mini=value;
            }
            else{
                st.push(value);
            }
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        long long ele=st.top();
        st.pop();
        
        if(ele<mini){           //it means top element is the modifed value
            mini=2*mini-ele;     //rollback mini value to prev mini
        }
    }
    
    int top() {
        if(st.empty())
            return -1;
        long long ele=st.top();
        if(ele<mini)    //if modified value is les than mini
            return mini;
        return ele;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */