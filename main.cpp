// 영어단어를 학습시키는 프로그램입니다.
#include <iostream>
#include "dictionary.h"
using namespace std;


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
                cout << "단어를 검색합니다. 검색을 원하시는 단어를 입력하세요" << endl;
                cout << "입력: ";
                cin >> input;
                if (dictionary.search(input, result)) {
                    cout << "검색하신 단어의 뜻은 " << result << " 입니다.\n" << endl;
                } else {
                    cout << "검색하신 단어를 찾을 수 없습니다.\n" << endl;
                }
                break;
            }
            case 2:
                // TODO: 단어 관리 메뉴 추가
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
        }
    }
    return 0;
}