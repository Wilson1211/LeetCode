class Solution {
    public:
        struct info{
            int v,p1,p2; // v is the sum of two elements, p1 is the index of the first array and p2 is the index of the second array
        };
        struct Comparele{  // This will compare elements in the priority queue in increasing order of v
        bool operator()(info const& p1, info const& p2){
            return p1.v>p2.v;
        } 
    };
    vector<vector<int>> kSmallestPairs(vector<int>& n1, vector<int>& n2, int k) {
        vector<vector<int>> ret;
        priority_queue<info,vector<info>,Comparele> pq;
        for(int i=0;i<n1.size();i++) pq.push({n1[i]+n2[0],i,0}); // pushed all elements of first array with the first element of the second array
        while(k-- && pq.size()){
            auto [v,p1,p2] = pq.top();
            pq.pop();
            ret.push_back({n1[p1],n2[p2]});
            if(p2+1<n2.size()) pq.push({n1[p1]+n2[p2+1],p1,p2+1}); // pushing the next element
        }
        return ret;
    }
};