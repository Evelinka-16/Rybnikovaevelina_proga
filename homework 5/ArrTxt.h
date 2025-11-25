#ifndef ARRTXT_H
#define ARRTXT_H

#include "DynArray.h"
#include <fstream>
#include <ctime>

class ArrTxt : public DynArray {
public:
    ArrTxt(int n) : DynArray(n) {}

    void saveToFile() override {
        time_t now = time(nullptr);
        tm* t = localtime(&now);

        char filename[64];
        strftime(filename, sizeof(filename), "%Y-%m-%d_%H-%M-%S.txt", t);

        std::ofstream file(filename);
        for (int i = 0; i < size; i++) {
            file << data[i] << " ";
        }
        file.close();
    }
};

#endif
