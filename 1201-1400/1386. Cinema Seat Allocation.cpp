/*
A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.

You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.

A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:

seats 2, 3, 4, 5
seats 4, 5, 6, 7
seats 6, 7, 8, 9
A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.

Return an integer denoting the maximum number of four-person groups that can be assigned.



Example 1:



Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows an optimal allocation of four groups. Seats marked in blue are already reserved, and each set of four contiguous seats marked in orange is assigned to one group.
Example 2:

Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
Output: 2
Example 3:

Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
Output: 4


Constraints:

1 <= n <= 109
1 <= reservedSeats.length <= min(10 * n, 104)
reservedSeats[i] == [rowi, seati]
1 <= rowi <= n
1 <= seati <= 10
All reservedSeats[i] are distinct.
*/
class Solution
{
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        // as n can be very large, we dont do simulation, we just calculate.
        // rows without reserved seats can accomodate 2 groups, so we start with 2*n
        // rows with reserved seats can accomodate 0, 1 or 2 groups, we calculate that and subtract from total
        // sort reservedSeats by row
        sort(reservedSeats.begin(), reservedSeats.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        int totalGroups = 2 * n;
        int currentRow = 0;
        int reservedIndex = 0;
        while (reservedIndex < reservedSeats.size())
        {
            int row = reservedSeats[reservedIndex][0];
            // get all reserved seats for this row
            vector<int> reservedInRow;
            while (reservedIndex < reservedSeats.size() && reservedSeats[reservedIndex][0] == row)
            {
                reservedInRow.push_back(reservedSeats[reservedIndex][1]);
                reservedIndex++;
            }

            // subtract the assumed 2 groups for this row
            totalGroups -= 2;

            // check if we can fit 1 group in seats 2-5
            bool canFitGroup1 = true;
            for (int seat = 2; seat <= 5; seat++)
            {
                if (find(reservedInRow.begin(), reservedInRow.end(), seat) != reservedInRow.end())
                {
                    canFitGroup1 = false;
                    break;
                }
            }
            if (canFitGroup1)
            {
                totalGroups += 1;
            }

            // check if we can fit 1 group in seats 6-9
            bool canFitGroup2 = true;
            for (int seat = 6; seat <= 9; seat++)
            {
                if (find(reservedInRow.begin(), reservedInRow.end(), seat) != reservedInRow.end())
                {
                    canFitGroup2 = false;
                    break;
                }
            }
            if (canFitGroup2)
            {
                totalGroups += 1;
            }

             // if we cannot fit in either group, check if we can fit in the middle block 4-7
            if (!canFitGroup1 && !canFitGroup2)
            {
                bool canFitGroup3 = true;
                for (int seat = 4; seat <= 7; seat++)
                {
                    if (find(reservedInRow.begin(), reservedInRow.end(), seat) != reservedInRow.end())
                    {
                        canFitGroup3 = false;
                        break;
                    }
                }
                if (canFitGroup3)
                {
                    totalGroups += 1;
                }
            }
        }
        return totalGroups;
    }
};