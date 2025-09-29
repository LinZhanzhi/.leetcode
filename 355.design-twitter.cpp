/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We need to design a simple Twitter system where users can post tweets, follow
 * or unfollow others, and view their news feed. The news feed should show the
 * 10 most recent tweets from the user and anyone they follow, ordered from
 * newest to oldest. Each tweet has a unique ID, and users cannot follow
 * themselves.
 *
 * High-Level Summary:
 * ----
 * We'll use a combination of data structures:
 *   - For tweets: Store each user's tweets as a list of (timestamp, tweetId)
 * pairs.
 *   - For following: Use a map from userId to a set of followeeIds.
 *   - For news feed: Use a min-heap (priority queue) to efficiently merge the
 * most recent tweets from all followed users and the user themself. We'll
 * maintain a global timestamp to order tweets. All operations are designed to
 * be efficient for the given constraints.
 *
 * Time Complexity:
 *   - postTweet: O(1)
 *   - follow/unfollow: O(1)
 *   - getNewsFeed: O(N log k), where N is the number of users the user follows
 * (including themself), and k is up to 10 (the news feed size).
 *
 * Space Complexity:
 *   - O(U + T), where U is the number of users and T is the number of tweets.
 */

#include <queue>         // For std::priority_queue
#include <unordered_map> // For std::unordered_map
#include <unordered_set> // For std::unordered_set
#include <utility>       // For std::pair
#include <vector>        // For std::vector

using namespace std;

// @lc code=start
class Twitter {
private:
  // Global timestamp to keep track of the order of tweets
  int timeStamp;

  // Each user's tweets: userId -> vector of (time, tweetId)
  unordered_map<int, vector<pair<int, int>>> tweets;

  // Each user's followees: userId -> set of followeeIds
  unordered_map<int, unordered_set<int>> followees;

public:
  // Constructor: Initializes the Twitter object
  Twitter() : timeStamp(0) {
    // No additional initialization needed
  }

  // User posts a new tweet
  void postTweet(int userId, int tweetId) {
    // Store the tweet with the current timestamp for ordering
    tweets[userId].emplace_back(timeStamp++, tweetId);
    // No need to limit the number of tweets per user, as per constraints
  }

  // Retrieve the 10 most recent tweet IDs in the user's news feed
  vector<int> getNewsFeed(int userId) {
    // Min-heap (priority queue) to get the most recent tweets efficiently
    // The heap stores tuples: (time, tweetId, userId, tweetIndex)
    // We use a max-heap by comparing time in descending order
    using TweetInfo = tuple<int, int, int, int>;
    priority_queue<TweetInfo> maxHeap;

    // Set to store all users whose tweets should be considered (user +
    // followees)
    unordered_set<int> usersToCheck = followees[userId];
    usersToCheck.insert(userId); // Always include the user themself

    // For each user, if they have tweets, push their most recent tweet into the
    // heap
    for (int uid : usersToCheck) {
      const auto &userTweets = tweets[uid];
      if (!userTweets.empty()) {
        int idx = userTweets.size() - 1; // Index of the most recent tweet
        // Push (time, tweetId, userId, tweetIndex) into the heap
        maxHeap.emplace(userTweets[idx].first, userTweets[idx].second, uid,
                        idx);
      }
    }

    vector<int> result;
    // Extract up to 10 most recent tweets
    while (!maxHeap.empty() && result.size() < 10) {
      auto [time, tweetId, uid, idx] = maxHeap.top();
      maxHeap.pop();
      result.push_back(tweetId);

      // If there are older tweets from this user, push the next one
      if (idx > 0) {
        const auto &userTweets = tweets[uid];
        maxHeap.emplace(userTweets[idx - 1].first, userTweets[idx - 1].second,
                        uid, idx - 1);
      }
    }
    return result;
  }

  // Follower follows a followee
  void follow(int followerId, int followeeId) {
    // A user cannot follow themselves
    if (followerId == followeeId)
      return;
    // Add followeeId to the follower's followee set
    followees[followerId].insert(followeeId);
  }

  // Follower unfollows a followee
  void unfollow(int followerId, int followeeId) {
    // A user cannot unfollow themselves (no effect)
    if (followerId == followeeId)
      return;
    // Remove followeeId from the follower's followee set, if present
    followees[followerId].erase(followeeId);
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
// @lc code=end
