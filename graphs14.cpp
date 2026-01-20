#include <iostream>
#include <unordered_set>
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
int main(){
    string startWord="hit";
    string targetWord="cog";
    vector<string> wordList={"hot","dot","dog","lot","log","cog"};
    cout<<wordLadderLength(startWord,targetWord,wordList);
    return 0;
}