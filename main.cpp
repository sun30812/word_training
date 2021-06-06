// 영어단어를 검색할 수 있는 영어사전 프로그램입니다.
#include "dictionary.h"
using namespace std;

void wordManagement(EnglishDictionary& dictionary);

int main() {
    cout << "==========" << endl;
    cout << "영어 단어장" << endl;
    cout << "==========" << endl;
    string words[] = {"settings", "passionate"};
    string means[] = {"설정", "열정적인"};
    EnglishDictionary dictionary(2,words, means);
    int answer = 0;
    bool isExit = false;
    while (!isExit) {
        cout << "1. 단어 검색" << endl;
        cout << "2. 단어 관리" << endl;
        cout << "3. 단어 전체 목록보기" << endl;
        cout << "4. 프로그램 종료" << endl;
        cout << "\n메뉴 번호 입력(번호만 입력하세요): ";
        cin >> answer;
        switch (answer) {
            case 1: {
                string input, result;
                cout << "단어를 검색합니다. 검색을 원하시는 단어를 입력하세요" << endl;
                cout << "입력: ";
                cin.ignore();
                getline(cin, input);
                if (dictionary.search(input, result)) {
                    cout << "\n\n검색하신 단어의 뜻은 " << "\"" << result << "\"" << " 입니다.\n" << endl;
                } else {
                    cout << "\n\n검색하신 단어를 찾을 수 없습니다.\n" << endl;
                }
                break;
            }
            case 2:
                wordManagement(dictionary);
                break;
            case 3: 
                dictionary.printAll();
                break;
            case 4:
                cout << "프로그램을 종료합니다." << endl;
                isExit = true;
                break;
            default:
                cout << "잘못 입력하셨습니다. 메뉴를 다시 확인해주세요\n\n" << endl;
                break;
        }
    }
    return 0;
}

// 사전 관리 메뉴
void wordManagement(EnglishDictionary& dictionary) {
    int answer = 0;
    bool isExit = false;
    cout << "해당 메뉴에서는 단어를 추가하거나 삭제할 수 있습니다." << endl;
    while (!isExit) {
        cout << "1. 단어 추가" << endl;
        cout << "2. 단어 삭제" << endl;
        cout << "3. 단어 수정" << endl;
        cout << "4. 뒤로 돌아가기" << endl;
        cout << "\n메뉴 번호 입력(번호만 입력하세요): ";
        cin >> answer;
        switch (answer) {
            case 1: {
                string word, meaning;
                cout << "추가할 단어를 입력해주세요: ";
                cin.ignore();
                getline(cin, word);
                cout << "뜻을 입력해주세요: ";
                getline(cin, meaning);
                if (dictionary.add(word, meaning)) {
                    cout << "단어가 정상적으로 추가되었습니다." << endl;
                } else {
                    cout << "이미 등록된 단어입니다." << endl;
                    cout << "새로운 단어를 추가하시려면 단어 추가 메뉴에서 진행해주세요." << endl;
                }
                break;
            }
            case 2: {
                string word;
                cout << "삭제할 단어를 입력해주세요: ";
                cin.ignore();
                getline(cin, word);
                if (dictionary -= word) {
                    cout << "단어가 정상적으로 지워졌습니다." << endl;
                } else {
                    cout << "해당 단어는 존재하지 않습니다." << endl;
                }
            }
                break;
            case 3: {
                string word, meaning;
                cout << "뜻을 수정할 단어를 입력해주세요: ";
                cin.ignore();
                getline(cin, word);
                cout << "해당 단어의 새로운 뜻을 입력해주세요: ";
                getline(cin, meaning);
                if (dictionary.modify(word, meaning)) {
                    cout << "정상 수정 되었습니다." << endl;
                } else {
                    cout << "입력하신 단어는 존재하지 않기 때문에 아무 일도 일어나지 않았습니다." << endl;
                    cout << "새로운 단어를 추가하시려면 단어 추가 메뉴에서 진행해주세요." << endl;
                }
            }
                break;
            case 4:
                isExit = true;
                break;

            default:
                cout << "잘못 입력하셨습니다. 메뉴를 다시 확인해주세요\n\n" << endl;
                break;
        }

    }
}
