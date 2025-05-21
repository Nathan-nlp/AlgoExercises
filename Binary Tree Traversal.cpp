#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> vec;

/* Pre-order traversal */
void preOrder(TreeNode *root) {
    if (root == nullptr) return;
    vec.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}

/*In-order traversal */
void inOrder(TreeNode *root) {
    if (root == nullptr) return;
    inOrder(root->left);
    vec.push_back(root->val);
    inOrder(root->right);
}

/*Post-order traversal */
void postOrder(TreeNode *root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    vec.push_back(root->val);
}

/*Level-order traversal */
vector<int> levelOrder(TreeNode *root) {
    vector<int> result;
    if (!root) return result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front(); q.pop();
        result.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    return result;
}

void printVector(const vector<int> &v) {
    for (int val : v) cout << val << " ";
    cout << endl;
}

TreeNode* buildTreeFromInput() {
    cout << "Please enter the value of the node in order. For blank nodes, enter -1. For example: 1 2 3 -1 -1 4 5:" << endl;
    int val;
    cin >> val;
    if (val == -1) return nullptr;

    TreeNode *root = new TreeNode(val);
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *node = q.front(); q.pop();

        int leftVal, rightVal;
        cin >> leftVal;
        if (leftVal != -1) {
            node->left = new TreeNode(leftVal);
            q.push(node->left);
        }

        cin >> rightVal;
        if (rightVal != -1) {
            node->right = new TreeNode(rightVal);
            q.push(node->right);
        }
    }

    return root;
}

int main() {
    TreeNode *root = buildTreeFromInput();

    cout << "Level-order traversal:";
    vector<int> level = levelOrder(root);
    printVector(level);

    vec.clear();
    preOrder(root);
    cout << "Pre-order traversal:";
    printVector(vec);

    vec.clear();
    inOrder(root);
    cout << "In-order traversal:";
    printVector(vec);

    vec.clear();
    postOrder(root);
    cout << "Post-order traversal:";
    printVector(vec);

    return 0;
}

