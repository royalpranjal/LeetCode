LeetCode
Problems
Mock 
Contest
Articles
Discuss
•
  Store 
 Premium
New PlaygroundroyalpranjalNotes Auto Saved.
|||

Type here...(Markdown is enabled)
​
 16 9
 
Add to List
720. Longest Word in Dictionary
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
Note:

All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].
Seen this question in a real interview before?   Yes  No
Difficulty:Easy
Total Accepted:2.4K
Total Submissions:6.4K
Contributor: zestypanda
Subscribe to see which companies asked this question.

Related Topics 
Hash Table Trie 
Similar Questions 
Longest Word in Dictionary through Deleting Implement Magic Dictionary 
 

1
class Solution {
2
public:
3
    struct comp{
4
        bool operator()(string& a, string& b){
5
            if(a.size() == b.size()){
6
                for(int i = 0; i < a.size(); i++){
7
                    if(a[i] < b[i]){
8
                        return true;
9
                    }
10
                    else if(a[i] > b[i]){
11
                        return false;
12
                    }
13
                }
14
            }
15
            
16
            return a.size() > b.size();
17
        }  
18
    };
19
    
20
    string getsubstr(string s){
21
        int n = s.size();
22
        
23
        string ans = "";
24
        
25
        for(int i = 0; i < n-1; i++){
26
            ans += s[i];
27
        }
28
        
29
        return ans;
30
    }
31
    
32
    
33
    string longestWord(vector<string>& words) {
34
        map<string, bool> m;
35
        
36
        int n = words.size();
37
        
38
        for(int i = 0; i < n; i++){
39
            m[words[i]] = true;
40
        }
41
        
42
        sort(words.begin(), words.end(), comp());
43
        
44
        // for(int i = 0; i < n; i++){
45
        //     cout << words[i] << " ";
46
        // }
47
        
48
        for(int i = 0; i < n; i++){
49
            string temp = getsubstr(words[i]);
50
            while(temp.size() != 0 && m.find(temp) != m.end()){
51
                temp = getsubstr(temp);
52
            }
53
            
54
            if(temp.size() == 0){
55
                return words[i];
56
            }
57
        }
58
        
59
        return "";
60
    }
61
};
  Custom Testcase( Contribute  )

["a", "banana", "app", "appl", "ap", "apply", "apple"]
 How to create a testcase
 Run Code Submit Solution
Submission Result: Accepted More Details 
Share your acceptance!

Check out our solution!Reveal Solution 

Copyright © 2017 LeetCode Contact Us  |  Frequently Asked Questions  |  Terms of Service 
