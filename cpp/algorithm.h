#pragma once
#include <utility>

namespace zgh {
// vc/include/algorithm
int* lower_bound(int *first, int *last, int val)
{
    int count = last - first; // distance(first, last)
    
    while (count > 0)
    {
        int count2 = count / 2;
        int *mid = first + count2;
        if (*mid < val)
        { // try top half
            first = ++mid;
            count -= count2 + 1;
        }
        else
        {
            count = count2;
        }
    }
    return first;
}

int* upper_bound(int *first, int *last, int val)
{
    int count = last - first;
    while (count > 0)
    {
        int count2 = count / 2;
        int *mid = first + count2;
        if (*mid <= val)
        { // try top half
            first = ++mid;
            count -= count2 + 1;
        }
        else
        {
            count = count2;
        }
    }
    return first;
}

std::pair<int*, int*> equal_range(int *first, int *last, int val)
{
    int count = last - first;
    while (count > 0)
    {
        int count2 = count / 2;
        int *mid = first + count2;

        if (*mid < val)
        {
            first = ++mid;
            count -= count2 + 1;
        }
        else if (val < *mid)
        {
            count = count2;
        }
        else
        {
            // range straddles Mid, find each end and return
            int *first2 = lower_bound(first, mid, val);
            int *last2 = upper_bound(++mid, first + count, val);
            return std::make_pair(first2, last2);
        }
    }
    return std::make_pair(first, first); // empty range
}

std::pair<int*, int*> equal_range2(int *first, int *last, int val)
{
    int *lower = lower_bound(first, last, val);
    int *upper = upper_bound(lower, last, val);
    return std::make_pair(lower, upper);
}
}