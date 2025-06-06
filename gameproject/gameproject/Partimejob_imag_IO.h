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

    // �ؽ�Ʈ ������ �� ������ �о� vector<string>�� �����Ͽ� ��ȯ

    inline vector<string> readLines(const string& filepath)
    {
        vector<string> lines;
        ifstream in(filepath);
        if (!in.is_open())
            cerr << "Error ���� ���� ����: " << filepath << endl;
        return lines;

        string line;
        // text���� �� �ּ�ó��
        while (getline(in, line)) {
            // 1) �յ� ���� �����
            string t = trim(line);
            // 2) �� �� �Ǵ� #�̳� // �� �����ϸ� ����
            if (t.empty() || t.rfind("#", 0) == 0 || t.rfind("//", 0) == 0)
                continue;
            lines.push_back(line);
        }
        return lines;
    }

    // �ؽ�Ʈ ���� ��ü�� �� ���� �о� �ֿܼ� ���
    // FileIO::printFile("Story/Day_per_20.txt");
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

        // 1) ������ �� ������ �о �ּ� ��(# �Ǵ� //)�� ����
        vector<string> filtered;
        string line;
        while (getline(in, line)) {
            string t = trim(line);             // �յ� ���� ����
            if (t.empty() || t.rfind("#", 0) == 0    // # �� �����ϰų�
                || t.rfind("//", 0) == 0)      // // �� �����ϸ�
                continue;                           // -> �ǳʶٱ�
            filtered.push_back(line);
        }

        // 2) ���� ���ε��� �ϳ��� ���ڿ��� ��ġ��
        std::ostringstream buf;
        for (auto& l : filtered) buf << l << '\n';
        std::string content = buf.str();

        // 3) ��ħǥ('.') �������� ���� �и�
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

    // ���� ���
    // FileIO::printSentenceAt("TextFile/test1.txt", 0); ���·� ��� ����

    inline void printSentenceAt(const string& filepath, size_t index)
    {
        UINT originalCP = GetConsoleOutputCP(); // ������ ���ڿ� ��� ��� ����
        SetConsoleOutputCP(CP_UTF8); // ���ڿ� ��� ���� UTF-8 �������� ����
        auto sentences = readSentences(filepath);
        if (index < sentences.size()) {
            cout << sentences[index] << endl;
        }
        else {
            cerr << "Error ���� �ε��� ���� �ʰ�: " << index << endl;
        }
        SetConsoleOutputCP(originalCP); // �ٽ� ������ ���ڿ� ��� ������� �ٲ�
    }
}