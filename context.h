//
// Created by OKB on 13.05.2019.
//

#ifndef NIR_CONTEXT_H
#define NIR_CONTEXT_H

#include <algorithm>
#include "data.h"
#include "Graph.h"

void set_statistic(data_t * data, int elem_gir, int elem_circles, int elem_even_gir, int elem_odd_gir) {
    data->gir.push_back(elem_gir);
    data->circle.push_back(elem_circles);
    data->even_gir.push_back(elem_even_gir);
    data->odd_gir.push_back(elem_odd_gir);

    for (int i = 0; i < data->gir.size(); i++)
        data->map_gir[data->gir[i]]++;

    for (int i = 0; i < data->circle.size(); i++)
        data->map_circle[data->circle[i]]++;

    for (int i = 0; i < data->even_gir.size(); i++)
        data->map_even_gir[data->even_gir[i]]++;

    for (int i = 0; i < data->odd_gir.size(); i++)
        data->map_odd_gir[data->odd_gir[i]]++;
}

#endif //NIR_CONTEXT_H
