class LRUCache
{
    public:
        class node
        {
            public:
                int key;
            int value;
            node * prev;
            node * next;
            node(int key, int value)
            {
                this->key = key;
                this->value = value;
            }
        };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int capacity;
    unordered_map<int, node*> mp;
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(node *curr)
    {
        node *l = curr->prev;
        node *r = curr->next;
        l->next = r;
        r->prev = l;
    }
    void addNode(node *curr)
    {
        curr->next = head->next;
        curr->prev = head;
        curr->next->prev = curr;
        head->next = curr;
    }
    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        node *curr = mp[key];
        int val = curr->value;
        mp.erase(key);
        deleteNode(curr);
        addNode(curr);
        mp[key] = head->next;
        return val;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            node *curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }
        if (mp.size() == capacity)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        mp[key] = head->next;
    }
};