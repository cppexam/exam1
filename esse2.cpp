#include <iostream>
#include <string.h>


class MicroSxem
{
private:
  int v;
public:
	MicroSxem();
	MicroSxem(int);
	~MicroSxem();
	void SetV(int);
	int GetV();
	MicroSxem & operator=(MicroSxem&);
};

class MobPhone
{
private:
	MicroSxem m;
	char * f;
public:
	MobPhone();
	MobPhone(MicroSxem, char*);
	MobPhone(MobPhone&);
	virtual ~MobPhone();
	void SetF(char *);
	char * GetF();
	MicroSxem & GetM();
	virtual void print();
	MobPhone & operator=(MobPhone&);
};
 class MobPhoneVideo : private MobPhone
 {
 private:
 	int k;
 public:
 	MobPhoneVideo();
 	MobPhoneVideo(MicroSxem, char*,int);
 	MobPhoneVideo(MobPhone,int);
 	~MobPhoneVideo();
 	void SetK(int);
 	int GetK();
 	void print();
 	MobPhoneVideo & operator=(MobPhoneVideo &);
 };

int main()
{

	//MobPhone p;
	//p.print();
	MicroSxem q(10);

	//MobPhoneVideo p2(q, "Intel", 100);
	MobPhone a(q, "Sony");
	//a.print();
	MobPhone b,c, *d;
	d = new MobPhone();
	(*d)=c=b=a;

	MobPhoneVideo p2(*d, 110);
	p2.print();
	delete d;
	return 0;
}


MicroSxem::MicroSxem():v(0)
{std::cout<<"\t\t\t working constructor no param MicroSxem"<<std::endl;}
MicroSxem::MicroSxem(int av):v(av)
{std::cout<<"\t\t\t working constructor param MicroSxem"<<std::endl;}
MicroSxem::~MicroSxem()
{std::cout<<"\t\t\t working destruct MicroSxem"<<std::endl;}
MicroSxem & MicroSxem::operator=(MicroSxem & am)
{
	if (this!=&am)
	{
		/* code */
	}
	v=am.v;
	return *this;
}
void MicroSxem::SetV(int av)
{
	v=av;
}
int MicroSxem::GetV()
{
	return v;
}



MobPhone::MobPhone():m(0)
{
	f = new char[5];
	strcpy(f, "NULL");
	std::cout<<"\t\t\t working construct no param MobPhone"<<std::endl;
}
MobPhone::MobPhone(MicroSxem am, char* af):m(am)
{
	f = new char[strlen(af)+1];
	strcpy(f, af);
	std::cout<<"\t\t\t working construct param MobPhone"<<std::endl;
}
MobPhone::MobPhone(MobPhone& mf)
{
	m=mf.m;
	f = new char[strlen(mf.f)+1];
	strcpy(f, mf.f);
}
MobPhone::~MobPhone()
{
	delete [] f;
	std::cout<<"\t\t\t working destruct MobPhone"<<std::endl;
}
void MobPhone::SetF(char* af)
{
	delete [] f;
	f = new char[strlen(af)+1];
	strcpy(f, af);
}
char * MobPhone::GetF()
{
	return f;
}
MicroSxem & MobPhone::GetM()
{
	return m;
}
void MobPhone::print()
{
	std::cout << "MicroSxem GB = " << m.GetV()
	<<"\nFirma : "<< f << std::endl;
}
MobPhone & MobPhone::operator=(MobPhone& mob)
{
	if (this!=&mob)
	{
		//m=mob.m;
		m = mob.GetM();
		delete [] f;
		f=new char[strlen(mob.f)+1];
		strcpy(f, mob.f);
	}
	return *this;
}




MobPhoneVideo::MobPhoneVideo():k(0)
{ 
	std::cout<<"\t\t\t working construct no param MobPhoneVideo"<<std::endl; 
}
MobPhoneVideo::MobPhoneVideo(MicroSxem am, char* af,int ak):MobPhone(am, af), k(ak)
{
	std::cout<<"\t\t\t working construct param MobPhoneVideo"<<std::endl; 
}
MobPhoneVideo::MobPhoneVideo(MobPhone ap,int ak): MobPhone(ap), k(ak)
{
	std::cout<<"\t\t\t working construct param MobPhoneVideo"<<std::endl; 
}
MobPhoneVideo::~MobPhoneVideo()
{
	std::cout<<"\t\t\t working destruct MobPhoneVideo"<<std::endl; 
}
void MobPhoneVideo::SetK(int ak)
{
	k=ak;
}
int MobPhoneVideo::GetK()
{
	return k;
}
void MobPhoneVideo::print()
{
	MobPhone::print();
	std::cout<<"Karta :" << k <<std::endl;
}
