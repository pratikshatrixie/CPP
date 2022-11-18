
#include <iostream>
#include <cstring>

using namespace std;

void flip(char* a)
{
    if(*a=='1')
    {
        *a='0';
        return;}

    else if (*a=='0')
    {
        *a='1';
        flip(a+1);
    }
}

int main()
{
	int N;
	string input;
    cin>>input;
    cin>>N;

	int l = input.length();
	char inp_array[l + 1];
	strcpy(inp_array, input.c_str());

	for (int i = 0; i < N; i++)
		{
            flip(inp_array);
        }

    for(int j=0;j<l;j++)
    {
        cout<<inp_array[j];
    }

	return 0;
}
