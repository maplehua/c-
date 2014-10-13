#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

void split(map<string,vector<string> > &shopList, string list) {
    stringstream ss;
    ss<<list;
    string customer, product;
    while(ss>>customer>>product) {
        map<string, vector<string> >::iterator iter = shopList.find(customer);
        if (iter != shopList.end()) {
            vector<string> tmp = shopList[customer] ;
            tmp.push_back(product);
            //shopList.insert(map<string, vector<string> >::value_type(customer, tmp)); //this way not working
            shopList[customer] = tmp;//the parameter type of insert : {} or pair<>() or make_pair()
        } else {
            vector<string> tmp ;
            tmp.push_back(product);
            //shopList.insert(customer, tmp);
            shopList[customer]=tmp;
        }
    }
}

void getMax(map<string, int> a, string &res) {
    int max = 0;
    map<string, int>::iterator iter = a.begin();
    while (iter != a.end()) {
        if (iter->second > max) {
            max = iter->second;
            res = iter->first;
        }
        iter++;
    }

}

void recommend(map<string,vector<string> > item, string prod, string &res) {
    vector<string> customers;
    map<string, vector<string> >::iterator iter = item.begin();//if parameter is const , so should when we use
    while (iter != item.end()) {
        vector<string> v1 = iter->second;
        if (find(v1.begin(), v1.end(), prod) != v1.end()) {
            customers.push_back(iter->first);
        }
        iter++;
    }
    map<string, int> data;//product list
    for (vector<string>::iterator i = customers.begin(); i!= customers.end(); i++) {
        vector<string> tmp = item[*i];
        vector<string>::iterator jj = tmp.begin();
        while (jj != tmp.end()) {
            if (data.find(*jj) != data.end()) {
                int x = data[*jj];
                x++;
                data[*jj] = x;
            } else {
                data[*jj] = 1;
            }
            jj++;
        }
    }
    data.erase(prod);
    if (data.empty()) {
        res = "None";
        return;
    }
    getMax(data, res);

}


int main()
{
    map<string, vector<string> > shopList;
    string item;
    string list;
    string res;
    while (true) {
        getline(cin, item);
        getline(cin, list);
        split(shopList, list);
        
        for (map<string, vector<string> >::iterator iter = shopList.begin(); iter!=shopList.end(); iter++) {
            cout<<"customer = "<<iter->first<<"\t shoplist= ";
            for (vector<string>::iterator i =iter->second.begin(); i!=iter->second.end(); i++)
                cout<<*i<<"\t";
            cout<<endl;
        }

        recommend(shopList, item, res);
        cout<<res<<endl;
    }

    return 0;
}
