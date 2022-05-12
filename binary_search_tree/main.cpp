/// Реализуйте бинарное дерево поиска для целых чисел. Программа получает на вход последовательность целых чисел
/// и строит из них дерево. Элементы в деревья добавляются в соответствии с результатом поиска их места.
/// Если элемент уже существует в дереве, добавлять его не надо. Балансировка дерева не производится.

/// На вход программа получает последовательность натуральных чисел. Последовательность завершается числом 0,
/// которое означает конец ввода, и добавлять его в дерево не надо.

/// Выведите единственное число – высоту получившегося дерева.

#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *left, *right;

    Node() = default;

    Node(int x) : value(x), left(nullptr), right(nullptr) {}
};

void addNode (int x, Node *&root) {
    if (root == nullptr) {
        root = new Node(x);
        return;
    }
    if (root->value == x) {
        return;
    }
    if (root->value > x) {
        addNode(x, root->left);
    } else if (root->value < x) {
        addNode(x, root->right);
    }
}

int hTree (Node *&root) {
    if (root == nullptr)
        return 0;
    return max(hTree(root->left), hTree((root->right))) + 1;
}


int main() {
    Node *root = nullptr;
    int x;
    while (cin >> x) {
        if (x == 0) {
            break;
        }
        addNode(x, root);
    }
    cout << hTree(root);
    return 0;
}