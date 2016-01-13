#ifndef INCLUDE_MY_HEADER_mcoord_h
#define INCLUDE_MY_HEADER_mcoord_h

#include "stdafx.h"

using namespace std;

class mcoord
{
protected:
	double *pcoord;
public:
	mcoord(double xx, double yy);
	mcoord() { pcoord = NULL; }
	mcoord(const mcoord &mc);
	~mcoord();
	mcoord & operator=(const mcoord &mc);
	int operator==(const mcoord &mc);
	friend ostream&operator<<(ostream&os, const mcoord &mc);
	friend istream&operator>>(istream&is, mcoord &mc);
	friend ofstream&operator<<(ofstream&ofs, const mcoord &mc);
	friend ifstream&operator>>(ifstream&ifs, mcoord &mc);
	void change(double xx, double yy);
};
#endif
