#if 0
A robot is located at the top-left corner of a m x n grid
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point
in time. The robot is trying to reach the bottom-right
corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
#endif

class Solution {
public:
    int uniquePaths(int m, int n) {
      // Use a 1D array to store intermediate results,
      // and always use the smaller dimension. 
      if (m > n) return uniquePaths(n, m);

      // initialize vector to 1, which represent base cases:
      //
      // f(m, 1) = 1, for any m
      //
      vector<int> A(m, 1);

      // starting from j = 1, since f(1, n) = 1
      for (int j = 1; j < n; ++j) {
          for (int i = 1; i < m; ++i) {
              A[i] += A[i - 1];
          }
      }
      return A.back();
    }
};
