#include <iostream>
#include <string.h>
const int YMAX = 120;
class Person
{
private:
  int y;
	char *c;
public:
	Person();
	Person(int, char*);
	~Person();
	void SetYear(int);
	int GetYear();
	void SetC(char*);
	char* GetC();
	virtual void print();
	virtual void operator--();
};

class Sovlet : public Person
{
private:
	char *p;
public:
	Sovlet();
	Sovlet(int, char*,char*);
	~Sovlet();
	void SetP(char*);
	char* GetP();
	void print();
	void operator--();
};
int main()
{
/*	Person p;
	p.print();
	Person p1(20,"Gorlovka");
	p1.print();
*/

	Sovlet s;
	Sovlet s1(20,"Makeevka", "1234567890");
	s.print();

	s1.print();
	--s1;
	s1.print();


	Sovlet s2(0,"Donetsk", "123");
	s2.print();
	--s2;
	s2.print();


	return 0;
}

Person::Person():y(0)
{
	c = new char[5];
	strcpy(c, "NULL");
	std::cout<<"\t\t\t working construct no param Person"<<std::endl;
}
Person::Person(int ay, char* ac): y(ay)
{
	c = new char[strlen(ac)+1];
	strcpy(c, ac);
	std::cout<<"\t\t\t working construct param Person"<<std::endl;
}
Person::~Person()
{
	delete [] c;
	std::cout<<"\t\t\t working destruct Person"<<std::endl;
}
void Person::SetYear(int ay)
{
	y=ay;
}
int Person::GetYear()
{
	return y;
}
void Person::SetC(char* ac)
{
	delete [] c;
	c = new char[strlen(ac)+1];
	strcpy(c, ac);
}
char* Person::GetC()
{	
	return c;
}
void Person::print()
{
	std::cout << "Vozrast = " << y 
	 << "\nMesto rojdeniya: " << c<<std::endl;
}
void Person::operator--()
{
	y--;
}
Sovlet::Sovlet()
{
	p = new char[5];
	strcpy(p, "NULL");
	std::cout<<"\t\t\t working construct no param Sovlet"<<std::endl;
}
Sovlet::Sovlet(int ay,char* ac, char* ap):Person(ay,ac)
{
	delete [] p;
	p = new char[strlen(ap)+1];
	strcpy(p, ap);
	std::cout<<"\t\t\t working construct param Sovlet"<<std::endl;
}
Sovlet::~Sovlet()
{
	delete [] p;
	std::cout<<"\t\t\t working destruct Sovlet"<<std::endl;
}
void Sovlet::SetP(char* ap)
{
	delete [] p;
	p = new char[strlen(ap)+1];
	strcpy(p, ap);
}
char* Sovlet::GetP()
{
	return p;
}
void Sovlet::print()
{
	Person::print();
	std::cout << "pasport: "<< p<<std::endl;
}
void Sovlet::operator--()
{
	if (GetYear()==0)
	{
		SetYear(YMAX);
	}
	else
		Person::operator--();
}
