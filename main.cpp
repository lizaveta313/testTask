#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

// Функция для поиска общих символов в двух текстах
void findCommonChars(string text1, string text2) {
    set<char> set1, set2, commonSet;

    // Создаем два множества символов для каждого текста
    for (char c : text1) {
        set1.insert(c);
    }

    for (char c : text2) {
        set2.insert(c);
    }

    // Поиск общего символа
    for (char c : set1) {
        if (set2.count(c)) {
            commonSet.insert(c);
        }
    }

    cout << "Символы общие для двух текстов: ";
    for (char c : commonSet) {
        cout << c << " ";
    }
    cout << endl;
}

// Функция поиска уникальных символов в первом тексте
void findUniqueChars(string text1, string text2) {
    set<char> set1, set2, uniqueSet;

    // Создаем два множества символов для каждого текста
    for (char c : text1) {
        set1.insert(c);
    }

    for (char c : text2) {
        set2.insert(c);
    }

    // Поиск уникального символа в тексте 1
    for (char c : set1) {
        if (!set2.count(c)) {
            uniqueSet.insert(c);
        }
    }

    cout << "Символы, которые встречаются только в первом тексте: ";
    for (char c : uniqueSet) {
        cout << c << " ";
    }
    cout << endl;
}

// Функция для определения количества уникальных символов в тексте
void findNumUniqueChars(string text1, string text2) {
    set<char> uniqueCharSet;

    // Вставка символов обоих текстов в uniqueCharSet
    for (char c : text1) {
        uniqueCharSet.insert(c);
    }
    for (char c : text2) {
        uniqueCharSet.insert(c);
    }

    cout << "Количество уникальных символов: " << uniqueCharSet.size() << endl;
}

int main() {

    setlocale(LC_ALL, "rus");
    

    string text1, text2;

    // Открытие первого файла и чтение его содержимого в переменную text1
    ifstream file1("text1.txt");
    if (file1.is_open()) {
        getline(file1, text1);
        file1.close();
    }
    else {
        cout << "Не удалось открыть файл 1" << endl;
        return 1;
    }

    // Открытие второго файла и чтение его содержимого в переменную text2
    ifstream file2("text2.txt");
    if (file2.is_open()) {
        getline(file2, text2);
        file2.close();
    }
    else {
        cout << "Не удалось открыть файл 2" << endl;
        return 1;
    }

    findCommonChars(text1, text2);
    findUniqueChars(text1, text2);
    findNumUniqueChars(text1, text2);

    return 0;
}