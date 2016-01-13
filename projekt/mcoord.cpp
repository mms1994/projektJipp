#include "stdafx.h"
#include "mcoord.h"

mcoord::~mcoord() {
	if (pcoord) {
		delete[] pcoord;
		pcoord = nullptr;
	}
}
mcoord::mcoord(double xx, double yy) {
	if (!pcoord) {
		pcoord = new double[2];
	}
	pcoord[0] = xx;
	pcoord[1] = yy;
}
mcoord::mcoord(const mcoord &mc) {
	if (mc.pcoord) {
		pcoord = new double[2];
		pcoord[0] = mc.pcoord[0];
		pcoord[1] = mc.pcoord[1];
	}
	else {
		pcoord = nullptr;
	}
}
mcoord & mcoord::operator=(const mcoord &mc) {
	if (!pcoord && !mc.pcoord) {
		return *this;
	}
	else if (pcoord && mc.pcoord) {
		pcoord[0] = mc.pcoord[0];
		pcoord[1] = mc.pcoord[1];
		return *this;
	}
	else if (!pcoord && mc.pcoord) {
		pcoord = new double[2];
		pcoord[0] = mc.pcoord[0];
		pcoord[1] = mc.pcoord[1];
		return *this;
	}
	else {
		if (pcoord)
			delete[] pcoord;
		pcoord = nullptr;
		return *this;
	}

}
int mcoord::operator==(const mcoord &mc) {
	return (pcoord[0]==mc.pcoord[0] && pcoord[1]==mc.pcoord[1]);
}
ostream&operator<<(ostream&os, const mcoord &mc) {
	if (mc.pcoord) {
		os<< "(" << mc.pcoord[0] << ", " << mc.pcoord[1] << ")" << endl;
		return os;
	}
	else {
		//thrown?
		cout << "blad" << endl;
	}
}
istream&operator>>(istream&is, mcoord &mc) {
	if (!mc.pcoord)
		mc.pcoord = new double[2];
	is >> mc.pcoord[0];
	is >> mc.pcoord[1];
	return is;
}
ofstream&operator<<(ofstream&ofs, const mcoord &mc) {
	if (mc.pcoord) {
		ofs.write(reinterpret_cast<const char*>(&mc.pcoord[0]), sizeof(double));
		ofs.write(reinterpret_cast<const char*>(&mc.pcoord[1]), sizeof(double));
		return ofs;
	}
	else {
		//thrown?
		cout << "blad" << endl;
	}
}
ifstream&operator>>(ifstream&ifs, mcoord &mc) {
	if (!mc.pcoord) {
		mc.pcoord = new double[2];
		mc.pcoord[0] = 0;
		mc.pcoord[1] = 0;
	}
	ifs.read(reinterpret_cast<char*>(&mc.pcoord[0]), sizeof(double));
	ifs.read(reinterpret_cast<char*>(&mc.pcoord[1]), sizeof(double));
	return ifs;
}
void mcoord::change(double xx, double yy) {
	if (!pcoord) {
		pcoord = new double[2];
	}
	pcoord[0] = xx;
	pcoord[1] = yy;
}
