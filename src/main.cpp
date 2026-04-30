#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <filesystem>
#include <algorithm>   
#include <cctype>     

using namespace std ;
namespace fs=filesystem;

 // how many times the word appears in the file !!
 unordered_map<string, unordered_map<string, int >> indexMap;

 //converting to lowertcase
 string normalize(string word){
    for (char &c : word) c=tolower(c);
    return word;
 }

 // validate filepath
 void indexFile(const string &filepath){
    ifstream file(filepath);
    if (!file) return;
    string word;
    while (file >> word){
        word = normalize(word);
        indexMap[word][filepath]++;
    }
 }

 //now indexing a single file
 void indexDirectory(const string &dirpath){
    for (const auto &entry : fs::directory_iterator(dirpath)){
        if (entry.is_regular_file()) {
            indexFile(entry.path().string());
        }
    }
    cout << "Indexing complete.\n";
 }

 //for search function
 void search(const string &query){
    stringstream ss(query);
    string word;
    unordered_map<string, int> scores;
    while(ss >>word) {
        word = normalize(word);
        if(indexMap.find(word)!=indexMap.end()){
            for(auto &filePair : indexMap[word]) {
                scores[filePair.first] +=filePair.second;
            }
        }
    }

    //to print results....
    vector<pair<string, int>> results(scores.begin(), scores.end());

    sort(results.begin(), results.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });
    cout << "\nResults:\n";
    for (auto &r : results) {
        cout<<r.first<< " (score: "<< r.second <<")\n";
    }
}

//command line loop;
int main() {
    string command;
    while (true) {
        cout << "\n> ";
        getline(cin, command);
        if (command=="exit") break;
        if (command.rfind("index ", 0)==0) {
            string path = command.substr(6);
            indexDirectory(path);
        } 
        else if(command.rfind("search ", 0)==0) {
            string query=command.substr(7);
            search(query);
        } 
        else {
            cout << "Commands:\n";
            cout << "index <folder>\nsearch <words>\nexit\n";
        }
    }
    return 0;
}