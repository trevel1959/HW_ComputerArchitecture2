#include<iostream>
#include<string>
#include<vector>
#include<ctime>
using namespace std;

void showMenu();
void inputData();
double random(vector<int>& input, int slot);

int main() {
	showMenu();
}

void showMenu() {
	int menu;
	do {
		cout << "1.시작\n2.종료" << endl;
		cout << "메뉴 입력 ▶ ";
		cin >> menu;
		switch (menu) {
		case 1:
			inputData();
			break;
		case 2:
			cout << "프로그램을 종료합니다." << endl;
			break;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	} while (menu != 2);
}

void inputData() {
	int slot, data; // 세트 당 슬롯의 개수, 입력 데이터의 개수
	cout << "세트 당 슬롯의 개수를 입력해주세요 ▶ ";
	cin >> slot;
	cout << "입력 데이터의 개수를 입력해주세요 ▶ ";
	cin >> data;
	vector<int> input; // 데이터 저장 백터
	for (int i = 0; i < data; i++) {
		cout << "데이터 " << i + 1 << " ▶ ";
		int num;
		cin >> num;
		input.push_back(num);
	}
	cout << "랜덤 적중률 : " << random(input, slot) << endl;
}

double random(vector<int>& input, int slot) {
	srand((unsigned int)time(NULL));
	vector<int> set;
	int hit = 0;
	for (int i = 0; i < input.size(); i++) { // input 개수만큼 반복
		int now = input.at(i);
		if (set.size() == 0) { // 캐시가 비었을 때
			set.push_back(input.at(i));
		}
		else { // 캐시가 비어있지 않을 때
			for (int j = 0; j < set.size(); j++) { // 캐시를 확인
				if (set.at(j) == now) { // 적중
					hit++;
					break;
				}
				if (j == set.size() - 1) { // 적중하지 않았을 때
					if (set.size() < slot) { // 캐시에 빈 슬롯이 있을 때
						set.push_back(now);
						break;
					}
					else { // 빈 슬롯이 없을 때 랜덤으로 위치
						set.at(rand() % set.size()) = now;
						break;
					}
				}
			}
		}
	}
	return (double)hit / input.size();
}