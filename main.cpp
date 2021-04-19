#include "coding/class/Class5.h"

using namespace std;

int main() {
    (new C5::Q1())->countOfRangeSum();
    return 0;
}


///**
// * struct ListNode {
// *	int val;
// *	struct ListNode *next;
// *	ListNode(int x) : val(x), next(nullptr) {}
// * };
// */
//
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * 计算两个代表整数的链表参与减法运算后的结果，结果通过链表形式返回。
//     * @param minuendList ListNode类 被减数链表头
//     * @param subtrahendList ListNode类 减数链表头
//     * @return ListNode类
//     */
//
//
//    ListNode* st(ListNode* minuendList, ListNode* subtrahendList,int k) {
//        // write code here
//        if (minuendList==NULL&&subtrahendList==NULL&&k==0)
//        {
//            return NULL;
//        }
//        int val=k;
//        if (minuendList!=NULL)
//        {
//            val+=minuendList->val;
//        }
//        if (subtrahendList!=NULL)
//        {
//            val+=subtrahendList->val;
//        }
//        ListNode* node=new ListNode(val%10);
//        node->next=st(minuendList==NULL?NULL:minuendList->next,subtrahendList==NULL?NULL:subtrahendList->next,val>=10?1:0);
//        return node;
//    }
//    ListNode* minusList(ListNode* minuendList, ListNode* subtrahendList) {
//        // write code here
//        if (subtrahendList->val<0)
//        {
//            subtrahendList->val*=-1;
//        }
//        else
//        {
//
//        }
//        return st(minuendList,subtrahendList,0);
//
//    }
//};