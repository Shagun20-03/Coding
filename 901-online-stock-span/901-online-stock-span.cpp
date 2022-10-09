class StockSpanner {
    stack<pair<int, int>>st;
public:
    StockSpanner() {
      
    }
    
    int next(int price) {
//         vector<int> v;
//         stack<pair<int, int>>st;
        
//         int n=sizeof(price);
        
//         for(int i=0;i<n;i++)
//         {
//             if(s.size()==0){
//                 v.push_back(-1);
//             }
//             else if(s.size()>0 s.top().first>price[i]){
//                 v.push_back(s.top().second);
//             }
//         }
        
        int res = 1;
        while (!st.empty() && st.top().first <= price) {
            res += st.top().second;
            st.pop();
        }
        st.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */