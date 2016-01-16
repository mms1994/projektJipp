#include "stdafx.h"
#include "my_interf.h"
#include "node.h"
#include "my_mess.h"


my_interf::my_interf(size_t dim) : vect() {
	sprintf_s(str_interf[MY_INTERF_PUSH], MAX_INTERF_CHAR*sizeof(char), "%d - push", MY_INTERF_PUSH);
	sprintf_s(str_interf[MY_INTERF_POP], MAX_INTERF_CHAR*sizeof(char), "%d - pop", MY_INTERF_POP);
	sprintf_s(str_interf[MY_INTERF_CLEAR], MAX_INTERF_CHAR*sizeof(char), "%d - clear all", MY_INTERF_CLEAR);
	sprintf_s(str_interf[MY_INTERF_MODIFY], MAX_INTERF_CHAR*sizeof(char), "%d - modify", MY_INTERF_MODIFY);
	sprintf_s(str_interf[MY_INTERF_ADD_OBJ], MAX_INTERF_CHAR*sizeof(char), "%d - add object", MY_INTERF_ADD_OBJ);
	sprintf_s(str_interf[MY_INTERF_ADD_TAB_OBJ], MAX_INTERF_CHAR*sizeof(char), "%d - add tab object", MY_INTERF_ADD_TAB_OBJ);
	sprintf_s(str_interf[MY_INTERF_DISP], MAX_INTERF_CHAR*sizeof(char), "%d - disp", MY_INTERF_DISP);
	sprintf_s(str_interf[MY_INTERF_FIND], MAX_INTERF_CHAR*sizeof(char), "%d - find", MY_INTERF_FIND);
	sprintf_s(str_interf[MY_INTERF_REMOVE], MAX_INTERF_CHAR*sizeof(char), "%d - remove", MY_INTERF_REMOVE);
	sprintf_s(str_interf[MY_INTERF_SAVE], MAX_INTERF_CHAR*sizeof(char), "%d - save to file", MY_INTERF_SAVE);
	sprintf_s(str_interf[MY_INTERF_LOAD], MAX_INTERF_CHAR*sizeof(char), "%d - read from file", MY_INTERF_LOAD);
	sprintf_s(str_interf[MY_INTERF_CHANGE], MAX_INTERF_CHAR*sizeof(char), "%d - change", MY_INTERF_CHANGE);
	sprintf_s(str_interf[MY_INTERF_FINISH], MAX_INTERF_CHAR*sizeof(char), "%d - finish", MY_INTERF_FINISH);
	vect.init(dim);
	run = true;
}

void my_interf::menu() {
	system("cls");
	int i;
	cout << "Wybrany tryb to: ";
	if (tryb == 0) cout << "node" << endl;
	else if (tryb == 1) cout << "note" << endl;
	else cout << "blad" << endl;
	for (i = 0; i<MY_INTERF_TOT; i++) {
		cout << str_interf[i] << endl;
	}
}

void my_interf::push() {
	system("cls");
	if (tryb == 0) {
		node nd(0, "", 0, 0);
		cin >> nd;
		vect.push(nd);
	}
	else if (tryb == 1) {
		note nt(0, "");
		cin >> nt;
		vect2.push(nt);
	}
	else {
		msg.mess(WARN_ARR_UNKN);
	}
}

void my_interf::pop() {
	system("cls");
	if (tryb == 0) {
		node *nd = nullptr;
		nd = vect.pop();
		if (nd) {
			cout << *nd;
		}
		else {
			msg.mess(WARN_ARR_EMPT);
		}
	}
	else if (tryb == 1) {
		note *nt = nullptr;
		nt = vect2.pop();
		if (nt) {
			cout << *nt;
		}
		else {
			msg.mess(WARN_ARR_EMPT);
		}
	}
	else {
		msg.mess(WARN_ARR_UNKN);
	}
	system("pause");
}

void my_interf::disp() {
	system("cls");
	if (tryb == 0)
		vect.disp();
	else if (tryb == 1)
		vect2.disp();
	else
		msg.mess(WARN_ARR_UNKN);
	system("pause");
}

void my_interf::find() {
	system("cls");
	if (tryb == 0) {
		node *begin = nullptr;
		node *end = nullptr;
		begin = vect.get_begin();
		end = vect.get_end();
		node *rez = nullptr;
		cout << "Podaj szukana wartosc" << endl;
		int key;
		cin >> key;
		while (true) {
			rez = Find(begin, end, key);
			if (rez) {
				cout << *rez << endl;
				break;
			}
			if (*begin == *end) {
				cout << "Brak" << endl;
				break;
			}
			else
				begin++;
		}
	}
	else if (tryb == 1) {
		note *begin = nullptr;
		note *end = nullptr;
		begin = vect2.get_begin();
		end = vect2.get_end();
		note *rez = nullptr;
		cout << "Podaj szukana wartosc" << endl;
		int key;
		cin >> key;
		while (true) {
			rez = Find(begin, end, key);
			if (rez) {
				cout << *rez << endl;
				break;
			}
			if (*begin == *end) {
				cout << "Brak" << endl;
				break;
			}
			else
				begin++;
		}
	}
	else
		msg.mess(WARN_ARR_UNKN);
	system("pause");
}

void my_interf::finish() {
	run = false;
}

void my_interf::default() {
	system("cls");
	msg.mess(WARN_ARR_UNKN);
}

void my_interf::remove() {
	system("cls");
	int i;
	cout << "Podaj numer indeksu do usuniecia: ";
	cin >> i;
	if (tryb == 0) {
		vect.remove(i);
		cout << "Usunieto" << endl;
	}
	else if (tryb == 1) {
		vect2.remove(i);
		cout << "Usunieto" << endl;
	}
	else {
		msg.mess(WARN_ARR_UNKN);
	}
	system("pause");
}

void my_interf::save() {
	system("cls");
	cout << "Podaj plik" << endl;
	char str[64];
	cin >> str;
	if (tryb == 0) {
		char str2[68];
		str2[0] = 'n';
		str2[1] = 'o';
		str2[2] = 'd';
		str2[3] = 'e';
		for (int i = 0; i < 64; i++)
			str2[4 + i] = str[i];
		setFileName(str2);
		flout.open(getFileName(), ios_base::out | ios::trunc | ios::binary);
		size_t max = vect.getLast();
		if (!max)
			msg.mess(WARN_ARR_EMPT);
		else if (!flout.is_open())
			msg.mess(ERR_OPEN_FILE);
		else {
			size_t i;
			flout.clear();
			flout.seekp(0);
			for (i = 0; i < max; i++) {
				flout << vect[i];
			}
			flout.clear();
			flout.close();
		}
	}
	else if (tryb == 1) {
		char str2[68];
		str2[0] = 'n';
		str2[1] = 'o';
		str2[2] = 't';
		str2[3] = 'e';
		for (int i = 0; i < 64; i++)
			str2[4 + i] = str[i];
		setFileName(str2);
		flout.open(getFileName(), ios_base::out | ios::trunc | ios::binary);
		size_t max = vect2.getLast();
		if (!max)
			msg.mess(WARN_ARR_EMPT);
		else if (!flout.is_open())
			msg.mess(ERR_OPEN_FILE);
		else {
			size_t i;
			flout.clear();
			flout.seekp(0);
			for (i = 0; i < max; i++) {
				flout << vect2[i];
			}
			flout.clear();
			flout.close();
		}
	}
	else {
		msg.mess(WARN_ARR_UNKN);
	}
	system("pause");
}

void my_interf::load() {
	system("cls");
	cout << "Podaj plik" << endl;
	char str[64];
	cin >> str;
	if (tryb == 0) {
		char str2[68];
		str2[0] = 'n';
		str2[1] = 'o';
		str2[2] = 'd';
		str2[3] = 'e';
		for (int i = 0; i < 64; i++)
			str2[4 + i] = str[i];
		setFileName(str2);
		flinp.open(getFileName(), ios_base::out | ios::binary);
		vect.clear_all();
		int i = 0;
		flinp.clear();
		if (!flinp.is_open())
			msg.mess(ERR_OPEN_FILE);
		else {
			int a = vect.getNdim();
			if (i == a)
				vect.realloc();
			vect.setLast();
			while (flinp >> vect[i]) {
				i++;
				vect.setLast();
				int a = vect.getNdim();
				if (i == a)
					vect.realloc();
			}
			vect.removeLast();
			flinp.clear();
			flinp.close();
		}
	}
	else if (tryb == 1) {
		char str2[68];
		str2[0] = 'n';
		str2[1] = 'o';
		str2[2] = 't';
		str2[3] = 'e';
		for (int i = 0; i < 64; i++)
			str2[4 + i] = str[i];
		setFileName(str2);
		flinp.open(getFileName(), ios_base::out | ios::binary);
		vect2.clear_all();
		int i = 0;
		flinp.clear();
		if (!flinp.is_open())
			msg.mess(ERR_OPEN_FILE);
		else {
			int a = vect2.getNdim();
			if (i == a)
				vect2.realloc();
			vect2.setLast();
			while (flinp >> vect2[i]) {
				i++;
				vect2.setLast();
				int a = vect2.getNdim();
				if (i == a)
					vect2.realloc();
			}
			vect2.removeLast();
			flinp.clear();
			flinp.close();
		}
	}
	else {
		msg.mess(WARN_ARR_UNKN);
	}
	system("pause");
}
void my_interf::clear_all() {
	system("cls");
	if (tryb == 0) {
		vect.clear_all();
		cout << "Skasowano wszystko" << endl;
	}
	else if (tryb == 1) {
		vect2.clear_all();
		cout << "Skasowano wszystko" << endl;
	}
	else
		msg.mess(WARN_ARR_UNKN);
	system("pause");
}
void my_interf::modify() {
	system("cls");
	cout << "Podaj index" << endl;
	size_t index;
	cin >> index;
	if (tryb == 0) {
		int i = vect.checkIndex(index);
		if (i == 1) {
			node temp(0, "", 0, 0);
			cin >> temp;
			vect.modify(temp, index);
			cout << "Zmieniono" << endl;
		}
		else if (i == 2) {
			msg.mess(WARN_ARR_EMPT);
		}
		else {
			cout << "Index spoza tablicy" << endl;
		}
	}
	else if (tryb == 1) {
		int i = vect2.checkIndex(index);
		if (i == 1) {
			note temp(0, "");
			cin >> temp;
			vect2.modify(temp, index);
			cout << "Zmieniono" << endl;
		}
		else if (i == 2) {
			msg.mess(WARN_ARR_EMPT);
		}
		else {
			cout << "Index spoza tablicy" << endl;
		}
	}
	else {
		msg.mess(WARN_ARR_UNKN);
	}
	system("pause");
}
void my_interf::addObj() {
	system("cls");
	cout << "Podaj index" << endl;
	size_t index;
	cin >> index;
	if (tryb == 0) {
		int i = vect.checkIndex(index);
		if (i == 1) {
			node temp(0, "", 0, 0);
			cin >> temp;
			vect.insert(temp, index);
			cout << "Dodano" << endl;
		}
		else if (i == 2) {
			msg.mess(WARN_ARR_EMPT);
		}
		else {
			cout << "Index spoza tablicy" << endl;
		}
	}
	else if (tryb == 1) {
		int i = vect2.checkIndex(index);
		if (i == 1) {
			note temp(0, "");
			cin >> temp;
			vect2.insert(temp, index);
			cout << "Dodano" << endl;
		}
		else if (i == 2) {
			msg.mess(WARN_ARR_EMPT);
		}
		else {
			cout << "Index spoza tablicy" << endl;
		}
	}
	else {
		msg.mess(WARN_ARR_UNKN);
	}
	system("pause");
}
void my_interf::addTabObj() {
	system("cls");
	cout << "Podaj index" << endl;
	size_t index;
	cin >> index;
	if (tryb == 0) {
		int i = vect.checkIndex(index);
		if (i == 1) {
			cout << "Podaj rozmiar tablicy" << endl;
			size_t size;
			cin >> size;
			if (size < 1) {
				cout << "Rozmiar musi by wiekszy od 0" << endl;
			}
			else {
				node *ptr = nullptr;
				ptr = new node[size];
				for (size_t i = 0; i < size; i++) {
					node temp(0, "", 0, 0);
					cout << "Podaj obiekt nr: " << i << endl;
					cin >> temp;
					ptr[i] = temp;
				}
				vect.insert(ptr, index, size);
			}
		}
		else if (i == 2) {
			msg.mess(WARN_ARR_EMPT);
		}
		else {
			cout << "Index spoza tablicy" << endl;
		}
	}
	else if (tryb == 1) {
		int i = vect2.checkIndex(index);
		if (i == 1) {
			cout << "Podaj rozmiar tablicy" << endl;
			size_t size;
			cin >> size;
			if (size < 1) {
				cout << "Rozmiar musi by wiekszy od 0" << endl;
			}
			else {
				note *ptr = nullptr;
				ptr = new note[size];
				for (size_t i = 0; i < size; i++) {
					note temp(0, "");
					cout << "Podaj obiekt nr: " << i << endl;
					cin >> temp;
					ptr[i] = temp;
				}
				vect2.insert(ptr, index, size);
			}
		}
		else if (i == 2) {
			msg.mess(WARN_ARR_EMPT);
		}
		else {
			cout << "Index spoza tablicy" << endl;
		}
	}
	else {
		msg.mess(WARN_ARR_UNKN);
	}
	system("pause");
}
void my_interf::setFileName(char name[]) {
	if(strlen(name)<64) 
		memcpy_s(this->filename, (strlen(name) + 1) * sizeof(char), name, (strlen(name) + 1)*sizeof(char));
}
char *my_interf::getFileName() {
	return filename;
}

void my_interf::setTryb(int t) {
	tryb = t;
}

int my_interf::getTryb() {
	return tryb;
}

void my_interf::change() {
	system("cls");
		if (tryb == 0) {
			tryb = 1;
			cout << "Zmieniono tryb na note" << endl;
		}
		else {
			tryb = 0;
			cout << "Zmieniono tryb na node" << endl;
		}
		system("pause");
}

