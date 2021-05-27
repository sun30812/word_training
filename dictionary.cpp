#include "dictionary.h"
#include <iostream>
using namespace std;

Dictionary::Dictionary(int data_length) {
    this->data_length = data_length;
    words = new string[data_length];
    means = new string[data_length];
}

// word 매개변수에 해당하는 단어가 사전에 있으면 result변수에 뜻을 반환하고
// true를 반환합니다. 사전에 없는 단어이면 false를 반환하고
// 아무 작업도 하지 않습니다.
bool Dictionary::search(const string& word, string& result) {
    for (int i = 0; i < data_length; i++) {
        if (words[i] == word) {
            result = means[i];
            return true;
        }
    }
    return false;
}

// word 매개변수에 해당하는 단어 사전에서 찾아서 있으면 그 위치를 반환하고,
// 해당 단어가 존재하지 않으면 -1을 반환합니다.
int Dictionary::search(const string& word) {
    if (data_length > 0) {
        for (int i = 0; i < data_length; i++) {
            if (words[i] == word) {
                return i;
            }
        }
    }
    return -1;
}

// 사전에 존재하는 모든 단어와 뜻을 출력합니다. 등록된 단어가 없는 경우 사전에 등록된 단어가
// 없다는 메세지가 출력됩니다.
// 단, 비어있는 단어를 추가한 경우(영어사전 클래스 생성 시 배열 크기만 지정한 경우)
// 해당 단어자리에 비어있음이 표시됩니다.
void Dictionary::printAll()
{
    cout << "\n" << endl;
    if (data_length) {
        for (int i = 0; i < data_length; i++)
        {
            if (words[i] != "") {
                cout << "[" << i + 1 << "]" << words[i] << ":" << means[i] << endl;
            }
            else {
                cout << "[" << i + 1 << "]" << "비어있음" << endl;
            }
        }
    } else {
        cout << "사전에 등록된 단어가 없습니다." << endl;
    }
    cout << "\n" << endl;
}

Dictionary::~Dictionary() {
    delete[] words;
    delete[] means;
}
// 아무 매개변수도 주지 않은 경우 빈 사전이 생성됩니다. 미리 등록하고 싶은 단어가 없으면
// 매개변수를 아무것도 않넣으면 됩니다.
// 단어가 없는 사전이여도 add함수를 통해 단어를 새로 등록할 수 있습니다.(add함수 사용 시 배열 크기 알아서 늘어남)
// 매개변수 설명: data_length = 사전을 위한 배열 생성에 요구되는 원소개수(단어가 몇개인가)
// 주의사항: data_length만 따로 지정할 수 있는 이유는 나중에 개발목적으로 테스트 할 경우
// 를 위한 것이며 일반적인 사용의 경우에는 권장하지 않습니다.
EnglishDictionary::EnglishDictionary(int data_length) : Dictionary(data_length) {}
// 주의사항: words와 means를 통해 사전에 단어를 미리 추가하려면 data_length를 반드시 명시해야합니다
// 매개변수 설명: data_length = 사전을 위한 배열 생성에 요구되는 원소개수(단어가 몇개인가)
// words = 영어단어만 들어있는 string배열
// means = 영어단어의 뜻만 들어있는 string배열
// words와 means의 원소의 개수는 같아야 하며, 단어와 뜻이 서로 1:1 대응이 되어야 합니다.
// 예: words = {"Windows", "macOS"}, means = {"윈도우", "맥OS"}
EnglishDictionary::EnglishDictionary(int data_length, string words[], string means[])
: Dictionary(data_length) {
    this->words = words;
    this->means = means;
}

// word매개변수에 해당하는 값과 그 뜻을 meaning매개변수로 단어장에 추가합니다.
// 해당 단어가 이미 등록되어 있던 경우 사전에 영향을 미치지 않으며 false를 반환합니다.
// 뜻을 변경하는 경우에는 modify함수를 사용하기 바랍니다.
bool EnglishDictionary::add(const string &word, const string &meaning) {
    if (search(word) == -1) {
        data_length++;
        string* new_words = new string[data_length]();
        for (int i = 0; i < data_length - 1; i++) {
            new_words[i] = words[i];
        }
        new_words[data_length - 1] = word;
        string* new_means = new string[data_length]();
        for (int i = 0; i < data_length - 1; i++) {
            new_means[i] = means[i];
        }
        new_means[data_length - 1] = meaning;
        words = new_words;
        means = new_means;
        return true;
    } else {
        return false;
    }
}


// 사전에서 특정 단어를 지우도록 해줍니다.
// 해당 단어가 존재하지 않는 경우 false를 반환하고 아무런 작업도 수행하지 않습니다.
// 사용법: english_dictionary -= "지울 단어"
bool EnglishDictionary::operator-=(const string& word) {
    int index = search(word);
    if (index >= 0) {
        this->words[index] = "/deleted";
        this->means[index] = "/deleted";
        data_length--;
        string* new_words = new string[data_length]();
        for (int i = 0, j = 0; i < data_length; i++, j++) {
            if (words[i] == "/deleted") {
                j++;
            }
            new_words[i] = words[j];
        }
        string* new_means = new string[data_length]();
        for (int i = 0, j = 0; i < data_length; i++, j++) {
            if (means[i] == "/deleted") {
                j++;
            }
            new_means[i] = means[j];
        }
        words = new_words;
        means = new_means;
        return true;
    } else {
        return false;
    }

}
// 사전에서 특정 단어의 뜻을 변경합니다.
// 해당 단어가 존재하지 않는 경우 false를 반환하고 아무런 작업도 수행하지 않습니다.
bool EnglishDictionary::modify(const string &word, const string& new_meaning) {
    if (search(word) == -1) {
        return false;
    } else {
        this->operator-=(word);
        this->add(word, new_meaning);
    }
    return true;
}

