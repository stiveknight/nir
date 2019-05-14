//
// Created by user on 12.05.2019.
//

#ifndef NIR_DATA_H
#define NIR_DATA_H

#include <vector>
#include <map>
#include "task_queue.h"

using namespace std;

typedef enum {
    TM_SINGLE,
    TM_MULTI,
} multithread_mode_t;

typedef struct data_t {
    string infilename;
    string outdir;
    string vertex_count;
    multithread_mode_t multithread_mode;
    vector<int> gir;
    vector<int> circle;
    vector<int> even_gir;
    vector<int> odd_gir;
    map<int, int> map_gir;
    map<int, int> map_circle;
    map<int, int> map_even_gir;
    map<int, int> map_odd_gir;

    queue_t queue;
    std::mutex count_elem_lock;
    std::mutex gen_lock;
} data_t;

int data_init(data_t * data, int argc, char *argv[]);

#endif //NIR_DATA_H
