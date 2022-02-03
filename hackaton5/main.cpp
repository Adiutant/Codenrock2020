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
struct DatePeriod{
    int day;
    int hour;
    int min;
    int dayEnd;
    int hourEnd;
    int minEnd;

};
struct Robot{
    string name;
    vector<DatePeriod> dateDOS;
};
struct DatePoints{
    int day;
    int hour;
    int min;
};
int main() {
    vector<string> pureAlpha = { "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш","щ","ъ","ы","ь","э","ю","я"};
    vector<string> pureAlphaUpper = { "A", "Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш","Щ","Ъ","Ы","Ь","Э","Ю","Я"};
    vector<Robot> robots;
    vector<DatePoints> points;
    regex reg("[^R:]+[|$]");
    smatch match;

    for (string line; getline(cin, line);) { // get the line
        if (line[0] =='R') {
            std::sregex_iterator next(line.begin(), line.end(), reg);
            std::sregex_iterator end;
            while (next != end) {
                std::smatch match = *next;
                string name;
                for (int i = 0; i < match.str().size() - 1; i++) {
                    name += match.str()[i];
                }
                robots.push_back({name, {}});
                // std::cout << match.str() << "\n";
                next++;
            }
            regex regDigit("[\\d]+");

            std::sregex_iterator nextDig(line.begin(), line.end(), regDigit);
            std::sregex_iterator endDig;
            int time = 0;
            while (nextDig != endDig) {

                std::smatch matchDig = *nextDig;
                string name;

                if (time == 0) {
                    robots[robots.size() - 1].dateDOS.push_back({});
                    robots[robots.size() - 1].dateDOS[robots[robots.size() - 1].dateDOS.size() - 1].day = atoi(
                            matchDig.str().c_str());

                }
                if (time == 1) {
                    robots[robots.size() - 1].dateDOS[robots[robots.size() - 1].dateDOS.size() - 1].hour = atoi(
                            matchDig.str().c_str());

                }
                if (time == 2) {
                    robots[robots.size() - 1].dateDOS[robots[robots.size() - 1].dateDOS.size() - 1].min = atoi(
                            matchDig.str().c_str());

                }
                if (time == 3) {
                    robots[robots.size() - 1].dateDOS[robots[robots.size() - 1].dateDOS.size() - 1].dayEnd = atoi(
                            matchDig.str().c_str());
                }
                if (time == 4) {
                    robots[robots.size() - 1].dateDOS[robots[robots.size() - 1].dateDOS.size() - 1].hourEnd = atoi(
                            matchDig.str().c_str());
                }

                if (time == 5) {
                    robots[robots.size() - 1].dateDOS[robots[robots.size() - 1].dateDOS.size() - 1].minEnd = atoi(
                            matchDig.str().c_str());
                    time = 0;
                } else {
                    time++;
                }
                // cout<< time<<endl;
                // std::cout << matchDig.str() << "\n";
                nextDig++;
            }
            // std::cout << 1<< std::endl; // print the answer as stdout
        }
        if (line[0] == 'T')
        {
            regex regDigit("[\\d]+");

            std::sregex_iterator nextDig(line.begin(), line.end(), regDigit);
            std::sregex_iterator endDig;
            int time = 0;
            while (nextDig != endDig) {
                std::smatch matchDig = *nextDig;
                if (time == 0) {
                    points.push_back({});
                   points[points.size() - 1].day = atoi(
                            matchDig.str().c_str());

                }
                if (time == 1) {
                    points[points.size() - 1].hour = atoi(
                            matchDig.str().c_str());

                }
                if (time == 2) {
                    points[points.size() - 1].min = atoi(
                            matchDig.str().c_str());
                    time=0;
                }
                else{
                    time++;
                }

            nextDig++;
            }
            string res;
            int status=0;
            cout<< points[points.size() - 1].day <<" "<<points[points.size() - 1].hour<<":"<<points[points.size() - 1].min<<endl;
            for(auto item :robots)
            {
                status = 0;
                for (auto period: item.dateDOS)
                {
                    bool dayInter = period.day<=points[points.size() - 1].day&&period.dayEnd>=points[points.size() - 1].day;
                    bool hourInter = period.hour<=points[points.size() - 1].hour&&period.hourEnd>=points[points.size() - 1].hour;
                    bool minInter = period.min<=points[points.size() - 1].min&&period.minEnd>=points[points.size() - 1].min;
                   if (dayInter&&(minInter||hourInter))
                   {
                       status+=1;
                   }
                }
                if (status>0) {
                    cout << item.name<< " " <<"GAME OVER"<<endl;
                } else{
                    cout << item.name<< " " <<"GAME CONTINUES"<<endl;
                }
            }

            //std::cout << line << std::endl;
        }
    }
    return 0;
}