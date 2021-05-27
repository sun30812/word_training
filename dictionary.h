﻿#ifndef FINAL_PROJECT_DICTIONARY_H
#define FINAL_PROJECT_DICTIONARY_H
#include <iostream>
using namespace std;
// 모든 사전관련 클래스 들의 부모입니다. 각 함수에 대한 설명은
// cpp소스파일을 봐주세요
class Dictionary {
protected:
    int data_length;
    string* words;
    string* means;
    Dictionary(int data_length);
    int search(const string& word);
    ~Dictionary();

public:
    bool search(const string& word, string& result);
    void printAll();
};

// 영어 단어장 기능을 담당하는 클래스입니다. 해당 클래스는 매개변수를 통해
// 이미 정의된 단어 목록을 불러올 수도 있습니다.
// 각 함수에 대한 설명은 cpp소스파일을 봐주세요
class EnglishDictionary : public Dictionary {
public:
    EnglishDictionary(int data_length=0);
    EnglishDictionary(int data_length, string words[], string means[]);
    bool add(const string& word, const string& meaning);
    bool modify(const string &word, const string& new_meaning);
    bool operator-=(const string& word);

};
#endif //FINAL_PROJECT_DICTIONARY_H
