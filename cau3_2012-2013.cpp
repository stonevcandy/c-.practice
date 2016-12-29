#include<iostream>
using namespace std;

class Stack
{
	protected:
		int a[90];
		int n;
	public:
		Stack()
		{
			
			n=0;
		}
		
		void push(int k)
		{
			a[n++]=k;
		}
		
		int pop()
		{
			return a[n--];
		}
		
};

class Chuyendoi: public Stack
{
	protected:
		char **b;
	public:
		Chuyendoi(){
		}
		void chuyendoi1()
		{
			for (int i=0; i<n; ++i)
			{
				char *t=new char;
			//	b[i]=new char;
				int j=0;
				int a1=a[i];
				do
				{
					
					int p=a1%16; 
					switch (p)
					{
						case 10: t[j++]='A';
							break;
						case 11: t[j++]='B';
							break;
						case 12: t[j++]='C';//t[j++]='C';
							break;
						case 13: t[j++]='D';  
							break;
						case 14: t[j++]='E';
							break;
						case 15: t[j++]='F';
							break;
						default:
							t[j++]=p+48;  
					}
					cout<<t[j-1];
					a1/=16;
				}
				
				while(a1!=0);
					cout<<endl<<t<<endl;
				//	cout<<j<<endl;
				
				for (int k=0; k<(j-1)/2; k++ )
				{
					char temp=t[k];//cout<<temp<<endl;
					t[k]=t[j-k];
					t[j-k]=temp;
				}	
			
				cout<<"a["<<i<<"] = "<<t<<endl;							
			}
		}
};

int main()
{
	Chuyendoi a;
	a.push(29);
	a.push(28);
	a.chuyendoi1();
	
}
