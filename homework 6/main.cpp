#include <iostream>
#include <stdexcept> 

class DynArray {
private:
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

    
    ~DynArray() {
        delete[] data;
    }

    // Сеттер
    void set(int index, int value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Ошибка: индекс вне диапазона");
        }
        if (value < -100 || value > 100) {
            throw std::invalid_argument("Ошибка: значение вне диапазона [-100, 100]");
        }
        data[index] = value;
    }

    // Геттер
    int get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Ошибка: индекс вне диапазона");
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
            throw std::invalid_argument("Ошибка: значение вне диапазона [-100, 100]");
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
            int valB = (i < other.size) ? other.data[i] : 0;
            result.data[i] = valA + valB;
        }

        return result;
    }

    // Вычитание массивов
    DynArray sub(const DynArray& other) const {
        DynArray result(size);

        for (int i = 0; i < size; i++) {
            int valA = data[i];
            int valB = (i < other.size) ? other.data[i] : 0;
            result.data[i] = valA - valB;
        }

        return result;
    }
};


int main() {
    try {
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

    

    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << "\n";
    }

    return 0;
}
