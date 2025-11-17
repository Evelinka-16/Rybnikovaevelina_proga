#include <iostream>

class DynArray {
private:
    int* data;
    int size;

public:
    // Конструктор
    DynArray(int n) {
        size = n;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    // Конструктор копирования
    DynArray(const DynArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Деструктор
    ~DynArray() {
        delete[] data;
    }

    // Сеттер
    void set(int index, int value) {
        if (index < 0 || index >= size) {
            std::cout << "Ошибка: индекс вне диапазона\n";
            return;
        }
        if (value < -100 || value > 100) {
            std::cout << "Ошибка: значение вне диапазона [-100, 100]\n";
            return;
        }
        data[index] = value;
    }

    // Геттер
    int get(int index) const {
        if (index < 0 || index >= size) {
            std::cout << "Ошибка: индекс вне диапазона\n";
            return 0;
        }
        return data[index];
    }

    // Вывод массива
    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }

    // Добавление элемента
    void push_back(int value) {
        if (value < -100 || value > 100) {
            std::cout << "Ошибка: значение вне диапазона [-100, 100]\n";
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

    // Сложение массивов
    DynArray add(const DynArray& other) const {
        DynArray result(size);

        for (int i = 0; i < size; i++) {
            int valA = data[i];
            int valB;

            if (i < other.size) {
                valB = other.data[i];
            } else {
                valB = 0;
            }

            result.data[i] = valA + valB;
        }

        return result;
    }

    // Вычитание массивов
    DynArray sub(const DynArray& other) const {
        DynArray result(size);

        for (int i = 0; i < size; i++) {
            int valA = data[i];
            int valB;

            if (i < other.size) {
                valB = other.data[i];
            } else {
                valB = 0;
            }

            result.data[i] = valA - valB;
        }

        return result;
    }
};


int main() {
    DynArray a(3);
    a.set(0, 10);
    a.set(1, 20);
    a.set(2, 30);

    DynArray b(2);
    b.set(0, 5);
    b.set(1, 15);

    DynArray c = a.add(b);
    DynArray d = a.sub(b);

    std::cout << "A: "; a.print();
    std::cout << "B: "; b.print();
    std::cout << "A + B: "; c.print();
    std::cout << "A - B: "; d.print();

    return 0;
}
