//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	struct Node{
	    int data;
	    struct Node* left;
	    struct Node* right;
	    
	    Node(int val){
	        data=val;
	        left=NULL;
	        right=NULL;
	    }
	};
	
	struct cmp{
	    bool operator()(Node* l, Node* r){
	        return (l->data > r->data); //taking left value first for min heap
	    }
	};
	
	void preOrder(Node *root, string s, vector<string> &ans){
	    if(!root)
	    return;
	    
	    if(!root->left && !root->right){
	        ans.push_back(s);
	    }
	    preOrder(root->left, s+"0", ans);
	    preOrder(root->right, s+"1", ans);
	}
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<Node*, vector<Node*>, cmp> min_heap;
		    
		    for(int i=0;i<N;i++){
		        Node* temp=new Node(f[i]);  //inserting frequency in leaf node 
		        min_heap.push(temp);
		    }
		    
		    while(min_heap.size()>1){
		        Node* left=min_heap.top();  //as the 1st top element of min heap contains min value element so we are putting it in left node
		        min_heap.pop();
		        Node* right=min_heap.top();
		        min_heap.pop();
		        Node* parent=new Node(left->data+right->data);
		        parent->left=left;
		        parent->right=right;
		        min_heap.push(parent);
		    }
		    Node* root=min_heap.top();
		    min_heap.pop();
		    vector<string> ans;
		    preOrder(root, "", ans);    //preorder traversal to find huffman code values
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends