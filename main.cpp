#include <iostream>
#include <fstream>
#include "TomaString.h"
#include "TSList.h"
#include "WCList.h"
#include "SortedOddsTSList.h"

using namespace std;

void printIntro();
bool getTextFromFile(TSList &list);
void createProtocol(const TSList &list);
void createWCListFile(const WCList &list);
void createOddsListFile(const SortedOddsTSList &list);

int main() {

    TSList textList;
    if (getTextFromFile(textList)){
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
                cout << "� �� ���﫠, �� �� ���, ���஡�� �� ࠧ" << endl;
                i--;
            }
        }

        if (!i) {
            cout << "�� ��� ��室�� ������⥫쭠� ��⨢�����. �� ᢨ�����!";
        }
    }

    return 0;
}

void printIntro() {
    cout << "���� ����������!" << endl;
    cout << "� �ணࠬ��, ����� 㬥�� �����, ᪮�쪮 ࠧ � ⥪�� ����砥��� ������ ᫮��=)" << endl;
    cout << "� �� ��祬-� 㬥� ���஢��� �� ��䠢��� ����� ᫮��, �᫨ � ��� ���᭠� ��室���� � �।���"
         << endl;
    cout << "��� ࠡ�� � ���� �㤥� �ந�室��� �१ 䠩��:" << endl;
    cout << "�� 㦥 ����㧨�� � ���� 䠩� (���� �� �� �� �⠫� �� ᮮ�饭��)" << endl;
    cout << "� ��୥��� ����� �ணࠬ�� 㦥 ����� ��⮪�� � ⥪⮬." << endl;
    cout << "����, १����� ���� ࠡ��� ���� ������ ⠬ ��=)" << endl;
    cout << "������ �롥�� ����:" << endl;
    cout << "1. �������� ᫮��" << endl;
    cout << "2. �����஢��� �� ��䠢��� ᫮�� � ����� ������⢮� �㪢 (� ������ ���᭠� � �।���)" << endl;
}

bool getTextFromFile(TSList &list) {
    ifstream fin("Test.txt", ios::in | ios::binary);
    if (!fin) {
        cout << "�訡�� ������ 䠩��";
        return false;
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
        return true;
    }
}

void createProtocol(const TSList &list) {
    ofstream fout("Protocol.txt");
    if (!fout) {
        cout << "�訡�� ������ 䠩��";
    } else {
        fout << list;
        fout.close();
    }
}

void createWCListFile(const WCList &list) {
    ofstream fout("WordCounter.txt");
    if (!fout) {
           cout << "�訡�� ������ 䠩��";
    } else {
        fout << list;
        fout.close();
    }
}

void createOddsListFile(const SortedOddsTSList &list) {
    ofstream fout("SortedOddWords.txt");
    if (!fout) {
        cout << "�訡�� ������ 䠩��";
    } else {
        fout << list;
        fout.close();
    }
}