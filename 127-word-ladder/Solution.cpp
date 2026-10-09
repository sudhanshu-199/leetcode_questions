class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> words(wordList.begin(), wordList.end());

        if (words.find(endWord) == words.end()) {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord) {
                return steps;
            }
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original) {
                        continue;
                    }

                    word[i] = c;

                    if (words.find(word) != words.end() &&
                        visited.find(word) == visited.end()) {

                        visited.insert(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};