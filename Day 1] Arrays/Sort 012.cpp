void sort012(int *nums, int n)
{
    int lo = 0, mid = 0, hi = n - 1;
    while (mid <= hi)
    {
        switch (nums[mid])
        {
        case 0:
            swap(nums[lo++], nums[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(nums[mid], nums[hi--]);
            break;
        }
    }
}