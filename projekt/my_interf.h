#ifndef INCLUDE_MY_HEADER_my_interf_h
#define INCLUDE_MY_HEADER_my_interf_h

#define MAX_INTERF_CHAR 512

#include "my_vect.h"
#include "mcoord.h"
/*
enum MY_INTERF
{
	MY_INTERF_PUSH,
	MY_INTERF_POP,
	MY_INTERF_DISP,
	MY_INTERF_FIND,
	MY_INTERF_REMOVE,
	MY_INTERF_ADD,
	MY_INTERF_LOAD,
	MY_INTERF_FINISH,
	MY_INTERF_TOT
};

class my_interf
{
private:
	my_vect<mcoord> vect;
	char str_interf[MY_INTERF_TOT][512];  //komunikaty, wy�wietlane na monitorze (menu)
	my_mess msg;
	ifstream flinp;
	ofstream flout;
	char filename[20];
public:
	bool run;

	my_interf() : vect() {};
	my_interf(size_t dim);
	void menu();
	void push();
	void pop();
	void disp();
	void find();
	void finish();
	void defaul();
	void remove();
	void save();
	void load();
};
*/
#endif