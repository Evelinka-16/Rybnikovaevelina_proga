#include <iostream>
#include <algorithm> 

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

   

   
    double average() const {
        if (size == 0) return 0;

        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += data[i];
        }
        return sum / size;
    }

    
    int min() const {
        if (size == 0) return 0;

        int m = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] < m) m = data[i];
        }
        return m;
    }

    int max() const {
        if (size == 0) return 0;

        int m = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] > m) m = data[i];
        }
        return m;
    }

 
    double median() const {
        if (size == 0) return 0;

        int* temp = new int[size];
        for (int i = 0; i < size; i++) temp[i] = data[i];

        std::sort(temp, temp + size);

        double med;
        if (size % 2 == 1) {
            med = temp[size / 2];
        } else {
            med = (temp[size / 2 - 1] + temp[size / 2]) / 2.0;
        }

        delete[] temp;
        return med;
    }
};


int main() {
    DynArray a(3);
    a.set(0, 10);
    a.set(1, 20);
    a.set(2, 30);

    std::cout << "Массив: ";
    a.print();
    std::cout << "Среднее: " << a.average() << "\n";
    std::cout << "Медиана: " << a.median() << "\n";
    std::cout << "Мин: " << a.min() << "\n";
    std::cout << "Макс: " << a.max() << "\n";

    return 0;
}
