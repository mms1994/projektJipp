#ifndef INCLUDE_MY_HEADER_node_h
#define INCLUDE_MY_HEADER_node_h

#include "stdafx.h"
#include "mcoord.h"

using namespace std;

class node : public mcoord
{
	int numb;       //numer wierzcho³ka
	char str[512];  //nazwa wierzcho³ka
public:
	node(int nb, char *st, double xx, double yy);
	node(const node &nd);
	node();
	~node();
	node operator=(const node &nd);
	int operator==(const node &nd);
	int operator==(const int key);
	friend ostream&operator<<(ostream &os, node &nd);
	friend istream&operator>>(istream &is, node &nd);
	friend ofstream&operator<<(ofstream&ofs, node &nd);
	friend ifstream&operator>>(ifstream&ifs, node &nd);
};

#endif