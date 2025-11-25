#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <iostream>

class DynArray {
protected:
    int* data;
    int size;

public:
    DynArray(int n) {
        size = n;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    DynArray(const DynArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    virtual ~DynArray() {
        delete[] data;
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            std::cout << "Ошибка: индекс вне диапазона\n";
            return;
        }
        if (value < -100 || value > 100) {
            std::cout << "Ошибка: значение вне диапазона\n";
            return;
        }
        data[index] = value;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            std::cout << "Ошибка: индекс вне диапазона\n";
            return 0;
        }
        return data[index];
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }

    void push_back(int value) {
        if (value < -100 || value > 100) {
            std::cout << "Ошибка: значение вне диапазона\n";
            return;
        }

        int* newData = new int[size + 1];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        newData[size] = value;

        delete[] data;
        data = newData;
        size += 1;
    }

    DynArray add(const DynArray& other) const {
        DynArray result(size);
        for (int i = 0; i < size; i++) {
            int a = data[i];
            int b = (i < other.size ? other.data[i] : 0);
            result.data[i] = a + b;
        }
        return result;
    }

    DynArray sub(const DynArray& other) const {
        DynArray result(size);
        for (int i = 0; i < size; i++) {
            int a = data[i];
            int b = (i < other.size ? other.data[i] : 0);
            result.data[i] = a - b;
        }
        return result;
    }

    // Виртуальная функция для сохранения в файл
    virtual void saveToFile() {};
};

#endif
