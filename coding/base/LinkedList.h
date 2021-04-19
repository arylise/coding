//
// Created by Arylise on 2021/4/5.
//

#ifndef CODING_LINKEDLIST_H
#define CODING_LINKEDLIST_H

using namespace std;

#if (_VAL == 1)
#define K int
K endOfInput = -1;

#elif (_VAL == 2)
#define K long long
K endOfInput = -1;

#elif (_VAL == 3)
#define K double
K endOfInput = 0.0;

#elif (_VAL == 4)
#define K char
K endOfInput = '%';

#else
#define K int
K endOfInput = -1;

#endif
#undef _VAL


struct LinkedNode {
    K val;
    LinkedNode *next;

    LinkedNode(K x) : val(x), next(nullptr) { }

    LinkedNode(K x, LinkedNode *p) : val(x), next(p) { }
};

class LinkedList {

private:
    vector<K> innerList;

    void _input() {
        K input;
        cin >> input;
        while (input != endOfInput) {
            innerList.push_back(input);
            cin >> input;
        }
    }

    K _getVal() {
        if (valCounter < innerList.size()) {
            return innerList[valCounter++];
        }
        return endOfInput;
    }

    LinkedNode *_creatNode(LinkedNode *next) {
        K i = _getVal();
        if (i == endOfInput) {
            return nullptr;
        }
        return new LinkedNode(i, next);
    }

    void _creatListByTail() {
        head = _creatNode(nullptr);
        if (!head) {
            return;
        }
        LinkedNode *node = head;
        while ((node->next = _creatNode(nullptr))) {
            node = node->next;
        }
    }

    void _creatListByHead() {
        head = _creatNode(nullptr);
        if (!head) {
            return;
        }
        LinkedNode *node;
        while ((node = _creatNode(head))) {
            head = node;
        }
    }


    static void _listOder(LinkedNode *node) {
        while (node) {
            cout << node->val << " ";
            node = node->next;
        }
    }

    static LinkedNode *_mergeSort(LinkedNode *node) {
        if (node->next == nullptr) {
            return node;
        }
        /// 快慢指针跑一圈,这样慢指针指向中点
        LinkedNode *fast, *slow;
        fast = slow = node;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        /// 分割链表,快指针没用了作为分割链表的头结点
        fast = slow->next;
        slow->next = nullptr;
        /// 分治处理
        slow = _mergeSort(node);
        fast = _mergeSort(fast);
        /// 假设之前已经排好了两个子链表
        /// 排序两条链表的第一个值，作为node返回,node必须接受fast或slow,否则如果node在merge中改动就失去了头结点位置
        if (_cmp(fast, slow)) {
            node = fast;
            fast = fast->next;
        } else {
            node = slow;
            slow = slow->next;
        }
        /// tail作为操作位进行主链表构建
        LinkedNode *tail = node;
        while (fast && slow) {
            ///每次取_cmp设定的比较器
            if (_cmp(fast, slow)) {
                tail->next = fast;
                fast = fast->next;
            } else {
                tail->next = slow;
                slow = slow->next;
            }
            tail = tail->next;/// 别忘了tail要++
        }
        /// 尾部的链表直接对接
        if (fast) {
            tail->next = fast;
        }
        if (slow) {
            tail->next = slow;
        }
        return node;
    }

    static bool _cmp(LinkedNode *a, LinkedNode *b) { return a->val < b->val; }


public:
    LinkedNode *head = nullptr;
    int valCounter = 0;
    enum WriteType {
        ByTail, ByHead
    };

    LinkedList() {
        _input();
        _creatListByTail();
    }

    LinkedList(WriteType type) {
        _input();
        switch (type) {
            case ByHead:
                _creatListByHead();
                break;
            case ByTail:
                _creatListByTail();
                break;
        }
    }

    LinkedList *sort() {
        if (head)
            head = _mergeSort(head);
        return this;
    }

    LinkedList *show() {
        _listOder(head);
        cout << endl;
        return this;
    }

    void end() {
        freeNode(head);
        free(this);
    }

    static void freeNode(LinkedNode *node) {
        if (node) {
            freeNode(node);
        }
        free(node);
    }
};

#undef K
#endif //CODING_LINKEDLIST_H
