class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

   
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < arr.size(); i++)
		pq.push({abs(arr[i] - x), arr[i]});

	vector<int> res;

	for (int i = 0; i < k; i++)
	{
		res.push_back(pq.top().second);
		pq.pop();
	}

	sort(res.begin(), res.end());
	return res;
}
};

// optimal:- https://leetcode.com/problems/find-k-closest-elements/discuss/2637918/C%2B%2BororBinary-Search-ororEasy-to-Understand