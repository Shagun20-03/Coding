//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(), wordList.end());
        //queue will contain list of words
        queue<vector<string>> q;
        q.push({beginWord});
        //words that are previously used
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        //before starting we are at level 0
        int level=0;
        vector<vector<string>> ans;
        while(!q.empty())
        {
            vector<string> vec=q.front();
            q.pop();
            //erase all words that have been used in the previous levels 
            if(vec.size()>level) {
                level++;
                for(auto it: usedOnLevel) {
                    st.erase(it);
                }
            }
            
        //last word in the sequence will be the word used for transformation
        string word=vec.back();
        
        for(int i=0;i<word.size();i++) {
            char original=word[i];
            for(char c='a';c<='z';c++) {
                word[i]=c;
                //if a word comes more than 1 time
                if(st.count(word)>0) {
                    vec.push_back(word);
                    q.push(vec);
                    //mark as visited on level
                    usedOnLevel.push_back(word);
                    //for particular transformtion thw word was added but we need to take it out for further 
                    //steps
                    vec.pop_back();
                }
            }
            word[i]=original;
        }
        if(word==endWord) {
            if(ans.size()==0) {
                ans.push_back(vec);
            }
        //if we have one of the sequence in the answer
        else if(ans[0].size()==vec.size()){
            ans.push_back(vec);
        }
        }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends