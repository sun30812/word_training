#include "dictionary.h"
#include <iostream>
using namespace std;

Dictionary::Dictionary(int data_length) {
    this->data_length = data_length;
    words = new string[data_length];
    means = new string[data_length];
}

// key 매개변수에 해당하는 단어 사전에서 찾아서 있으면 result변수에 뜻을 반환하고
// 함수 자체는 true를 반환합니다. 사전에 없는 단어이면 false를 반환하고 result변수에
// 아무 작업도 하지 않습니다.
bool Dictionary::search(const string& key, string& result) {
    for (int i = 0; i < data_length; i++) {
        if (words[i] == key) {
            result = means[i];
            return true;
        }
    }
    return false;
}

// key 매개변수에 해당하는 단어 사전에서 찾아서 있으면 그 위치를 반환하고,
// 없으면 -1을 반환합니다.
int Dictionary::search(const string& key) {
    for (int i = 0; i < data_length; i++) {
        if (words[i] == key) {
            return i;
        }
    }
    return -1;
}

// 단어장에 존재하는 모든 리스트를 출력합니다.
void Dictionary::printAll()
{
    cout << "\n" << endl;
    for (int i = 0; i < data_length; i++)
    {
        if (words[i] != "") {
            cout << "[" << i + 1 << "]" << words[i] << ":" << means[i] << endl;
        }
        else {
            cout << "[" << i + 1 << "]" << " 비어있음" << endl;
        }
    }
    cout << "\n" << endl;
}

Dictionary::~Dictionary() {
    delete[] words;
    delete[] means;
}

EnglishDictionary::EnglishDictionary(int data_length) : Dictionary(data_length) {
    // TODO: 데이터를 파일에서(fstream) 읽어오는 로직 추가 필요
    words[0] = "test";
    means[0] = "시험";
    words[1] = "pizza";
    means[1] = "피자";
    means[4] = "xxxaaaaa";
    words[4] = "x";
}

// word매개변수에 해당하는 값과 그 뜻을 meaning매개변수로 단어장에 추가합니다.
// 이미 등록되어 있던 경우 데이터가 추가되거나 변경되지 않습니다.
void EnglishDictionary::add(const string &word, const string &meaning) {
    if (search(word) == -1) {
        data_length++;
        string* new_words = new string[data_length]();
        for (int i = 0; i < data_length - 1; i++) {
            new_words[i] = words[i];
        }
        new_words[data_length - 1] = word;
        string* new_means = new string[data_length]();
        for (int i = 0; i < data_length - 1; i++) {
            new_words[i] = words[i];
        }
        new_means[data_length - 1] = meaning;
        words = new_words;
        means = new_means;
        cout << "단어가 정상적으로 추가되었습니다." << endl;
    } else {
        cout << "이미 등록된 단어입니다." << endl;
    }
}


// 단어장에서 특정 단어를 지우도록 해줍니다.
// 존재하지 않는 경우 메세지를 띄우고 아무런 작업도 수행하지 않습니다.
// 사용법: english_dictionary -= "지울 단어"
void EnglishDictionary::operator-=(const string& word) {
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
        cout << "단어가 정상적으로 지워졌습니다." << endl;
    } else {
        cout << "해당 단어는 존재하지 않습니다." << endl;
    }

}

int EnglishDictionary::getLength()
{
    return data_length;
}

