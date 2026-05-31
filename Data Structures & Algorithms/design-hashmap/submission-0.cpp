class Node {
public: // Added public access
    int key; // Added missing key declaration
    int val;
    Node* next;

    Node(int key, int value) {
        this->key = key;
        this->val = value;
        this->next = nullptr;
    }
}; // Added missing semicolon

class MyHashMap {
public:
    vector<Node*> backingArray;

    MyHashMap() {
        // Fixed assignment syntax
        backingArray = vector<Node*>(1000, nullptr); 
    }
    
    void put(int key, int value) {
        int hash = key % 1000;
        
        if (backingArray[hash] != nullptr) {
            Node* curr = backingArray[hash];
            
            // Simplified traversal: just check curr
            while (curr != nullptr) {
                if (curr->key == key) {
                    curr->val = value;
                    return; // Added required return
                }
                // If we are at the tail, break so we can append
                if (curr->next == nullptr) break; 
                curr = curr->next;
            }
            // Append to the end
            curr->next = new Node(key, value); 
            
        } else {
            // Doesn't have a head
            backingArray[hash] = new Node(key, value);
        }
    }
    
    int get(int key) {
        int hash = key % 1000;
        // Simplified: head check is automatically handled by the while loop
        Node* curr = backingArray[hash];
        while (curr != nullptr) {
            if (curr->key == key) {
                return curr->val; // Fixed: 'curr->val' instead of 'value'
            }
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash = key % 1000;
        
        if (backingArray[hash] != nullptr) {
            // Handle head case
            if (backingArray[hash]->key == key) {
                Node* temp = backingArray[hash];
                backingArray[hash] = backingArray[hash]->next;
                delete temp; // Prevent memory leak
                return;      // Added required return!
            }
            
            Node* prev = backingArray[hash];
            Node* curr = backingArray[hash]->next;
            
            // Fixed loop condition: must check curr, not prev
            while (curr != nullptr) { 
                if (curr->key == key) {
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
};