class LRUCache {
    struct Node {
        int key;
        int value;
        Node *prev;
        Node *next;
        Node(int key, int val) : key(key), value(val), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    int size;
    Node *head;
    Node *tail;
    map<int, Node*> hash;

    void moveToEnd(Node *p) {
        if (size == 1 || p == tail) {
            return;
        }
        // move head to the end;
        //             P
        // head------> N1 <--> N2 <--> N3 --> nullptr
        // head------> N2 <--> N3 <--> N1 --> nullptr
        //                             P
        if (p == head) {
            head = p->next;
            head->prev = nullptr;

            tail->next = p;
            p->prev = tail;
            p->next = nullptr;

            tail = p;
            return;
        }

        // move internal node to the end;
        //                     P
        // head------> N1 <--> N2 <--> N3 <--> N4 --> nullptr
        // head------> N1 <--> N3 <--> N4 <--> N2 --> nullptr
        //                                     P
        p->prev->next = p->next;
        p->next->prev = p->prev;

        tail->next = p;
        p->prev = tail;
        p->next = nullptr;

        tail = p;
    }

    Node *find(int key) {
        auto Iter = hash.find(key);
        if (Iter != hash.end()) {
            return Iter->second;
        }

        return nullptr;
    }

public:
    LRUCache(int capacity) : capacity(capacity), size(0), head(nullptr), tail(nullptr) {}

    // get(key) - Get the value (will always be positive) of the key if the key
    //            exists in the cache, otherwise return -1.
    int get(int key) {
        if (auto p = find(key)) {
            moveToEnd(p);
            return p->value;
        }

        return -1;
    }
    // set(key, value) - Set or insert the value if the key is not already present.
    //                   When the cache reached its capacity, it should invalidate
    //                   the least recently used item before inserting a new item.
    void set(int key, int value) {
        if (size == 0) {
            head = tail = new Node(key, value);
            hash[key] = head;
            size = 1;
            return;
        }

        if (auto p = find(key)) {
            moveToEnd(p);
            p->value = value;
            return;
        }

        if (size < capacity) {
            Node *p = new Node(key, value);
            hash[key] = p;

            tail->next = p;
            p->prev = tail;
            tail = p;

            ++size;
            return;
        }

        // move head to tail then invalidate the tail.
        // Invalidate this key, by setting its corresponding node to nullptr..
        moveToEnd(head);
        hash[tail->key] = nullptr;

        // reuse tail node for this new key.
        tail->key = key;
        tail->value = value;
        hash[key] = tail;
    }
};
