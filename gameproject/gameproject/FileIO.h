#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

namespace FileIO {

    // ���ڿ� �յ� ���� ���� �Լ�

    static inline string trim(const string& s)
    {
        auto ws_front = find_if_not(s.begin(), s.end(), ::isspace);
        auto ws_back = find_if_not(s.rbegin(), s.rend(), ::isspace).base();
        return (ws_front < ws_back ? string(ws_front, ws_back) : string());
    }


    // �ؽ�Ʈ ������ �� ������ �о� vector<string>�� �����Ͽ� ��ȯ

    inline vector<string> readLines(const string& filepath)
    {
        vector<string> lines;
        ifstream in(filepath);
        if (!in.is_open()) {
            cerr << "Error ���� ���� ����: " << filepath << endl;
            return lines;
        }
        string line;
        while (getline(in, line)) {
            lines.push_back(line);
        }
        return lines;
    }

    // �ؽ�Ʈ ���� ��ü�� �� ���� �о� �ֿܼ� ���

    inline void printFile(const string& filepath)
    {
        ifstream in(filepath);
        if (!in.is_open()) {
            cerr << "Error ���� ���� ����: " << filepath << endl;
            return;
        }
        string line;
        while (getline(in, line)) {
            cout << line << endl;
        }
    }

    // �ؽ�Ʈ ���� ��ü�� �о� ��ħǥ�� �и��Ͽ� ��ȯ, ����ǥ�� ����ǥ �߰� ����

    inline vector<string> readSentences(const string& filepath)
    {
        ifstream in(filepath);
        vector<string> sentences;
        if (!in.is_open()) {
            cerr << "Error ���� ���� ����: " << filepath << endl;
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

    // ���� ���
    // FileIO::printSentenceAt("TextFile/test1.txt", 0); ���·� ��� ����

    inline void printSentenceAt(const string& filepath, size_t index)
    {
        auto sentences = readSentences(filepath);
        if (index < sentences.size()) {
            cout << sentences[index] << endl;
        }
        else {
            cerr << "Error ���� �ε��� ���� �ʰ�: " << index << endl;
        }
    }
}
