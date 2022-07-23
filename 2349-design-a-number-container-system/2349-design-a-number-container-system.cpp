class NumberContainers {
public:
    unordered_map<int,int> mpp;
    unordered_map<int,set<int>> smpp;
    NumberContainers() 
    {
        
    }
    
    void change(int index, int number) 
    {
        if(mpp.count(index))
        {
            smpp[mpp[index]].erase(index);
            smpp[number].insert(index);
            
            mpp[index]=number;
        }
        else
        {
            mpp[index]=number;
            smpp[number].insert(index);
        }
    }
    
    int find(int number) 
    {
        if(smpp.find(number)==smpp.end() || smpp[number].size()==0)
        {
            return -1;
        }
        
        return *(smpp[number].begin());
        
        // return 0;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */