#include "stdafx.h"
#include "note.h"


note::note(int nb, char *tx) {
	this->numb = nb;
	memcpy_s(this->text, (strlen(tx) + 1)*sizeof(char), tx, (strlen(tx) + 1)*sizeof(char));
	GetLocalTime(&st);
}
note::note(const note &nt) {
	this->numb = nt.numb;
	memcpy_s(text, (strlen(nt.text) + 1) * sizeof(char), nt.text, (strlen(nt.text) + 1)*sizeof(char));
	st = nt.st;
}
note::note() {
	this->numb = 0;
}
note::~note() {
	this->numb = 0;
	*text = NULL;
}
note note::operator=(const note &nt) {
	this->numb = nt.numb;
	memcpy_s(text, (strlen(nt.text) + 1) * sizeof(char), nt.text, (strlen(nt.text) + 1)*sizeof(char));
	st = nt.st;
	return *this;
}
int note::operator==(const note &nt) {
	return (this->numb == nt.numb);
}
int note::operator==(const int key) {
	return (this->numb == key);
}
ostream&operator<<(ostream &os, note &nt) {
	os << "Notatka: " << nt.text << endl << "Numer: " << nt.numb << endl << "Data: " << 
		nt.st.wDay<<"-"<<nt.st.wMonth<<"-"<<nt.st.wYear<<" "<<nt.st.wHour<<":"<<nt.st.wMinute<<":"<<nt.st.wSecond<< endl;;
	return os;
}
istream&operator>>(istream &is, note &nt) {
	cout << "Podaj notatke" << endl;
	is >> nt.text;
	cout << "Podaj numer" << endl;
	is >> nt.numb;
	GetLocalTime(&nt.st);
	return is;
}
ofstream&operator<<(ofstream&ofs, note &nt) {
	ofs.write(nt.text, sizeof(nt.text));
	ofs.write(reinterpret_cast<const char*>(&nt.numb), sizeof(int));
	ofs.write(reinterpret_cast<const char*>(&nt.st), sizeof(SYSTEMTIME));
	return ofs;
}
ifstream&operator>>(ifstream&ifs, note &nt) {
	ifs.read(nt.text, sizeof(nt.text));
	ifs.read(reinterpret_cast<char*>(&nt.numb), sizeof(int));
	ifs.read(reinterpret_cast<char*>(&nt.st), sizeof(SYSTEMTIME));
	return ifs;
}
