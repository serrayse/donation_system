#include "donation.h"
using namespace std;



void menu(){
	cout<<"\n\nBagis almak icin  1\nSisteme bagis yapmak icin  2\nBir kuruma bagis gondermek icin  3\nIslemi bitirmek icin  4:\t\t";
}



Money::Money(){
	name="-";
	surname="-";
	butce=0;
	posta="-";
	hane=0;
	setID(hane);
}


Money::Money(string na, string sur, float but, string p, int han){
	
	setName(na);
	setSurname(sur);
	setButce(but);
	setPosta(p);
	setHane(han);
	setID(han);
	
}


Money::~Money(){
	delete [] ID; 
    
}


Money::Money(Money &other){
	
	name=other.name;
	surname=other.surname;
	butce=other.butce;
	posta=other.posta;
	hane=other.hane;
	
	ID = new int[hane];
	for(int i=0; i<hane; ++i){
        ID[i] = other.ID[i];
    }  
	
}



void Money::setName(string i){
	while( !checkString(i)){
		cout<<"Gecersiz isim girisi, tekrar deneyiniz:";
		cin>>i;
	}
	name=i;
}



void Money::setSurname(string s){
	while( !checkString(s)){
		cout<<"\nGecersiz soyisim girisi, tekrar deneyiniz:";
		cin>>s;
	}
	surname=s;
}


void Money::setButce(float b){
	if (b <= 0){
	    butce=0;
	}
	else{
		butce=b;
	}

}




void Money::setPosta(string p){
	while( !checkPosta(p)){
		cout<<"Gecersiz, posta kodunu dogru hanede giriniz:";
		cin>>p;
	}
	posta=p;
}



void Money::setHane(int han){
	hane=han;
}


void Money::setID(int han){
	hane=han;
	ID = new int[hane];  //dynamic memory kullanımı
	for(int i=0; i<hane; ++i){
        ID[i]=rand()%9;
    }  
}




int Money::getButce(){
	return butce;
}

string Money::getPosta(){
	return posta;
}

string Money::getName(){
	return name;
}

string Money::getSurname(){
	return surname;
}

int Money::getHane(){
	return hane;
}




bool Money::checkString(string n){ // size metodu
	for(int check=0; check<n.size(); check++){
		if(!((n[check] >='A' && n[check] <='Z') || (n[check] >='a' && n[check] <='z'))){    
		   return false;	
		}
	}
	return true;
}





void Money::operator + (float miktar){  //bagis yapma
	while(miktar <= 0){
		cout<<"Gecersiz miktar, lutfen gecerli miktar giriniz:";
		cin>>miktar;
	}
	butce += miktar;
}


void Money::operator - (float miktar){  //bağis alma
	while(miktar <= 0 || miktar > butce){
		cout<<"Yeterli miktar yok, lutfen gecerli miktar giriniz:";
		cin>>miktar;
	}
	butce -= miktar;
}



bool Money::checkPosta(string posta){ // posta kodunun 5 haneli olmasi kontrolu

	
	if( posta.size() != 5){ //size metodu
		return false;
	}
	
	return true;

}


ostream &operator <<(ostream &out, const Money &obj){ //friend 

   out<<"----------------------------------------"<<endl
   <<"->"<<obj.name<<endl
   <<"->"<<obj.surname<<endl
   <<"->Posta kodu:"<<obj.posta<<endl
   <<"->Fonda bulunan toplam miktar:"<<obj.butce<<" TL"<<endl
   <<"->Gecici ID:";
   for(int i=0; i<obj.hane; ++i){
   	    out<<obj.ID[i]<<" ";
   }
   out<<"\n----------------------------------------"<<endl;
   return out;
}




void Money::donateMoneySociety(Money &oth, float miktar){ //yardim fonu uzerinden kuruma bagis yapma
	while(miktar <= 0 || butce < miktar){
		cout<<"Fonda yeterli miktar yok, gecerli miktar girmelisiniz:\t"<<endl;
		cin>>miktar;
	}
	
	butce -= miktar;
	oth.butce += miktar;
}

//----------------------------------------------------------------------------------------------------------------------


Stuff::Stuff(){
	isim="URUNLER";
	category=0;
	adet=72000;
	kurum="TUM KURUMLAR";

}


Stuff::Stuff(string i, int c, int a, string k){
	
	setIsim(i);
	setCategory(c);
	setAdet(a);
	setKurum(k);
	
}


Stuff::~Stuff(){
   
}


Stuff::Stuff(Stuff &other){
	
	isim=other.isim;
	category=other.category;
	adet=other.category;
	
}


bool Stuff::checkWord(string word){
	for(int i=0; i<word.size(); i++){
		if(!((word[i] >='A' && word[i] <='Z') || (word[i] >='a' && word[i] <='z'))){    
		   return false;	
		}
	}
	return true;
}


void Stuff::operator + (int al){
	
	while(al <= 0){
		cout<<"Gecersiz adet, lutfen gecerli sayi giriniz:";
		cin>>al;
	}
	adet += al;
	
}



void Stuff::operator - (int ver){ 
	while(ver <= 0 || ver > adet ){
		cout<<"Gecersiz adet, lutfen gecerli giris yapiniz:";
		cin>>ver;
	}
	adet -= ver;
}




ostream &operator <<(ostream &out, const Stuff &obj){ //friend 

   out<<"----------------------------------------"<<endl
   <<"->Urun ismi:"<<obj.isim<<endl
   <<"->Kategori:"<<obj.category<<endl
   <<"->Fonda bulunan esya:"<<obj.adet<<" adet"<<endl
   <<"->Kurum:"<<obj.kurum<<endl;
   
   out<<"----------------------------------------"<<endl;
   return out;
}



void Stuff::setIsim(string i){
	while( !checkWord(i)){
		cout<<"Gecersiz isim, tekrar deneyiniz:";
		cin>>i;
	}
	isim=i;
}



void Stuff::setKurum(string k){
	while( !checkWord(k)){
		cout<<"Gecersiz isim, tekrar deneyiniz:";
		cin>>k;
	}
	kurum=k;
}


void Stuff::setCategory(int c){
	
	category=c;
}


void Stuff::setAdet(int a){
	
	adet=a;
}



int Stuff::getCategory(){
	return category;
}

string Stuff::getIsim(){
	return isim;
}

int Stuff::getAdet(){
	return adet;
}
