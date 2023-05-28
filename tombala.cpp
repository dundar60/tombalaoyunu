/* Ad : Yusuf Eren
   Soyad : DÜNDAR
   Öðrenci No : 200 757 036
   Bölüm : Bilgisayar Mühendisliði (2.Ö)
   Ders Adý : Nesneye Yönelik Programalama
   Ders Kodu : BIM-104-50-50-B
   Dersin Verildiði Dönem : 2021 Bahar Yarýyýlý
   Proje No : 1
   Dersi Veren : Ahmet COÞKUNÇAY
*/

#include <iostream>						
#include <cstdlib>							//Kütüphane deklerasyonlarý
#include <ctime>
using namespace std;

void KartlariOlustur(int [][15],int);
void KartAtamalari(int [][15],int [][15],int );			//Fonksiyon prototipleri
void TorbaIcerigi(int []);
void Puanlar(int ,int [][2]);

int main(int argc, char** argv) {
												//Gerekli deðiþken atamalarý
	int kartlar[10][15],kartsayi,oyuncuSayisi,torba[90]={0},oyuncuKartlari[5][15],y=0,oyuncuPuan[5][1]={0},d=1,e=1,f=1,sonPuanlar[5][2]={0},q=0;
	
	srand(time(0));					
	
	cout<<"Oyuncu sayisini giriniz : ";
	cin>>oyuncuSayisi;							//Oyuncu sayýsýný kullanýcýdan alma
	
for(int i=0;i<=2;i++)		//Oyunun 3 set dönmesi için oluþturulmuþ döngü
	{
				
	y=0;											
	d=1;
	e=1;
	f=1;
										//Her sette deðiþkenlerin sýfýrlanmasý için (34-48. satýrlar)
	for(int i=0;i<=4;i++)
	{
		oyuncuPuan[i][0]=0;
	}
	
	for(int i=0;i<=89;i++)
	{
		torba[i]=0;
	}												
	
	
	
	if(oyuncuSayisi>=2 && oyuncuSayisi<=5)			//Oyuncu sayýsý kurala uygun ise
	{	
		
		cout<<endl<<"--------------------------------------------------"<<endl<<i+1<<". Set"<<endl;
		cout<<"\nTombala kartlari..."<<endl<<"--------------------------------------------------"<<endl;
		
		KartlariOlustur(kartlar,kartsayi);	//Tombala kartlarýný oluþturan fonksiyonu çaðýrma
		
		cout<<"--------------------------------------------------"<<endl<<"Oyuncu Kartlari..."<<endl<<"--------------------------------------------------"<<endl;
		
		
	KartAtamalari(oyuncuKartlari,kartlar,oyuncuSayisi); //Oyunculara kart atamasý yapan fonksiyonu çaðýrma
	
	cout<<"---------------------------------------------------"<<endl;
	
	
	
	TorbaIcerigi(torba);		//Tombala torbasýný oluþturan fonksiyon
	
	
	
	
	while(y<=89)	//Oyuncu kartlarý ile torbadan çekilen sayýlarýn karþýlaþtýrmasý yapýlan döngü baþlangýcý
	{		
		for(int i=0;i<oyuncuSayisi;i++)
		{	
			
			for(int j=0;j<=14;j++)
			{
				if(oyuncuKartlari[i][j]==torba[y])
				{
					oyuncuKartlari[i][j]=(-1);			//Sayýlarýn karþýlaþtýrýlmasý ve uygun haldeyse -1 deðeri atamasý
					oyuncuPuan[i][0]+=1;				//Çinko ve tombalalarýn kontrolü için
					
				}
			
				
			}
			if(y<=89)		//Çinko ve tombalalarýn kontrolünün baþlangýcý
			{
				
				
				if(oyuncuPuan[i][0]==5 && d==1)						//1.Çinkonun kontrolü (93-105.satýrlar)
				{	sonPuanlar[i][1]+=5;	//Oyuncunun 1.çinkodan kazandýðý puanýn , puan dizisine eklenmesi 
					cout<<i+1<<".Oyuncu ilk cinkoyu yapti!!!"<<endl;		
					d=2;	//Ayný çinkoyu 1 den fazla oyuncu yapamayacaðý için program bu if bloðuna tekrar girmemelidir.Bu "d" deðiþkeni ile saðlanmýþtýr.
				for(int i=0;i<oyuncuSayisi;i++)							
				{	cout<<"\n";
					for(int j=0;j<15;j++)
					{
					cout<<oyuncuKartlari[i][j]<<" ";	//1.Çinko sonrasý son durum gözlenmesi için
					}
				}
					cout<<"\n\n";
				}
				
				if(oyuncuPuan[i][0]==10 && e==1)				//2.Çinkonun kontrolü (107-109.satýrlar)
				{	sonPuanlar[i][1]+=10;		//Puan eklemesi
					cout<<i+1<<".Oyuncu ikinci cinkoyu yapti!!!"<<endl;
					e=2;		//Bloða tekrar girmemesi için
				for(int i=0;i<oyuncuSayisi;i++)
				{	cout<<"\n";
					for(int j=0;j<15;j++)
					{
					cout<<oyuncuKartlari[i][j]<<" "; //Son durum yazdýrmasý
					}
				}
					cout<<"\n\n";
				}
				
				if(oyuncuPuan[i][0]==15 && f==1)			//Tombalanýn kontrolü (127-139.satýrlar)
				{	sonPuanlar[i][1]+=15;
					cout<<i+1<<".Oyuncu tombala yapti!!!"<<endl;
					f=2;	
					
				for(int i=0;i<oyuncuSayisi;i++)
				{	
					cout<<"\n";
					for(int j=0;j<15;j++)
					{
					cout<<oyuncuKartlari[i][j]<<" ";
					}
					
				}	
				
					cout<<"\n";
					cout<<"--------------------------------------------------"<<endl;
					break;	//Tombala yapýldýðýnda bulunulan setin sonlanmasý için
				}
			
				
			}	
			if(f==2)	//138. satýr sonrasý bir sonraki bloða çýkýþ için
			{
				break;
			}
			
			
		}
		if(f==2)	//Son olarak while döngüsünden çýkarmak için
			{
				break;
			}
		
		y++;	//While döngüsünün tekrar deðiþkeni
	}
	
	

}	
	
	
		else		//Oyuncu sayýsý uygun deðerlerde deðilse
		{	
			cout<<"\n";
			cout<<"Oyun min 2 , max 5 kisi ile oynanmaktadir. \nLutfen bu aralikta oyuncu seciniz"<<endl;
			q=1;	
			break;
		}
		
		if(q==1) break;	//Oyuncu sayýsý uygun deðerlerde olmadýðýnda programýn sonlanmasý için
		
		
	
}	
	if(q==0)	//Else bloðuna girilmediyse yani program normal akýþýnda devam ediyorsa
	{
	
	cout<<"\n"<<"Oyun sona erdi.\n\n"<<"--------------------------------------------------"<<endl;
	
	Puanlar(oyuncuSayisi,sonPuanlar);	//Oyun sona erer. Oyunu kazanan oyuncu açýklanýr ve tüm oyuncularýn sýrasýyla puanlarý yazdýrýlýr.
	
	}	
	system("PAUSE");
	
	return 0;
}

void KartlariOlustur(int dizi[][15],int kartsayisi)	//Tombala kartlarýný oluþturan fonksiyon
{
	
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=14;j++)
		{
			dizi[i][j]=rand()%90+1;		//Tombala kartlarýnýn tutulduðu diziye random sayýlarýn atanmasý
		}
	}
	for(int k=0;k<=9;k++)
	{	cout<<k+1<<".Kart :";
		for(int l=0;l<=14;l++)		//Yazdýrma iþlemleri (198-207)
		{	cout<<" ";
			cout<<dizi[k][l];
			
		}
		
		cout<<"\n";
	}
}

void KartAtamalari(int dizi[][15],int dizi1[][15],int length)	//Oyunculara kart atamasýný yapan fonksiyon
{	int m=0;
	m=0;
	for(int i=1;i<=length;i++)
	{	
		int x=rand()%10;		/*x sayýsý random olarak seçilir ve tombala kartlarýndan rastgele bir satýr 
									seçilmesi için yani dizinin satýr indisini belirlemesi için kullanýlýr (221.satýr)*/
		cout<<i<<". Oyuncunun Karti : ";
	
	for(int j=0;j<=14;j++)
	{	
		dizi[m][j]=dizi1[x][j];	//Tombala kartlarýndan rastgele seçilen bir kart oyuncuya atanýr
		cout<<dizi[m][j]<<" ";
	}
	
		cout<<"\n";
		m++;
	}
}

void TorbaIcerigi(int dizi[])	//Tombala torbasýný oluþturan fonksiyon

{	
	
	
	for(int i=1;i<=90;i++)	//Torbaya 1-90 sayýlarý random ve eksiksiz bir þekilde atanýr
	{	
	while(true)
	
	{
		int z=rand()%90;		//z random seçilir. Dizinin satýr indisini belirler. 
		
		if(dizi[z]==0)
		{
		
		dizi[z]=i;	//For döngüsünden sýrasýyla gelen deðer torba dizisinin rastgele seçilen satýrýna atanýr
		break;
		
		}
	}
		
	}
	

	cout<<"Torbadan Cekilen sayilar..."<<endl<<"-----------------------------------------------";
	for(int j=0;j<=89;j++)
	{	if(j%10==0) cout<<"\n";
																		//Torbanýn içeriðini yazdýrma (254-261)
		cout<<" "<<dizi[j]<<" ";
		
	}
	cout<<"\n"<<"-----------------------------------------------"<<endl;
}

void Puanlar(int length,int dizi[][2])	//Oyuncularýn puanlarýný ve sýralamalarýný tutan ve bunlarý deðerlerine göre sýralayan fonksiyon
{	
	int gecici,geciciSira;

	for(int i=0;i<length;i++)
	{
		dizi[i][0]=(i+1);
	}
	for(int j=0;j<(length-1);j++)
	{
	
	for(int i=0;i<(length-1);i++) 
        { 
        
        if(dizi[i][1]<dizi[i+1][1]) 
        { 
        gecici=dizi[i][1]; 
        dizi[i][1]=dizi[i+1][1]; 				//Bubble Sort yöntemi ile puanlarý büyükten küçüðe sýralama (280-282)
        dizi[i+1][1]=gecici; 				//ve o puana sahip olan oyuncunun hangi numaralý oyuncu olduðunu sýrasýyla yazdýrma (283-285)							
        geciciSira=dizi[i][0];
        dizi[i][0]=dizi[i+1][0];
        dizi[i+1][0]=geciciSira;
        }
		}	
	}
	
	cout<<"Kazanan "<<dizi[0][1]<<" puan ile "<<dizi[0][0]<<". oyuncu\n\n"<<"Sonuclar:\n"<<endl;
	
	for(int i=0;i<length;i++)															//Sonuçlarý açýklama (290-295)
	{
		cout<<dizi[i][0]<<".Oyuncu "<<dizi[i][1]<<" P"<<endl;
	}
}
