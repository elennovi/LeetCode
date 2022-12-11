class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // use a map (find operation)
        unordered_map<string, int> mmap;
        for (int i = 0; i< wordList.size(); i++)
            mmap.insert({wordList[i], i}); // insert the word in the map
        mmap.insert({beginWord, wordList.size()});

        // the bfs solution to the problem 
        vector<bool> visited(mmap.size(), 0); 
        queue<pair<string, int>> q; // to store the words to loop through and the number of words
        // already processed
        q.push({beginWord, 1});
        while(!q.empty()){
            string curr = q.front().first;
            int numb = q.front().second;
            q.pop(); // delete the element, already loop trough
            visited[mmap.find(curr)->second] = true;
            if (curr == endWord) // find the endword
                return numb; // return the number of words 

            // calculating its adjacenct nodes
            for (int p = 0; p < endWord.length(); p++){
                char letter = 'a'; 
                for (int i = 0; i < 26; i++){
                    string adj = curr;
                    adj[p] = letter + i; // change the letter
                    auto it = mmap.find(adj);
                    if (it != mmap.end() && !visited[it->second]) // exists and not visited
                        q.push({adj, numb + 1});
                }
            }
        }
        return 0; // impossible to reach the endWord
    }
};
