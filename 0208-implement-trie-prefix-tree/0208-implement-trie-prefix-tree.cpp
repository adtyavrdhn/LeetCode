struct Node
{
    Node* links[26];
    
    bool flag = false;
    
    bool contains(char c)
    {
        return links[c-'a']!=NULL;
    }
    void put(char c, Node* node)
    {
        links[c-'a'] = node;
    }
    Node* get(char c)
    {
        return links[c-'a'];
    }
};
Node* root;
class Trie {
public:
    Trie() {
        root = new Node(); // root of our trie
    }
    
    void insert(string word) 
    {
        Node* node = root;
        
        for(int i=0;i<word.size();i++)
        {
            if(!node->contains(word[i]))
            {
                node->put(word[i],new Node());
            }
            
            node = node->get(word[i]);
        }
        
        node->flag = true; // marking EOW
    }
    
    bool search(string word) 
    {
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->contains(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        
        return node->flag;
    }
    
    bool startsWith(string word) 
    {
         Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->contains(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */