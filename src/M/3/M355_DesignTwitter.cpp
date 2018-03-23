//
// Created by Andrii Cherniak on 3/23/18.
//
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;
struct tweet_struct{
    int tweet_id;
    int tweet_ts;
};
struct comparator{
    bool operator()(const tweet_struct & ts1, const tweet_struct & ts2){
        return ts1.tweet_ts > ts2.tweet_ts;
    }
};

class Twitter {
    unordered_map<int, unordered_set<int> > followers;
    unordered_map<int, vector<tweet_struct> > tweets;
    int tweet_ts = 0;
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweet_struct ts = {tweetId, tweet_ts};
        tweet_ts++;
        tweets[userId].push_back(ts);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<tweet_struct, vector<tweet_struct>, comparator > q;
        for(tweet_struct ts: tweets[userId]){
            q.push(ts);
            if (q.size() > 10) q.pop();
        }
        for (int f_id: followers[userId])
            for(tweet_struct ts: tweets[f_id]){
                q.push(ts);
                if (q.size() > 10) q.pop();
            }
        vector<int> feed;
        while (!q.empty()){
            feed.push_back(q.top().tweet_id);
            q.pop();
        }
        reverse(feed.begin(), feed.end());
        return feed;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
        followers[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};