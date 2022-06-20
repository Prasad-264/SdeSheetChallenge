/*
Problem Statement

You are given a non-empty string S containing no spaces’ and a dictionary of non-empty strings (say the list of words). 
You are supposed to construct and return all possible sentences after adding spaces in the originally given string ‘S’,
such that each word in a sentence exists in the given dictionary.

Note :

The same word in the dictionary can be used multiple times to make sentences.
Assume that the dictionary does not contain duplicate words.

Sample Input 1:

1
6
god is now no where here
godisnowherenowhere

Sample Output 1:

god is no where no where
god is no where now here
god is now here no where
god is now here now here

Explanation To Sample Input 1:

One way to make sentences is to take “god” and append a space, then take “is”  and append space, take “now” from the dictionary 
and take “here” as well. 
Similarly, for other sentences also, we can add space to get other possible sentences. Note that we can reuse dictionary words 
as “no” and “now” are used two times in the same sentence.

Sample Input 2:

1
4
god is no here
godisnowhere

Sample Output 2:

No output to be printed

Explanation To Sample Input 2:

We can not make any sentence because after making “god is no” we will be stuck with “where”. There is no way to 
break “where” further such that we can get any word from the dictionary.

*/

void words(string &s, int start, vector<string> &dictionary, vector<string> &ans, string &curr) {
    // We've reached end of string
    if(start >= s.size()) {
        ans.push_back(curr);
        return;
    }
    
    for(int i=start; i<s.size(); ++i) {
        string tmp = s.substr(start, i-start+1);
        
        // Check if this word is present in dictionary
        bool isPresent = false;
        for(string st : dictionary) {
            if(st.compare(tmp) == 0) {
                isPresent = true;
                break;
            }
        }
        
        // If this word is present in dictionary
        // then try the remaining string
        if(isPresent) {
            string x = curr;
            // Push this to current ans
            curr += tmp + " ";
            
            words(s, i+1, dictionary, ans, curr);
            
            // Backtracking
            curr = x;
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary) {
    vector<string> ans;
    string curr;
    words(s, 0, dictionary, ans, curr);
    return ans;
}