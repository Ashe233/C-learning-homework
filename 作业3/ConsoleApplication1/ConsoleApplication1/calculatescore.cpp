#include "calculatescore.h"

float gethighestscore(int a, int b, int c, int d, int e, int f)
{
	int temp = a;
	if (a < b) temp = b;
	if (temp < c) temp = c;
	if (temp < d) temp = d;
	if (temp < e) temp = e;
	if (temp < f) temp = f;
	return temp;
}

float getlowestscore(int a, int b, int c, int d, int e, int f)
{
	int temp = a;
	if (a > b) temp = b;
	if (temp > c) temp = c;
	if (temp > d) temp = d;
	if (temp > e) temp = e;
	if (temp > f) temp = f;
	return temp;
}
