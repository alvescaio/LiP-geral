#include <iostream>
using namespace std;

void intercalar(char s1[], char s2[], int tams1, int tams2){
	int i;
	int conts1 = 0, conts2 = 0;
	int tams3 = tams1 + tams2;
	char s3[tams3];
	
	for(i = 0; i < tams3; i++){
		
		if(i%2 == 0 && conts1 < tams1-1){
			s3[i] = s1[conts1];
			conts1++;
		}else if(i%2 != 0 && conts2 <tams2-1){
			s3[i] = s2[conts2];
			conts2++;
		}
		
		if(conts1 > tams2-1 && conts1 < tams1-1){
			s3[i] = s1[conts1];
			conts1++;
		}else if(conts2 > tams1-1 && conts2 <tams2-1){
			s3[i] = s2[conts2];
			conts2++;
		}
		
		cout<<"\nString 3 ["<<i+1<<"] = "<<s3[i];
		
	}
	
}

int main()
{
	
	char s1[5] = {'a','a', 'a', 'a'};
	char s2[6] = {'b', 'b', 'b', 'b', 'b'};

	intercalar(s1, s2, 5, 6);
	
	return 0;
}

