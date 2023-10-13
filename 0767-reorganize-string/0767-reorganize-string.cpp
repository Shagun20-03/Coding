class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        vector<int> cnt(26, 0);
        
        for(char &ch: s){
            cnt[ch-'a']++;  //storing the freq 
            
            if(cnt[ch-'a']>(n+1)/2)     //if the freq of any char is greater then (n+1)/2
                return "";  //not possible
        }
        //max heap
        priority_queue<pair<int, char> , vector<pair<int, char>>> pq;
        
        // for(int i=0;i<n;i++){
        //     char ch=i+'a';
        //     if(cnt[i]>0){
        //          pq.push(cnt[i], ch)
        //      }
        // } Or
        for(char ch='a'; ch<='z'; ch++){
            if(cnt[ch-'a']>0){
                //{freq, char}
                pq.push({cnt[ch-'a'], ch});
            }
        }
        string res="";
        
        while(pq.size()>=2){    //pop 2 elements at a time
            auto P1=pq.top();
            pq.pop();
            
            auto P2=pq.top();
            pq.pop();
            
            res.push_back(P1.second);
            P1.first--; //decrease the freq
            res.push_back(P2.second);
            P2.first--;
            
            if(P1.first>0)  //if there are still elements left
                pq.push(P1);
            if(P2.first>0)
                pq.push(P2);
        }
        if(!pq.empty())
            res.push_back(pq.top().second);
        
        return res;
    }
    
};