//Ques1
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return NULL;
    }
    TreeNode* root = new TreeNode(nodes[index++]);
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);
    return root;
}

void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

int main() {
    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    int index = 0;
    TreeNode* root = buildTree(nodes, index);
    vector<int> result;
    inorderTraversal(root, result);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}

//Ques2
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getDepth(TreeNode* node) {
    int depth = 0;
    while (node) {
        depth++;
        node = node->left;
    }
    return depth;
}

int countNodes(TreeNode* root) {
    if (!root) return 0;
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    if (leftDepth == rightDepth) {
        return (1 << leftDepth) + countNodes(root->right);
    } else {
        return (1 << rightDepth) + countNodes(root->left);
    }
}

TreeNode* buildTree(vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return NULL;
    }
    TreeNode* root = new TreeNode(nodes[index++]);
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    int index = 0;
    TreeNode* root = buildTree(nodes, index);
    cout << countNodes(root);
    return 0;
}

//Ques3
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getDepth(TreeNode* node) {
    if (!node) return 0;
    return 1 + max(getDepth(node->left), getDepth(node->right));
}

TreeNode* buildTree(vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return NULL;
    }
    TreeNode* root = new TreeNode(nodes[index++]);
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    int index = 0;
    TreeNode* root = buildTree(nodes, index);
    cout << getDepth(root);
    return 0;
}

//Ques4
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorderTraversal(TreeNode* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);
    preorderTraversal(root->left, result);
    preorderTraversal(root->right, result);
}

TreeNode* buildTree(vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return NULL;
    }
    TreeNode* root = new TreeNode(nodes[index++]);
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    int index = 0;
    TreeNode* root = buildTree(nodes, index);
    vector<int> result;
    preorderTraversal(root, result);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}

//Ques5
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumOfNodes(TreeNode* root) {
    if (!root) return 0;
    return root->val + sumOfNodes(root->left) + sumOfNodes(root->right);
}

TreeNode* buildTree(vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return NULL;
    }
    TreeNode* root = new TreeNode(nodes[index++]);
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    int index = 0;
    TreeNode* root = buildTree(nodes, index);
    cout << sumOfNodes(root);
    return 0;
}

//Ques6
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q || p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

TreeNode* buildTree(vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return NULL;
    }
    TreeNode* root = new TreeNode(nodes[index++]);
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);
    return root;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> nodes1(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes1[i];
    }
    cin >> m;
    vector<int> nodes2(m);
    for (int i = 0; i < m; i++) {
        cin >> nodes2[i];
    }
    int index1 = 0, index2 = 0;
    TreeNode* root1 = buildTree(nodes1, index1);
    TreeNode* root2 = buildTree(nodes2, index2);
    cout << (isSameTree(root1, root2) ? "true" : "false");
    return 0;
}

//Ques7
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right || left->val != right->val) return false;
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isSymmetric(root->left, root->right);
}

TreeNode* buildTree(vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return NULL;
    }
    TreeNode* root = new TreeNode(nodes[index++]);
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    int index = 0;
    TreeNode* root = buildTree(nodes, index);
    cout << (isSymmetric(root) ? "true" : "false");
    return 0;
}

//Ques8
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (!root) return NULL;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

TreeNode* buildTree(vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return NULL;
    }
    TreeNode* root = new TreeNode(nodes[index++]);
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);
    return root;
}

void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    int index = 0;
    TreeNode* root = buildTree(nodes, index);
    root = invertTree(root);
    printTree(root);
    return 0;
}

//Ques9
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countLeaves(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

TreeNode* buildTree(vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return NULL;
    }
    TreeNode* root = new TreeNode(nodes[index++]);
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    int index = 0;
    TreeNode* root = buildTree(nodes, index);
    cout << countLeaves(root);
    return 0;
}

//Ques10
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;
    if (!root->left && !root->right) return sum == root->val;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

TreeNode* insertNode() {
    int val;
    cout << "Enter node value (-1 to stop): ";
    cin >> val;
    if (val == -1) return NULL;

    TreeNode* node = new TreeNode(val);
    cout << "Enter left child of " << val << ":" << endl;
    node->left = insertNode();
    cout << "Enter right child of " << val << ":" << endl;
    node->right = insertNode();
    
    return node;
}

int main() {
    int targetSum;
    cout << "Enter target sum: ";
    cin >> targetSum;

    cout << "Enter the root node value:" << endl;
    TreeNode* root = insertNode();

    if (hasPathSum(root, targetSum)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}

//Ques11
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {
    if (preStart > preEnd || inStart > inEnd) return NULL;

    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);

    int rootIndexInInorder = inorderMap[rootVal];
    int leftTreeSize = rootIndexInInorder - inStart;

    root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftTreeSize, inorder, inStart, rootIndexInInorder - 1, inorderMap);
    root->right = buildTreeHelper(preorder, preStart + leftTreeSize + 1, preEnd, inorder, rootIndexInInorder + 1, inEnd, inorderMap);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); ++i) {
        inorderMap[inorder[i]] = i;
    }

    return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
}

void preorderTraversal(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);

    cout << "Preorder Traversal of Constructed Tree: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}

//Ques12
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& inorderMap) {
    if (inStart > inEnd || postStart > postEnd) return NULL;

    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);

    int rootIndexInInorder = inorderMap[rootVal];
    int leftTreeSize = rootIndexInInorder - inStart;

    root->left = buildTreeHelper(inorder, inStart, rootIndexInInorder - 1, postorder, postStart, postStart + leftTreeSize - 1, inorderMap);
    root->right = buildTreeHelper(inorder, rootIndexInInorder + 1, inEnd, postorder, postStart + leftTreeSize, postEnd - 1, inorderMap);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); ++i) {
        inorderMap[inorder[i]] = i;
    }

    return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderMap);
}

void preorderTraversal(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int n;
    
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<int> inorder(n), postorder(n);

    cout << "Enter the inorder traversal: ";
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }

    cout << "Enter the postorder traversal: ";
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }

    TreeNode* root = buildTree(inorder, postorder);

    cout << "Preorder Traversal of Constructed Tree: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}

//Ques13
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return NULL;
    if (root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

TreeNode* insertLevelOrder(int arr[], int n, TreeNode* root, int i) {
    if (i < n) {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, n, root->left, 2 * i + 1);
        root->right = insertLevelOrder(arr, n, root->right, 2 * i + 2);
    }
    return root;
}

TreeNode* findNode(TreeNode* root, int value) {
    if (!root) return NULL;
    if (root->val == value) return root;
    TreeNode* left = findNode(root->left, value);
    if (left) return left;
    return findNode(root->right, value);
}

int main() {
    int n;
    cout << "Enter the number of nodes in the tree: ";
    cin >> n;
    int arr[n];
    cout << "Enter the values of the nodes in level order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    TreeNode* root = NULL;
    root = insertLevelOrder(arr, n, root, 0);

    int p_val, q_val;
    cout << "Enter the values of p and q: ";
    cin >> p_val >> q_val;

    TreeNode* p = findNode(root, p_val);
    TreeNode* q = findNode(root, q_val);

    if (p && q) {
        TreeNode* lca = lowestCommonAncestor(root, p, q);
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } else {
        cout << "Nodes not found in the tree!" << endl;
    }

    return 0;
}

//Ques14
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumNumbersHelper(TreeNode* root, int currentSum) {
    if (!root) return 0;
    currentSum = currentSum * 10 + root->val;
    if (!root->left && !root->right) return currentSum;
    return sumNumbersHelper(root->left, currentSum) + sumNumbersHelper(root->right, currentSum);
}

int sumNumbers(TreeNode* root) {
    return sumNumbersHelper(root, 0);
}

TreeNode* insertLevelOrder(int arr[], int n, TreeNode* root, int i) {
    if (i < n) {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, n, root->left, 2 * i + 1);
        root->right = insertLevelOrder(arr, n, root->right, 2 * i + 2);
    }
    return root;
}

int main() {
    int n;
    cout << "Enter the number of nodes in the tree: ";
    cin >> n;
    int arr[n];
    cout << "Enter the values of the nodes in level order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    TreeNode* root = NULL;
    root = insertLevelOrder(arr, n, root, 0);

    cout << "Total sum of all root-to-leaf numbers: " << sumNumbers(root) << endl;

    return 0;
}

//Ques15
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(currentLevel);
    }

    return result;
}

TreeNode* insertLevelOrder(int arr[], int n, TreeNode* root, int i) {
    if (i < n) {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, n, root->left, 2 * i + 1);
        root->right = insertLevelOrder(arr, n, root->right, 2 * i + 2);
    }
    return root;
}

int main() {
    int n;
    cout << "Enter the number of nodes in the tree: ";
    cin >> n;
    int arr[n];
    cout << "Enter the values of the nodes in level order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    TreeNode* root = NULL;
    root = insertLevelOrder(arr, n, root, 0);

    vector<vector<int>> result = levelOrder(root);

    cout << "Level Order Traversal: \n";
    for (auto level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

//Ques16
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();
            if (i < levelSize - 1) {
                node->next = q.front();
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
}

void printLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->val;
        if (node->next) cout << "->" << node->next->val;
        else cout << "->#";
        cout << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

Node* insertLevelOrder(int arr[], int n, Node* root, int i) {
    if (i < n) {
        Node* temp = new Node(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, n, root->left, 2 * i + 1);
        root->right = insertLevelOrder(arr, n, root->right, 2 * i + 2);
    }
    return root;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Node* root = NULL;
    root = insertLevelOrder(arr, n, root, 0);
    connect(root);
    printLevelOrder(root);
    return 0;
}

//Ques17
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            if (i == levelSize - 1) {
                result.push_back(node->val);
            }
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    return result;
}

TreeNode* insertLevelOrder(int arr[], int n, TreeNode* root, int i) {
    if (i < n) {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, n, root->left, 2 * i + 1);
        root->right = insertLevelOrder(arr, n, root->right, 2 * i + 2);
    }
    return root;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    TreeNode* root = NULL;
    root = insertLevelOrder(arr, n, root, 0);
    
    vector<int> result = rightSideView(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

//Ques18
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            currentLevel.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        if (!leftToRight) {
            reverse(currentLevel.begin(), currentLevel.end());
        }
        
        result.push_back(currentLevel);
        leftToRight = !leftToRight;
    }
    
    return result;
}

TreeNode* insertLevelOrder(int arr[], int n, TreeNode* root, int i) {
    if (i < n) {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, n, root->left, 2 * i + 1);
        root->right = insertLevelOrder(arr, n, root->right, 2 * i + 2);
    }
    return root;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    TreeNode* root = NULL;
    root = insertLevelOrder(arr, n, root, 0);
    
    vector<vector<int>> result = zigzagLevelOrder(root);
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

//Ques19
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        maxPathSumHelper(root, max_sum);
        return max_sum;
    }
    
    int maxPathSumHelper(TreeNode* node, int& max_sum) {
        if (node == NULL) return 0;
        
        int left_sum = max(0, maxPathSumHelper(node->left, max_sum));
        int right_sum = max(0, maxPathSumHelper(node->right, max_sum));
        
        max_sum = max(max_sum, node->val + left_sum + right_sum);
        
        return node->val + max(left_sum, right_sum);
    }
};

TreeNode* insertLevelOrder(int arr[], int n, TreeNode* root, int i) {
    if (i < n) {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, n, root->left, 2 * i + 1);
        root->right = insertLevelOrder(arr, n, root->right, 2 * i + 2);
    }
    return root;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    TreeNode* root = NULL;
    root = insertLevelOrder(arr, n, root, 0);
    
    Solution sol;
    cout << sol.maxPathSum(root) << endl;
    
    return 0;
}

//Ques20
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        return inorder[k - 1];
    }
    
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if (root == NULL) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
};

TreeNode* insertLevelOrder(int arr[], int n, TreeNode* root, int i) {
    if (i < n) {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, n, root->left, 2 * i + 1);
        root->right = insertLevelOrder(arr, n, root->right, 2 * i + 2);
    }
    return root;
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    TreeNode* root = NULL;
    root = insertLevelOrder(arr, n, root, 0);
    
    Solution sol;
    cout << sol.kthSmallest(root, k) << endl;
    
    return 0;
}
