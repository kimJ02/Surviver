#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

namespace FileIO {

    // 문자열 앞뒤 공백 제거 함수

    static inline string trim(const string& s)
    {
        auto ws_front = find_if_not(s.begin(), s.end(), ::isspace);
        auto ws_back = find_if_not(s.rbegin(), s.rend(), ::isspace).base();
        return (ws_front < ws_back ? string(ws_front, ws_back) : string());
    }


    // 텍스트 파일을 줄 단위로 읽어 vector<string>에 저장하여 반환

    inline vector<string> readLines(const string& filepath)
    {
        vector<string> lines;
        ifstream in(filepath);
        if (!in.is_open()) {
            cerr << "Error 파일 열기 실패: " << filepath << endl;
            return lines;
        }
        string line;
        while (getline(in, line)) {
            lines.push_back(line);
        }
        return lines;
    }

    // 텍스트 파일 전체를 한 번에 읽어 콘솔에 출력

    inline void printFile(const string& filepath)
    {
        ifstream in(filepath);
        if (!in.is_open()) {
            cerr << "Error 파일 열기 실패: " << filepath << endl;
            return;
        }
        string line;
        while (getline(in, line)) {
            cout << line << endl;
        }
    }

    // 텍스트 파일 전체를 읽어 마침표로 분리하여 반환, 느낌표나 물음표 추가 예정

    inline vector<string> readSentences(const string& filepath)
    {
        ifstream in(filepath);
        vector<string> sentences;
        if (!in.is_open()) {
            cerr << "Error 파일 열기 실패: " << filepath << endl;
            return sentences;
        }
        ostringstream buf;
        buf << in.rdbuf();
        string content = buf.str();

        istringstream ss(content);
        string part;
        while (getline(ss, part, '.')) {
            string s = trim(part);
            if (!s.empty()) {
                sentences.push_back(s + ".");
            }
        }
        return sentences;
    }

    // 문장 출력
    // FileIO::printSentenceAt("TextFile/test1.txt", 0); 형태로 사용 가능

    inline void printSentenceAt(const string& filepath, size_t index)
    {
        auto sentences = readSentences(filepath);
        if (index < sentences.size()) {
            cout << sentences[index] << endl;
        }
        else {
            cerr << "Error 문장 인덱스 범위 초과: " << index << endl;
        }
    }
}
