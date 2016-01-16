// projekt.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "my_interf.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int op;  //operacje
	my_interf ifc(2);
	
	cout << "Wybierz tryb pracy, 0 - node, 1 - note" << endl;
	int t;
	cin >> t;
	ifc.setTryb(t);
	while (ifc.run)
	{
		ifc.menu();
		cin >> op;
		switch (op)
		{
		case MY_INTERF_PUSH:
			ifc.push();
			break;
		case MY_INTERF_POP:
			ifc.pop();
			break;
		case MY_INTERF_CLEAR:
			ifc.clear_all();
			break;
		case MY_INTERF_MODIFY:
			ifc.modify();
			break;
		case MY_INTERF_ADD_OBJ:
			ifc.addObj();
			break;
		case MY_INTERF_ADD_TAB_OBJ:
			ifc.addTabObj();
			break;
		case MY_INTERF_DISP:
			ifc.disp();
			break;
		case MY_INTERF_FIND:
			ifc.find();
			break;
		case MY_INTERF_REMOVE:
			ifc.remove();
			break;
		case MY_INTERF_SAVE:
			ifc.save();
			break;
		case MY_INTERF_LOAD:
			ifc.load();
			break;
		case MY_INTERF_CHANGE:
			ifc.change();
			break;
		case MY_INTERF_FINISH:
			ifc.finish();
			break;
		default:
			ifc.default();
		};
	}
	return 0;
}

