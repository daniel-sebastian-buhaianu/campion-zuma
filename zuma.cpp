#include <fstream>
#include <cstring>
#define LGMAX 201
using namespace std;
void citesteDateleDeIntrare(char*, int&);
void bordeazaSir(char*);
void zuma(char*, int, int);
void debordeazaSir(char*);
void afiseazaRezultatul(char*);
int main()
{
	char s[LGMAX];
	int poz;
	citesteDateleDeIntrare(s, poz);
	bordeazaSir(s);
	zuma(s, poz, 0);
	debordeazaSir(s);
	afiseazaRezultatul(s);
	return 0;
}
void afiseazaRezultatul(char* sir)
{
	ofstream fout("zuma.out");
	fout << sir;
	fout.close();
}
void debordeazaSir(char* sir)
{
    int n, i;
    n = strlen(sir);
    for (i = 1; i <= n-2; i++)
        sir[i-1] = sir[i];
    sir[n-2] = 0;
}
void zuma(char* sir, int poz, int pas)
{
	int i, n;
	char *p;
	n = strlen(sir);
	if (sir[poz] == sir[poz-1]
        && sir[poz] == sir[poz+1])
    {
        for (p = sir+poz; *p == sir[poz]; p++);
        for (i = poz-1; i > 0 && sir[i-1] == sir[poz]; i--);
        sir[i] = 0;
        strcat(sir, p);
        zuma(sir, i-1, pas+1);
    }
    else if (pas > 0 && n > 4)
        if (sir[poz] == sir[poz+1]
            && sir[poz] == sir[poz+2])
                zuma(sir, poz+1, pas);
}
void bordeazaSir(char* sir)
{
    int n, i;
    n = strlen(sir);
    for (i = n; i >= 1; i--)
        sir[i] = sir[i-1];
    sir[0] = sir[n+1] = '_';
    sir[n+2] = 0;
}
void citesteDateleDeIntrare(char* sir, int& poz)
{
	ifstream fin("zuma.in");
	fin >> poz >> sir;
	fin.close();
}
