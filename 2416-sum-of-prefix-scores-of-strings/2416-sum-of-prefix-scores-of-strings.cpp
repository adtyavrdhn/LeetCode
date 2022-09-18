struct Node
{
    Node* links[26];
    bool flag = false;
    int cp = 0;
    
    bool contains(char c)
    {
        return links[c-'a'] != NULL;
    }
    void put(char c, Node* node)
    {
        links[c-'a']=node;
    }
    Node* get(char c)
    {
        return links[c-'a'];
    }
};
class Solution {
public:
    Node* root;
    vector<int> sumPrefixScores(vector<string>& words) 
    {
        root = new Node();
        
        Node* node = root;
        
        for(int i=0;i<words.size();i++)
        {
            string s = words[i];
            
            node = root;
            
            for(int j=0;j<s.size();j++)
            {
                if(!node->contains(s[j]))
                {
                    node->put(s[j],new Node());
                }
                
                node = node->get(s[j]);
                node->cp++;
            }
            
            node->flag = true;
        }
        
        vector<int> res;
        
        for(int i=0;i<words.size();i++)
        {
            string s = words[i];
            node = root;
            int count = 0;
            
            for(int j=0;j<s.size();j++)
            {
                node = node->get(s[j]);
                
                count+= node->cp;
            }
            
            res.push_back(count);
        }
        
        return res;
    }
};