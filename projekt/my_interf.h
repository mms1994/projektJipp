#ifndef INCLUDE_MY_HEADER_my_interf_h
#define INCLUDE_MY_HEADER_my_interf_h

#define MAX_INTERF_CHAR 512

#include "my_vect.h"
#include "node.h"
#include "my_mess.h"
#include "note.h"

enum MY_INTERF
{
	MY_INTERF_PUSH,
	MY_INTERF_POP,
	MY_INTERF_CLEAR,
	MY_INTERF_MODIFY,
	MY_INTERF_ADD_OBJ,
	MY_INTERF_ADD_TAB_OBJ,
	MY_INTERF_DISP,
	MY_INTERF_FIND,
	MY_INTERF_REMOVE,
	MY_INTERF_SAVE,
	MY_INTERF_LOAD,
	MY_INTERF_CHANGE,
	MY_INTERF_FINISH,
	MY_INTERF_TOT
};

class my_interf
{
private:
	my_vect<node> vect;
	my_vect<note> vect2;
	char str_interf[MY_INTERF_TOT][512];  //komunikaty, wyœwietlane na monitorze (menu)
	my_mess msg;
	ifstream flinp;
	ofstream flout;
	char filename[64];
	int tryb;
public:
	bool run;

	my_interf() : vect() {};
	my_interf(size_t dim);
	void setTryb(int t);
	int getTryb();
	void menu();
	void push();
	void pop();
	void disp();
	void find();
	void finish();
	void default();
	void remove();
	void save();
	void load();
	void change();
	void clear_all();
	void modify();
	void addObj();
	void addTabObj();
	void setFileName(char name[]);
	char *getFileName();
};

#endif