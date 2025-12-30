/*
 * @lc app=leetcode id=3242 lang=cpp
 *
 * [3242] Design Neighbor Sum Service
 */

// @lc code=start
class NeighborSum {
public:
  NeighborSum(vector<vector<int>> &grid) {
    n = grid.size();
    this->grid = grid;
    pos.resize(n * n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        pos[grid[i][j]] = {i, j};
      }
    }
  }

  int adjacentSum(int value) {
    int sum = 0;
    static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    auto [i, j] = pos[value];
    for (int d = 0; d < 4; ++d) {
      int ni = i + dirs[d][0], nj = j + dirs[d][1];
      if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
        sum += grid[ni][nj];
      }
    }
    return sum;
  }

  int diagonalSum(int value) {
    int sum = 0;
    static const int dirs[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    auto [i, j] = pos[value];
    for (int d = 0; d < 4; ++d) {
      int ni = i + dirs[d][0], nj = j + dirs[d][1];
      if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
        sum += grid[ni][nj];
      }
    }
    return sum;
  }

private:
  int n;
  vector<vector<int>> grid;
  vector<pair<int, int>> pos;
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
// @lc code=end
