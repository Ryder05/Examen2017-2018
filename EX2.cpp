#include <iostream>
#include<string>
#include<set>
using namespace  std;
class Mobile
{
private:
	long num;
	string nom;
	int prixMn;
public:
	friend class MobilePre;
	friend class MobilePost;
	virtual void operator+(double r)=0;
	friend  ostream& operator<<(ostream& os, Mobile& m)
	{
		m.print(os);
		return os;
	};
	virtual void print(std::ostream& os) const = 0;
	friend class Station;
	friend ostream& operator<<(ostream& os, MobilePre& m);
	friend ostream& operator<<(ostream& os, MobilePost& m);
	Mobile(int num,string nom,int prixMn):num{num},nom{nom},prixMn{prixMn}{}
};
class MobilePre :virtual public Mobile
{
	double duree;
	double remise;
	friend class Station;
public:
	MobilePre(int num, string nom, int prixMn, double duree, double remise) :Mobile(num, nom, prixMn), duree{ duree }, remise{ remise } { }
	virtual void print(ostream& os) const
	{
		cout << "Ligne Pre- payee - Numero : " << num << " - abonne : " << nom << " - duree des communication : " << duree << " - remise :" << remise << "%" << endl;

	}
	friend ostream& operator<<(ostream& os, MobilePre& m)
	{
		m.print(os);
		return os;
	}
	void operator+(double r)	{remise+=r;	}
	double facturer()
	{
		return static_cast<double>(duree)*prixMn*(1-static_cast<float>(remise)/100);
	}
};
class MobilePost:public virtual Mobile
{
	double solde;
	double bonus;
	friend class Station;

public:
	MobilePost(int num, string nom, int prixMn, float solde,float bonus) :Mobile(num, nom, prixMn), solde{solde}, bonus{bonus} {}
	virtual void print(ostream& os) const
	{
		cout<< "Ligne post-payee - Numero : " << num << " - abonne : " << nom << " - solde : " << solde << " - bonus :" << bonus << endl;
	}
	 friend ostream& operator<<(ostream& os, MobilePost& m) {
		m.print(os);
		return os;
	}
	void operator+(double r)
	{
		this->bonus= this->bonus+r;
	}

	void charger(double val)
	{
		solde+=val;
		bonus+=val*0.5;
	}
};
class Station
{
	set<Mobile*> s;
	string nom;
public:
	Station(string nom):nom{""}
	{
		this->nom=nom;

	}
	long chercher_num(string str)
	{
		for(Mobile* x:s)
		{
			if(x->nom==str)
			{
				return x->num;
			}
		}
		return 0;
	}
	bool ajouter(Mobile* m)
	{
		if(s.find(m)==s.end())
		{
			s.insert(m);
			return true;
		}
		return false;
	}
	void recompenser()
	{
		if(s.empty())
			return;
		for (auto x : s)
		{
			MobilePost* Mp = dynamic_cast<MobilePost*>(x);
			if (Mp == nullptr)
			{
				MobilePre* Mp = dynamic_cast<MobilePre*>(x);
				Mp->remise += 1;
			}
			else
			{
				Mp->bonus += 2;
			}
		}
	}
	void afficher()
	{
		for (Mobile* x : s)
		{
			cout<<*x;
		}
	}
};
int main()
{
	MobilePre m1(522220216,"Osama",1,200,10);
	m1+5;
	cout<<m1;
	auto r=m1.facturer();
	cout<<r<<endl;
	MobilePost m2(96481032,"Uma",1,5,50);
	cout<<m2<<endl;
	m2+10;
	m2.charger(5);
	cout<<m2<<endl;
	Station st("stationTT");
	st.ajouter(&m1);
	st.ajouter(&m2);
	st.ajouter(&m2);
	MobilePost m3(50403020,"Tbag",10,52,0);
	st.ajouter(&m3);
	MobilePre m4(966947, "Yusuf", 1.5, 20, 2);
	st.ajouter(&m4);
	cout<<st.chercher_num("Osama")<<endl;
	st.afficher();
	st.recompenser();
	cout<<"\n\t-----------Les Lignes Apres Recompense-----------------\n"<<endl;
	st.afficher();
	
}
