#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <windows.h>
using namespace std;

namespace PartTimeJob_imagIO {

    static inline string trim(const string& s) {
        auto is_space = [](char ch) {
            return isspace(static_cast<unsigned char>(ch));
            };
        auto ws_front = find_if_not(s.begin(), s.end(), is_space);
        auto ws_back = find_if_not(s.rbegin(), s.rend(), is_space).base();
        return (ws_front < ws_back ? string(ws_front, ws_back) : string());
    }

    // 텍스트 파일을 줄 단위로 읽어 vector<string>에 저장하여 반환

    inline vector<string> readLines(const string& filepath)
    {
        vector<string> lines;
        ifstream in(filepath);
        if (!in.is_open())
            cerr << "Error 파일 열기 실패: " << filepath << endl;
        return lines;

        string line;
        // text파일 내 주석처리
        while (getline(in, line)) {
            // 1) 앞뒤 공백 지우고
            string t = trim(line);
            // 2) 빈 줄 또는 #이나 // 로 시작하면 무시
            if (t.empty() || t.rfind("#", 0) == 0 || t.rfind("//", 0) == 0)
                continue;
            lines.push_back(line);
        }
        return lines;
    }

    // 텍스트 파일 전체를 한 번에 읽어 콘솔에 출력
    // FileIO::printFile("Story/Day_per_20.txt");
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

        // 1) 파일을 줄 단위로 읽어서 주석 줄(# 또는 //)은 무시
        vector<string> filtered;
        string line;
        while (getline(in, line)) {
            string t = trim(line);             // 앞뒤 공백 제거
            if (t.empty() || t.rfind("#", 0) == 0    // # 로 시작하거나
                || t.rfind("//", 0) == 0)      // // 로 시작하면
                continue;                           // -> 건너뛰기
            filtered.push_back(line);
        }

        // 2) 남은 라인들을 하나의 문자열로 합치기
        std::ostringstream buf;
        for (auto& l : filtered) buf << l << '\n';
        std::string content = buf.str();

        // 3) 마침표('.') 기준으로 문장 분리
        std::istringstream ss(content);
        std::string part;
        while (std::getline(ss, part, '.')) {
            std::string s = trim(part);
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
        UINT originalCP = GetConsoleOutputCP(); // 원래의 문자열 출력 방식 저장
        SetConsoleOutputCP(CP_UTF8); // 문자열 출력 형식 UTF-8 형식으로 변경
        auto sentences = readSentences(filepath);
        if (index < sentences.size()) {
            cout << sentences[index] << endl;
        }
        else {
            cerr << "Error 문장 인덱스 범위 초과: " << index << endl;
        }
        SetConsoleOutputCP(originalCP); // 다시 원래의 문자열 출력 방식으로 바꿈
    }
}