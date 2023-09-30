#include <iostream>
#include <fstream>
#include <cstring>

#define LGMAX 201

using namespace std;

int main()
{
	int i;
	char s[LGMAX], *st, *dr, c;
	bool ok;

	ifstream fin("zuma.in");
	fin >> i >> s;
	fin.close();
	
	if (s[i-2] == s[i-1] && s[i-2] == s[i])
	{
		st = s+i-2, dr = s+i;
		c = *st;
		do
		{
			ok = 0;

			for (; *st == c; st--);
			for (; *dr == c; dr++);

			if ((int)(dr-st)-1 >= 3)
			{
				ok = 1;

				*(st+1) = '\0';

				strcat(s, dr);
			}

			dr = st+1;
			c = *st;
		}
		while (ok);
	}
	
	fin.close();

	ofstream fout("zuma.out");
	fout << s;
	fout.close();

	return 0;
}
// scor 75
