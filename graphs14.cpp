#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;
//Problem 1: Word Ladder-I
//Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//Only one letter can be changed at a time. Each transformed word must exist in the word list.
//Note: Return 0 if there is no such transformation sequence.All words have the same length. All words contain only lowercase alphabetic characters.
//You may assume no duplicates in the word list.You may assume beginWord and endWord are non-empty and are not the same.
//For Optimal Approach, we will use BFS traversal to find the shortest path in an unweighted graph. 
int wordLadderLength(string startWord,string targetWord,vector<string> &wordList){
    queue<pair<string,int>> q;
    q.push({startWord,1});
    unordered_set<string> st(wordList.begin(),wordList.end());
    if(st.find(targetWord)==st.end()){ 
        return 0;
    }
    st.erase(startWord);
    while (!q.empty()){
        string word=q.front().first;
        int steps=q.front().second;
        q.pop();
        if(word==targetWord){
            return steps;
        }
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i]=original;
        }
    }
    return 0;
} // TC=O(N*M*26) SC=O(N) for unordered_set + O(M) for queue where N=number of words in wordList and M=length of each word
//Problem 2: Word Ladder-II
//Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//Only one letter can be changed at a time. Each transformed word must exist in the word list.
//Note: Return an empty list if there is no such transformation sequence.All words have the same length. All words contain only lowercase alphabetic characters.
//You may assume no duplicates in the word list.You may assume beginWord and endWord are non-empty and are not the same.
//For Optimal Approach, we will use BFS to build a graph of the shortest paths, then use DFS to find all paths from beginWord to endWord.
void DFS(string currentWord,string targetWord,unordered_map<string,vector<string>>& adj,vector<string>& path,vector<vector<string>>& result){
    if(currentWord==targetWord){
        result.push_back(path);
        return;
    }
    for(auto neighbor:adj[currentWord]){
        path.push_back(neighbor);
        DFS(neighbor,targetWord,adj,path,result);
        path.pop_back();
    }
}
vector<vector<string>> wordLadderAllPaths(string startWord,string targetWord,vector<string> &wordList){
    queue<string> q;
    q.push(startWord);
    unordered_set<string> st(wordList.begin(),wordList.end());
    unordered_map<string,vector<string>> adj;
    vector<vector<string>> result;
    if(st.find(targetWord)==st.end()){ 
        return result;
    }
    st.erase(startWord);
    bool found=false;
    while (!q.empty() && !found){
        int size=q.size();
        unordered_set<string> visitedThisLevel;
        for(int i=0;i<size;i++){
            string word=q.front();
            q.pop();
            string parent=word;
            for(int j=0;j<word.size();j++){
                char original=word[j];
                for(char ch='a';ch<='z';ch++){
                    word[j]=ch;
                    if(st.find(word)!=st.end()){
                        visitedThisLevel.insert(word);
                        adj[parent].push_back(word);
                        if(word==targetWord){
                            found=true;
                        }
                        q.push(word);
                    }
                }
                word[j]=original;
            }
        }
        for(auto it:visitedThisLevel){
            st.erase(it);
        }
    }
    if(found){
        vector<string> path;
        path.push_back(startWord);
        DFS(startWord,targetWord,adj,path,result);
    }
    return result;
} // TC=O(N*M*26 + K) SC=O(N) for unordered_set + O(N) for adjacency list + O(M) for path + O(K) for result where N=number of words in wordList, M=length of each word, and K=number of paths found
int main(){
    string startWord="hit";
    string targetWord="cog";
    vector<string> wordList={"hot","dot","dog","lot","log","cog"};
    cout<<wordLadderLength(startWord,targetWord,wordList);
    cout<<endl;
    vector<vector<string>> allPaths=wordLadderAllPaths(startWord,targetWord,wordList);
    for(auto path:allPaths){
        for(auto word:path){
            cout<<word<<" ";
        }
        cout<<endl;
    }
    return 0;
}