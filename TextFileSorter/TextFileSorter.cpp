#include <iostream>
#include <string>
#include <fstream>
#include "TableSorter.h"
#include "SortColumn.h"
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX 1
#include <windows.h>
#endif
using namespace std;

int main()
{
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif
    string filePath;
    cout << "Введите путь к файлу\n";
    cin >> filePath;
    ifstream file(filePath);
    while (!file.is_open()) {
        cout << "Введите корректный путь к файлу\nВвод: ";
        cin >> filePath;
        ifstream file(filePath);
    }
    int sortColumn = 0;
    SortColumn sc;
    while(sortColumn == 0) {
        cout << "Для сортировки по именам введите – 1, по фамилиям введите- 2, по телефонам введите- 3\nВвод: ";
        cin >> sortColumn;
        sc = static_cast<SortColumn>(sortColumn);
        switch (sc) {
        case SortColumn::NAME:
            break;
        case SortColumn::FAMILYNAME:
            break;
        case SortColumn::PHONE:
            break;
        default:
            sortColumn = 0;
        }
    }
    TableSorter ts;
    cout << "Вывод:" << std::endl;
    ts.SortTable(file, sc);
    file.close();
    std::cout << "Нажмите Enter для выхода." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}
