#include <bits/stdc++.h>
using namespace std;

int countSubarrays(int nums[], int n, int target) {
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int countTarget = 0;

        for (int j = i; j < n; j++) {
            if (nums[j] == target)
                countTarget++;

            int length = j - i + 1;
            if (countTarget > length / 2)
                ans++;
        }
    }

    return ans;
}

int main() {
    int nums[] = {1, 2, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 2;

    cout << countSubarrays(nums, n, target) << endl;

    return 0;
}