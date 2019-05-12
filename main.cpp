#include <iostream>
#include <fstream>
#include "Graph.h"
#include "data.h"
#include <algorithm>

using namespace std;


int main() {
    data_t data;
//    setlocale(LC_ALL, "Russian");
    string n;
    cin >> n;
    string fname = "../graphs" + n + ".txt";
//    cout << "file name: ";
//    cin >> fname;
    ifstream infile(fname);
    if (!infile) cout << "NO"<< endl;

    std::string s;
    for (infile >> s; !infile.eof(); infile >> s) {
        Graph g(s);
        set<int> cycles = g.girth();
        if (cycles.empty()) {
            data.gir.push_back(-1);
            data.circle.push_back(-1);
            data.even_gir.push_back(-1);
            data.odd_gir.push_back(-1);
        } else {
            data.gir.push_back(*(cycles.begin()));
            data.circle.push_back(*(max_element(cycles.begin(), cycles.end())));

            int elem = -1;
            for (int item: cycles) {
                if (item % 2 == 0) {
                    elem = item;
                    break;
                }

            }
            data.even_gir.push_back(elem);

            elem = -1;
            for (int item: cycles) {
                if (item % 2 == 1) {
                    elem = item;
                    break;
                }
            }
            data.odd_gir.push_back(elem);
        }

        for (int i = 0; i<data.gir.size(); i++)
            data.map_gir[data.gir[i]]++;

        for (int i = 0; i<data.circle.size(); i++)
            data.map_circle[data.circle[i]]++;

        for (int i = 0; i<data.even_gir.size(); i++)
            data.map_even_gir[data.even_gir[i]]++;

        for (int i = 0; i<data.odd_gir.size(); i++)
            data.map_odd_gir[data.odd_gir[i]]++;

    }
    ofstream fout("output.txt");
//    cout << gir.size() << ' ' << circle.size() << ' ' << even_gir.size() << ' ' << odd_gir.size();
    for (int item: data.gir)
        fout << item << " ";
    fout << endl;
    for (int item: data.circle)
        fout << item << " ";
    fout << endl;
    for (int item: data.even_gir)
        fout << item << " ";
    fout << endl;
    for (int item: data.odd_gir)
        fout << item << " ";
    fout << endl;

    ofstream fout1("gir" + n + ".txt");
    for (auto item: data.map_gir)
        fout1 << item.first << " : " << item.second << endl;

    ofstream fout2("circle" + n + ".txt");
    for (auto item: data.map_circle)
        fout2 << item.first << " : " << item.second << endl;

    ofstream fout3("even_gir" + n + ".txt");
    for (auto item: data.map_even_gir)
        fout3 << item.first << " : " << item.second << endl;

    ofstream fout4("odd_gir" + n + ".txt");
    for (auto item: data.map_odd_gir)
        fout4 << item.first << " : " << item.second << endl;
}