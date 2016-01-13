#include "stdafx.h"
#include "my_mess.h"

char *my_mess::strtab[] =
{
	"E  memory alloc error",          //ERR_ALLOC_MEM
	"E open file error",              //ERR_OPEN_FILE
	"E read file error",              //ERR_WRITE_FILE
	"E write file error",             //ERR_READ_FILE
	"W  array is full",               //WARN_ARR_FULL
	"W  array is empty",              //WARN_ARR_EMPT
	"W  niepoprawny kod operacji"     //WARN_ARR_UNKN
};

void my_mess::mess(enum MY_MESSAGE ms)
{
	if (strtab[ms][0] == 'E')
	{
		cout << "ERROR: " << &strtab[ms][1] << endl;
		system("pause");
		exit(1);
	}
	else if (strtab[ms][0] == 'W')
	{
		cout << "WARNING: " << &strtab[ms][1] << endl;
	}
}
