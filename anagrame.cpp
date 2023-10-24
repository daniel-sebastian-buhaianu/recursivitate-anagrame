#include <fstream>
#include <cstring>
#define LGMAX 101
using namespace std;
ifstream fin("anagrame.in");
ofstream fout("anagrame.out");
bool eAnagrama(char*, char*);
int main()
{
	char x[LGMAX], y[LGMAX];
	fin.getline(x, LGMAX);
	fin.getline(y, LGMAX);
	fin.close();
	if (eAnagrama(x, y))
	{
		fout << "DA";
	}
	else
	{
		fout << "NU";
	}
	fout.close();
	return 0;
}
bool eAnagrama(char* x, char* y)
{
	char* p;
	if (!*x && !*y) return 1;
	p = strchr(y, *x); // caut in y primul caracter din x
	if (!p) return 0; // nu l-am gasit
	*p = 0; strcat(y, p+1); // l-am gasit, il sterg din y
	return eAnagrama(x+1, y); // repet procesul pt urm caracter
}
