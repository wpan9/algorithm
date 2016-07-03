// Design and implement a data structure for Least Recently Used (LRU) cache.
// It should support the following operations: get and set.
//
// get(key) - Get the value (will always be positive) of the key if the key
//            exists in the cache, otherwise return -1.
//
// set(key, value) - Set or insert the value if the key is not already present.
//                   When the cache reached its capacity, it should invalidate
//                   the least recently used item before inserting a new item.
//
class LRUCache {
    struct Node {
        int Key;
        int Value;
        int Age;
        Node(int Key = 0, int Value = 0, int Age = 0) : Key(Key), Value(Value), Age(Age) {}
    };
    std::vector<Node> Nodes;
    unsigned Time;

public:
    LRUCache(int capacity) : Time(0) {
        Nodes.reserve(capacity);
    }
    int get(int key) {
        Time++;
        for (auto &Item : Nodes) {
            if (Item.Key == key) {
                Item.Age = Time;
                return Item.Value;
            }
        }
        return -1;
    }
    void set(int key, int value) {
        Time++;
        for (auto &Item : Nodes) {
            if (Item.Key == key) {
                Item.Value = value;
                Item.Age = Time;
                return;
            }
        }

        if (Nodes.size() < Nodes.capacity()) {
           Nodes.push_back(Node(key, value, Time));
           return;
        }

        // Invalidate node with smallest age.
        int smallestIdx = 0
        int smallestVal = 0xEFFFFFF;
        for (int i = 0; i < Nodes.size(); ++i) {
            if (Nodes[i].Age < smallestVal) {
                smallestIdx = i;
                smallestVal = Nodes[i].Age;
            }
        }
        Nodes[smallestIdx].Value = value;
        Nodes[smallestIdx].Key = key;
        Nodes[smallestIdx].Age = Time;
    }
};

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
    map<int, Node*> hashobj;

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
        auto Iter = hashobj.find(key);
        if (Iter != hashobj.end()) {
            return Iter->second;
        }

        return nullptr;
    }

    void print() {
        if (size == 0) std::cout << "(nil)" << std::endl;
        for (auto p = head; p != nullptr; p = p->next) {
            std::cout << "(" << p->key << "," << p->value << ")" << std::endl;
        }
    }

public:
    LRUCache(int capacity) : capacity(capacity), size(0), head(nullptr), tail(nullptr) {}
    ~LRUCache() {
        for (auto p = head; p != nullptr; ) {
            auto q = p;
            p = p->next;
            delete q;
        }
    }
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
            hashobj[key] = head;
            size = 1;
            return;
        }

        if (auto p = find(key)) {
            moveToEnd(p);
            tail->value = value;
            return;
        }

        if (size < capacity) {
            Node *p = new Node(key, value);
            hashobj[key] = p;
            tail->next = p;
            p->prev = tail;
            tail = p;

            ++size;
            return;
        }

        moveToEnd(head);
        hashobj.erase(tail->key);
        hashobj[key] = tail;
        tail->key = key;
        tail->value = value;
    }
};
