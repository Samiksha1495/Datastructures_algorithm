#include <bits/stdc++.h> 
using namespace std; 
#define NO_OF_CHARS 256 
  
int longestUniqueSubsttr(string str) 
{ 
    int n = str.size(); 
  
    int res = 0; 
    vector<int> lastIndex(NO_OF_CHARS, -1); 
    int i = 0; 
    for (int j = 0; j < n; j++) { 
        i = max(i, lastIndex[str[j]] + 1); 
        res = max(res, j - i + 1); 
        lastIndex[str[j]] = j; 
    } 
    return res; 
} 
  
// Driver code 
int main() 
{ 
    string str = "geeksforgeeks"; 
    cout << "The input string is " << str << endl; 
    int len = longestUniqueSubsttr(str); 
    cout << "The length of the longest non-repeating "
            "character substring is "
         << len; 
    return 0; 
} 