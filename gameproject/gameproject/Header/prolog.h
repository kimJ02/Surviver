#pragma once
#include <iostream>
#include <string>
using namespace std;

class prolog
{
public:
	string name;
	string enter;
	void print_prolog()
	{
		cout << "프롤로그: 프로젝트의 시작" << endl;
		cout << "이름을 입력하세요 : ";
		getline(cin, name);
		system("cls");

		cout << " 어… 나 지금 뭘 해야 하지? " << endl;
		cout << " 나는 대학교 3학년 " << name << "," << endl;
		cout << " 객체지향 프로그래밍 수업으로 프로젝트를 하게 됐다. 이번에 게임을 만든다고? " << endl;
		cout << " 이거 정말 멋진 일이긴 한데, 솔직히 걱정도 돼. 내가 게임을 만든다고? 내가 그냥 게임만 하는 사람인데... " << endl;
		cout << " 음, 뭐, 일단 팀원들이랑 잘 협력하면 되겠지? " << endl;
		cout << " 내가 속한 팀은 정말 다양한 개성을 가진 사람들로 이루어져 있다. 그리고 그들이 모두 특별한 역할을 맡고 있어서, 나도 하나씩 맡아 해야 할 일이 많다. " << endl;
		cout << " 매일매일 결정해야 하는 순간들이 다가오고, 그 선택에 따라 프로젝트가 성공할 수도, 망할 수도 있다. 팀워크가 중요하다고 하는데... 그게 말처럼 쉬운 일이 아니겠지? " << endl;

		cout << " ENTER ";
		getline(cin, enter);
		if (enter.empty())
		{
			system("cls");
		}

		cout << " 우리 팀원을 소개할게. " << endl;
		cout << " 민준 : 우리 팀의 리더! 항상 차분하고 논리적이어서, 위기 상황에서도 침착하게 대처한다. 자주 내가 '민준이 진짜 리더답다' 싶을 때가 많다." << endl;
		cout << " 금비 : 분석가로서 항상 데이터를 꼼꼼하게 체크하는 금비는 문제를 빠르게 파악하고 해결하는 데 능숙하다. 덕분에 프로젝트 진행이 한결 수월해진다." << endl;
		cout << " 영환 : 디자인 담당. 창의력 넘치는 친구라서 시각적인 요소를 맡고 있다. 때로는 너무 자유로운 사고를 해서 의견 충돌이 있긴 하지만, 그만큼 뛰어난 해결사이기도 하다." << endl;
		cout << " 민성 : 기술 담당. 코드와 버그 수정에 능한 친구로, 항상 빠르게 문제를 해결하려고 한다. 그 덕분에 프로젝트가 순조롭게 진행된다." << endl;

		cout << endl;
		cout << endl;
		cout << endl;

		cout << "자 그럼 팀원들과 프로젝트 시작해볼까?" << endl;

		cout << " ENTER ";
		getline(cin, enter);
		if (enter.empty())
		{
			system("cls");
		}

	};

};
