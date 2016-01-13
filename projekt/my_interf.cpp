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
	sprintf_s(str_interf[MY_INTERF_ADD], MAX_INTERF_CHAR*sizeof(char), "%d - save to file", MY_INTERF_ADD);
	sprintf_s(str_interf[MY_INTERF_LOAD], MAX_INTERF_CHAR*sizeof(char), "%d - read from file", MY_INTERF_LOAD);
	sprintf_s(str_interf[MY_INTERF_FINISH], MAX_INTERF_CHAR*sizeof(char), "%d - finish", MY_INTERF_FINISH);
	vect.init(dim);
	run = true;
}

void my_interf::menu() {
	int i;
	for (i = 0; i<MY_INTERF_TOT; i++) {
		cout << str_interf[i] << endl;
	}
}

void my_interf::push() {
	mcoord ob(0, 0);
	cin >> ob;
	vect.push(ob);
}

void my_interf::pop() {
	mcoord *ptr = nullptr;
	ptr = vect.pop();
	if (ptr) {
		cout << *ptr;
	}
	else {
		msg.mess(WARN_ARR_EMPT);
	}
}

void my_interf::disp() {
	vect.disp();
}

void my_interf::find() {
	mcoord ob(0, 0);
	mcoord *ptr = nullptr;
	mcoord *ptr1 = nullptr;
	cout << "input x, y - object for search\n";
	cin >> ob;
	ptr = vect.get_begin();
	ptr1 = vect.get_end();
	size_t dist;
	int i = 0;
	while (ptr)	{
		ptr = Find(ptr, vect.get_end(), ob);
		if (ptr) {
			dist = ptr - vect.get_begin();
			cout << "it = " << dist << " " << *ptr;
			if (*ptr == *ptr1)
				i++;
			else
				ptr++;
		}
		else
			cout << "search end\n";
		if (i) {
			cout << "search end\n";
			ptr = nullptr;
		}
	}
}

void my_interf::finish() {
	run = false;
}

void my_interf::default() {
	msg.mess(WARN_ARR_UNKN);
}

void my_interf::remove() {
	int i;
	cout << "Podaj numer indeksu do usuniecia: ";
	cin >> i;
	vect.remove(i);
}

void my_interf::save() {
	cout << "Podaj plik" << endl;
	char str[64];
	cin >> str;
	setFileName(str);
	flout.open(getFileName(), ios_base::out | ios::trunc | ios::binary);
	size_t max = vect.getLast();
	if (!max)
		cout << "Tablica jest pusta !!!" << endl;
	else if (!flout.is_open())
		cout << "Plik nie zostal otwarty !!!" << endl;
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

void my_interf::load() {
	cout << "Podaj plik" << endl;
	char str[64];
	cin >> str;
	setFileName(str);
	flinp.open(getFileName(), ios_base::out | ios::trunc | ios::binary);
	vect.clear_all();
	int i = 0;
	flinp.clear();
	if (!flinp.is_open())
		cout << "Plik nie zostal otwarty !!!" << endl;
	else {
			int a = vect.getNdim();
			if (i == a)
				vect.realloc();
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
void my_interf::clear_all() {
	vect.clear_all();
}
void my_interf::modify() {
	cout << "Podaj index" << endl;
	size_t index;
	cin >> index;
	int i = vect.checkIndex(index);
	if (i == 1) {
		node temp(0, "", 0, 0);
		cin >> temp;
		vect.modify(temp, index);
	}
	else if (i == 2) {
		cout << "Pusto" << endl;
	}
	else {
		cout << "Index spoza tablicy" << endl;
	}
}
void my_interf::addObj() {
	cout << "Podaj index" << endl;
	size_t index;
	cin >> index;
	int i = vect.checkIndex(index);
	if (i == 1) {
		node temp(0, "", 0, 0);
		cin >> temp;
		vect.insert(temp, index);
	}
	else if (i == 2) {
		cout << "Pusto" << endl;
	}
	else {
		cout << "Index spoza tablicy" << endl;
	}
}
void my_interf::addTabObj() {
	cout << "Podaj index" << endl;
	size_t index;
	cin >> index;
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
				cout << "Index: " << i << "podaj obiekt" << endl;
				cin >> temp;
				ptr[i] = temp;
			}
			//co jest kurwa?
			//vect.insert(ptr, index, size);
		}
	}
	else if (i == 2) {
		cout << "Pusto" << endl;
	}
	else {
		cout << "Index spoza tablicy" << endl;
	}
}
void my_interf::setFileName(char name[]) {
	if(strlen(name)<64) 
		memcpy_s(this->filename, 64 * sizeof(char), name, (strlen(name) + 1)*sizeof(char));
}
char *my_interf::getFileName() {
	return filename;
}

