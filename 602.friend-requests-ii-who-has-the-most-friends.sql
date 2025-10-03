--
-- @lc app=leetcode id=602 lang=mysql
--
-- [602] Friend Requests II: Who Has the Most Friends
--
-- @lc code=start
# Write your MySQL query statement below
WITH FriendCount AS (
  SELECT requester_id AS id
  FROM RequestAccepted
  UNION ALL
  SELECT accepter_id AS id
  FROM RequestAccepted
),
FriendNum AS (
  SELECT id,
    COUNT(*) AS num
  FROM FriendCount
  GROUP BY id
)
SELECT id,
  num
FROM FriendNum
WHERE num = (
    SELECT MAX(num)
    FROM FriendNum
  );
/*
 Brief, Digested Understanding:
 ----
 This problem asks us to find the person with the most friends, where a "friend" is anyone who has either sent or received a friend request (from the RequestAccepted table). Each row in the table represents a successful friend request between two people. We need to count, for each person, how many unique friends they have, and return the person(s) with the highest count.
 
 High-Level Summary:
 ----
 We first "flatten" the RequestAccepted table so that each friendship is represented twice (once for each person in the pair), then count the number of unique friends for each person. We use CTEs (Common Table Expressions) to show each intermediate step:
 1. FriendPairs: Each row is (id, friend_id) for both requester and accepter.
 2. UniqueFriendPairs: Remove duplicate friendships (since friendship is mutual).
 3. FriendCount: Count unique friends for each id.
 Finally, we select the id(s) with the maximum number of friends.
 Time Complexity: O(N), where N is the number of rows in RequestAccepted.
 Space Complexity: O(N), for storing intermediate tables.
 
 -- Input Table: RequestAccepted
 -- +--------------+-------------+-------------+
 -- | requester_id | accepter_id | accept_date |
 -- +--------------+-------------+-------------+
 -- | 1            | 2           | 2016/06/03  |
 -- | 1            | 3           | 2016/06/08  |
 -- | 2            | 3           | 2016/06/08  |
 -- | 3            | 4           | 2016/06/09  |
 -- +--------------+-------------+-------------+
 
 -- Step 1: FriendPairs (flatten both sides of each friendship)
 -- +----+-----------+
 -- | id | friend_id |
 -- +----+-----------+
 -- | 1  | 2         |
 -- | 2  | 1         |
 -- | 1  | 3         |
 -- | 3  | 1         |
 -- | 2  | 3         |
 -- | 3  | 2         |
 -- | 3  | 4         |
 -- | 4  | 3         |
 -- +----+-----------+
 
 -- Step 2: UniqueFriendPairs (remove duplicates, if any)
 -- (In this case, all pairs are unique, so table is the same as above.)
 
 -- Step 3: FriendCount (count unique friends for each id)
 -- +----+-----+
 -- | id | num |
 -- +----+-----+
 -- | 1  | 2   |  -- friends: 2, 3
 -- | 2  | 2   |  -- friends: 1, 3
 -- | 3  | 3   |  -- friends: 1, 2, 4
 -- | 4  | 1   |  -- friends: 3
 -- +----+-----+
 
 -- Final Output (id(s) with the most friends)
 -- +----+-----+
 -- | id | num |
 -- +----+-----+
 -- | 3  | 3   |
 -- +----+-----+
 */
-- @lc code=end