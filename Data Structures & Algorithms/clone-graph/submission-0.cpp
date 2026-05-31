/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> seen;
        // seen[node] = new Node(node->val);
        dfs(seen, node);
        return seen[node];
    }

    Node* dfs(unordered_map<Node*, Node*>& seenMap, Node* node) {
        //base case
        if (node == NULL) {
            return nullptr;
        }
        if (seenMap.count(node)) {
            //node already exists as a key
            return seenMap[node];
        } 
        seenMap[node] = new Node(node->val);
        for (Node* neighbor: node->neighbors) {
            //traverse original nodes neighbours
            seenMap[node]->neighbors.push_back(dfs(seenMap, neighbor));
        }
        return seenMap[node];
    }

};
