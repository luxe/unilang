/* 'The C Programming Language' by Kernigan & Richie */
int isleapyear(int year)
{
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

/* Tomohiko Sakamoto */
int dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	 
    y -= m < 3;
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
