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

    data->map_gir[elem_gir]++;

    data->map_circle[elem_circles]++;

    data->map_even_gir[elem_even_gir]++;

    data->map_odd_gir[elem_odd_gir]++;
}

#endif //NIR_CONTEXT_H
