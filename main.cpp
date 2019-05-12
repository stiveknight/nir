#include <iostream>
#include <fstream>
#include "Graph.h"
#include "data.h"
#include "utils.h"
#include "mthread.h"
#include "context.h"
#include <thread>
#include <mutex>
#include <algorithm>
#include <time.h>

using namespace std;


void thread_mod(data_t * data) {
    std::cout << "Thread mod start" << std::endl;
    int nthreads = std::thread::hardware_concurrency();
    if(nthreads == 0)
        nthreads = 2;
    // nthreads = 4;
    std::cout << "Count of threads: " << nthreads << std::endl;
    std::vector<std::thread> threads;
    for(int i = 0; i < nthreads; i++) {
        std::thread thr(consumer, data, i);
        threads.emplace_back(std::move(thr));
    }
    producer(data);
    data->queue.stop_push = 1;

    for(auto& thr : threads) {
        thr.join();
    }

    std::cout << "Done!" << std::endl;
}


void single_mod(data_t * data) {
    ifstream infile(data->infilename);
    if (!infile) {
        cout << "NO" << endl;
        exit(EXIT_FAILURE);
    }
    std::string s;
    for (infile >> s; !infile.eof(); infile >> s) {
        Graph g(s);
        set<int> cycles = g.girth();
        int elem_gir, elem_circle, elem_even_gir, elem_odd_gir;
        if (cycles.empty()) {
            elem_gir = -1;
            elem_circle = -1;
            elem_even_gir = -1;
            elem_odd_gir = -1;
        } else {
            elem_gir = *(cycles.begin());
            elem_circle = *(max_element(cycles.begin(), cycles.end()));

            int elem = -1;
            for (int item: cycles) {
                if (item % 2 == 0) {
                    elem = item;
                    break;
                }
            }
            elem_even_gir = elem;

            elem = -1;
            for (int item: cycles) {
                if (item % 2 == 1) {
                    elem = item;
                    break;
                }
            }
            elem_odd_gir = elem;
        }
        set_statistic(data, elem_gir, elem_circle, elem_even_gir, elem_odd_gir);
    }
}



void run(data_t * data) {
    switch (data->multithread_mode) {
        case TM_SINGLE:
            single_mod(data);
            break;
        case TM_MULTI:
            thread_mod(data);
            break;
    }

    ofstream fout(data->outdir + "output.txt");

    for (int item:data->gir)
        fout << item << " ";
    fout << endl;
    for (int item: data->circle)
        fout << item << " ";
    fout << endl;
    for (int item: data->even_gir)
        fout << item << " ";
    fout << endl;
    for (int item: data->odd_gir)
        fout << item << " ";
    fout << endl;

    save_map(data->map_gir, data->outdir + "gir" + to_string(data->vertex_count) + ".txt");
    save_map(data->map_circle, data->outdir + "circle" + to_string(data->vertex_count) + ".txt");
    save_map(data->map_even_gir, data->outdir + "even_gir" + to_string(data->vertex_count) + ".txt");
    save_map(data->map_odd_gir, data->outdir + "odd_gir" + to_string(data->vertex_count) + ".txt");
}


int main(int argc, char *argv[]) {
    clock_t start_time = clock();
    data_t data;

    data_init(&data, argc, argv);
    run(&data);

    std::cout << "\ntime: " << ((float)(clock() - start_time)) / CLOCKS_PER_SEC << std::endl;
    return 0;
}