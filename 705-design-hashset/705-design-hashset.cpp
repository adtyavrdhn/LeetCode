class MyHashSet {
public:
   const int BUCKET_SIZE = 123; 
	vector<int> bucket[123];
	MyHashSet() {
	
	}

	void add(int key) { 
		int index = key % BUCKET_SIZE;
		if(!contains(key))
			bucket[index].push_back(key);
	}

	void remove(int key) {
		int index = key % BUCKET_SIZE;
		for(vector<int>::iterator it = bucket[index].begin(); it != bucket[index].end(); it++)
			if(*it == key) { bucket[index].erase(it); break; }
	}

	bool contains(int key) 
    {
		int index = key % BUCKET_SIZE;
		for(vector<int>::iterator it = bucket[index].begin(); it != bucket[index].end(); it++)
			if(*it == key) { return true; }
		return false;
	}
};
