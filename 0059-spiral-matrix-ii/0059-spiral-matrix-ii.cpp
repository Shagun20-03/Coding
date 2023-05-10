class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n));
        int cnt=1;
        for(int layer=0;layer<(n+1)/2;layer++){
            //left to right
            for(int ptr=layer; ptr<n-layer;ptr++){
                res[layer][ptr]=cnt++;
            }
            //top to bottom
            for(int ptr=layer+1; ptr<n-layer;ptr++){
                res[ptr][n-layer-1]=cnt++;
            }
            //right to left
            for(int ptr=n-layer-2;ptr>=layer;ptr--){
                res[n-layer-1][ptr]=cnt++;
            }
            //bottom to top
            for(int ptr=n-layer-2;ptr>layer;ptr--){
                res[ptr][layer]=cnt++;
            }
        }
        return res;
    }
};