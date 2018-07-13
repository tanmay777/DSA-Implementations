/**
 * Author: Tanmay Jha
 * Date: 05/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

#define hashmap unordered_map<char,node*>

class node{
    public: 
        char data;
        hashmap h;
        bool isTerminal;

        node(char d){
            data=d;
            isTerminal=false;
        }
};

class Trie{
    node *root;

    public:
        Trie(){
            root=new node('\0');
        }
        
        //Insertion
        void addWord(char* word){
            node *temp=root;
            for(int i=0;word[i]!='\0';i++)
            {
                if(temp->h.count(word[i])==0){
                    node *child=new node(word[i]);
                    temp->h[word[i]]=child;
                    temp=child;
                }
                else
                    temp=temp->h[word[i]];
            }
            temp->isTerminal=true;
        }

        //lookUp
        bool search(char* word){
            node *temp=root;
            for(int i=0;word[i]!='\0';i++)
            {
                if(temp->h.count(word[i]))
                    temp=temp->h[word[i]];
                else
                    return false;
            }
            return temp->isTerminal;
        }
};
                
        

int main()
{
    char word[10][100]={"apple","ape","coder","coding blocks","no"};

    Trie t;
    for(int i=0;i<10;i++)
        t.addWord(word[i]);

    char searchword[100];
    cin.getline(searchword,100);

    if(t.search(searchword))
        cout<<searchword<<" found"<<endl;
    else
        cout<<"not found"<<endl;

    return 0;
}


