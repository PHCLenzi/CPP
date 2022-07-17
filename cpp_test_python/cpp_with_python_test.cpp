#include <stdio.h>
#include <conio.h>
#include <Python.h>
// source https://www.codeproject.com/Articles/820116/Embedding-Python-program-in-a-C-Cplusplus-code
int main()
{
	PyObject* pInt;

	Py_Initialize();

	PyRun_SimpleString("print('Hello World from Embedded Python!!!')");
	
	Py_Finalize();

	printf("\nPress any key to exit...\n");
	if(!_getch()) _getch();
	return 0;
}