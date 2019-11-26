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
		cout << "1.����\n2.����" << endl;
		cout << "�޴� �Է� �� ";
		cin >> menu;
		switch (menu) {
		case 1:
			inputData();
			break;
		case 2:
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
	} while (menu != 2);
}

void inputData() {
	int slot, data; // ��Ʈ �� ������ ����, �Է� �������� ����
	cout << "��Ʈ �� ������ ������ �Է����ּ��� �� ";
	cin >> slot;
	cout << "�Է� �������� ������ �Է����ּ��� �� ";
	cin >> data;
	vector<int> input; // ������ ���� ����
	for (int i = 0; i < data; i++) {
		cout << "������ " << i + 1 << " �� ";
		int num;
		cin >> num;
		input.push_back(num);
	}
	cout << "���� ���߷� : " << random(input, slot) << endl;
}

double random(vector<int>& input, int slot) {
	srand((unsigned int)time(NULL));
	vector<int> set;
	int hit = 0;
	for (int i = 0; i < input.size(); i++) { // input ������ŭ �ݺ�
		int now = input.at(i);
		if (set.size() == 0) { // ĳ�ð� ����� ��
			set.push_back(input.at(i));
		}
		else { // ĳ�ð� ������� ���� ��
			for (int j = 0; j < set.size(); j++) { // ĳ�ø� Ȯ��
				if (set.at(j) == now) { // ����
					hit++;
					break;
				}
				if (j == set.size() - 1) { // �������� �ʾ��� ��
					if (set.size() < slot) { // ĳ�ÿ� �� ������ ���� ��
						set.push_back(now);
						break;
					}
					else { // �� ������ ���� �� �������� ��ġ
						set.at(rand() % set.size()) = now;
						break;
					}
				}
			}
		}
	}
	return (double)hit / input.size();
}