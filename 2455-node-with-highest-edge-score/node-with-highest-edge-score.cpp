class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<long long>score(n,0);
        for(int i=0;i<n;++i){
            score[edges[i]]+=i;
        }
        long long maxscore=-1;
        int resultnode=-1;
        for(int i=0;i<n;++i){
            if(score[i]>maxscore){
                maxscore=score[i];
                resultnode=i;
            }
        }
        return resultnode;
        
    }
};