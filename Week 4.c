int twoStacks(int maxSum, int a_count, int* a, int b_count, int* b) {
    int i = 0, j = 0;
    int sum_a = 0, sum_b = 0;
    int count = 0;
    int max_count = 0;
    while (i < a_count && sum_a + a[i] <= maxSum) {
        sum_a += a[i];
        i++;
        count++;
    }

    max_count = count;
    while (j < b_count) {
        sum_b += b[j];
        j++;
        count++;
        while (sum_a + sum_b > maxSum && i > 0) {
            i--;
            sum_a -= a[i];
            count--;
        }
        if (sum_a + sum_b <= maxSum) {
            max_count = (count > max_count) ? count : max_count;
        }
    }

    return max_count;
}
