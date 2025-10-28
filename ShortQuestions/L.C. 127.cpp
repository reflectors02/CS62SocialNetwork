class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        //faster lookup time than wordList, i think...
        unordered_set<string> listWords(wordList.begin(), wordList.end());

        //edge case if it doesn't have it, then save time.
        if(!listWords.contains(endWord)){return 0;};

        unordered_set<char> alphabet({'a','b','c','d','e','f','g','h','i','j',
                                    'k','l','m','n','o','p','q','r','s','t',
                                    'u','v','w','x','y','z'});

        unordered_map<string, string> prev;
        unordered_set<string> visited;
        queue<string> qu;
        qu.push(beginWord);
        visited.insert(beginWord);

        //in class we did -1 in ints, so just to keep the consistency
        prev[beginWord] = "-1";


        //added because if there's no edge to the end but the endword does exist---i kept on getting infinite loops caused by it not being found.
        bool isFound = false;
        while(!qu.empty())
        {
            string curr_word = qu.front();
            qu.pop();
            vector<char> curr(curr_word.begin(), curr_word.end());
            
            if(curr_word == endWord){isFound = true; break;}

            for(int pos = 0; pos < curr.size(); pos++)
            {
                vector<char> neighbor = curr;
                for(auto letter : alphabet)
                {
                    neighbor[pos] = letter;
                    string neighbor_word(neighbor.begin(), neighbor.end());

                    //so we don't keeping doing the same word-> infinite loop
                    if(neighbor_word == curr_word) {continue;}

                    if(listWords.contains(neighbor_word) && !visited.contains(neighbor_word))
                    {
                        visited.insert(neighbor_word);
                        prev[neighbor_word] = curr_word;
                        qu.push(neighbor_word);
                    }
                }
            }
        }

        //if we don't find it, then we prevent an infinite loop in the following lines
        if(isFound == false){return 0;}

        vector<string> sol;
        string curr = endWord;

        while(curr != "-1")
        {
            sol.push_back(curr);
            curr = prev[curr];
        }

        reverse(sol.begin(), sol.end());
        return sol.size();
    }
};