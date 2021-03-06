//
// Created by Arylise on 2021/4/18.
//

#ifndef CODING_CLASS05_H
#define CODING_CLASS05_H

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Q1
{
    /**
     * 题目描述：
     * https://leetcode.com/problems/count-of-range-sum/
     * 给定一个数组arr，两个整数lower和upper，
     * 返回arr中有多少个子数组的累加和在[lower,upper]范围上
     */
    int *arr{};
    int ans = 0;
    int lower, upper;

    void _merge(int left, int mid, int right)
    {
        int l = left;
        int r = left;
        // [l, r)
        for (int i = mid + 1; i <= right; i++)
        {
            long min = arr[i] - upper;
            long max = arr[i] - lower;
            while (r <= mid && arr[r] <= max)
            {
                r++;
            }
            while (l <= mid && arr[l] < min)
            {
                l++;
            }
            ans += r - l;
        }
    }

    void _process(int left, int right)
    {
        if (left == right)
        {
            if (lower<= arr[left]&& arr[left]<= upper))
            {
                ans++;
            }
            return;
        }
        int mid = left + ((right - left) >> 1);
        _process(left, mid);
        _process(mid + 1, right);
        _merge(left, mid, right);
    }

public:
    void countOfRangeSum()
    {
//            int n = 10;
//            arr = new int[n]{7, 4, 9, 6, 3, 5, 0, 2, 1, 8};
//            lower = 6;
//            upper = 11;
        int n;
        cin >> n;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> lower >> upper;
        for (int i = 1; i < n; i++)
        {
            arr[i] += arr[i - 1];
//                arr[i-1]-=lower;
        }
//            arr[n-1]-=lower;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
        _process(0, n - 1);
        cout << ans;
    }

    int test(int *a, int n, int l, int u)
    {
        arr = new int[n];
        lower = l;
        upper = u;
        arr[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            arr[i] = arr[i - 1] + a[i];
        }
        _process(0, n - 1);
        free(arr);
        return ans;
    }

    class Cmp
    {
        int *arr{};
        int ans = 0;
        int lower, upper;

        void _process(int left, int right)
        {
            for (int i = left; i <= right; i++)
            {
                for (int j = i; j <= right; j++)
                {
                    int res = 0;
                    for (int t = i; t <= j; t++)
                    {
                        res += arr[t];
                    }

                    if (lower <= res && res <= upper)
                    {
                        ans++;
                    }
                }
            }
        }

    public:
        void countOfRangeSum()
        {
            int n = 10;
            arr = new int[n]{7, 4, 9, 6, 3, 5, 0, 2, 1, 8};
            lower = 6;
            upper = 11;
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << ' ';
            }
            cout << endl;
            _process(0, n - 1);
            cout << ans;
        }

        int test(int *a, int n, int l, int u)
        {
            arr = new int[n];
            lower = l;
            upper = u;
            for (int i = 0; i < n; i++)
            {
                arr[i] = a[i];
            }
            _process(0, n - 1);
            free(arr);
            return ans;
        }
    };
};

class Q2
{
    /**
     * Partition过程
     * 定一个数组arr，和一个整数num。请把小于等于num的数放在数组的左边，大于num的数放在数组的右边。
     * 要求额外空间复杂度O(1)，时间复杂度O(n)
     *
     * 荷兰国旗问题
     * 给定一个数组arr，和一个整数num。请把小于num的数放在数组的左边，等于num的数放在中间，大于num的数放在数组的右边。
     * 要求额外空间复杂度O(1)，时间复杂度O(n)
     */

    int *arr{};

    void _swap(int i, int j)
    {
        if (i == j)
        {
            return;
        }
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    int *_partition(int left, int right)
    {
        if (left > right)
        {
            return new int[2]{-1, -1};
        }
        if (left == right)
        {
            return new int[2]{left, right};
        }
        int l = left - 1;
        int r = right;
        while (left < r)
        {
            if (arr[left] < arr[right])
            {
                _swap(left++, ++l);
            } else if (arr[left] > arr[right])
            {
                _swap(left, --r);
            } else
            {
                left++;
            }
        }
        _swap(left, right);
        return new int[2]{l + 1, r};
    }

    void _process(int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        _swap(left + (int) rand() * (right - left + 1), right);
        int *leaf = _partition(left, right);
        _process(left, leaf[0] - 1);
        _process(leaf[1] + 1, right);
        free(leaf);
    }

public:
    void quickSort()
    {
        int n = 11;
        arr = new int[n]{1, 2, 5, 3, 4, 6, 7, 5, 8, 9, 5};
        _process(0, n - 1);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
    }

    int *test(int *a, int n)
    {
        if (a == nullptr || n < 2)
        {
            return a;
        }
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = a[i];
        }
        _process(0, n - 1);
        return arr;
    }

    void end()
    {
        free(arr);
        free(this);
    }
};

class Q3
{
    /**
     * 快速排序1.0
     *
     * 在arr[L..R]范围上，进行快速排序的过程：
     * 1）用arr[R]对该范围做partition，<= arr[R]的数在左部分并且保证arr[R]最后来到左部分的最后一个位置，记为M； <= arr[R]的数在右部分（arr[m+1..R]）
     * 2）对arr[L..m-1]进行快速排序(递归)
     * 3）对arr[m+1..R]进行快速排序(递归)
     * 因为每一次partition都会搞定一个数的位置且不会再变动，所以排序能完成
     *
     * 快速排序2.0
     * 在arr[L..R]范围上，进行快速排序的过程：
     * 1）用arr[R]对该范围做partition，< arr[R]的数在左部分，== arr[R]的数中间，>arr[R]的数在右部分。假设== arr[R]的数所在范围是[a,b]
     * 2）对arr[L..a-1]进行快速排序(递归)
     * 3）对arr[b+1..R]进行快速排序(递归)
     * 因为每一次partition都会搞定一批数的位置且不会再变动，所以排序能完成
     *
     * 快速排序1.0和2.0的时间复杂度分析
     *
     * 数组已经有序的时候就是复杂度最高的时候
     * 对于完全有序的数组会失去分治的优势，变为等差的排序（不管正序还是逆序）
     * 时间复杂度O(n^2)
     *
     * 快速排序3.0(随机快排+荷兰国旗技巧优化)
     *
     * 在arr[L..R]范围上，进行快速排序的过程：
     * 1）在这个范围上，随机选一个数记为num，
     * 1）用num对该范围做partition，< num的数在左部分，== num的数中间，>num的数在右部分。假设== num的数所在范围是[a,b]
     * 2）对arr[L..a-1]进行快速排序(递归)
     * 3）对arr[b+1..R]进行快速排序(递归)
     * 为每一次partition都会搞定一批数的位置且不会再变动，所以排序能完成
     *
     *
     * 随机快排的时间复杂度分析
     *
     * 1）通过分析知道，划分值越靠近中间，性能越好；越靠近两边，性能越差
     * 2）随机选一个数进行划分的目的就是让好情况和差情况都变成概率事件
     * 3）把每一种情况都列出来，会有每种情况下的时间复杂度，但概率都是1/n
     * 4）那么所有情况都考虑，时间复杂度就是这种概率模型下的长期期望！
     *
     * 时间复杂度O(n*logN)，额外空间复杂度O(logN)都是这么来的。
     */
};

namespace Cmp
{
    int cmpTimes = 100;
    int maxN = 100;
    int maxAi = 100;
    int maxU = 1000;

    bool judQ1(int *a, int n)
    {
        int u = rand() % maxU;
        int l = rand() % u;
        auto fun = new Q1();
        auto pCmp = new Q1::Cmp();
        bool ans = fun->test(a, n, l, u) != pCmp->test(a, n, l, u);
        free(fun);
        free(pCmp);
        if (ans)
        {
            cout << l << " " << u;
        }
        return ans;
    }

    bool judQ2(int *a, int n)
    {
        auto *fun = new Q2();
        int *b = fun->test(a, n);
        std::sort(a, a + n - 1);
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
        fun->end();
        return true;
    }

#define jud judQ1

    void test()
    {
        bool cmp = true;
        while (cmpTimes--)
        {
            int n = rand() % maxN;
            int *a = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = rand() % maxAi;
            }
            if (jud(a, n))
            {
#undef jud
                cout << "mother fucker!" << endl << n;
                for (int i = 0; i < n; i++)
                {
                    cout << a[i] << " ";
                }
                free(a);
                cmp = false;
                break;
            }

        }
        if (cmp)
        {
            cout << "OK";
        }
    }
}


#endif //CODING_CLASS05_H
