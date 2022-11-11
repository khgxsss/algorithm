#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

bool comp(string &p1,string &p2){

    if (p1.length() != p2.length()){
        return p1.length() < p2.length();
    }
    
    for (int i = 0; i < p1.length(); i++)
    {
        if (int(p1[i]) == int(p2[i]))
        {
            continue;
        }
        return int(p1[i]) < int(p2[i]);
    }
}

int main(int argc, char const *argv[])
{
    int words_num;
    cin >> words_num;
    vector<string> words;
    int flag = 0;
    for (int i = 0; i < words_num; i++)
    {
        string word;
        
        cin >> word;
        auto it = find(words.begin(), words.end(), word);
        if (it == words.end()){
            words.push_back(word);
        }else{
            flag++;
        }
    }
    words_num -= flag;
    
    sort(words.begin(), words.end(), comp);

    for (int i = 0; i < words.size(); i++)
    {
        cout << words.at(i) << "\n";
    }
    
    
    return 0;
}
