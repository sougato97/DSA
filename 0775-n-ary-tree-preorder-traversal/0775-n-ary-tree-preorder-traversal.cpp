/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root == nullptr){
            return result;
        }
        traversePreOrder(root, result);
        return result;
    }
private:
    void traversePreOrder(Node* root, vector<int>& result){
        if (root == nullptr){
            return;
        }
        // add the root value first
        result.push_back(root->val);
        // recursively add the childrem
        for (auto child: root->children){
            // here each child behaves as they are their own root
            traversePreOrder(child, result);
        }    
    }
};