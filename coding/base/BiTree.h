//
// Created by Arylise on 2021/4/5.
//

#ifndef CODING_BITREE_H
#define CODING_BITREE_H

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//namespace BiTreeSpace {

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

struct TreeNode {
    K val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode() : left(nullptr), val(0), right(nullptr) { }

    TreeNode(K x) : left(nullptr), val(x), right(nullptr) { }

    TreeNode(TreeNode *left, K x) : left(left), val(x), right(nullptr) { }

    TreeNode(K x, TreeNode *right) : left(nullptr), val(x), right(right) { }

    TreeNode(TreeNode *left, K x, TreeNode *right) : left(left), val(x), right(right) { }
};

class BiTree {

private:
    vector<K> innerList;
    int valCounter = 0;

private:
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
        return endOfLeaf;
    }

    TreeNode *_creatNode() {
        K i = _getVal();
        if (i == endOfLeaf) {
            return nullptr;
        }
        return new TreeNode(i);
    }

    /**
     * initFun
     */
    void _creatTreeByLevel() {
        if (!(root = _creatNode())) {
            return;
        }
        queue<TreeNode *> sta;
        sta.push(root);
        while (!sta.empty()) {
            TreeNode *p = sta.front();
            sta.pop();
            if ((p->left = _creatNode())) {
                sta.push(p->left);
            }
            if ((p->right = _creatNode())) {
                sta.push(p->right);
            }
        }
    }


    /**
     * oderFunc
     * @param node
     */
    static void _preOder(TreeNode *node) {
        if (node) {
            cout << node->val << " ";
            _preOder(node->left);
            _preOder(node->right);
        } else
            cout << endOfLeaf << " ";
    }

    static void _inOder(TreeNode *node) {
        if (node) {
            _inOder(node->left);
            cout << node->val << " ";
            _inOder(node->right);
        } else
            cout << endOfLeaf << " ";
    }

    static void _postOder(TreeNode *node) {
        if (node) {
            _postOder(node->left);
            _postOder(node->right);
            cout << node->val << " ";
        } else
            cout << endOfLeaf << " ";
    }


    static void _levelOder(TreeNode *node) {
        queue<TreeNode *> sta;
        sta.push(node);
        while (!sta.empty()) {
            if (sta.front()) {
                TreeNode *p = sta.front();
                cout << p->val << " ";
                if (p->left) {
                    sta.push(p->left);
                } else {
                    sta.push(nullptr);
                }
                if (p->right) {
                    sta.push(p->right);
                } else {
                    sta.push(nullptr);
                }
            } else {
                cout << endOfLeaf << " ";
            }
            sta.pop();
        }
    }


public:
    static char endOfLeaf;

    TreeNode *root;

    enum WriteType {
        ByLevel
    };

    enum Oder {
        PreOder, InOder, PostOder, LevelOder
    };
public:
    BiTree() {
        _input();
        _creatTreeByLevel();
    }

    BiTree(WriteType type) {
        _input();
        switch (type) {
            case ByLevel :

                _creatTreeByLevel();

                break;
        }
    }

public:
    BiTree *show() {
        _levelOder(root);
        cout << endl;
        return this;
    }

    BiTree *show(Oder oder) {
        switch (oder) {
            case PreOder:
                _preOder(root);
                break;
            case InOder:
                _inOder(root);
                break;
            case PostOder:
                _postOder(root);
                break;
            case LevelOder:
                _levelOder(root);
                break;
        }
        cout << endl;
        return this;
    }

/**
 * 释放内存
 */
    void end() {
        freeTree(root);
        free(this);
    }

/**
 * endFun
 * @param node
 */
    static void freeTree(TreeNode *node) {
        if (node) {
            freeTree(node->left);
            freeTree(node->right);
            free(node);
        }
    }
};

char BiTree::endOfLeaf = '#';
//}
#undef K
#endif //CODING_BITREE_H
