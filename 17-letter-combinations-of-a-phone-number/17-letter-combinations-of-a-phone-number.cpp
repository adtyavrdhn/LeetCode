class Solution {
public:
   vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;
vector<string> letterCombinations(string digits) {
	if(digits == "") return ans;        
	string combination = "";
	helper(digits, 0, combination);
	return ans; 
}                
void helper(string &digits, int i, string &combi)
{
	if(i == size(digits)) {
		ans.push_back(combi);    
		return;
	}
	for(auto c : mappings[digits[i] - '2']){
		combi.push_back(c);           
		helper(digits, i + 1, combi); 
		combi.pop_back(); 
	}   
}
};