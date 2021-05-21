// 단어 시험기능을 통해 영어단어를 학습시키는 프로그램입니다.
#include <iostream>
#include "dictionary.h"
using namespace std;

// 단어 관리 메뉴
void wordManagement(EnglishDictionary& dictionary);

int main() {
    cout << "==========" << endl;
    cout << "영단어 학습기" << endl;
    cout << "==========" << endl;
    EnglishDictionary dictionary(5);
    int answer = 0;
    while (true) {
        cout << "1. 단어 검색" << endl;
        cout << "2. 단어 관리" << endl;
        cout << "3. 단어 시험보기" << endl;
        cout << "4. 프로그램 종료" << endl;
        cout << "\n메뉴 번호 입력: ";
        cin >> answer;
        switch (answer) {
            case 1: {
                string input, result;
                dictionary -= "test";
                cout << "단어를 검색합니다. 검색을 원하시는 단어를 입력하세요" << endl;
                cout << "입력: ";
                cin >> input;
                if (dictionary.search(input, result)) {
                    cout << "\n\n검색하신 단어의 뜻은 " << result << " 입니다.\n" << endl;
                } else {
                    cout << "\n\n검색하신 단어를 찾을 수 없습니다.\n" << endl;
                }
                break;
            }
            case 2:
                wordManagement(dictionary);
                break;
            case 3:
                // TODO: 단어 시험 메뉴 추가
                break;
            case 4:
                cout << "프로그램을 종료합니다." << endl;
                exit(0);
                break;
            default:
                cout << "잘못 입력하셨습니다. 메뉴를 다시 확인해주세요\n\n" << endl;
                break;
        }
    }
    return 0;
}

void wordManagement(EnglishDictionary& dictionary) {
    int answer = 0;
    bool isExit = false;
    cout << "해당 메뉴에서는 단어를 추가하거나 삭제할 수 있습니다." << endl;
    while (!isExit) {
        cout << "1. 단어 추가" << endl;
        cout << "2. 단어 삭제" << endl;
        cout << "3. 뒤로 돌아가기" << endl;
        cout << "\n메뉴 번호 입력: ";
        cin >> answer;
        switch (answer) {
            case 1: {
                string word, meaning;
                cout << "추가할 단어를 입력해주세요: ";
                cin >> word;
                cout << "뜻을 입력해주세요: ";
                cin >> meaning;
                dictionary.add(word, meaning);
                break;
            }
            case 2:
                // TODO: 단어 삭제
                break;
            case 3:
                isExit = true;
                break;
            default:
                cout << "잘못 입력하셨습니다. 메뉴를 다시 확인해주세요\n\n" << endl;
                break;
        }

    }
}