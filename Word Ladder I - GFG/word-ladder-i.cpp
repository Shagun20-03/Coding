//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        //{character, length of sequence}
        queue<pair<string, int>>q;
        q.push({startWord,1});
        //unordered_set takes amartized O(1) TC
        unordered_set<string> s(wordList.begin(), wordList.end());
        //marking visited by deleting that element from set so that it is not taken again in future to avoid 
        //length increase
        s.erase(startWord);
        while(!q.empty()) {
            string word=q.front().first;
            int steps=q.front().second;
            //everytime we are traversing we are popping element form queue
            q.pop();
            // if(word==targetWord)
            // return steps;
            //traversing each character in every word
            for(int i=0; i<word.size(); i++) {
                char original=word[i];
                for(char ch='a'; ch<='z'; ch++) {
                    word[i]=ch;
                    //if that word exist in set 
                    if(s.find(word)!=s.end()) {
                        s.erase(word);
                        q.push({word, steps+1});
                    }
                }
                //if we do not get we have to take the original string for next step
                word[i]=original;
            }
            if(word==targetWord)
            return steps;
        }
        // no possible way to transform sequence from startWord to targetWord 
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends