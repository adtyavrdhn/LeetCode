struct Node
{
    Node* links[26]; // Links
    
    bool flag = false; // EOW
    
    bool contains(char c)
    {
        return links[c-'a'] != NULL;
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
class Trie {
public:
    Node* root; // root of our trie
    Trie() 
    {
        root = new Node();
    }
    
    void insert(string word) 
    {
        Node* node = root; // pointer to root;
        
        for(int i=0;i<word.size();i++)
        {
            if(!node->contains(word[i]))
            {
               // if the character is not there, we will add a node corr to it
                
                node->put(word[i],new Node()); // now we need to change our reference pointer to this new node
            }
            
            node = node->get(word[i]);
        }
        
        node->flag = true; // setting end of the word
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