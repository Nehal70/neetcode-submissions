class Node {
public: 
    int val;
    Node* next;

    Node(int value) {
        this->val = value;
        this->next = nullptr;
    }
};

class MyHashSet {
public:
    vector<Node*> backingArray;

    MyHashSet() {
        backingArray = vector<Node*>(1000, nullptr);
    } // Missing closing brace added here
    
    void add(int key) {
        int hash = key % 1000; 
        if (backingArray[hash] != nullptr) {
            Node* curr = backingArray[hash];
            while (curr->next != nullptr) {
                if (curr->val == key) {
                    return;
                } else {
                    curr = curr->next;
                }
            }
            
            // Replaced ternary with if statement
            if (curr->val == key) {
                return;
            } else {
                curr->next = new Node(key);
            }
        } else {
            // Head
            backingArray[hash] = new Node(key);
        }
    }
    
    void remove(int key) {
        int hash = key % 1000; 
        if (backingArray[hash] != nullptr) {
            // handle head case
            if (backingArray[hash]->val == key) {
                Node* temp = backingArray[hash];
                backingArray[hash] = backingArray[hash]->next;
                delete temp; // Prevent memory leak
                return;      // Exit after removal
            }
            // handle rest
            Node* prev = backingArray[hash];
            Node* curr = prev->next;
            while (curr != nullptr) {
                if (curr->val == key) { // Compare value, not pointer
                    prev->next = curr->next;
                    delete curr; // Prevent memory leak
                    return;
                } else {
                    prev = curr;
                    curr = curr->next;
                }
            }
        } 
    }
    
    bool contains(int key) {
        int hash = key % 1000;
        // Simplify by checking head directly (handles nullptr automatically)
        Node* curr = backingArray[hash]; 
        while (curr != nullptr) {
            if (curr->val == key) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */