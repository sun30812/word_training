#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
using namespace std;
// 사전 기능을 수행하기 위한 기본 클래스(부모 클래스)입니다. 각 함수에 대한 설명은
// dictionary.cpp소스파일을 봐주세요(아마 함수에 커서 올려도 나올겁니다.)
class Dictionary {
protected:
    int data_length;
    string* words;
    string* means;
    bool is_dynamic;
    Dictionary(int data_length=0);
    Dictionary(int data_length, string words[], string means[]);
    int search(const string& word);
    ~Dictionary();

public:
    bool search(const string& word, string& result);
    void printAll();
};

// 영어 사전 기능을 수행하는 클래스입니다. 해당 클래스는 매개변수를 통해
// 이미 정의된 단어 목록을 불러올 수도 있습니다.
// 각 함수에 대한 설명은 cpp소스파일을 봐주세요(아마 함수에 커서 올려도 나올겁니다.)
class EnglishDictionary : public Dictionary {
public:
    EnglishDictionary(int data_length=0);
    EnglishDictionary(int data_length, string words[], string means[]);
    bool add(const string& word, const string& meaning);
    bool modify(const string &word, const string& new_meaning);
    bool operator-=(const string& word);

};
#endif
