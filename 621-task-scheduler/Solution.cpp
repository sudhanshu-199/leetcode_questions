class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mp;
        int max_freq = 0, freq = 0;
        for(auto i:tasks){
            mp[i]++;
            max_freq = max(max_freq,mp[i]);
        }
        for(auto i:mp){
            if(i.second == max_freq)
            freq++;
        }
        if((max_freq-1)*(n+1)+freq <tasks.size())    
        return tasks.size();
        return (max_freq-1)*(n+1)+freq;
    }
};