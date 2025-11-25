#ifndef ARRCSV_H
#define ARRCSV_H

#include "DynArray.h"
#include <fstream>
#include <ctime>


class ArrCSV : public DynArray {
public:
    ArrCSV(int n) : DynArray(n) {}

    void saveToFile() override {
        time_t now = time(nullptr);
        tm* t = localtime(&now);

        char filename[64];
        strftime(filename, sizeof(filename), "%Y-%m-%d_%H-%M-%S.csv", t);

        std::ofstream file(filename);
        for (int i = 0; i < size; i++) {
            file << data[i];
            if (i < size - 1) {
                file << ",";
            }
        }
        file.close();
    }
};

#endif
