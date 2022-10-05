#include <iostream> 
using namespace std;

int main()
{ 
    int M,N,K,i;
    char letter;
	cin>>M>>N>>K;
	letter=M;
	for(i=M; i<N; i++)
	{
	   cout<<letter;
	   letter++;
	    if ((i-M+1)%K==0)
	      cout<<endl;
    }
	return 0;	
}
