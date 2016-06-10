#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
#include<string.h>

using namespace std;

void setMap(map<string, int> &habMap, map<int ,string> &tozMap) {
    //pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu
    habMap["pop"] = 1;
    habMap["no"] = 2;
    habMap["zip"] = 3;
    habMap["zotz"] = 4;
    habMap["tzec"] = 5;
    habMap["xul"] = 6;
    habMap["yoxkin"] = 7;
    habMap["mol"] = 8;
    habMap["chen"] = 9;
    habMap["yax"] = 10;
    habMap["zac"] = 11;
    habMap["ceh"] = 12;
    habMap["mac"] = 13;
    habMap["kankin"] = 14;
    habMap["muan"] = 15;
    habMap["pax"] = 16;
    habMap["koyab"] = 17;
    habMap["cumhu"] = 18;
    habMap["uayet"] = 19;
    // imix, ik, akbal, kan, chicchan, cimi, manik, lamat, muluk, ok, chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau
    tozMap[1] = "imix";
    tozMap[2] = "ik";
    tozMap[3] = "akbal";
    tozMap[4] = "kan";
    tozMap[5] = "chicchan";
    tozMap[6] = "cimi";
    tozMap[7] = "manik";
    tozMap[8] = "lamat";
    tozMap[9] = "muluk";
    tozMap[10] = "ok";
    tozMap[11] = "chuen";
    tozMap[12] = "eb";
    tozMap[13] = "ben";
    tozMap[14] = "ix";
    tozMap[15] = "mem";
    tozMap[16] = "cib";
    tozMap[17] = "caban";
    tozMap[18] = "eznab";
    tozMap[19] = "canac";
    tozMap[20] = "ahau";
}

string intToString(int a) {
    stringstream ss;
    ss<<a;
    string str;
    ss>>str;
    return str;
}

void parse(string data, map<string, int> habMap, int &year, int &month, int &day) {
    //10. zac 0
    stringstream ss;
    ss<<data;
    string s1, s2;
    ss>>s1>>s2>>year;
    month = habMap[s2];
    s1.erase(s1.begin()+s1.length()-1);
    day = atoi(s1.c_str());
}

void getNumofDays(string data, map<string, int>habMap,  int &numOfDays) {
    int year, month, day;
    parse(data, habMap, year, month, day);
    int num = 0;
    if (year >= 1)
        num+=(year)*365;
    if (month >= 1)
        num+=(month-1)*20;
    num+=(day+1);
    numOfDays = num;
}

void getDayDesc(int numOfDays, map<int, string> tozMap, string &desc) {
    int year;
    if (numOfDays%260 == 0 ) {//be careful
        desc.append("13 ahau ");
        desc.append(intToString(numOfDays/260-1));
        return ;
    }
    year = numOfDays/260;
    int leftDays = numOfDays%260;
    string month = tozMap[leftDays%20];
    int day = leftDays%13;
    desc.append(intToString(day));
    desc.append(" "+month+" ");
    desc.append(intToString(year));
}

void convertDataFromHabtoToz(string input,map<string, int> habMap, map<int, string> tozMap, vector<string> &res) {
    int numOfDays = 0;
    getNumofDays(input, habMap, numOfDays);
    string desc;
    getDayDesc(numOfDays, tozMap, desc);
    res.push_back(desc);
}

int main()
{
    int n;
    vector<string> res;
    map<string, int> habMap;
    map<int, string> tozMap;
    setMap(habMap, tozMap);
    string input;
    while (cin >> n) {
        getline(cin, input);
        for (int i = 0; i<n; i++) {
            getline(cin, input);
            convertDataFromHabtoToz(input, habMap, tozMap, res);
        }
        cout<<n<<endl;
        vector<string>::iterator iter = res.begin();
        while (iter != res.end()) {
            cout<<*iter<<endl;
            iter++;
        }
        res.clear();
    }

    return 0;
}
