#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int D0, M0, A0;
	int D1, M1, A1;
	
	cout<<"Primeira data [DD MM AAAA]: ";
	cin>>D0>>M0>>A0;
	cout<<"Segunda data [DD MM AAAA]: ";
	cin>>D1>>M1>>A1;
	
	int totalDias0 = (((A0-1)*12) + (M0-1))*30 + D0;
	int totalDias1 = (((A1-1)*12) + (M1-1))*30 + D1;
	
	cout<<"Dias entre as datas: "<<totalDias0 - totalDias1;
	
 	return 0;
}

