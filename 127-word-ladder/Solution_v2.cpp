class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string> s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int ans=q.front().second;
            q.pop();
            if(word==endWord)
            return ans;
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.count(word)){
                        q.push({word,ans+1});
                        s.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};