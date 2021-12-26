#include <stdio.h>


void foo(const char* s)
{
	const int* p = (int*) (s+1);
	int  i = 3;
	while(i)
	{
		printf("%c", *((char*)p));
		p++;
		i--;
	}
}
int main() {
	char sp[] = "59059099555090";
	foo(sp);
	return 0;
}