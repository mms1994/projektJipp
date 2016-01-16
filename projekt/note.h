#ifndef INCLUDE_MY_HEADER_note_h
#define INCLUDE_MY_HEADER_note_h

#include <Windows.h>

class note
{
	int numb;
	char text[512];
	SYSTEMTIME st;
public:
	note(int nb, char *tx);
	note(const note &nt);
	note();
	~note();
	note operator=(const note &nt);
	int operator==(const note &nt);
	int operator==(const int key);
	friend ostream&operator<<(ostream &os, note &nt);
	friend istream&operator>>(istream &is, note &nt);
	friend ofstream&operator<<(ofstream&ofs, note &nt);
	friend ifstream&operator>>(ifstream&ifs, note &nt);
	
};

#endif;