
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
//Зишифруйте сообщение меняя буквы на их порядковый номер в алфавите. Пробелы при этом не учитывать. Строки будут даны без знаков препинания, только с пробелами. Регистр не учитывать.
//
//Входные данные: шифруемая строка, длиной до 1000 символов, на латинице
//
//Пример входных данных:
//
//MR Robot
//
//Выходные данные: через запятую порядковый номер букв в алфавите
//
//Пример выходных данных:
int main() {
    for (string line; getline(cin, line);) { // get the line
        //here your code
        const  vector<string> ALPHABET_VEC ={ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
        string res;
        toLower(line);
        for (int i = 0; i < line.length();i++)
        {
            string s(1,line[i]);
            if (contains(ALPHABET_VEC,s)) {

                res += to_string(findIndex(ALPHABET_VEC, s)+1);
                if (!(i == line.length() - 1)) {
                    res += ",";
                }
            }
        }
        //res[res.length()-1] =;
        std::cout << res << std::endl; // print the answer as stdout
    }
    return 0;
}