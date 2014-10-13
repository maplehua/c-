#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<sstream>

using namespace std;

void split(vector<int> &ori, vector<int> &res, string origin, string result) {
    stringstream ss;
    ss<<origin;
    int tmp;
    while (ss>>tmp) {
        ori.push_back(tmp);
    }
    ss.clear();//important
    ss<<result;
    while (ss>>tmp) {
        res.push_back(tmp);
    }

}

void getOperations(string origin, string result, string &operations) {
    vector<int> ori, res;
    split(ori, res, origin, result);
    stack<int> s;
    vector<int>::iterator iterOri = ori.begin();
    vector<int>::iterator iterRes = res.begin();
    while (iterRes != res.end() ) {
        if (s.empty()) {
            s.push(*iterOri);
            if (operations != "") operations += "|";
            operations = operations + "push";
            operations+=(int(iterOri - ori.begin())+'1');//don't know why s =s + .... not work
            iterOri++;
            continue;
        }
        while (s.top() != *iterRes) {// if stack is empty,then s.top() will turn fault
            if (iterOri != ori.end()) {
                s.push(*iterOri);
                if (operations != "") operations += "|";
                operations = operations + "push";
                operations+=(int(iterOri - ori.begin())+'1');//don't know why s =s + .... not work
                iterOri++;
            } else {
                operations = "None";
                return;
            }
        }
        s.pop();
        operations = operations + "|pop";
        operations+=(int(iterOri - ori.begin())+'0');
        iterRes++;
        if (iterOri == ori.end() && !s.empty())
            break;
    }
    while (iterRes != res.end()) {
        if (!s.empty()) {
            if (s.top() == *iterRes) {
                iterRes++;
                iterOri--;
                s.pop();//return type : none
                operations = operations + "|pop";
                operations+=(int(iterOri - ori.begin())+'0');
            } else {
                operations = "None";
                return;
            }
        } else {
            operations = "None";
            return;
        }
    }
}

int main()
{
    string origin, result, operations;
    while (true) {
        getline(cin, origin);
        getline(cin, result);
        getOperations(origin, result, operations);
        cout<<operations<<endl;
        operations = "";
    }
    
    return 0;
}
