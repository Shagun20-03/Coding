class Solution {
public:
    //we can only take 2 types of fruit as thre are 2 baskets and a basket can take only single type of fruit
    //longest length of subarray with atmost two diff nos
    int totalFruit(vector<int>& fruits) {
        set<int> s; //to keep distinct type of trees
        for(int i: fruits){
            s.insert(i);
        }
        if(s.size()<=2) return fruits.size(); //array already contains 2 diff type of fruit
        fruits.push_back(100001);   //max size of fruit array allowed is 10^5
        int n=fruits.size();
        int j=0, total=0;
        vector<int> freq(100005);
        int maxi=0;
        
        for(int i=0;i<n;i++){
            if(freq[fruits[i]]==0 && total==2)  //means new type of fruit is found and already we have 2 diff type of fruits
            {
                maxi=max(maxi, i-j);    //i is for every index and j s for diff type of fuits index
                //we have to move j as i has found new type of fruitso that the ranje i, i consists only 2 type of fruit
                while(j<i)
                {
                    if(freq[fruits[j]]>1)   //keep on deleting the fruit if the freq of that fruit is more than 1 to reach the next type of fruit
                    {
                        freq[fruits[j]]--;
                        j++;
                    }
                    else if(freq[fruits[j]]==1)
                    {
                        freq[fruits[j]]--;
                        j++;
                        break;
                    }
                }
                freq[fruits[i]]++;  //for valid conditions
            }
            else if(freq[fruits[i]]==0){ //valid for two types and new type
                total++;
                freq[fruits[i]]++;
            }
            else{
                freq[fruits[i]]++;  //valid for same 2 type
            }
        }
        return maxi;
    }
};