#include <algorithm>
#include <iostream>

void sort(int A[], int n) {
    // [0, i1), [i1, i2), [i2, i3), [i3, i4), [i4, n)
    //   0         1       unknown     2         3
    int i1 = 0, i2 = 0, i3 = n, i4 = n;

    while (i2 < i3) {
        if (A[i2] == 0) {
            std::swap(A[i1], A[i2]);
            i1++;
            i2++;
        } else if (A[i2] == 1) {
            i2++;
        } else if (A[i2] == 2) {
            i3--;
            std::swap(A[i2], A[i3]);
        } else {
            // A[i2] == 3
            i2++;
            i3--;
            std::swap(A[i2], A[i3]);
            i4--;
            std::swap(A[i3], A[i4]);
        }
    }
}

int main() {
    int A[] = {3, 2, 0, 0, 0, 1, 1, 1, 2, 2, 3, 0, 3, 1, 3, 2, 2, 2, 0, 1, 1};
    int n = sizeof(A) / sizeof(A[0]);
    sort(A, n);
    for (int i = 0; i < n; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout<< std::endl;
    return 0;
}
