#include "stdafx.h"
#include "node.h"

node::node(int nb, char *st, double xx, double yy) : mcoord(xx,yy) {
	this->numb = nb;
	memcpy_s(this->str, (strlen(st) + 1)*sizeof(char), st, (strlen(st)+1)*sizeof(char));
}
node::node():mcoord() {
	this->numb = 0;
}
node::~node() {
	mcoord::~mcoord();
	numb = 0;
	*str = NULL;
}
node::node(const node &nd) : mcoord(nd) {
	this->numb = nd.numb;
	memcpy_s(str, (strlen(nd.str) + 1) * sizeof(char), nd.str, (strlen(nd.str)+1)*sizeof(char));
}
node node::operator=(const node &nd) {
	this->numb = nd.numb;
	memcpy_s(str, (strlen(nd.str) + 1) * sizeof(char), nd.str, (strlen(nd.str) + 1)*sizeof(char));
	this->mcoord::operator=(nd);
	return *this;
}
int node::operator==(const node &nd) {
	return (this->numb == nd.numb);
}
int node::operator==(const int key) {
	return (this->numb == key);
}
ostream&operator<<(ostream &os, node &nd) {
	os << "Opis: " << nd.str << endl << "Numer: " << nd.numb << endl << static_cast<const mcoord&>(nd);
	return os;
}
istream&operator>>(istream &is, node &nd) {
	cout << "Podaj nazwe" << endl;
	is >> nd.str;
	cout << "Podaj numer" << endl;
	is >> nd.numb;
	cout << "Podaj koordynaty" << endl;
	is >> static_cast<mcoord&>(nd);
	return is;
}
ofstream&operator<<(ofstream&ofs, node &nd) {
	if (nd.pcoord) {
		ofs.write(nd.str, sizeof(nd.str));
		ofs.write(reinterpret_cast<const char*>(&nd.numb), sizeof(int));
		ofs << static_cast<const mcoord&>(nd);
		return ofs;
	}
	else {
		cout << "Blad!" << endl;
		return ofs;
	}
}
ifstream&operator>>(ifstream&ifs, node &nd) {
	ifs.read(nd.str, sizeof(nd.str));
	ifs.read(reinterpret_cast<char*>(&nd.numb), sizeof(int));
	ifs >> static_cast<mcoord&>(nd);
	return ifs;
}
