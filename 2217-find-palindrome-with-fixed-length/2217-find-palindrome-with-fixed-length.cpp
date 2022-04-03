class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
         
    //for taking the power if intLength is 7 which is odd then 10^(7/2) i.e., 10^3 and if its 6 which is even the 10^(6/2-1) i.e., 10^2
    int power = intLength%2==0 ? (intLength/2-1) : (intLength/2);
    int start = pow(10, power);
    
    vector<long long> ans;
    for(int i=0; i<queries.size(); i++){
        
        //according to the observation 10+ query no. if its length is 3 & if length is 4 then it will start from 100 + query no.
        //start+ queries[i] - 1 -> 100 + 1 - 1 = 100
        string temp = to_string(start+ queries[i] - 1);
        
        //rev will store temp and will reverse it
        //reverse(100) -> 001
        string rev = temp;
        reverse(rev.begin(), rev.end());
        
        //intLength is even then 100+001 -> 100001 as its stored in string
        if(intLength%2==0){
            temp = temp + rev;
            
        //if intLength is odd then 1000+001 -> 1000001
        } else {
            //substr(pos, length) -> pos = position of first character and length of string
            //0001 -> 001
            temp = temp + rev.substr(1, rev.size()-1);
        }
        
        //Edge case that string should fall under the given length
        if(temp.size() == intLength){
            
            //stoll is used to convert string to long long
            ans.push_back(stoll(temp));
        }else {
            ans.push_back(-1);
        }
    }
    return ans;
    }
};