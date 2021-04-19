//
// Created by Arylise on 2021/4/11.
//

#ifndef CODING_FIXTREE_H
#define CODING_FIXTREE_H
#include "../base/BiTree.h"
/**
 * 修剪一棵树为完美二叉树
 * @param tree
 * @return
 */
BiTree *fixTree(BiTree *tree) {
    /// 特殊情况考虑
    TreeNode *root = tree->root;
    if (root == nullptr) {
        return tree;
    }
    if (root->right == nullptr) {
        BiTree::freeTree(root->left);
        root->left = nullptr;
        return tree;
    }
    if (root->left == nullptr) {
        BiTree::freeTree(root->right);
        root->right = nullptr;
        return tree;
    }

    /// num作为记录本层有多少节点
    int num = 1;
    /// que用来层序遍历树
    queue<TreeNode *> que;
    /// lastLine用来记录上一层节点
    queue<TreeNode *> lastLine;
    /// topLast用来记录下一层的结尾
    TreeNode *nextLast = root->right;
    que.push(root);
    /// 当第一次子树有空,则认为上一层为完全二叉树最后一层,进行修剪
    while (que.front()->left != nullptr && que.front()->right != nullptr) {
//            cout << que.front()->val << endl;
//            cout << que.front()->left->val << " " << que.front()->right->val << endl;

        /// 检测是否为一层的最后一个节点
        if (que.front() == nextLast) {
            /// lastLine去除上一层的节点
            for (int i = 0; i < num; ++i) {
                lastLine.pop();
            }
            /// num*2
            num = num << 1;
            /// 重新记录nextLast
            nextLast = que.front()->right;
        }
        /// 节点塞进记录栈,将子节点压入栈,节点出栈
        lastLine.push(que.front());
        que.push(que.front()->left);
        que.push(que.front()->right);
        que.pop();
//            cout<<"?"<<que.size()<<"?"<<lastLine.size()<<endl;
    }
    /// 以上一层进行修剪,所记录的最后一层不要修剪,会报错(已经被修剪过)
    while (num--) {
        TreeNode *p = lastLine.front();
        BiTree::freeTree(p->left->left);
        BiTree::freeTree(p->left->right);
        BiTree::freeTree(p->right->left);
        BiTree::freeTree(p->right->right);
        p->left->left = nullptr;
        p->left->right = nullptr;
        p->right->left = nullptr;
        p->right->right = nullptr;
        lastLine.pop();
    }
    return tree;
}
#endif //CODING_FIXTREE_H
