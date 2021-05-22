#ifndef FINAL_PROJECT_DICTIONARY_H
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
    ~Dictionary();

public:
    virtual bool search(const string& key, string& result);
    virtual int search(const string& key);
    virtual void printAll();
};

// 영어 단어장 기능을 담당하는 클래스입니다. 각 함수에 대한 설명은
// cpp소스파일을 봐주세요
class EnglishDictionary : public Dictionary {
public:
    EnglishDictionary(int data_length);
    void add(const string& word, const string& meaning);
    bool modify(const string& key);
    void operator-=(const string& word);
    int getLength();

};
#endif //FINAL_PROJECT_DICTIONARY_H
