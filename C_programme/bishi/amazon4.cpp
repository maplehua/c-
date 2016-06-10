#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int m, n;
    while (cin>>m>>n) {
        vector<int> vect1, vect2;
        int i = 0;
        int x;
        while (i < m) {
            cin>>x;
            i++;
            vect1.push_back(x);
        }
        i = 0;
        while (i < n) {
            cin>>x;
            i++;
            vect2.push_back(x);
        }

        int max = 0;
        do {
            int tmp = vect1[0];
            int index = 0;
            for (int j =0; j<n; j++) {
                index += vect2[j];
                tmp += vect1[index];
            }
            if (tmp > max) {
                max = tmp;
            }

        }while (next_permutation(vect2.begin(), vect2.end()));
        cout<<max<<endl;
    }
    return 0;
}
