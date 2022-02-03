#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
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

int main() {
    vector<string> pureAlpha = { "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш","щ","ъ","ы","ь","э","ю","я"};
    vector<string> pureAlphaUpper = { "A", "Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш","Щ","Ъ","Ы","Ь","Э","Ю","Я"};
   // setlocale(LC_ALL, "Russian");
    regex reg("[А-Я][А-я]+ [А-Я][А-я]+");
    string res;
    //system("chcp 1251");
    for (string line; getline(cin, line);) { // get the line

            std::sregex_iterator next(line.begin(), line.end(), reg);
            std::sregex_iterator end;
            while (next != end) {
                std::smatch match = *next;
                res+=match.str();

                next++;
                if (next != end) {
                    res += ",";
                }
            }

        }


            std::cout << res << std::endl;


    return 0;
}