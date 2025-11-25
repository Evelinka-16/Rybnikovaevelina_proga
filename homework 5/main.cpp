#include <iostream>
#include "ArrTxt.h"
#include "ArrCSV.h"

int main() {
    ArrTxt txtArr(3);
    txtArr.set(0, 10);
    txtArr.set(1, 20);
    txtArr.set(2, 30);

    ArrCSV csvArr(3);
    csvArr.set(0, 5);
    csvArr.set(1, 15);
    csvArr.set(2, 25);

    std::cout << "TXT array: ";
    txtArr.print();

    std::cout << "CSV array: ";
    csvArr.print();

    txtArr.saveToFile();
    csvArr.saveToFile();

    std::cout << "Файлы успешно созданы\n";

    return 0;
}
