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
        stack<Node*> stack;
        vector<int> result; // stores the preorder traversal
        if (root == nullptr){
            return result;
        }

        // inserting the root element into the stack
        // this will help start the traversal
        stack.push(root);
        while(!stack.empty()){
            Node* node = stack.top();
            stack.pop();
            // storing the elements into the preorder traversal fashion
            result.push_back(node->val);
            // as 
            reverse(node->children.begin(), node->children.end());
            for (Node* child: node-> children){
                stack.push(child);
            }
        }
        return result;
    }
};