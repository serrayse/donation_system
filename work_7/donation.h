#ifndef donation_h_
#define donation_h_
#include<iostream>
#include<string>
using namespace std;

void menu();


class Money{
	
private:
	string name;
	string surname; // kisi ise soyad, kurum ise sehir bilgisi 
	float butce;
	string posta;
	int *ID; //dmm
	int hane;
	
	friend ostream &operator <<(ostream &out, const Money &obj); 
	
public:
	
	Money();
	Money(string na, string sur, float but=0, string pho = "", int han=0);
	Money(Money &other);
	~Money();
	bool checkString(string n);
	bool checkPosta(string posta);
	
	void operator + (float c); //(BAGIS YAPMA)   sisteme
	void operator - (float w); // (BAGIS ALMA)     sistemden
	void donateMoneySociety(Money &oth, float miktar); // (BAGIS YAPMA)  kuruma
	
	void setName(string i);
	void setSurname(string s);
	void setPosta(string p);
	void setButce(float b);
	void setHane(int han);
	void setID(int han);
	
	int getButce();
	string getPosta();
	string getName();
	string getSurname();
	int getHane();
	

		
}; 

//---------------------------------------------------------------------------------------------------------------------




class Stuff{
	
private:
	string isim;
	int category; //kiyafet=1, kirtasiye=2, mobilya=3, diger=4
	int adet;
	string kurum;
	
	friend ostream &operator <<(ostream &out, const Stuff &obj); 
	
public:
	Stuff();
	Stuff(string i, int c, int a=0, string k="");
	Stuff(Stuff &other);
	~Stuff();
	bool checkWord(string word);

	void operator + (int al); 
	void operator - (int ver); 


	void setIsim(string i);
	void setCategory(int c);
	void setAdet(int a);
	void setKurum(string k);
	
	int getCategory();
	string getIsim();
	int getAdet();

	
		
	
	
};








#endif