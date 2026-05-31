/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node*, Node*> node_map;
        Node* curr = head;
        //populate unordered map with copies
        while (curr) {
            node_map[curr] = new Node(curr->val);
            curr = curr->next;
        }
        //create copy
        Node* newHead = node_map[head];
        //add randomize nodes logic
        Node* newCurr = head;
        while (newCurr) {
            node_map[newCurr]->random = node_map[newCurr->random];
            node_map[newCurr]->next = node_map[newCurr->next];
            newCurr = newCurr->next;
        }
        return newHead;
    }
};
