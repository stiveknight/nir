//
// Created by OKB on 13.05.2019.
//

#ifndef NIR_CONTEXT_H
#define NIR_CONTEXT_H

#include <algorithm>
#include "data.h"
#include "Graph.h"

void set_statistic(data_t * data, set<int> &cycles) {
    if (cycles.empty()) {
        data->gir.push_back(-1);
        data->circle.push_back(-1);
        data->even_gir.push_back(-1);
        data->odd_gir.push_back(-1);
    } else {
        data->gir.push_back(*(cycles.begin()));
        data->circle.push_back(*(max_element(cycles.begin(), cycles.end())));

        int elem = -1;
        for (int item: cycles) {
            if (item % 2 == 0) {
                elem = item;
                break;
            }
        }
        data->even_gir.push_back(elem);

        elem = -1;
        for (int item: cycles) {
            if (item % 2 == 1) {
                elem = item;
                break;
            }
        }
        data->odd_gir.push_back(elem);
    }

    for (int i = 0; i<data->gir.size(); i++)
        data->map_gir[data->gir[i]]++;

    for (int i = 0; i<data->circle.size(); i++)
        data->map_circle[data->circle[i]]++;

    for (int i = 0; i<data->even_gir.size(); i++)
        data->map_even_gir[data->even_gir[i]]++;

    for (int i = 0; i<data->odd_gir.size(); i++)
        data->map_odd_gir[data->odd_gir[i]]++;
}

#endif //NIR_CONTEXT_H
