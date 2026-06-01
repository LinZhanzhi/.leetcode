/*
A transaction is possibly invalid if:

the amount exceeds $1000, or;
if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.

Return a list of transactions that are possibly invalid. You may return the answer in any order.



Example 1:

Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
Output: ["alice,20,800,mtv","alice,50,100,beijing"]
Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
Example 2:

Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
Output: ["alice,50,1200,mtv"]
Example 3:

Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
Output: ["bob,50,1200,mtv"]


Constraints:

transactions.length <= 1000
Each transactions[i] takes the form "{name},{time},{amount},{city}"
Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
Each {time} consist of digits, and represent an integer between 0 and 1000.
Each {amount} consist of digits, and represent an integer between 0 and 2000.
*/
class Solution
{
public:
    vector<string> invalidTransactions(vector<string> &transactions)
    {
        // first group transactions by name
        // then for each group, output and exclude transaction with amount > 1000
        // for the rest, sort by time, if any consecutive two transactions have time difference <= 60 and city different, output both. dont output repeatingly
        unordered_map<string, vector<tuple<int, int, string, string>>> name2transactions;
        for (const auto &transaction : transactions)
        {
            stringstream ss(transaction);
            string name, time, amount, city;
            getline(ss, name, ',');
            getline(ss, time, ',');
            getline(ss, amount, ',');
            getline(ss, city, ',');
            name2transactions[name].emplace_back(stoi(time), stoi(amount), city, transaction);
        }
        vector<string> ans;
        for (auto &[name, transactions] : name2transactions)
        {
            // output and exclude transaction with amount > 1000 before sorting
            // for (auto &[time, amount, city, transaction] : transactions)
            // {
            //     if (amount > 1000)
            //     {
            //         ans.push_back(transaction);
            //         // remove the element from transactions
            //         time = -1;
            //     }
            // }
            // remove the element with time = -1
            // transactions.erase(remove_if(transactions.begin(), transactions.end(), [](const auto &t)
            //                              { return get<0>(t) == -1; }),
            //                    transactions.end());
            // sort by time
            sort(transactions.begin(), transactions.end(), [](const auto &a, const auto &b)
                 { return get<0>(a) < get<0>(b); });
            // use a flag to avoid output repeatingly
            vector<bool> flagged(transactions.size(), false);
            for (int i = 0; i < transactions.size(); ++i)
            {
                auto &[time, amount, city, transaction] = transactions[i];
                for (int j = i + 1; j < transactions.size() && get<0>(transactions[j]) - time <= 60; ++j)
                {
                    auto &[time2, amount2, city2, transaction2] = transactions[j];
                    if (city != city2)
                    {
                        if (!flagged[i])
                        {
                            ans.push_back(transaction);
                            flagged[i] = true;
                        }
                        if (!flagged[j])
                        {
                            ans.push_back(transaction2);
                            flagged[j] = true;
                        }
                    }
                }
            }
            // output transaction with amount > 1000

            for (int i = 0; i < transactions.size(); ++i)
            {
                auto &[time, amount, city, transaction] = transactions[i];
                if (amount > 1000)
                {
                    // avoid output repeatingly, so check if it is already flagged
                    if (!flagged[i])
                    {
                        ans.push_back(transaction);
                        flagged[i] = true;
                    }
                }
            }
        }
        return ans;
    }
};