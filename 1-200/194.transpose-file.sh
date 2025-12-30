#
# @lc app=leetcode id=194 lang=bash
#
# [194] Transpose File
#

# @lc code=start
# Read from the file file.txt and print its transposed content to stdout.

awk '
{
    # For each field in the current line, store it in array a with key [column, row]
    # NF is the number of fields in the current line
    for (i=1; i<=NF; i++) {
        a[i, NR]=$i
    }
    # Keep track of the maximum number of fields (columns) in any row
    if (NF > max) max=NF
    # Keep track of the current row number
    # NR is the number of the current record (line)
    row=NR
}
END {
    # Loop over each column (from 1 to max)
    for (i=1; i<=max; i++) {
        # For each row, print the value at [column, row]
        for (j=1; j<=row; j++) {
            # Print the value, followed by a space if not the last row, else a newline
            # ORS is the output record separator, OFS is the output field separator
            printf "%s%s", a[i, j], (j==row ? ORS : OFS)
        }
    }
}
' file.txt

# @lc code=end
