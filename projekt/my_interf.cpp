#include "stdafx.h"
#include "my_interf.h"
#include "my_mess.h"
/*

my_interf::my_interf(size_t dim) : vect() {
	sprintf_s(str_interf[MY_INTERF_PUSH], MAX_INTERF_CHAR*sizeof(char), "%d - push", MY_INTERF_PUSH);
	sprintf_s(str_interf[MY_INTERF_POP], MAX_INTERF_CHAR*sizeof(char), "%d - pop", MY_INTERF_POP);
	sprintf_s(str_interf[MY_INTERF_DISP], MAX_INTERF_CHAR*sizeof(char), "%d - disp", MY_INTERF_DISP);
	sprintf_s(str_interf[MY_INTERF_FIND], MAX_INTERF_CHAR*sizeof(char), "%d - find", MY_INTERF_FIND);
	sprintf_s(str_interf[MY_INTERF_REMOVE], MAX_INTERF_CHAR*sizeof(char), "%d - remove", MY_INTERF_REMOVE);
	sprintf_s(str_interf[MY_INTERF_ADD], MAX_INTERF_CHAR*sizeof(char), "%d - save to file", MY_INTERF_ADD);
	sprintf_s(str_interf[MY_INTERF_LOAD], MAX_INTERF_CHAR*sizeof(char), "%d - read from file", MY_INTERF_LOAD);
	sprintf_s(str_interf[MY_INTERF_FINISH], MAX_INTERF_CHAR*sizeof(char), "%d - finish", MY_INTERF_FINISH);
	vect.init(dim);
	run = true;
}

void my_interf::menu()
{
	int i;
	for (i = 0; i<MY_INTERF_TOT; i++)
	{
		cout << str_interf[i] << endl;
	}
}

void my_interf::push()
{
	mcoord ob(0, 0);
	cin >> ob;
	vect.push(ob);
}

void my_interf::pop()
{
	mcoord *ptr = nullptr;
	ptr = vect.pop();
	if (ptr)
	{
		cout << *ptr;
	}
	else
	{
		msg.mess(WARN_ARR_EMPT);
	}
}

void my_interf::disp()
{
	vect.disp();
}

void my_interf::find()
{
	mcoord ob(0, 0);
	mcoord *ptr = nullptr;
	mcoord *ptr1 = nullptr;
	cout << "input x, y - object for search\n";
	cin >> ob;
	ptr = vect.get_begin();
	ptr1 = vect.get_end();
	size_t dist;
	int i = 0;
	while (ptr)
	{
		ptr = Find(ptr, vect.get_end(), ob);
		if (ptr)
		{
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

void my_interf::finish()
{
	run = false;
}

void my_interf::defaul()
{
	msg.mess(WARN_ARR_UNKN);
}

void my_interf::remove() {
	int i;
	cout << "Podaj numer indeksu do usuniecia: ";
	cin >> i;
	vect.remove(i);
}

void my_interf::save() {
	cout << "Blabla1" << endl;
	flout.open("dane.dat", ios_base::out | ios::trunc | ios::binary);
	size_t max = vect.get_last_element();
	if (!max)
		cout << "Tablica jest pusta !!!" << endl;
	else if (!flout.is_open())
		cout << "Plik nie zosta? otwarty !!!" << endl;
	else {
		cout << "Blabla2" << endl;
		size_t i;
		flout.clear();
		flout.seekp(0);
		for (i = 0; i < max; i++) {
			flout << vect[i];
			//flout.flush();
		}
		cout << "Blabla3" << endl;
		flout.clear();
		flout.close();
	}
}

void my_interf::load() {
	cout << "ladowanie" << endl;
	flinp.open("dane.dat", ios_base::in | ios::binary);
	vect.clear_all();
	int i = 0;
	flinp.clear();
	if (!flinp.is_open())
		cout << "Plik nie zosta? otwarty !!!" << endl;
	else {
		while (flinp.good()) {
			cout << "weszlo" << endl;
			//if (flinp.fail()) break;
			int a = vect.get_ndim();
			if (i == a)
				vect.realloc();
			flinp >> vect[i];
			//flinp.flush();
			i++;
			vect.set_last();
			//if (flinp.eof()) break;
			//flinp.clear();
		}
		flinp.clear();
		flinp.close();
	}
}*/
