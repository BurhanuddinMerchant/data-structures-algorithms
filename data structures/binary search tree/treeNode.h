template <typename V>
class TreeNode
{
private:
    V val;
    TreeNode *left, *right;

public:
    // constructors
    TreeNode() : left(nullptr), right(nullptr) {}
    TreeNode(V v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(V v, TreeNode *l, TreeNode *r) : val(v), left(l), right(r) {}

    // getters
    V getVal() { return this->val; }
    TreeNode *getRightChild() { return this->right; }
    TreeNode *getLeftChild() { return this->left; }

    // setters
    void setVal(V v) { this->val = v; }
    void setLeftChild(TreeNode *l) { this->left = l; }
    void setRightChild(TreeNode *r) { this->right = r; }
};