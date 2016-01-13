#ifndef INCLUDE_MY_HEADER_my_mess_h
#define INCLUDE_MY_HEADER_my_mess_h


#include "stdafx.h"

enum MY_MESSAGE
{
	ERR_ALLOC_MEM,     //b��d alokacji pami�ci
	ERR_OPEN_FILE,	   //blad otwarcia pliku	
	ERR_WRITE_FILE,	   //blad zapisu do pliku
	ERR_READ_FILE,	   //blad odczytu pliku
	WARN_ARR_FULL,     //tablica jest wypelniona (last > ndim)
	WARN_ARR_EMPT,     //tablica jest pusta (last = 0)
	WARN_ARR_UNKN,     //niepoprawny kod dzia�ania (interfejs)
	TOT_NUMB           //og�lna ilo�� komunikat�w
};

class my_mess
{
	static char *strtab[TOT_NUMB];  //tablica tekstowa komunikat�w

public:
	void mess(enum MY_MESSAGE ms);    //Przy wywo�aniu tej funkcji na ekran 
									  //pozostaje wyprowadzony komunikat. Je�li to b��d, obliczenia trzeba 
									  //sko�czy�E je�li nie �Ekontynuowa�E ms �Esk�adowa enumeration, kt�ra podaje 
									  //numer komunikatu
};

#endif