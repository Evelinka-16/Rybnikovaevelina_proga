#include <iostream>
#include <cmath>
#include <typeinfo>
#include <stdexcept>
#include <vector>

template<typename T>
class Array {
private:
    std::vector<T> data;

public:
    
    Array(size_t n) : data(n) {}

    
    Array(std::initializer_list<T> list) : data(list) {}

    
    size_t size() const { return data.size(); }

    // Универсальный сеттер
    void set(size_t index, const T& value) {
        if (index >= data.size()) {
            throw std::out_of_range("Индекс вне диапазона");
        }
        data[index] = value;
    }

    // Сеттер только для чисел с проверкой диапазона [-100, 100]
    void setNumeric(size_t index, const T& value) {
        if (!std::is_arithmetic<T>::value) {
            throw std::bad_typeid();
        }
        if (index >= data.size()) {
            throw std::out_of_range("Индекс вне диапазона");
        }
        if (value < -100 || value > 100) {
            throw std::invalid_argument("Значение вне диапазона [-100, 100]");
        }
        data[index] = value;
    }

    // Геттер
    T get(size_t index) const {
        if (index >= data.size()) {
            throw std::out_of_range("Индекс вне диапазона");
        }
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
        os << "[";
        for (size_t i = 0; i < arr.data.size(); ++i) {
            os << arr.data[i];
            if (i + 1 < arr.data.size()) os << ", ";
        }
        os << "]";
        return os;
    }

    // Евклидово расстояние между массивами для чисел
    double euclideanDistance(const Array<T>& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Массивы должны быть одинакового размера");
        }
        if (!std::is_arithmetic<T>::value) {
            throw std::bad_typeid();
        }

        double sum = 0.0;
        for (size_t i = 0; i < data.size(); ++i) {
            double diff = static_cast<double>(data[i]) - static_cast<double>(other.data[i]);
            sum += diff * diff;
        }
        return std::sqrt(sum);
    }
};

int main() {
    try {
        Array<int> a = {1, 2, 3};
        Array<int> b = {4, 5, 6};

        std::cout << "Array a: " << a << std::endl;
        std::cout << "Array b: " << b << std::endl;

       
        a.setNumeric(0, 10);

        // Евклидово расстояние
        double dist = a.euclideanDistance(b);
        std::cout << "Euclidean distance: " << dist << std::endl;

     
        Array<std::string> s1 = {"a", "b"};
        Array<std::string> s2 = {"c", "d"};
        

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
