#
# @lc app=leetcode id=192 lang=bash
#
# [192] Word Frequency
#

# @lc code=start
# Read from the file words.txt and output the word frequency list to stdout.

# 1. Output the contents of words.txt
cat words.txt |
# 2. Replace spaces with newlines, squeeze multiple spaces into one newline
tr -s ' ' '\n' |
# 3. Remove empty lines
grep -v '^$' |
# 4. Sort the words alphabetically
sort |
# 5. Count occurrences of each word (words must be adjacent)
uniq -c |
# 6. Sort by frequency in descending order, -rn option is for numerical sort
sort -rn |
# 7. Print word and its frequency in the required format
awk '{print $2, $1}'

# @lc code=end
