#include <iostream>
#include <exception>
#include "Array.cpp"

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    std::cout << "/ПРОВЕРКА ИСКЛЮЧЕНИЙ В КОНСТРУКТОРЕ" << std::endl;
    setlocale(LC_ALL, "RUSSIAN");
    std::cout << "/ПРОВЕРКА ИСКЛЮЧЕНИЙ В КОНСТРУКТОРЕ" << std::endl;
    Array<float> arr2(4);
    Array<int> arr1(-1);
    std::cout << "//ПРОВЕРКА ИСКЛЮЧЕНИЯ В ИНДЕКСИРОВАНИИ" << std::endl;
    std::cout << arr2[-2];
    std::cout << "ДОБАВЛЯЕМ ЭЛЕМЕНТЫ И ПРОВЕРЯЕМ ВЫХОД ЗА РАМКИ" << std::endl;

    arr2.addBeginElement(1.3f);
    arr2.addBeginElement(2.2f);
    arr2.addBeginElement(3.5f);
    arr2.addBeginElement(4.4f);
    arr2.addBeginElement(5.2f);
    arr2.printArr();
    arr2.showCount();

    std::cout << "ПОПЫТКА УДАЛЕНИЯ ОТРИЦАТЕЛЬНОГО ИНДЕКСА" << std::endl;
    arr2.removeByIndex(-2);
    arr2.removeByIndex(2);
    arr2.printArr();

    std::cout << "УДАЛЕНИЕ ЭЕЛМЕНТОВ И ПОПЫТКА УДАЛИТЬ ЭЛЕМЕНТ ИЗ УЖЕ ПУСТОГО КОНТЕЙНЕРА" << std::endl;
    arr2.removeBeginElement();
    arr2.removeBeginElement();
    arr2.removeBeginElement();
    arr2.removeBeginElement();
    arr2.printArr();
    arr2.showCount();
    arr2.removeBeginElement();
    arr2.printArr();
    arr2.showCount();
    std::cout << "ЗАПОЛНЯЕМ С ПОМОЩЬЮ ИНДЕКСОВ" << std::endl;
    arr2.addByIndex(4.21f, 1);
    arr2.addByIndex(4.21f, 2);
    arr2.addByIndex(4.21f, 3);
    arr2.addByIndex(4.21f, 4);
    arr2.printArr();
    arr2.showCount();
    std::cout << "ПОПЫТКА ВСТАВИТЬ ЭЛЕМЕНТ С ПОМОЩЬЮ НЕПРАВИЛЬНОГО ИНДЕКСА" << std::endl;
    arr2.addByIndex(4.21f, 6);
    arr2.addByIndex(4.21f, -2);
    arr2.printArr();
    arr2.showCount();

    arr2.removeByIndex(3);
    arr2.printArr();
    arr2.showCount();

    arr2.addByIndex(4.21f, 3);
    arr2.printArr();
    arr2.showCount();

    arr2.removeElement();
    arr2.addElement(7.22f);
    arr2.printArr();
    arr2.showCount();
    

	return 0;
}