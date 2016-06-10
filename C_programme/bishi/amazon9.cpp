#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>

using namespace std;

int getInput(int ori[][5], int res[][5], char oper[]);
void caculateTheRightSequence(int ori[][5], int res[][5], char inOper[], char outOper[] );
void findZero(int matrix[][5], int pos[]);//Multidimensional array parameters, must specify size except the first
bool isSame(int ori[][5], int res[][5]);
bool operate(int matrix[][5], char oper);

int main()
{
    int ori[5][5], res[5][5];
    char inOper[100] = {0};
    char outOper[100] = {0};
    while (getInput(ori, res, inOper)) {
        caculateTheRightSequence(ori, res, inOper, outOper);
    }

    return 0;
}

int getInput(int ori[][5], int res[][5], char oper[]) {
    for(int i =0; i<5; i++)
        for (int j=0; j<5; j++) {
            scanf("%d", &ori[i][j]);//be careful about the type of the parameter
        }
    for(int i =0; i<5; i++)
        for (int j=0; j<5; j++) {
            scanf("%d", &res[i][j]);
        }
    scanf("%s", oper);

    return 1;
}

void findZero(int matrix[][5], int pos[]) {
    for (int i =0; i<5; i++)
        for (int j=0; j<5; j++) {
            if (matrix[i][j] == 0) {
                pos[0] = i;
                pos[1] = j;
            }
        }
}

bool isSame(int ori[][5], int res[][5]) {
    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++) {
            if (ori[i][j] != res[i][j])
                return false;
        }
    return true;
}

bool operate(int matrix[][5], char oper) {
    int pos[2];
    findZero(matrix, pos);
    int x = pos[0];
    int y = pos[1];
    switch(oper) {
        case 'U':
            {
            if (x == 0) return false;
            int tmp = matrix[x][y];
            matrix[x][y] = matrix[x-1][y];
            matrix[x-1][y] = tmp;
            break;
            }
        case 'D':
            {
            if (x == 4) return false;
            int tmp = matrix[x][y];
            matrix[x][y] = matrix[x+1][y];
            matrix[x+1][y] = tmp;
            break;
            }
        case 'L':
            {
            if (y == 0) return false;
            int tmp = matrix[x][y];
            matrix[x][y] = matrix[x][y-1];
            matrix[x][y-1] = tmp;
            break;
            }
        case 'R':
            {
            if (y == 4) return false;
            int tmp = matrix[x][y];
            matrix[x][y] = matrix[x][y+1];
            matrix[x][y+1] = tmp;
            break;
            }
        default :
            break;
    }
    return true;
}

void caculateTheRightSequence(int ori[][5], int res[][5], char inOper[], char outOper[] ) {
    std::sort(inOper,inOper+strlen(inOper));//very import  the reason of next_permutation
    do {
        //printf("%s\n", inOper);
        //printf("%d\n", sizeof(inOper)); // sizeof() is not correct
        //printf("%d\n", strlen(inOper));return;
        char *tmp = inOper;
        bool flag = false;
        int ori_bak[5][5];//can't valuation directly
        for(int i =0; i<5; i++)
            for (int j=0; j<5; j++)
            {
                ori_bak[i][j] = ori[i][j];
            }
        int i = 0;
        while (i != strlen(inOper)) {//be careful about this way
            if(!operate(ori_bak, *tmp)) {
                flag = true;
                break;
            }
            tmp++;
            i++;
        }
        if (flag) continue;
        if (isSame(ori_bak , res)) {
            outOper = inOper;
            printf("%s\n", outOper);
            return;
        }
    }while (next_permutation(inOper, inOper+strlen(inOper)));

    cout<<"None"<<endl;
    return;
}
