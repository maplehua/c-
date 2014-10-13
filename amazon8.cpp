#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;

int splitAndConvert(int array[], char line[]) {
    char *strtoken = strtok(line, " ");
    int i = 0;
    while (strtoken != NULL) {
        array[i] = atoi(strtoken);
        i++;
        strtoken = strtok(NULL, " ");
    }
    return i;
}

void createEquationAndPrint(int array[], int length, int final) {
    if (length == 1 ) {
        if (array[0] == final) 
            cout<<array[0]<<"="<<final<<endl;
        else
            cout<<"Invalid"<<endl;
        return;
    }

    char *operators = new char[length-1];
    for(int time = 0; time <= length-1; time++) {

         for(int y=0; y<=length-1-time;y++)
             operators[y] = '+';
         int x = length-1-time;
         int j = 0;
         while (j < time) {
            operators[x+j] = '-';
            j++;
         }
         do {
            int i = 1;
            int count = array[0];
            while (i <= length -1) {
                if (operators[i-1] == '+') {
                    count = count +array[i];
                } else {
                    count = count - array[i];
                }
                i++;
            }
            if (count == final) {
                int i = 0;
                while (i < length-1) { 
                    cout<<array[i]<<operators[i];
                    i++;
                }
                cout<<array[length-1]<<"="<<final<<endl;
                return;
            }
    
        } while (next_permutation(operators, operators+length-1));

    }
    cout<<"Invalid"<<endl;
}

//another way to realise it  : recursion
void createEquationAndPrint_2(int array[], int length, int final) {
    static int sum ;// can not give sum a value here : for recursion
    static string res;
    static int originLength;
    static int recTimes = 0;
    static bool found = false;
    static int index;

    if (recTimes == 0) {
        sum = array[0];
        res+=(array[0]+'0');
        index = 1;
        originLength = length;
    } 

    recTimes++;

    if (length == 2) {
        if (sum + array[originLength-1] == final) {
           res.append("+");
           res+=(array[originLength-1]+'0');
           res.append("=");
           res+=(array[originLength]+'0');
           found = true;
           cout<<res<<endl;
           return;
        } else if (sum - array[originLength-1] == final) {
           res.append("-");
           res+=(array[originLength-1]+'0');
           res.append("=");
           res+=(array[originLength]+'0');//this way
           found = true;
           cout<<res<<endl;
           return;
        } else {
            return;
        }
    } else {
        string tmp_str = res;
        int tmp_sum = sum;
        sum = sum + array[index];
        res.append("+");
        res+=(array[index]+'0');
        index++;
        if (!found) createEquationAndPrint_2(array, length-1, final);
        sum = tmp_sum;
        res = tmp_str;
        index--;
        sum = sum - array[index];
        res.append("-");
        res+=(array[index]+'0');
        index++;
        if (!found) createEquationAndPrint_2(array, length-1, final);
    }
    cout<<"---123--"<<endl;
    return;
}

int main() {

    char line[1000] = {0};
    while (gets(line)) {
        int array[30] = {0};
        int length = splitAndConvert(array, line);
        if (length == 0) {
            break;
        }
        string s(line);
        cout<<s<<endl;
        createEquationAndPrint_2(array, length-1, array[length-1]);//way 1 is ok ; way 2 has some problem that not fixed
    }
    return 0;
}
