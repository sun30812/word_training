#include "dictionary.h"
#include <iostream>
using namespace std;

Dictionary::Dictionary(int data_length) {
    this->data_length = data_length;
    words = new string[data_length]();
    means = new string[data_length]();
}



Dictionary::~Dictionary() {
    delete[] words;
    delete[] means;
}

EnglishDictionary::EnglishDictionary(int data_length) : Dictionary(data_length) {
    words[0] = "test";
    means[0] = "시험";
    words[1] = "pizza";
    means[1] = "피자";
}

// key 매개변수에 해당하는 단어 사전에서 찾아서 있으면 result변수에 뜻을 반환하고
// 함수 자체는 true를 반환합니다. 사전에 없는 단어이면 false를 반환하고 result변수에
// 아무 작업도 하지 않습니다.
bool EnglishDictionary::search(const string& key, string& result) {
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
int EnglishDictionary::search(const string& key) {
    for (int i = 0; i < data_length; i++) {
        if (words[i] == key) {
            return i;
        }
    }
    return -1;
}

// 단어를 제외시킬 떄 사용합니다. 아직 완성되지 않았습니다.
void EnglishDictionary::operator-=(const string& word) {
    int index = search(word);
    if (index >= 0) {
        this->words[index] = "";
        this->means[index] = "";
        data_length--;
        string* new_words = new string[data_length]();
        for (int i = 0, j = 0; i < data_length; i++, j++) {
            if (words[j] == "")
                j++;
            new_words[i] = words[j];
        }
        string* new_means = new string[data_length]();
        for (int i = 0, j = 0; i < data_length; i++, j++) {
            if (means[j] == "")
                j++;
            new_means[i] = means[j];
        }
        words = new_words;
        means = new_means;
    }

}
