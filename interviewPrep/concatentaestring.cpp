/* algo used:
1) sort the alphabetical order stored word according to length 
2) create a set of word and loop through each word for following
3) For each word check wether it is concatanened string or not
4) if its concatenated store in concatenated list otherwise in normal word list
5) the concatenated list last element would be the firs t longest concatenated list and size of 
list would the total no of concatenated string
*/


#include<iostream>
#include<fstream>
#include<set>
#include<string>
#include<vector>
#include<ctime>

using namespace std;
// to store word without concatenation
set<string> norm_word;
// to store the value of concatenated words
vector<string> concat_list;
// for sorting the set according to length of string
struct compareElement{
    bool operator () (string a,string  b){
        if(a.size() == b.size()){
            return (a < b) ; 
        }
        return (a.size() < b.size());
    }
};
    
bool checkConcatenation(string word, int level, int cur_index, string substr) {
    // if word is consumed and its substring is part of normal words then return true
    if(cur_index == word.length()) {
        // if level of concatenatio is greater than 0 and its subtring present in set return true else false
        if(level > 0 && norm_word.find(substr) != norm_word.end()){ 
            return true;
        }
            //cout<<"coming #############################################here"<<endl;
            return false;
    }
    substr = substr + (word[cur_index]);
    // if current word is find in nonconcatened set then increase the level of concatenation
    // also pass new empty string for next substr
    if(norm_word.find(substr) != norm_word.end()) {
        if(checkConcatenation(word, level+1, cur_index+1, "")){
            return true;
        }
    }
    // if the subtring is not present in set of non concatened words, increase pointer to next index
    if(checkConcatenation(word, level, cur_index+1, substr)){ 
        return true;
    }
    else{ 
        return false;
    }
}


int main (){
    clock_t start, end;
    start = clock();
    int leng;
    set<string, compareElement> word_set;
    // read the file for words
    // i have used relative path currently so please provide absolute path in your case
    ifstream list_ofword("wordsforproblem.txt");
    if (list_ofword.is_open()){
        string word;
        //set<string, compareElement>::iterator it = word_set.begin();
        while ( getline (list_ofword,word) ){
            //cout<<word;
            if(word.length()>0)
                // removing the newline character from word and storing in the total word set
                word_set.insert(word.substr(0,word.length()-1));
        }
        list_ofword.close();
    }else{
        cout<<"not able to pen the file"<<endl;
        return -1;
    }
    // loop through 
    set<string, compareElement>::iterator iter = word_set.begin();
    for(int i=0; i<word_set.size();i++){
        string word = *iter;
        //cout<<" word checking is : "<<*iter<<"size : "<< (*iter).length()<<endl;
        //if(i==4)
        //    return 0;
        if(checkConcatenation(word, 0, 0, "")){
        // add a word if it is concatened
            concat_list.push_back(word); 
        }else{ 
        // add a word if its not concatenaned word
            norm_word.insert(word); 
        }
        advance(iter,1);
    }
    leng = concat_list.size();
    if(leng > 1){
        cout<<"first longest concatenated string : "<<concat_list[leng-1]<<endl;
        cout<<"second longest concatenated string : "<<concat_list[leng-2]<<endl;
        cout<<"total number of concatenated words : "<<leng<<endl;
    }else if(leng > 0){
        cout<<"first longest concatenated string : "<<concat_list[leng-1]<<endl;
    }else{
        cout<<"no concatenated characters found";
    }
    end = clock();
   // cout<<"running time for the process : "<<((float)(end - start)/(1000*CLOCKS_PER_SEC))<<" ms "<<endl;
    return 0;
}