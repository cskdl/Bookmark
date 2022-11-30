#include"Bookmark.h"

void Bookmark::saveurl() {
	string URL;	//임시로 주소를 담은 문자열을 가지고 있을 변수
	cin >> URL;

	fstream writeFile(filepath, ios::app);	//뒤에 덧붙여쓸 수 있도록 열기

	writeFile << URL << endl;	//주소 저장
	urls.push_back(URL);	//벡터에도 맨 뒤에 주소 저장
	writeFile.close();
	return;		//string형태일 필요가 없어서 void로 수정
}

void Bookmark::savename() {
	string explain;	//임시로 주소 설명을 담을 문자열 변수
	cin.ignore(100, '\n');
	getline(cin, explain);	//주소 설명은 띄어쓰기를 포함할 수 있어야 함

	ofstream writeFile(filepath, ios::app);;
	writeFile << explain << endl;
	urls.push_back(explain);
	writeFile.close();
	return;
}

void Bookmark::drawselect() {
	system("cls");
	//저장된 북마크가 3개 이상
	if (urls.size() - this->index >= 5) {
		cout << urls.at(index) << endl << endl
			<< urls.at(index + 2) << endl << endl
			<< urls.at(index + 4) << endl << endl;
	}
	//저장된 북마크가 3개 미만일 시 3개를 출력하려고 하면 에러 발생
	//저장된 북마크가 2개라면 2개만 출력
	else if (urls.size() - this->index >= 3) {
		cout << urls.at(index) << endl << endl
			<< urls.at(index + 2) << endl << endl;
	}
	//저장된 북마크 2개 미만시 1개 출력
	else {
		cout << urls.at(index) << endl << endl;
	}

	gotoxy(0, 10);
	//유저 도움말 역할
	cout << "이동-위아래 화살표키 입력" << endl <<
		"선택-enter키 입력" << endl <<
		"추가-'s'키 입력" << endl <<
		"제거-'d'키 입력" << endl <<
		"수정-'a'키 입력" << endl <<
		"종료-'x'키 입력" << endl << endl <<
		"※이 안내가 보이지 않는 경우에 x키로 종료할 수 없습니다." << endl <<
		"※입력이 무시될 경우 한영키를 한 번 눌러주세요" << endl;
}

void Bookmark::saveboth() {
	//url저장, 주소 설명 저장 순서
	system("cls");
	cout << "저장할 url을 복붙하세요: ";
	saveurl();
	cout << "사이트 설명을 적어주세요(한애고 공식 홈피): ";
	savename();
	//저장이 끝나면 기본 화면으로 이동
	//printscreen();
	return;
}

void Bookmark::deleteurl() {
	system("cls");
	//제발 한 번은 물어봐줬으면해서 추가
	cout << "정말 삭제하시겠습니까?" << endl <<
		"네(enter) / 아니요(backspace)" << endl;
	fstream overwriteF;
	int temp_input;
	for (;;) {
		temp_input = _getch();
		//backspace
		if (temp_input == 8) break;
		//enter
		else if (temp_input == 13) {
			//커서 위치에 따라 삭제해야하는 북마크가 바뀜
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
				//이러면 오류
			default:
				break;
			}
			//벡터에서 지우기
			urls.erase(urls.begin() + URL_i);
			urls.erase(urls.begin() + URL_i);
			//벡터의 요소들로 덮어쓰기
			overwriteF.open(filepath, ios::out);
			for (int i = 0; i < urls.size(); i++) {
				if (urls.at(i) != "")
					overwriteF << urls.at(i) << endl;
			}
			break;
		}
		else continue;
	}
	//북마크가 하나 있었던 거 아니면 2칸 앞(북마크 기준으로는 하나 앞) 가리키기
	if (index != 1) index -= 2;
	//하나였으면 새로 생성
	else saveboth();
	overwriteF.close();
	//맨 끝을 가리키고 있었으면 커서 다시 가운데로 올리기
	if (full == 1) full = 0;
	return;
}

void Bookmark::amendBookmark() {
	system("cls");
	gotoxy(0, 0);
	//멤버의 인덱스로 하면 마우스 포인터와 관련해 수정해줬다가 다시 되돌려놔야 함
	int temp_index;
	if (full == -1) temp_index = index;
	else if (full == 0) temp_index = index + 2;
	else if (full == 1) temp_index = index + 4;
	else return;
	//선택했던 북마크 보여줌(사용자가 잘못 수정하는 거 방지)
	cout << "선택된 북마크" << endl <<
		"URL : " << urls[index - 1] << endl <<
		"주소 설명 : " << urls[index] << endl;
	gotoxy(0, 8);
	//변경내용 선택
	cout << "주소(URL) 변경" << endl <<
		"주소 설명 변경" << endl <<
		"수정 취소" << endl;
	gotoxy(0, 8);
	int temp_input, temp_pos = 1;
	string temp;
	for (;;) {
		temp_input = _getch();
		//backspace
		if (temp_input == 8) return;
		//enter
		else if (temp_input == 13) {
			//주소(URL)변경
			if (temp_pos == 1) {
				gotoxy(0, 0);
				system("cls");
				cout << urls[temp_index] << "에 저장할 주소를 다시 입력해주세요 : ";
				cin >> temp;

				cout << "진짜 수정하시겠습니까?" << endl <<
					"네(Enter) / 아니요(Backspace)" << endl;
				temp_input = _getch();
				for (;;) {
					temp_input = _getch();
					//엔터(수정 확인)
					if (temp_input == 13) {
						//벡터 값 변경
						urls[temp_index - 1] = temp;
						//외부파일 변경
						fstream overwriteF;
						overwriteF.open(filepath, ios::out);
						for (int i = 0; i < urls.size(); i++) {
							if (urls.at(i) != "")
								overwriteF << urls.at(i) << endl;
						}
						return;
					}
					//백스페이스(수정 취소)
					else if (temp_input == 8) return;
					else continue;
				}
			}
			//주소설명변경
			else if (temp_pos == 2) {
				gotoxy(0, 0);
				system("cls");
				cout << urls[temp_index] << "를 대체할 설명을 다시 입력해주세요 : ";
				cin.clear();
				getline(cin, temp);

				cout << "진짜 수정하시겠습니까?" << endl <<
					"네(Enter) / 아니요(Backspace)" << endl;

				for (;;) {
					temp_input = _getch();
					//엔터
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
					//백스페이스
					else if (temp_input == 8) return;
					else continue;
				}
			}
			//수정취소
			else if (temp_pos == 3) return;
			else continue;
		}
		//화살표
		else if (temp_input == 224) {
			temp_input = _getch();
			//위쪽 화살표
			if (temp_input == 72 && temp_pos > 1) {
				gotoxy(0, (temp_pos + 6));
				temp_pos--;
			}
			//아래쪽 화살표
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
	//x누르면 종료
	while (input != 'x') {
		if (input == 224) {
			input = _getch();
			//위쪽 화살표
			//북마크 중간에서
			if (input == 72 && index != 1 && full != -1 && full != 1) {
				system("cls");
				index -= 2;
				gotoxy(0, 0);
				drawselect();
				gotoxy(0, 2);
				full = 0;
			}
			//마우스 포인터는 2번째 위치
			else if (input == 72 && index == 1 && full == 0) {
				gotoxy(0, 0);
				full = -1;
			}
			//맨 밑
			else if (input == 72 && index != 1 && full == 1) {
				gotoxy(0, 2);
				full = 0;
			}

			//아래쪽 화살표
			//size()는 메모장 길이와 동일(한 문장이 1을 차지)
			//인데 왜...... 범위를 넘어간다고 나오지
			//bookmarks.size() == 6일 때, index가 1부터 시작하니까...... ...
			//else if (input == 80 && (index + 4) <= bookmarks.size()) {
			//이게 왜 됨?

			//아래쪽 화살표
			//북마크 중간
			else if (input == 80 && (index + 5) <= urls.size() && full != -1) {
				system("cls");
				index += 2;
				gotoxy(0, 0);
				drawselect();
				gotoxy(0, 2);
				full = 0;
			}
			//맨 위
			else if (input == 80 && (index + 3) <= urls.size() && full == -1) {
				gotoxy(0, 2);
				full = 0;
			}
			//마우스 포인터가 뒤에서 2번째
			else if (input == 80 && (index + 5) == urls.size() && full == 0) {
				gotoxy(0, 4);
				full = 1;
			}
		}
		//엔터키 입력시 이동
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
			//이동할 url저장
			string URL = urls.at(URL_i);
			wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
			wstring wide = converter.from_bytes(URL);
			LPCWSTR _URL = wide.c_str();
			//chrome으로 주소 이동
			ShellExecute(NULL, L"open", L"chrome.exe", _URL, NULL, SW_SHOWNORMAL);
		}
		//s로 저장
		else if (input == 's') {
			saveboth();
			drawselect();
			if (full == -1) gotoxy(0, 0);
			else gotoxy(0, 2);
		}
		//d로 제거
		else if (input == 'd') {
			deleteurl();
			drawselect();
			if (full == -1) gotoxy(0, 0);
			else gotoxy(0, 2);
		}
		//a로 수정
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
	//파일이 없거나 파일은 있는데 비어있다면 새로 생성
	if (!readFile.is_open() || readFile.peek() == ifstream::traits_type::eof()) {
		cout << "unable to find file" << endl << "새롭게 북마크를 생성해주세요" << endl;
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
	//일단 실행해서 파일 나열되는 건 얘 때문이었음
	/*for (int j = 0; j < urls.size(); j += 2) {
		cout << urls[j] << endl;
	}*/
	readFile.close();
	return;
}