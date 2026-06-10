/*
You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startDayi <= d <= endDayi. You can only attend one event at any time d.

Return the maximum number of events you can attend.



Example 1:


Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
Example 2:

Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4


Constraints:

1 <= events.length <= 105
events[i].length == 2
1 <= startDayi <= endDayi <= 105
*/
class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        // sort the events by their start day
        sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        // top of the priority queue will always be the event with the earliest end day
        priority_queue<int, vector<int>, greater<int>> pq;
        int day = 0, i = 0, n = events.size(), ans = 0;
        // day is the current day we are attending events
        while (i < n || !pq.empty())
        {
            // if the priority queue is empty, we can start attending events from the next available day
            if (pq.empty())
                day = events[i][0];
            // add all the events that start on or before the current day to the priority queue
            while (i < n && events[i][0] <= day)
            {
                pq.push(events[i][1]);
                i++;
            }

            pq.pop(); // attend the event with the earliest end day
            ans++;
            day++; // move to the next day after attending the event

            // remove all the events that have already ended before the current day
            while (!pq.empty() && pq.top() < day)
                pq.pop();
        }

        return ans;
    }
};