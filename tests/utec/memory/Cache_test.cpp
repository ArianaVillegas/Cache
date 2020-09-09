#include <fstream>
#include <sstream>
#include <ctime>

#include "../general/Print.cpp"
#include "Cache_test.h"

template <class K, class V>
double Tester<K,V>::execute(bool p, int maxSize, K (*cachePolicy)(Cache<K,V>*), void (*update)(Cache<K,V>*, K, V)) {
    Cache<char,int> L(maxSize, cachePolicy, update);

    ifstream infile;
    infile.open("instructions.txt");

    string line;
    int a,b,c;

    clock_t etime;
    etime = clock();
    while (getline(infile, line))
    {
        istringstream iss(line);
        iss >> a;
        if (a) {
            iss >> b;
            if(a==1){
                if(p) print(L.getValueFromKey(b));
                else L.getValueFromKey(b);
            } else {
                iss >> c;
                L.insertKeyValuePair(b,c);
            }
        } else {
            if(p) print(L.getMostRecentKey());
            else L.getMostRecentKey();
        }
    }
    etime = clock() - etime;

    return (float)etime/CLOCKS_PER_SEC;
}