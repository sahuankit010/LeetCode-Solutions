class Twitter {
public:
    map<int, set<int>> friends;
    stack<vector<int>> timeline;
    Twitter() {
        friends.clear();
        timeline = stack<vector<int>>(); //clearing the stack timeline
    }
    
    void postTweet(int userId, int tweetId) {
        timeline.push({tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        stack<vector<int>> s = timeline;
        int n = 0;
        while(!s.empty() && n < 10){
            auto temp = s.top();
            // temp[0] = tweetid, temp[1] = userId
            s.pop();
            if(temp[1] == userId || friends[userId].count(temp[1])){
                ans.push_back(temp[0]);
                n++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
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