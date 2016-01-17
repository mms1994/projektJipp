#ifndef INCLUDE_MY_HEADER_my_vect_h
#define INCLUDE_MY_HEADER_my_vect_h

#include "stdafx.h"
#include "my_mess.h"

template <class T> class my_vect
{
	T *dat;       //wskaŸnik do tablicy typu ogólnego T
	size_t ndim;  //iloœæ elementów, na jak¹ zosta³a zaalokowana pamiêæ dla tablicy dat
	size_t last;  //indeks, który wskazuje na pierwszy wolny element tablicy
	my_mess msg;

public:
	my_vect(size_t dim);  //alokuje pamiêæ dla tablicy dat na dim elementów (przy tworzeniu obiektu)
	my_vect() { dat = nullptr; ndim = last = 0; }
	~my_vect();           //zwalnia pamiêæ
	void init(size_t dim);					  
	T *get_begin() { return dat; }   //zwraca wskaŸnik do dat[0] (pierwszego elementu)
	T *get_end() { return &dat[last]; } // zwraca wskaŸnik na pierwszy wolny element tablicy
	void disp(); //wyswietlanie
	T & operator [] (const size_t ind); //0 <= ind < last
	void push(const T &ob); // dodaje obiekt typu T w pierwsz¹ woln¹ pozycjê i zwiêksza last o jedynkê
	T * pop();       //dekrementuje last i zwraca ostatni element tablicy
	void insert(const T &ob, size_t ind); //wstawia element ob w tablicê dat po elemencie dat[ind]
	void insert(const T *tab_ob, size_t ind, size_t numb);  // wstawia tablicê elementów tab_ob w tablicê dat po elemencie dat[ind], gdzie numb - iloœæ elementów w tablicy tab_ob
	void erase(const T *ob); //usuwa element *ob z tablicy dat i przesuwa elementy tablicy tak, aby po usuniêciu elementy by³y umieszczone w sposób ci¹g³y (metoda "pakuje" tablicê)
	void clear_all();
	template <class T, class Key>
	friend T *Find(const T *begin, const T *end, const Key &k);
	void remove(size_t ind);
	void removeLast();
	void modify(const T &ob, size_t ind);
	int getLast();
	int checkIndex(size_t ind);
	void setLast();
	int getNdim();
	void realloc();   //jeœli last >= ndim – zwiêksza ndim i realokuje pamiêæ
private:
	void alloc(size_t dim);
};

template <class T>
void my_vect<T>::alloc(size_t dim) {
	try {
		if (!dat) {
			dat = new T[dim];
		}
	}
	catch (bad_alloc) {
		msg.mess(ERR_ALLOC_MEM);
		system("pause");
		exit(-1);
	}
}
template <class T>
void my_vect<T>::realloc() {
	T *dat2 = nullptr;
	try {
		dat2 = new T[ndim + 10];
		for (size_t i = 0; i < last; i++)
			dat2[i] = dat[i];
		ndim += 10;
		size_t temp = last;
		clear_all();
		last = temp;
		dat = dat2;
	}
	catch (bad_alloc) {
		msg.mess(ERR_ALLOC_MEM);
		system("pause");
		exit(-1);
	}
}
template <class T>
void my_vect<T>::init(size_t dim) {
	alloc(dim);
	ndim = dim;
	last = 0;
}
template <class T>
my_vect<T>::my_vect(size_t dm) {
	alloc(dm);
	ndim = dm;
	last = 0;
}
template <class T>
my_vect<T>::~my_vect() {
	if (dat) delete[] dat;
	dat = nullptr;
	ndim = 0;
	last = 0;
}
template <class T>
void my_vect<T>::disp() {
	if (last>0) {
		for (size_t i = 0; i < (last); i++)
			cout << dat[i] << endl;
	}
	else
		msg.mess(WARN_ARR_EMPT);
}
template <class T>
void my_vect<T>::push(const T &ob) {
	if (last < ndim) {
		dat[last] = ob;
		last++;
	}
	else {
		realloc();
		dat[last] = ob;
		last++;
	}
}
template <class T>
T *my_vect<T>::pop() {
	if (last <= 0) {
		return nullptr;
	}
	else {
		last--;
		return &dat[last];
	}
}
template <class T>
T & my_vect<T>::operator[](const size_t ind) {
	if (0 <= ind && ind < last)
		return dat[ind];
	else {
		cout << "index spoza zakresu" << endl;
		return T();
	}
}
template <class T>
void my_vect<T>::erase(const T *ob) {

}
template <class T, class Key>
T *Find(const T *begin, const T *end, const Key &k) {
	T *temp= const_cast<T*>(begin);
	while (!(*temp == *end)) {
		if (*temp==k) return temp;
		*temp++;
	}
		
	return nullptr;
}
template <class T>
void my_vect<T>::clear_all() {
	while (last) {
		last--;
		dat[last].T::~T();
	}
}
template <class T>
void my_vect<T>::remove(size_t ind) {
	if (ind >= 0 && ind < last) {
		for (ind; ind < last; ind++)
			dat[ind] = dat[ind + 1];
		last--;
		dat[last].T::~T();
	}
	else {
		msg.mess(WARN_ARR_EMPT);
	}
}
template <class T>
void my_vect<T>::removeLast() {
	if (last) {
		last--;
		dat[last].T::~T();
	}
}
template <class T>
void my_vect<T>::modify(const T &ob, size_t ind) {
	dat[ind] = ob;
}
template <class T>
int my_vect<T>::getLast() {
	return last;
}
template <class T>
int my_vect<T>::checkIndex(size_t ind) {
	if (ind >= 0 && ind < last)
		return 1;
	else if (ind >= last && ind <= ndim)
		return 2;
	else
		return 0;
}
template <class T>
void my_vect<T>::setLast() {
	last++;
}
template <class T>
int my_vect<T>::getNdim() {
	return ndim;
}
template <class T>
void my_vect<T>::insert(const T &ob, size_t ind) {
	if (!dat) {
		msg.mess(WARN_ARR_EMPT);
	}
	else if (last < ndim) {
		int temp = last;
		while (ind != temp) {
			temp--;
			dat[temp + 1] = dat[temp];
		}
		dat[ind+1] = ob;
		last++;
	}
	else {
		realloc();
		int temp = last;
		while (ind != temp) {
			temp--;
			dat[temp+1] = dat[temp];
		}
		dat[ind+1] = ob;
		last++;
	}
}
template <class T>
void my_vect<T>::insert(const T *tab_ob, size_t ind, size_t numb) {
	if (!dat) {
		msg.mess(WARN_ARR_EMPT);
	}
	else if (last < ndim && (last - 1 + numb) < ndim) {
		int temp = last;
		int temp2 = numb;
		size_t temp3 = ind;
		size_t diff = last - ind;
		last += numb;
		int diff2 = last - diff;
		for (size_t i = 0; i < diff; i++) {
			dat[diff2] = dat[temp3];
			diff2++;
			temp3++;
		}
		temp3 = ind+1;
		for (size_t i = 0; i < numb; i++) {
			dat[temp3] = tab_ob[i];
			temp3++;
		}
	}
	else {
		while (!(last < ndim && (last - 1 + numb) < ndim))
			realloc();
		int temp = last;
		int temp2 = numb;
		size_t temp3 = ind;
		size_t diff = last - ind;
		last += numb;
		int diff2 = last--;
		for (size_t i = 0; i < diff; i++) {
			dat[diff2] = dat[temp3];
			diff--;
			temp3++;
		}
		temp3 = ind+1;
		for (size_t i = 0; i < numb; i++) {
			dat[temp3] = tab_ob[i];
			temp3++;
		}
	}
}

#endif
