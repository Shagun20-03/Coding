class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int leftSmaller[n], rightSmaller[n];
        
        //next smaller to left
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                leftSmaller[i]=0;
            }
            else{
                leftSmaller[i]=st.top()+1;  //storing index
            }
            st.push(i);
        }
        //reuse the prev stack
        while(!st.empty())
            st.pop();
        
        //next smaller to right
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                rightSmaller[i]=n-1;
            }
            else{
                rightSmaller[i]=st.top()-1;
            }
            st.push(i);
        }
        int maxarea=0;
        for(int i=0;i<n;i++){
            maxarea=max(maxarea, (rightSmaller[i]-leftSmaller[i]+1) * heights[i]);
        }
        return maxarea;
    }
};