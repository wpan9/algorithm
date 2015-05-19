#include <algorithm>

#if 0
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
#endif

class Solution {
public:
  void sortColors(int A[], int n);
  void sortColors2(int A[], int n);
};

void Solution::sortColors(int A[], int n) {
  int L = 0, M = 0, H = n;
  // not vectorizable.
  while (M < H) {
    // Loop invariant: known 0s [0, L), known 1s [L, M), unknowns [M, H),
    // known 2s [H, n)
    if (A[M] == 0) {
      std::swap(A[L], A[M]), ++L, ++M;
    } else if (A[M] == 1) {
      ++M;
    } else {
      std::swap(A[M], A[H - 1]), --H;
    }
  }
}

void Solution::sortColors2(int A[], int n) {
  int n0 = 0, n1 = 0;
  // vectorizable.
  for (int i = 0; i < n; ++i) {
    if (A[i] == 0)
      ++n0;
    else if (A[i] == 1)
      ++n1;
  }

  for (int i = 0; i < n; ++i) {
    A[i] = (i < n0) ? 0 : (i < n0 + n1) ? 1 : 2;
  }
}