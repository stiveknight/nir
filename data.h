//
// Created by user on 12.05.2019.
//

#ifndef NIR_DATA_H
#define NIR_DATA_H

#include <vector>
#include <map>

using namespace std;

typedef struct data_t {

    vector<int> gir;
    vector<int> circle;
    vector<int> even_gir;
    vector<int> odd_gir;
    map<int, int> map_gir;
    map<int, int> map_circle;
    map<int, int> map_even_gir;
    map<int, int> map_odd_gir;


} data_t;


#endif //NIR_DATA_H
