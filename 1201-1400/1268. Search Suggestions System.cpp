/*
You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.



Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.


Constraints:

1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 104
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.
*/
class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        // vector<vector<string>> ans;
        // sort(products.begin(), products.end());
        // for (int i = 0; i < searchWord.size(); i++)
        // {
        //     string prefix = searchWord.substr(0, i + 1);
        //     vector<string> temp;
        //     for (string &product : products)
        //     {
        //         if (product.substr(0, prefix.size()) == prefix)
        //         {
        //             temp.push_back(product);
        //             if (temp.size() == 3)
        //                 break;
        //         }
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;
        // above code is too slow because it is O(n*m) where n is the number of products and m is the length of searchWord
        // actually adding one more character to the prefix is being more restrictive, and it may eliminate some products from the previous prefix, so we can just check the products that are in the previous prefix and not all the products
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        vector<string> temp; // temp will hold all the products that match the previous prefix; and we only push 3 products to the ans
        temp = products;
        for (int i = 0; i < searchWord.size(); i++)
        {
            char currentChar = searchWord[i];
            for (string &product : temp)
            {
                // if the current character of the product is not equal to the current character of the searchWord, remove it from the temp
                if (i >= product.size() || product[i] != currentChar)
                {
                    // remove the product from temp
                    product = ""; // mark it as empty string, we will remove it later
                }
            }
            // remove the empty strings from temp
            temp.erase(remove(temp.begin(), temp.end(), ""), temp.end());
            // push the first 3 products from temp to ans
            ans.push_back(temp.size() > 3 ? vector<string>(temp.begin(), temp.begin() + 3) : temp);
        }
        return ans;
        // good this solution is fast
    }
};