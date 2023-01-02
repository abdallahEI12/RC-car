/*
 * helpers.c
 *
 * Created: 8/24/2022 11:04:03 PM
 *  Author: bedoa
 */ 
int get_strlen(char* array)
{	char none = 0x00;
	for(int i = 0;;i++)
	{
		char data = *(array+i);
		if(data == none)
		{
			return i;
		}
	}
}
