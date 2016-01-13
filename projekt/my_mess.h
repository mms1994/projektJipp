#ifndef INCLUDE_MY_HEADER_my_mess_h
#define INCLUDE_MY_HEADER_my_mess_h


#include "stdafx.h"

enum MY_MESSAGE
{
	ERR_ALLOC_MEM,     //b³¹d alokacji pamiêci
	ERR_OPEN_FILE,	   //blad otwarcia pliku	
	ERR_WRITE_FILE,	   //blad zapisu do pliku
	ERR_READ_FILE,	   //blad odczytu pliku
	WARN_ARR_FULL,     //tablica jest wypelniona (last > ndim)
	WARN_ARR_EMPT,     //tablica jest pusta (last = 0)
	WARN_ARR_UNKN,     //niepoprawny kod dzia³ania (interfejs)
	TOT_NUMB           //ogólna iloœæ komunikatów
};

class my_mess
{
	static char *strtab[TOT_NUMB];  //tablica tekstowa komunikatów

public:
	void mess(enum MY_MESSAGE ms);    //Przy wywo³aniu tej funkcji na ekran 
									  //pozostaje wyprowadzony komunikat. Jeœli to b³¹d, obliczenia trzeba 
									  //skoñczyE jeœli nie EkontynuowaE ms Esk³adowa enumeration, która podaje 
									  //numer komunikatu
};

#endif