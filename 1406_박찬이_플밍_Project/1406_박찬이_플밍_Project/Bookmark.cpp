#include"Bookmark.h"

void Bookmark::saveurl() {
	string URL;	//�ӽ÷� �ּҸ� ���� ���ڿ��� ������ ���� ����
	cin >> URL;

	fstream writeFile(filepath, ios::app);	//�ڿ� ���ٿ��� �� �ֵ��� ����

	writeFile << URL << endl;	//�ּ� ����
	urls.push_back(URL);	//���Ϳ��� �� �ڿ� �ּ� ����
	writeFile.close();
	return;		//string������ �ʿ䰡 ��� void�� ����
}

void Bookmark::savename() {
	string explain;	//�ӽ÷� �ּ� ������ ���� ���ڿ� ����
	cin.ignore(100, '\n');
	getline(cin, explain);	//�ּ� ������ ���⸦ ������ �� �־�� ��

	ofstream writeFile(filepath, ios::app);;
	writeFile << explain << endl;
	urls.push_back(explain);
	writeFile.close();
	return;
}

void Bookmark::drawselect() {
	system("cls");
	//����� �ϸ�ũ�� 3�� �̻�
	if (urls.size() - this->index >= 5) {
		cout << urls.at(index) << endl << endl
			<< urls.at(index + 2) << endl << endl
			<< urls.at(index + 4) << endl << endl;
	}
	//����� �ϸ�ũ�� 3�� �̸��� �� 3���� ����Ϸ��� �ϸ� ���� �߻�
	//����� �ϸ�ũ�� 2����� 2���� ���
	else if (urls.size() - this->index >= 3) {
		cout << urls.at(index) << endl << endl
			<< urls.at(index + 2) << endl << endl;
	}
	//����� �ϸ�ũ 2�� �̸��� 1�� ���
	else {
		cout << urls.at(index) << endl << endl;
	}

	gotoxy(0, 10);
	//���� ���� ����
	cout << "�̵�-���Ʒ� ȭ��ǥŰ �Է�" << endl <<
		"����-enterŰ �Է�" << endl <<
		"�߰�-'s'Ű �Է�" << endl <<
		"����-'d'Ű �Է�" << endl <<
		"����-'a'Ű �Է�" << endl <<
		"����-'x'Ű �Է�" << endl << endl <<
		"���� �ȳ��� ������ �ʴ� ��쿡 xŰ�� ������ �� �����ϴ�." << endl <<
		"���Է��� ���õ� ��� �ѿ�Ű�� �� �� �����ּ���" << endl;
}

void Bookmark::saveboth() {
	//url����, �ּ� ���� ���� ����
	system("cls");
	cout << "������ url�� �����ϼ���: ";
	saveurl();
	cout << "����Ʈ ������ �����ּ���(�Ѿְ� ���� Ȩ��): ";
	savename();
	//������ ������ �⺻ ȭ������ �̵�
	//printscreen();
	return;
}

void Bookmark::deleteurl() {
	system("cls");
	//���� �� ���� ������������ؼ� �߰�
	cout << "���� �����Ͻðڽ��ϱ�?" << endl <<
		"��(enter) / �ƴϿ�(backspace)" << endl;
	fstream overwriteF;
	int temp_input;
	for (;;) {
		temp_input = _getch();
		//backspace
		if (temp_input == 8) break;
		//enter
		else if (temp_input == 13) {
			//Ŀ�� ��ġ�� ���� �����ؾ��ϴ� �ϸ�ũ�� �ٲ�
			int URL_i;
			switch (full) {
			case -1:
				URL_i = index - 1;
				break;
			case 0:
				URL_i = index + 1;
				break;
			case 1:
				URL_i = index + 3;
				break;
				//�̷��� ����
			default:
				break;
			}
			//���Ϳ��� �����
			urls.erase(urls.begin() + URL_i);
			urls.erase(urls.begin() + URL_i);
			//������ ��ҵ�� �����
			overwriteF.open(filepath, ios::out);
			for (int i = 0; i < urls.size(); i++) {
				if (urls.at(i) != "")
					overwriteF << urls.at(i) << endl;
			}
			break;
		}
		else continue;
	}
	//�ϸ�ũ�� �ϳ� �־��� �� �ƴϸ� 2ĭ ��(�ϸ�ũ �������δ� �ϳ� ��) ����Ű��
	if (index != 1) index -= 2;
	//�ϳ������� ���� ����
	else saveboth();
	overwriteF.close();
	//�� ���� ����Ű�� �־����� Ŀ�� �ٽ� ����� �ø���
	if (full == 1) full = 0;
	return;
}

void Bookmark::amendBookmark() {
	system("cls");
	gotoxy(0, 0);
	//����� �ε����� �ϸ� ���콺 �����Ϳ� ������ ��������ٰ� �ٽ� �ǵ������� ��
	int temp_index;
	if (full == -1) temp_index = index;
	else if (full == 0) temp_index = index + 2;
	else if (full == 1) temp_index = index + 4;
	else return;
	//�����ߴ� �ϸ�ũ ������(����ڰ� �߸� �����ϴ� �� ����)
	cout << "���õ� �ϸ�ũ" << endl <<
		"URL : " << urls[index - 1] << endl <<
		"�ּ� ���� : " << urls[index] << endl;
	gotoxy(0, 8);
	//���泻�� ����
	cout << "�ּ�(URL) ����" << endl <<
		"�ּ� ���� ����" << endl <<
		"���� ���" << endl;
	gotoxy(0, 8);
	int temp_input, temp_pos = 1;
	string temp;
	for (;;) {
		temp_input = _getch();
		//backspace
		if (temp_input == 8) return;
		//enter
		else if (temp_input == 13) {
			//�ּ�(URL)����
			if (temp_pos == 1) {
				gotoxy(0, 0);
				system("cls");
				cout << urls[temp_index] << "�� ������ �ּҸ� �ٽ� �Է����ּ��� : ";
				cin >> temp;

				cout << "��¥ �����Ͻðڽ��ϱ�?" << endl <<
					"��(Enter) / �ƴϿ�(Backspace)" << endl;
				temp_input = _getch();
				for (;;) {
					temp_input = _getch();
					//����(���� Ȯ��)
					if (temp_input == 13) {
						//���� �� ����
						urls[temp_index - 1] = temp;
						//�ܺ����� ����
						fstream overwriteF;
						overwriteF.open(filepath, ios::out);
						for (int i = 0; i < urls.size(); i++) {
							if (urls.at(i) != "")
								overwriteF << urls.at(i) << endl;
						}
						return;
					}
					//�齺���̽�(���� ���)
					else if (temp_input == 8) return;
					else continue;
				}
			}
			//�ּҼ�����
			else if (temp_pos == 2) {
				gotoxy(0, 0);
				system("cls");
				cout << urls[temp_index] << "�� ��ü�� ������ �ٽ� �Է����ּ��� : ";
				cin.clear();
				getline(cin, temp);

				cout << "��¥ �����Ͻðڽ��ϱ�?" << endl <<
					"��(Enter) / �ƴϿ�(Backspace)" << endl;

				for (;;) {
					temp_input = _getch();
					//����
					if (temp_input == 13) {
						urls[temp_index] = temp;
						fstream overwriteF;
						overwriteF.open(filepath, ios::out);
						for (int i = 0; i < urls.size(); i++) {
							if (urls.at(i) != "")
								overwriteF << urls.at(i) << endl;
						}
						return;
					}
					//�齺���̽�
					else if (temp_input == 8) return;
					else continue;
				}
			}
			//�������
			else if (temp_pos == 3) return;
			else continue;
		}
		//ȭ��ǥ
		else if (temp_input == 224) {
			temp_input = _getch();
			//���� ȭ��ǥ
			if (temp_input == 72 && temp_pos > 1) {
				gotoxy(0, (temp_pos + 6));
				temp_pos--;
			}
			//�Ʒ��� ȭ��ǥ
			else if (temp_input == 80 && temp_pos < 3) {
				gotoxy(0, (temp_pos + 8));
				temp_pos++;
			}
		}
		//temp_input = _getch();
	}
}

void Bookmark::printscreen() {
	system("cls");
	ifstream readFile(filepath);
	filelist();
	gotoxy(0, 0);
	drawselect();
	gotoxy(0, 0);
	input = _getch();
	//x������ ����
	while (input != 'x') {
		if (input == 224) {
			input = _getch();
			//���� ȭ��ǥ
			//�ϸ�ũ �߰�����
			if (input == 72 && index != 1 && full != -1 && full != 1) {
				system("cls");
				index -= 2;
				gotoxy(0, 0);
				drawselect();
				gotoxy(0, 2);
				full = 0;
			}
			//���콺 �����ʹ� 2��° ��ġ
			else if (input == 72 && index == 1 && full == 0) {
				gotoxy(0, 0);
				full = -1;
			}
			//�� ��
			else if (input == 72 && index != 1 && full == 1) {
				gotoxy(0, 2);
				full = 0;
			}

			//�Ʒ��� ȭ��ǥ
			//size()�� �޸��� ���̿� ����(�� ������ 1�� ����)
			//�ε� ��...... ������ �Ѿ�ٰ� ������
			//bookmarks.size() == 6�� ��, index�� 1���� �����ϴϱ�...... ...
			//else if (input == 80 && (index + 4) <= bookmarks.size()) {
			//�̰� �� ��?

			//�Ʒ��� ȭ��ǥ
			//�ϸ�ũ �߰�
			else if (input == 80 && (index + 5) <= urls.size() && full != -1) {
				system("cls");
				index += 2;
				gotoxy(0, 0);
				drawselect();
				gotoxy(0, 2);
				full = 0;
			}
			//�� ��
			else if (input == 80 && (index + 3) <= urls.size() && full == -1) {
				gotoxy(0, 2);
				full = 0;
			}
			//���콺 �����Ͱ� �ڿ��� 2��°
			else if (input == 80 && (index + 5) == urls.size() && full == 0) {
				gotoxy(0, 4);
				full = 1;
			}
		}
		//����Ű �Է½� �̵�
		else if (input == 13) {
			int URL_i;
			switch (full) {
			case -1:
				URL_i = index - 1;
				break;
			case 0:
				URL_i = index + 1;
				break;
			case 1:
				URL_i = index + 3;
				break;
			default:
				break;
			}
			//�̵��� url����
			string URL = urls.at(URL_i);
			wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
			wstring wide = converter.from_bytes(URL);
			LPCWSTR _URL = wide.c_str();
			//chrome���� �ּ� �̵�
			ShellExecute(NULL, L"open", L"chrome.exe", _URL, NULL, SW_SHOWNORMAL);
		}
		//s�� ����
		else if (input == 's') {
			saveboth();
			drawselect();
			if (full == -1) gotoxy(0, 0);
			else gotoxy(0, 2);
		}
		//d�� ����
		else if (input == 'd') {
			deleteurl();
			drawselect();
			if (full == -1) gotoxy(0, 0);
			else gotoxy(0, 2);
		}
		//a�� ����
		else if (input == 'a') {
			amendBookmark();
			drawselect();
			if (full == -1) gotoxy(0, 0);
			else gotoxy(0, 2);
		}
		input = _getch();
	}
	return;
}

void Bookmark::filelist() {
	ifstream readFile(filepath);
	string s;
	//������ ���ų� ������ �ִµ� ����ִٸ� ���� ����
	if (!readFile.is_open() || readFile.peek() == ifstream::traits_type::eof()) {
		cout << "unable to find file" << endl << "���Ӱ� �ϸ�ũ�� �������ּ���" << endl;
		system("pause");
		Bookmark::saveboth();
	}
	/*while (!readFile.eof()) {
		urls.resize(i);
		getline(readFile, urls.at(i - 1));
		i++;
	}*/
	while (std::getline(readFile, s)) {
		urls.push_back(s);
	}
	//�ϴ� �����ؼ� ���� �����Ǵ� �� �� �����̾���
	/*for (int j = 0; j < urls.size(); j += 2) {
		cout << urls[j] << endl;
	}*/
	readFile.close();
	return;
}