/* name: Vo Van Nhan
   class: K39C CNTT */
   
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std; 

class Printer
{
	protected:
		char *Name=new char ;
		int Soluong;
		Printer *p=NULL;
	public:
		Printer *next;
		Printer()
		{

		}
		Printer(char *t, int nu)
		{
			
			strcpy(Name,t);
			Soluong=nu;
			
		}
		
		void nhapkho(int q)
		{
			cout<<"Import "<<q<<" goods: "<<endl;
			for (int i=0; i<q; i++)
			{
				char *t=new char;
				cout<<"Enter name: ";
				fflush(stdin);
				gets(t);
				
				int nu;
				cout<<"Enter qualities: ";
				cin>>nu; 
				
				Printer *w = new Printer(t,nu);
				if (p==NULL) p=w;
				else
				{
					p->next=w;
					w=p;
				}
			}
		}
		
		void xuatkho(int q)
		{
			cout<<"Export "<<q<<" goods: "<<endl;
			while(p!=NULL)
			{
				cout<<"Name: "<<p->Name<<" | Qualities: "<<p->Soluong<<endl;
				p=p->next;
			}
		}
};

class Laser: virtual public Printer
{
	protected:
		int Dpi;
	public:
		void nhapkho(int q)
		{
			cout<<"Import "<<q<<" goods: "<<endl;
			for (int i=0; i<q; i++)
			{
				Printer *t=p;
				while (t!=NULL)
				{
					cout<<"Enter Dpi "<<q+1<<" : "<<endl;
					cin>>t->Dpi;
				}
	
				
			}
		}
			
};

class ColorPrinter: virtual public Printer
{
	protected:
		char *Color=new char;
	
};

class ColorLaser: public Laser, public ColorPrinter
{
	public:
		void printMax()
		{
			int k=0;
			Printer *temp=p;
			while(temp!=NULL)
			{
				if (temp->Soluong>k) k=temp->Soluong;
				temp=temp->next;
			}
			Printer *t=p;
			while(t!=NULL)
			{
				if (t->Soluong==k)
				cout<<"Name "<<t->Name<<"qualities: "<<t->Soluong;
				t=t->next;
			}
		}
};

int main()
{
	ColorLaser list[2];
	for (int i=0; i<2; i++)
	{
		list[i].Printer::nhapkho(2);
		list[i].Printer::xuatkho(2);
		list[i].Laser::nhapkho(2);
	}
	for (int i=0; i<2; i++)
	{
		list[i].printMax();
	}

}


