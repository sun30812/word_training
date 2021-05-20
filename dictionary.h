#ifndef FINAL_PROJECT_DICTIONARY_H
#define FINAL_PROJECT_DICTIONARY_H
#include <iostream>
using namespace std;
// 모든 사전관련 클래스 들의 부모입니다.
/* 나중에 일본어 학습기, 중국어 학습기 기능을 프로그램에 추가시키려면
해당 클래스를 상속해야 합니다. */
class Dictionary {
protected:
    int data_length;
    string* words;
    string* means;
    Dictionary(int data_length);
    ~Dictionary();
};

// 해당 프로그램은 영어학습기라서 EnglishDictionary하나만 존재합니다.
class EnglishDictionary : Dictionary {
public:
    EnglishDictionary(int data_length);
    void view();
    bool search(const string& key, string& result);
    int search(const string& key);
    void operator-=(const string& word);

};
#endif //FINAL_PROJECT_DICTIONARY_H
