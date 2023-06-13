#include <iostream>
#include <fstream>
#include "TomaString.h"
#include "TSList.h"
#include "WCList.h"
#include "SortedOddsTSList.h"

using namespace std;

void printIntro();
void getTextFromFile(TSList &list);
void createProtocol(const TSList &list);
void createWCListFile(const WCList &list);
void createOddsListFile(const SortedOddsTSList &list);

int main() {

    TSList textList;
    getTextFromFile(textList);
    createProtocol(textList);

    printIntro();
    int choice;
    int i = 3;
    while (i) {
        cin >> choice;
        if (choice == 1) {
            WCList listOfCounts;
            listOfCounts.fillFromTSList(textList);
            createWCListFile(listOfCounts);
            break;
        } else if (choice == 2) {
            SortedOddsTSList listOfOdds;
            listOfOdds.fillSortedOddsList(textList);
            createOddsListFile(listOfOdds);
            break;
        } else {
            cout << "Я не поняла, что вы хотите, попробуйте еще раз" << endl;
            i--;
        }
    }

    if (!i) {
        cout << "От вас исходит подозрительная активность. До свидания!";
    }

    return 0;
}

void printIntro() {
    cout << "Добро пожаловать!" << endl;
    cout << "Я программа, которая умеет считать, сколько раз в тексте встречается каждое слово=)" << endl;
    cout << "А еще зачем-то умею сортировать по алфавиту нечетные слова, если у них гласная находится в середине"
         << endl;
    cout << "Вся работа со мной будет происходить через файлы:" << endl;
    cout << "Вы уже загрузили в меня файл." << endl;
    cout << "Если я его успешно считала, то в корневой папке программы лежит протокол с тектом." << endl;
    cout << "Кстати, результаты моей работы будут лежать там же=)" << endl;
    cout << "Теперь выберите опцию:" << endl;
    cout << "1. Подсчитать слова" << endl;
    cout << "2. Отсортировать по алфавиту слова с нечетным количеством букв (у которых гласная в середине)" << endl;
}

void getTextFromFile(TSList &list) {
    ifstream fin("Twinkle.txt", ios::in | ios::binary);
    if (!fin) {
        cout << "Ошибка открытия файла";
    } else {
        char ch;
        TomaString str;
        int i;
        while (!fin.eof()) {
            str = "";
            i = TomaString::getMaxLength();
            while (!fin.eof() && (i > 0)) {
                fin.get(ch);
                if (!fin.eof() && ch != 13 && ch != 10) {
                    str.append(ch);
                    i--;
                } else break;
            }
            if (str.length() > 1) {
                list.pushBack(str);
            }
        }
        fin.close();
    }
}

void createProtocol(const TSList &list) {
    ofstream fout("Protocol.txt");
    if (!fout) {
        cout << "Ошибка открытия файла";
    } else {
        fout << list;
        fout.close();
    }
}

void createWCListFile(const WCList &list) {
    ofstream fout("WordCounter.txt");
    if (!fout) {
           cout << "Ошибка открытия файла";
    } else {
        fout << list;
        fout.close();
    }
}

void createOddsListFile(const SortedOddsTSList &list) {
    ofstream fout("SortedOddWords.txt");
    if (!fout) {
        cout << "Ошибка открытия файла";
    } else {
        fout << list;
        fout.close();
    }
}