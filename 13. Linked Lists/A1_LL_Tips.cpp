//SLL
#include <iostream>
#include <vector>
using namespace std;

class LinkedList {
private:
    // node struct inside the class (encapsulation)
    struct Node {
        int data;
        Node* next;
        Node(int v) : data(v), next(nullptr) {} // convenient constructor
    };

    Node* head; // points to the first node
    int sz;     // current size (length) of the list

    // helper: return pointer to node at index pos (0-based).
    // returns nullptr if pos is out of range.
    Node* getNodeAt(int pos) const {
        if (pos < 0 || pos >= sz) return nullptr;
        Node* cur = head;
        for (int i = 0; i < pos; ++i) cur = cur->next;
        return cur;
    }

public:
    // constructor & destructor
    LinkedList() : head(nullptr), sz(0) {}
    ~LinkedList() { clear(); } // free all nodes on destruction

    // Basic queries
    int length() const { return sz; }
    bool isEmpty() const { return head == nullptr; }

    // Insertions
    bool insertAtHead(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
        ++sz;
        return true;
    }

    bool insertAtTail(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
        } else {
            Node* cur = head;
            while (cur->next) cur = cur->next; // traverse to last
            cur->next = n;
        }
        ++sz;
        return true;
    }

    // Insert at position pos (0-based). Valid pos: 0..sz (pos==sz inserts at tail).
    // Returns false if pos is invalid.
    bool insertAtPos(int pos, int val) {
        if (pos < 0 || pos > sz) return false; // invalid
        if (pos == 0) return insertAtHead(val);
        // get node before insertion point
        Node* prev = getNodeAt(pos - 1);
        Node* n = new Node(val);
        n->next = prev->next;
        prev->next = n;
        ++sz;
        return true;
    }

    // Display list: "1 -> 2 -> 3"
    void display() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " -> ";
            cur = cur->next;
        }
        cout << '\n';
    }

    // Search for value, return first index (0-based), or -1 if not found
    int search(int val) const {
        Node* cur = head;
        int idx = 0;
        while (cur) {
            if (cur->data == val) return idx;
            cur = cur->next;
            ++idx;
        }
        return -1;
    }

    // Delete node at position pos (0-based). Returns false if pos invalid.
    bool deleteAtPos(int pos) {
        if (pos < 0 || pos >= sz || !head) return false;
        Node* toDel = nullptr;
        if (pos == 0) {
            toDel = head;
            head = head->next;        // move head forward
        } else {
            Node* prev = getNodeAt(pos - 1);
            if (!prev || !prev->next) return false; // safety
            toDel = prev->next;
            prev->next = toDel->next; // link around node-to-delete
        }
        delete toDel;
        --sz;
        return true;
    }

    // Delete first occurrence of value. Returns true if deleted.
    bool deleteByValue(int val) {
        if (!head) return false;
        if (head->data == val) {
            Node* t = head;
            head = head->next;
            delete t;
            --sz;
            return true;
        }
        Node* cur = head;
        while (cur->next && cur->next->data != val) cur = cur->next;
        if (!cur->next) return false; // not found
        Node* toDel = cur->next;
        cur->next = toDel->next;
        delete toDel;
        --sz;
        return true;
    }

    // Reverse list in-place (iterative)
    void reverse() {
        Node* prev = nullptr;
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        head = prev;
    }

    // Clear list and free memory
    void clear() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = nullptr;
        sz = 0;
    }

    // Utility: return vector of values (useful for tests)
    vector<int> toVector() const {
        vector<int> v;
        Node* cur = head;
        while (cur) {
            v.push_back(cur->data);
            cur = cur->next;
        }
        return v;
    }
};

// Demonstration / quick test
int main() {
    LinkedList L;

    // insert some values
    L.insertAtTail(10);
    L.insertAtTail(20);
    L.insertAtTail(30);
    L.insertAtHead(5);           // list: 5 -> 10 -> 20 -> 30
    L.insertAtPos(2, 15);        // insert 15 at index 2: 5 -> 10 -> 15 -> 20 -> 30
    cout << "After inserts: ";
    L.display();

    cout << "Length: " << L.length() << '\n';
    cout << "Index of 20: " << L.search(20) << '\n';
    cout << "Index of 99: " << L.search(99) << '\n';

    L.deleteAtPos(2);            // deletes 15
    cout << "After deleteAtPos(2): ";
    L.display();

    L.deleteByValue(5);          // deletes head (5)
    cout << "After deleteByValue(5): ";
    L.display();

    L.reverse();
    cout << "After reverse: ";
    L.display();

    L.clear();
    cout << "After clear, isEmpty: " << boolalpha << L.isEmpty() << '\n';

    return 0;
}

//DLL

#include <iostream>
#include <vector>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int v) : data(v), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail; // handy for O(1) insertion at tail
    int sz;

    // get node at pos (0-based), nullptr if out of range
    Node* getNodeAt(int pos) const {
        if (pos < 0 || pos >= sz) return nullptr;
        // choose direction based on closeness for efficiency
        if (pos < sz/2) {
            Node* cur = head;
            for (int i = 0; i < pos; ++i) cur = cur->next;
            return cur;
        } else {
            Node* cur = tail;
            for (int i = sz-1; i > pos; --i) cur = cur->prev;
            return cur;
        }
    }

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), sz(0) {}
    ~DoublyLinkedList() { clear(); }

    int length() const { return sz; }
    bool isEmpty() const { return sz == 0; }

    bool insertAtHead(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
        ++sz;
        return true;
    }

    bool insertAtTail(int val) {
        Node* n = new Node(val);
        if (!tail) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        ++sz;
        return true;
    }

    // insert at pos (0..sz)
    bool insertAtPos(int pos, int val) {
        if (pos < 0 || pos > sz) return false;
        if (pos == 0) return insertAtHead(val);
        if (pos == sz) return insertAtTail(val);
        Node* nextNode = getNodeAt(pos);
        if (!nextNode) return false; // safety
        Node* prevNode = nextNode->prev;
        Node* n = new Node(val);
        n->next = nextNode;
        n->prev = prevNode;
        prevNode->next = n;
        nextNode->prev = n;
        ++sz;
        return true;
    }

    void display() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " <-> ";
            cur = cur->next;
        }
        cout << '\n';
    }

    int search(int val) const {
        Node* cur = head;
        int idx = 0;
        while (cur) {
            if (cur->data == val) return idx;
            cur = cur->next;
            ++idx;
        }
        return -1;
    }

    bool deleteAtPos(int pos) {
        if (pos < 0 || pos >= sz || !head) return false;
        Node* toDel = nullptr;
        if (pos == 0) {
            toDel = head;
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr; // list became empty
        } else {
            toDel = getNodeAt(pos);
            Node* p = toDel->prev;
            Node* n = toDel->next;
            p->next = n;
            if (n) n->prev = p;
            else tail = p; // removed last element
        }
        delete toDel;
        --sz;
        return true;
    }

    bool deleteByValue(int val) {
        Node* cur = head;
        int pos = 0;
        while (cur && cur->data != val) {
            cur = cur->next;
            ++pos;
        }
        if (!cur) return false;
        return deleteAtPos(pos);
    }

    // Reverse by swapping next/prev and swapping head/tail
    void reverse() {
        Node* cur = head;
        while (cur) {
            Node* tmp = cur->next;
            cur->next = cur->prev;
            cur->prev = tmp;
            cur = tmp;
        }
        // swap head and tail
        Node* tmp = head;
        head = tail;
        tail = tmp;
    }

    void clear() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = tail = nullptr;
        sz = 0;
    }

    vector<int> toVector() const {
        vector<int> v; v.reserve(sz);
        Node* cur = head;
        while (cur) { v.push_back(cur->data); cur = cur->next; }
        return v;
    }
};

//CLL

#include <iostream>
#include <vector>
using namespace std;

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int v) : data(v), next(nullptr) {}
    };

    Node* tail; // tail==nullptr => empty; head = tail->next
    int sz;

    // get node at pos (0-based), nullptr if out of range
    Node* getNodeAt(int pos) const {
        if (pos < 0 || pos >= sz || !tail) return nullptr;
        Node* cur = tail->next; // head
        for (int i = 0; i < pos; ++i) cur = cur->next;
        return cur;
    }

public:
    CircularLinkedList() : tail(nullptr), sz(0) {}
    ~CircularLinkedList() { clear(); }

    int length() const { return sz; }
    bool isEmpty() const { return sz == 0; }

    // Insert at head (pos 0); O(1)
    bool insertAtHead(int val) {
        Node* n = new Node(val);
        if (!tail) {
            tail = n;
            tail->next = tail; // single node circular
        } else {
            n->next = tail->next; // new->next = head
            tail->next = n;       // tail->next = new head
        }
        ++sz;
        return true;
    }

    // Insert at tail (O(1) by inserting after tail and moving tail)
    bool insertAtTail(int val) {
        insertAtHead(val);   // insert new node as head
        tail = tail->next;   // advance tail to new node
        return true;
    }

    // insert at pos (0..sz)
    bool insertAtPos(int pos, int val) {
        if (pos < 0 || pos > sz) return false;
        if (pos == 0) return insertAtHead(val);
        if (pos == sz) return insertAtTail(val);

        // find node at pos-1
        Node* prev = getNodeAt(pos - 1);
        if (!prev) return false;
        Node* n = new Node(val);
        n->next = prev->next;
        prev->next = n;
        ++sz;
        return true;
    }

    // Linear display (prints head..tail once). If empty prints newline.
    void display() const {
        if (!tail) { cout << '\n'; return; }
        Node* cur = tail->next; // head
        for (int i = 0; i < sz; ++i) {
            cout << cur->data;
            if (i < sz-1) cout << " -> ";
            cur = cur->next;
        }
        cout << '\n';
    }

    // search returns index of first match else -1
    int search(int val) const {
        if (!tail) return -1;
        Node* cur = tail->next; // head
        for (int i = 0; i < sz; ++i) {
            if (cur->data == val) return i;
            cur = cur->next;
        }
        return -1;
    }

    // delete at pos (0..sz-1)
    bool deleteAtPos(int pos) {
        if (!tail || pos < 0 || pos >= sz) return false;
        if (sz == 1) { // only node
            delete tail;
            tail = nullptr;
            sz = 0;
            return true;
        }
        if (pos == 0) {
            Node* head = tail->next;
            tail->next = head->next; // bypass head
            delete head;
            --sz;
            return true;
        }
        Node* prev = getNodeAt(pos - 1);
        if (!prev || !prev->next) return false;
        Node* toDel = prev->next;
        prev->next = toDel->next;
        if (toDel == tail) tail = prev; // adjust tail if last removed
        delete toDel;
        --sz;
        return true;
    }

    bool deleteByValue(int val) {
        int pos = search(val);
        if (pos == -1) return false;
        return deleteAtPos(pos);
    }

    // Reverse circular list (reverse links and adjust tail)
    void reverse() {
        if (!tail || sz <= 1) return;
        Node* prev = tail;
        Node* cur = tail->next; // head
        Node* start = cur;
        for (int i = 0; i < sz; ++i) {
            Node* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        // after loop, prev==old-tail, cur==old-head
        tail = start; // new tail is old head
    }

    void clear() {
        if (!tail) return;
        Node* cur = tail->next; // head
        for (int i = 0; i < sz; ++i) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        tail = nullptr;
        sz = 0;
    }

    vector<int> toVector() const {
        vector<int> v;
        if (!tail) return v;
        Node* cur = tail->next;
        for (int i = 0; i < sz; ++i) {
            v.push_back(cur->data);
            cur = cur->next;
        }
        return v;
    }
};
