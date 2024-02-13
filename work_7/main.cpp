#include "donation.h"
#include <cassert>
#include <time.h>
using namespace std;


int main(){

    srand(time(NULL));

    cout<<"\t\t\t-----------------------";
    cout<<"\n\t\t\t  BAGIS HESAP SISTEMI\n";
    cout<<"\t\t\t-----------------------\n\n";
    
    int choose;
    cout<<"\t\t\tPARA bagis islemleri icin  1\n\t\t\tESYA bagis islemleri icin  2\n\t\t\tEk uyelik olusturmak icin  3\t\t";
    cin>>choose;
    

if(choose==1){ //PARA


    int secim;
    float cekilen_miktar, yatirilan_miktar, gonderilen_miktar;
    
    string bir_na, bir_sur, bir_pho;
    int bir_han;
    float bir_but=3000.0;
    
    string iki_na, iki_sur, iki_pho;
    int iki_han;
    float iki_but=250000.0;
    
    
	menu();
    cin>>secim;
    assert(( secim==1 || secim==2 || secim==3 || secim==4 ) );
    
    Money bir;
    if(secim==1 || secim==2 || secim==3){
	
    cout<<"\nBilgileri giriniz,"<<endl;
    cout<<"Isim:";
	cin>>bir_na;
	bir.setName(bir_na);
	
    cout<<"Soyisim:";
	cin>>bir_sur;
	bir.setSurname(bir_sur);
	
    cout<<"Posta kodu:";
	cin>>bir_pho;
	bir.setPosta(bir_pho);
	
    cout<<"Bagis kartinizda yazan uye no hane sayisi:";
	cin>>bir_han;
	bir.setHane(bir_han);
	
	bir.setID(bir_han);
	bir.setButce(bir_but);
				
    cout<<bir;
    }
    			
    while(secim != 4){
    	switch(secim){
    		case 1:{
    			
    			cout<<"Gereken miktari giriniz:";
    			cin>>cekilen_miktar;
    			bir - cekilen_miktar;
    			cout<<"\n--GUNCEL--"<<endl;
    			cout<<bir;
    			
				menu();
                cin>>secim;
                assert(( secim==1 || secim==2 || secim==3 || secim==4 ) );
				break;
			}
			
			case 2:{
				
				cout<<"\n-----------------------------------------\n";
    			cout<<"Sisteme yapacaginiz bagis miktarini giriniz:";
    			cin>>yatirilan_miktar;
    			bir + yatirilan_miktar; 
    		    cout<<"\n--GUNCEL--"<<endl;
    			cout<<bir;
    			
				menu();
                cin>>secim;
                assert(( secim==1 || secim==2 || secim==3 || secim==4 ) );
				
				break;
			}
			
			case 3:{
				
				Money iki;
				cout<<"\nBagis yapacaginiz kurumun bilgilerini giriniz,"<<endl;
                cout<<"Kurum adi:";
	            cin>>iki_na;
	            iki.setName(iki_na);
	            
                cout<<"Kurumun bulundugu il:";
	            cin>>iki_sur;
	            iki.setSurname(iki_sur);
	            
                cout<<"Posta kodu:";
	            cin>>iki_pho;
	            iki.setPosta(iki_pho);
	            
                cout<<"Kurum kodunun hane sayisi:";
	            cin>>iki_han;
	            
	            iki.setID(iki_han);
	            iki.setButce(iki_but); 
				
				cout<<"Bagis yapacaginiz miktari giriniz:";
    			cin>>gonderilen_miktar;
    			bir.donateMoneySociety(iki,gonderilen_miktar); 
    		    cout<<"\n--GUNCEL--"<<endl;
    			cout<<bir;
    			cout<<iki;
    			
				menu();
                cin>>secim;
                assert(( secim==1 || secim==2 || secim==3 || secim==4 ) );
				
				break;
			}
			
			default:{
				cout<<"Hatali giris"<<endl;
				menu();
                cin>>secim;
                assert(( secim==1 || secim==2 || secim==3 || secim==4 ) );
				
				break;
			}
			
		}
	}

   
}
	



	
if(choose==2){ //ESYA
	
	
	int secmek;
	int cekilen_adet=0, yatirilan_adet=0, gonderilen_adet;
	
	string first_is, first_kur;
    int first_cat, first_ad;
    
    string second_is, second_kur;
    int second_cat;
    
    string third_is, third_kur;
    int third_cat;
    
    
    int uye;
    
    cout<<"\n\t\t\tUyelik kartinizda bulunan uye numarasini giriniz:  ";
    cin>>uye;
    cout<<"\t\t\t"<<uye<<" no'lu uye icin islem baslatildi."<<endl;
	
	menu();
    cin>>secmek;
    assert(( secmek==1 || secmek==2 || secmek==3 || secmek==4 ) );
    
    
	
    while(secmek != 4){
    	switch(secmek){
    		case 1:{
    			
    			Stuff first;
    			cout<<first;
    			
                cout<<"\nEsya bilgilerini giriniz,"<<endl;
                cout<<"Esya ismi:";
                cin>>first_is;
                first.setIsim(first_is);
             
    			
                cout<<"Kategori bilgisi giriniz (kiyafet icin 1, kirtasiye icin 2, mobilya icin 3, diger 4) :";
                cin>>first_cat;
                first.setCategory(first_cat);
    			
                cout<<"Ihtiyaciniz olan urunun adet bilgisini giriniz:";
                cin>>cekilen_adet;
                first - cekilen_adet;
    		
    			cout<<"\n--GUNCEL--"<<endl;
    			cout<<first;
    			
    		    
				menu();
                cin>>secmek;
                assert(( secmek==1 || secmek==2 || secmek==3 || secmek==4 ) );
				break;
			}
			
			case 2:{
				
				Stuff second;
                cout<<"\nEsya bilgilerini giriniz,"<<endl;
                cout<<"Esya ismi:";
                cin>>second_is;
                second.setIsim(second_is);
                
    			cout<<"Kategori bilgisi giriniz (kiyafet icin 1, kirtasiye icin 2, mobilya icin 3, diger 4) :";
                cin>>second_cat;
                second.setCategory(second_cat);
    			
    			second.setAdet(72000-cekilen_adet);
                cout<<"Bagislamak istediginiz urunun adet bilgisini giriniz:";
                cin>>yatirilan_adet;
                second + yatirilan_adet;
    		
    			cout<<"\n--GUNCEL--"<<endl;
    			cout<<second;
				
    		    menu();
                cin>>secmek;
                assert(( secmek==1 || secmek==2 || secmek==3 || secmek==4 ) );
				
				break;
			}
			
			case 3:{
				
				Stuff third;
				cout<<"\nBagis yapacaginiz kurumun adini giriniz:";
				cin>>third_kur;
				third.setKurum(third_kur);
				
				
				cout<<"Esya ismi:";
                cin>>third_is;
                third.setIsim(third_is);
                
                cout<<"Kategori bilgisi giriniz (kiyafet icin 1, kirtasiye icin 2, mobilya icin 3, diger 4) :";
                cin>>third_cat;
                third.setCategory(third_cat);
                
                third.setAdet((72000-cekilen_adet)+yatirilan_adet);
                cout<<"Bagislamak istediginiz urunun adet bilgisini giriniz:";
                cin>>yatirilan_adet;
                third + yatirilan_adet;
    		
    			cout<<"\n--GUNCEL--"<<endl;
    			cout<<third;
				
			    menu();
                cin>>secmek;
                assert(( secmek==1 || secmek==2 || secmek==3 || secmek==4 ) );
                
				break;
			}
			
			default:{
				cout<<"Hatali giris"<<endl;
				menu();
                cin>>secmek;
                assert(( secmek==1 || secmek==2 || secmek==3 || secmek==4 ) );
				
				break;
			}
			
		}
	}

	
}
	

	
if(choose==3){ // EK UYELIK (copy constructor)

    Money uye;
    
    string NAME,SURNAME,POSTA;
    int hanee;
    
    cout<<"\nBilgileri giriniz,"<<endl;
    cout<<"Isim:";
	cin>>NAME;
	uye.setName(NAME);
	
    cout<<"Soyisim:";
	cin>>SURNAME;
	uye.setSurname(SURNAME);
	
    cout<<"Posta kodu:";
	cin>>POSTA;
	uye.setPosta(POSTA);
	
    cout<<"Bagis kartinizda yazan uye no hane sayisi:";
	cin>>hanee;
	uye.setHane(hanee);
	
	cout<<"\n--------------------------------------"<<endl;
	cout<<"Isim: "<<uye.getName()<<endl;
	cout<<"Soyisim: "<<uye.getSurname()<<endl;
	cout<<"Posta kodu: "<<uye.getPosta()<<endl;
	cout<<"Uye kartinda bulunan hane sayisi: "<<uye.getHane()<<endl;
	cout<<"--------------------------------------"<<endl;
	
	Money ekUye(uye);
	
	cout<<"\nVar olan hesabiniza ek uyeliginiz olusturulmustur.(copied)"<<endl;
	
	cout<<"\n--------------------------------------"<<endl;
	cout<<"Isim: "<<ekUye.getName()<<endl;
	cout<<"Soyisim: "<<ekUye.getSurname()<<endl;
	cout<<"Posta kodu: "<<ekUye.getPosta()<<endl;
	cout<<"Uye kartinda bulunan hane sayisi: "<<ekUye.getHane()<<endl;
	cout<<"--------------------------------------"<<endl;
	
	
	
}	
	
	

	
	

    return 0;

}