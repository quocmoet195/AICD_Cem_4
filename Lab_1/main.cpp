#include <iostream>
#include "Set.h"
#include <chrono>


size_t lcg(size_t& i) {
    return (i * 1021 + 24631) % 116640;
}

std::vector<int> findDuplicates(const std::vector<int>& nums) {
    Set bst;
    std::vector<int> duplicates;

    for (int num : nums) {
        if (!bst.insert(num)) {
            duplicates.push_back(num);
        }
    }

    return duplicates;
}

void testing_code() {
    Set set1000, set10000, set100000;

    std::cout << "For my set:\n";
    std::cout << "Test1 - 1000\n";
    // test 1 - 1000
    // insert
    auto start = std::chrono::high_resolution_clock::now(); // запоминаем время начала выполнения
    for (size_t j = 0; j < 100; j++)
        for (size_t i = 0; i < 1000; i++)
            set1000.insert(lcg(i));
    auto end = std::chrono::high_resolution_clock::now(); // запоминаем время завершения выполнения
    std::chrono::duration<double, std::micro> duration = (end - start); // вычисляем время выполнения в микросекундах
    std::cout << "Среднее время заполнения для 1000: " << (double)duration.count() / 100 << " us" << std::endl;

    // search (contains)
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
        set1000.contains(lcg(i));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время поиска для 1000: " << (double)duration.count() / 1000 << " ms" << std::endl;

    // remove (erase)
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
        set1000.erase(lcg(i));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время удаления для 1000: " << (double)duration.count() / 1000 << " ms" << std::endl;

    std::cout << "Test2 - 10000\n";
    // test 2 - 10000
    // insert
    start = std::chrono::high_resolution_clock::now();
    for (size_t j = 0; j < 100; j++)
        for (size_t i = 0; i < 10000; i++)
            set10000.insert(lcg(i));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время заполнения для 10000: " << (double)duration.count() / 100 << " ms" << std::endl;

    // search (contains)
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
        set10000.contains(lcg(i));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время поиска для 10000: " << (double)duration.count() / 1000 << " ms" << std::endl;

    // remove (erase)
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
        set10000.erase(lcg(i));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время удаления для 10000: " << (double)duration.count() / 1000 << " ms" << std::endl;

    std::cout << "Test3 - 100000\n";
    // test 3 - 100000
    // insert
    start = std::chrono::high_resolution_clock::now();
    for (size_t j = 0; j < 100; j++)
        for (size_t i = 0; i < 100000; i++)
            set100000.insert(lcg(i));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время заполнения для 100000: " << (double)duration.count() / 100 << " ms" << std::endl;

    // search (contains)
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
        set100000.contains(lcg(i));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время поиска для 100000: " << (double)duration.count() / 1000 << " ms" << std::endl;

    // remove (erase)
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
        set100000.erase(lcg(i));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время удаления для 100000: " << (double)duration.count() / 1000 << " ms" << std::endl;

    std::cout << "\nFor std::vector:\n";
    // std::set<int> std_set1000, std_set10000, std_set100000;
    std::vector<int> std_set1000, std_set10000, std_set100000;
    std::cout << "Test1 - 1000\n";
    // test 1 - 1000
    // insert
    start = std::chrono::high_resolution_clock::now();
    for (size_t j = 0; j < 100; j++)
        for (size_t i = 0; i < 1000; i++)
            std_set1000.push_back(lcg(i));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время заполнения для 1000: " << (double)duration.count() / 100 << " ms" << std::endl;

    // search (contains)
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
        std::find(std_set1000.begin(), std_set1000.end(), lcg(i));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время поиска для 1000: " << (double)duration.count() / 1000 << " ms" << std::endl;

    // remove
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
        std_set1000.erase(std::find(std_set1000.begin(), std_set1000.end(), lcg(i)));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время удаления для 1000: " << (double)duration.count() / 1000 << " ms" << std::endl;

    std::cout << "Test2 - 10000\n";
    // test 2 - 10000
    // insert
    start = std::chrono::high_resolution_clock::now();
    for (size_t j = 0; j < 100; j++)
        for (size_t i = 0; i < 10000; i++)
            std_set10000.push_back(lcg(i));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время заполнения для 10000: " << (double)duration.count() / 100 << " ms" << std::endl;

    // search (contains)
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
        std::find(std_set10000.begin(), std_set10000.end(), lcg(i));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время поиска для 10000: " << (double)duration.count() / 1000 << " ms" << std::endl;

    // remove (erase)
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
        std_set10000.erase(std::find(std_set10000.begin(), std_set10000.end(), lcg(i)));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время удаления для 10000: " << (double)duration.count() / 1000 << " ms" << std::endl;

    std::cout << "Test3 - 100000\n";
    // test 3 - 100000
    // insert
    start = std::chrono::high_resolution_clock::now();
    for (size_t j = 0; j < 100; j++)
        for (size_t i = 0; i < 100000; i++)
            std_set100000.push_back(lcg(i));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время заполнение для 100000: " << (double)duration.count() / 100 << " ms" << std::endl;

    // search (contains)
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
        std::find(std_set100000.begin(), std_set100000.end(), lcg(i));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время поиска для 100000: " << (double)duration.count() / 1000 << " ms" << std::endl;

    // remove (erase)
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
        std_set100000.erase(std::find(std_set100000.begin(), std_set100000.end(), lcg(i)));
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start);
    std::cout << "Среднее время удаления для 100000: " << (double)duration.count() / 1000 << " ms" << std::endl;
}

int main()
{
    vector<int> vec;
    int element,index;
    while (true) {
        int command;
        int command2;
        std::cout << "\n[0] Заполнить вектор\n[1] Добавить элемент\n[2] Удалить элемент\n[3] Вывод вектор\n[4] Найти все повторяющиеся элементы\n[5] Тестирование\n[6] Закончить работу\n--> ";
        std::cin >> command;
        switch (command) {
        case 0: {
            std::cout << "Введите количество добавляемых элементов: ";
            int count;
            std::cin >> count;
            if (count < 0)
                std::cout << "error command\n";

            for (int i = 0; i < count; i++) {
                std::cout << "значение: ";
                std::cin >> element;
                vec.push_back(element);
            }
            break;
        }
        case 1:
            while (true) {
                std::cout << "Значение нужно добавить: ";
                std::cin >> element;
                std::cout << "Место нужно добавить: ";
                std::cin >> index;
                vec.insert(vec.begin()+index,element);


                std::cout << "\n[1] Продолжать добавить\n[2] назад\n--> ";
                std::cin >> command2;
                if (command2 == 2) {
                    break;
                }
            }
            break;
        case 2:
            while (true) {
                std::cout << "Место нужно удалить: ";
                std::cin >> index;
                vec.erase(vec.begin() + index);

                std::cout << "\n[1] Продолжать удалить\n[2] назад\n--> ";
                std::cin >> command2;
                if (command2 == 2) {
                    break;
                }
            }
            break;

        case 3:
            while (true) {
                std::cout << "Вектор: ";
                for (int num : vec) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
            }
            break;
        case 4: {
            std::vector<int> duplicates = findDuplicates(vec);
            if (duplicates.empty()) {
                cout << "\nНет повторяющихся элементов!!!!!\n";
                break;
            }

            std::cout << "Векторный результат: ";
            for (int num : duplicates)
                std::cout << num << " ";
            std::cout << std::endl;
            break;
        }
        case 5:
            testing_code();
            break;
        case 6:
            return 0;
        default:
            std::cout << "error command\n";
        }
    }
    return 0;
}

