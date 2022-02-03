#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int findIndex(const vector<string>& vec, const string& elem) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i) == elem) { return i; }
    }
    return -1;
}
void  toLower(string& s) {
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) { return tolower(c); }
    );
}
template<class c,class k>
bool contains(c str, const k& key) {
    for (auto ch : str) {
        //string s(1,ch);
        if (ch == key) {
            return true;
        }
    }
    return false;
}

//RLE - самый простой алгоритм сжатия. Его суть состоит в замене повторяющихся данных образцом, и количеством повтора образца. Алгоритм подходит для сжатия данных, имеющих большое количество повторений.  При сжатии учитывайте регистр.
//
//Напишите программу, которая реализует RLE для строк, состоящих из букв латинского алфавита, не имеющих пробелы.
//
//Во входных данных только одна строка.
//
//Например: DDDDFFFFHHHHk → 4D,4F,4H,1k
int main() {
    for (string line; getline(cin, line);) { // get the line
        string bufLine = line;
        int freq =0;
        string res;

            char nowCheck = bufLine[0];
            string s(1,nowCheck);

            for (int i = 0; i < bufLine.length(); i++) {
                if (bufLine[i] == nowCheck) {
                    freq +=1;
                }
                else{
                    res+=to_string(freq) + nowCheck;
                    res+=",";
                    nowCheck = bufLine[i];
                    freq =1;
                }
                if (i==bufLine.length()-1){
                    res+=to_string(freq) + nowCheck;
                }
            }
            //bufLine.erase(remove( bufLine.begin(),  bufLine.end(), nowCheck),  bufLine.end());


        std::cout << res << std::endl; // print the answer as stdout
    }
    return 0;
}