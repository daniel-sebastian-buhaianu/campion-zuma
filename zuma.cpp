#include <iostream>
#include <fstream>
#include <cstring>

#define LGMAX 201

using namespace std;

int main()
{
	int i;
	char s[LGMAX], *st, *dr, c, ok;

	ifstream fin("zuma.in");

	fin >> i >> s;

	fin.close();

	st = dr = s+i;
	c = *(s+i);

	do
	{
		ok = 0;

		for (; st != s && *st == c; st--);

		if (*st != c)
		{
			st++;
		}

		for (; dr != NULL && *dr == c; dr++);

		if (*dr != c)
		{
			dr--;
		}

		if ((int)(dr-st) >= 2)
		{
			ok = 1;

			*st = 0;

			i = strlen(s);

			strcat(s, dr+1);
			
			st = dr = s+i-1;

			c = *st;
		}
	}
	while (ok);

	ofstream fout("zuma.out");

	fout << s;

	fout.close();

	return 0;
}
// scor 70
