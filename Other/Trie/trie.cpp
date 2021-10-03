#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Node{
    public:
        char c;
        map<char,Node * > sub;
        bool end_of_word = false;
    
    /** Inserts a word into the trie. */
    static void insert(string word, Node * root) {
        Node * cur = root;
        bool exists = true;
        for(int i = 0; i<word.length(); i++){
            if(exists && cur->sub.find(word[i]) != cur->sub.end()){
                cur = cur->sub[word[i]];
            }else{
                exists = false;
                Node * new_node = new Node();
                new_node->c = word[i];
                cur->sub.insert(make_pair(new_node->c,new_node));
                cur = new_node;
            }
        }
        cur->end_of_word = true;
        return;
    }
    
    /** Returns if the word is in the trie. */
    static bool search(string word, Node * root) {
        Node * cur = root;
        for(int i = 0; i<word.length(); i++){
            if(cur->sub.find(word[i]) != cur->sub.end()){
                cur = cur->sub[word[i]];
            }
            else
                return false;
        }
        return cur->end_of_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    static bool startsWith(string prefix, Node * root) {
        Node * cur = root;
        for(int i = 0; i<prefix.length(); i++){
            if(cur->sub.find(prefix[i]) != cur->sub.end()){
                cur = cur->sub[prefix[i]];
            }
            else
                return false;
        }
        return true;
    }
};


class Trie {
public:
    /** Initialize your data structure here. */
    Node * root = new Node();
    Trie() {
        
    }
    void insert(string word){
        Node::insert(word,root);
        return;
    }
    
    bool search(string word){
        return Node::search(word,root);
    }
    bool startsWith(string prefix) {
        return Node::startsWith(prefix,root);
    }
    
    
};

int main(){
    Trie trie;
    trie.insert("apple");
    cout<<trie.search("apple")<<endl;   // return True
    cout<<trie.search("app")<<endl;     // return False
    cout<<trie.startsWith("app")<<endl; // return True
    trie.insert("app");
    cout<<trie.search("app")<<endl;     // return True

    
    return 0;
}