
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
//На рисунке изображен клин треугольником, ряды противника прямоугольником.
//
//Чтобы образовать клин надо, знать число человек в ряду противника, в задней части клина количество участников равно количеству человек в ряду у противника. В каждом ряду клина на два участника меньше, чем в предыдущем ряду. На острой части клина может быть либо 2 либо 1 участник.
//
//Так если в ряду у противника 9 человек то ряды клина состоят из такого количества человек:
int main() {
    for (string line; getline(cin, line);) { // get the line
        //here your code
        int res = 0;
        int enemy = atoi(line.c_str());
        while (enemy>2)
        {
            res+=enemy;
            enemy-=2;
        }
        res+=enemy;
        //res[res.length()-1] =;
        std::cout << res << std::endl; // print the answer as stdout
    }
    return 0;
}