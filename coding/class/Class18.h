//
// Created by Arylise on 2021/4/10.
//

#ifndef CODING_CLASS18_H
#define CODING_CLASS18_H

#include "../base/BaseDefine.h"


/**
 * 假设有排成一行的N个位置，记为1~n，n 一定大于或等于 2
 * 开始时机器人在其中的M位置上(m 一定是 1~n 中的一个)
 * 如果机器人来到1位置，那么下一步只能往右来到2位置；
 * 如果机器人来到N位置，那么下一步只能往左来到 n-1 位置；
 * 如果机器人来到中间位置，那么下一步可以往左走或者往右走；
 * 规定机器人必须走 K 步，最终能来到P位置(P也是1~N中的一个)的方法有多少种
 * 给定四个参数 n、m、K、P，返回方法数。
 */
class Q2
{
    /**
 * 给定一个整型数组arr，代表数值不同的纸牌排成一条线
 * 玩家A和玩家B依次拿走每张纸牌
 * 规定玩家A先拿，玩家B后拿
 * 但是每个玩家每次只能拿走最左或最右的纸牌
 * 玩家A和玩家B都绝顶聪明
 * 请返回最后获胜者的分数。
 */
    int *arr;

    int Aways(int, int);

    int Bways(int, int);

    int Bways(int left, int right)
    {
        if (left == right)
        {
            return 0;
        }
        int ans1 = Aways(left + 1, right);
        int ans2 = Aways(left, right - 1);
        return ans1 < ans2 ? ans1 : ans2;
    }

    int Aways(int left, int right)
    {
        if (left == right)
        {
            return arr[left];
        }
        int ans1 = arr[left] + Bways(left + 1, right);
        int ans2 = arr[right] + Bways(left, right - 1);
        return ans1 > ans2 ? ans1 : ans2;
    }

    void test()
    {
        arr = new int[4]{50, 100, 20, 10};
        for (int i = 0; i < 4; i++)std::cout << arr[i] << " ";
        std::cout << Aways(0, 3) << std::endl;
        std::cout << Bways(0, 3);

    }
};


#endif //CODING_CLASS18_H
