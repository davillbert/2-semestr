#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

// bool comp(const map<string, int> &a,const map<string, int> &b) return a.second < b.second;

int main()
{
    int N;
    cin >> N;
    map<string, int> a; // хочу чтоб по значению строки я могла получить доступ к длине 
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        a[tmp] = tmp.length();
    }
    for (auto num : a) {
        cout << num.first << " " << num.second << endl;
    }

    set<int> dl;
    for (auto num : a) {
        dl.insert(num.second);   //хочу знать все длины
    }
}
    int j = 0; //для начала хочу посчитать число строк удовлетворяющих услови.

    for (int i = 0; i < N; i++) {
        for (auto num : a) {
            if (i > 1) {
                int k = 1;
                if (num.second == i) {// беру любую длину большую единчки 
                    if (dl.find(i - k) != nullptr) {//если она раскоадывается на сумму двух других длин из всех возможных
                        string s1, s2, s3, s4;
                        s1 = num.second.substr(0, i); //то делю строку на две подстроки нужной длины 
                        s2 = num.second.substr(i);
                        s3 = num.second.substr(0, k);//двумя способами 2 + 3 = 3 + 2 но тут важен порядок
                        s4 = num.second.substr(k);
                        if (((a.find(s1) != nullptr) && (a.find(s2) != nullptr)) || ((a.find(s3) != nullptr) && (a.find(s4) != nullptr)))
                            j++; //проверяю находится ли такая пара подстрок во множестве ключей, если да то эта строчка удовлетворяет условия
                    }
                    else {
                        k = k + 1;  //если на предыдущем шаге с данными k разложения нет, то увеличиваю k
                        if (k == i / 2 + 1) { //такой  k  не имееет смысоа пора переходить к слудующей строке скроке
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << j << endl;
}
