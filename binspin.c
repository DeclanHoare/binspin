/*
	Copyright 2017 Declan Hoare

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	unsigned char ibuffer[8], obuffer[8], tmp;
	int bytes, i, x;
	while ((bytes = fread(ibuffer, 1, 8, stdin)) == 8)
	{
		memset(obuffer, 0, 8);
		for (i = 0; i < 8; i++)
		{
			for (x = 0; x < 8; x++)
			{
				tmp = 128 >> x;
				tmp = ibuffer[i] & tmp;
				tmp = tmp >> (7 - x);
				tmp = tmp << (7 - i);
				obuffer[x] = obuffer[x] ^ tmp;
			}
		}
		for (i = 0; i < 8; i++)
			putchar(obuffer[i]);
	}
	for (i = 0; i < bytes; i++)
		putchar(ibuffer[i]);
	return 0;
}
