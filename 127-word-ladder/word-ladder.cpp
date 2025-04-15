class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordset(wordList.begin(),wordList.end());
        if(wordset.find(endWord)==wordset.end()){
            return 0;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto[word,steps]=q.front();
            q.pop();
            if(word==endWord){
                return steps;
            }
            for(int i=0;i<word.size();++i){
                string temp=word;
                for(char c='a';c<='z';++c){
                    temp[i]=c;
                    if(wordset.find(temp)!=wordset.end()){
                        q.push({temp,steps+1});
                        wordset.erase(temp);
                    }
                }
            }
        }
        return 0;  
    }
};