#if 0
iven an array of integers, every element appears three
times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity.
Could you implement it using O(1) extra memory?

#endif
int singleNumber(int A[], int n) {
    int zeros = 0xffffffff, ones = 0, twos = 0;
    for (int i = 0; i < n; ++i) {
        int t1 = ones;
        ones = (zeros & A[i]) | (ones & ~A[i]);
        int t2 = twos;
        twos = (t1 & A[i]) | (twos & ~A[i]);
        zeros = (t2 & A[i]) | (zeros & ~A[i]);
    }
    return ones;
}
