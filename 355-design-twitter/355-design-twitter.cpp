class Twitter {
public:
    set<pair<int,int>> st;
    vector<pair<int,int>> g;
    int count=0;
    
    Twitter() {
        st.clear();
        g.clear();
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        g.push_back({userId,tweetId});
        count++;
    }
    
    vector<int> getNewsFeed(int userId) {
       vector<int> v;
        int k=0;
        for(int i=count-1;i>=0&&k<10;i--)
        {
            if(g[i].first==userId)
            {
v.push_back(g[i].second);
                k++;
            }
            
            else if(st.find({userId,g[i].first})!=st.end())
            {
                v.push_back(g[i].second);
                k++;
            }
        }
        
        return v;
    }
    
    void follow(int followerId, int followeeId) {
        st.insert({followerId,followeeId});
    }
    
    void unfollow(int followerId, int followeeId) {
        st.erase({followerId,followeeId});
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */