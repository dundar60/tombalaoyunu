/* Ad : Yusuf Eren
   Soyad : D�NDAR
   ��renci No : 200 757 036
   B�l�m : Bilgisayar M�hendisli�i (2.�)
   Ders Ad� : Nesneye Y�nelik Programalama
   Ders Kodu : BIM-104-50-50-B
   Dersin Verildi�i D�nem : 2021 Bahar Yar�y�l�
   Proje No : 1
   Dersi Veren : Ahmet CO�KUN�AY
*/

#include <iostream>						
#include <cstdlib>							//K�t�phane deklerasyonlar�
#include <ctime>
using namespace std;

void KartlariOlustur(int [][15],int);
void KartAtamalari(int [][15],int [][15],int );			//Fonksiyon prototipleri
void TorbaIcerigi(int []);
void Puanlar(int ,int [][2]);

int main(int argc, char** argv) {
												//Gerekli de�i�ken atamalar�
	int kartlar[10][15],kartsayi,oyuncuSayisi,torba[90]={0},oyuncuKartlari[5][15],y=0,oyuncuPuan[5][1]={0},d=1,e=1,f=1,sonPuanlar[5][2]={0},q=0;
	
	srand(time(0));					
	
	cout<<"Oyuncu sayisini giriniz : ";
	cin>>oyuncuSayisi;							//Oyuncu say�s�n� kullan�c�dan alma
	
for(int i=0;i<=2;i++)		//Oyunun 3 set d�nmesi i�in olu�turulmu� d�ng�
	{
				
	y=0;											
	d=1;
	e=1;
	f=1;
										//Her sette de�i�kenlerin s�f�rlanmas� i�in (34-48. sat�rlar)
	for(int i=0;i<=4;i++)
	{
		oyuncuPuan[i][0]=0;
	}
	
	for(int i=0;i<=89;i++)
	{
		torba[i]=0;
	}												
	
	
	
	if(oyuncuSayisi>=2 && oyuncuSayisi<=5)			//Oyuncu say�s� kurala uygun ise
	{	
		
		cout<<endl<<"--------------------------------------------------"<<endl<<i+1<<". Set"<<endl;
		cout<<"\nTombala kartlari..."<<endl<<"--------------------------------------------------"<<endl;
		
		KartlariOlustur(kartlar,kartsayi);	//Tombala kartlar�n� olu�turan fonksiyonu �a��rma
		
		cout<<"--------------------------------------------------"<<endl<<"Oyuncu Kartlari..."<<endl<<"--------------------------------------------------"<<endl;
		
		
	KartAtamalari(oyuncuKartlari,kartlar,oyuncuSayisi); //Oyunculara kart atamas� yapan fonksiyonu �a��rma
	
	cout<<"---------------------------------------------------"<<endl;
	
	
	
	TorbaIcerigi(torba);		//Tombala torbas�n� olu�turan fonksiyon
	
	
	
	
	while(y<=89)	//Oyuncu kartlar� ile torbadan �ekilen say�lar�n kar��la�t�rmas� yap�lan d�ng� ba�lang�c�
	{		
		for(int i=0;i<oyuncuSayisi;i++)
		{	
			
			for(int j=0;j<=14;j++)
			{
				if(oyuncuKartlari[i][j]==torba[y])
				{
					oyuncuKartlari[i][j]=(-1);			//Say�lar�n kar��la�t�r�lmas� ve uygun haldeyse -1 de�eri atamas�
					oyuncuPuan[i][0]+=1;				//�inko ve tombalalar�n kontrol� i�in
					
				}
			
				
			}
			if(y<=89)		//�inko ve tombalalar�n kontrol�n�n ba�lang�c�
			{
				
				
				if(oyuncuPuan[i][0]==5 && d==1)						//1.�inkonun kontrol� (93-105.sat�rlar)
				{	sonPuanlar[i][1]+=5;	//Oyuncunun 1.�inkodan kazand��� puan�n , puan dizisine eklenmesi 
					cout<<i+1<<".Oyuncu ilk cinkoyu yapti!!!"<<endl;		
					d=2;	//Ayn� �inkoyu 1 den fazla oyuncu yapamayaca�� i�in program bu if blo�una tekrar girmemelidir.Bu "d" de�i�keni ile sa�lanm��t�r.
				for(int i=0;i<oyuncuSayisi;i++)							
				{	cout<<"\n";
					for(int j=0;j<15;j++)
					{
					cout<<oyuncuKartlari[i][j]<<" ";	//1.�inko sonras� son durum g�zlenmesi i�in
					}
				}
					cout<<"\n\n";
				}
				
				if(oyuncuPuan[i][0]==10 && e==1)				//2.�inkonun kontrol� (107-109.sat�rlar)
				{	sonPuanlar[i][1]+=10;		//Puan eklemesi
					cout<<i+1<<".Oyuncu ikinci cinkoyu yapti!!!"<<endl;
					e=2;		//Blo�a tekrar girmemesi i�in
				for(int i=0;i<oyuncuSayisi;i++)
				{	cout<<"\n";
					for(int j=0;j<15;j++)
					{
					cout<<oyuncuKartlari[i][j]<<" "; //Son durum yazd�rmas�
					}
				}
					cout<<"\n\n";
				}
				
				if(oyuncuPuan[i][0]==15 && f==1)			//Tombalan�n kontrol� (127-139.sat�rlar)
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
					break;	//Tombala yap�ld���nda bulunulan setin sonlanmas� i�in
				}
			
				
			}	
			if(f==2)	//138. sat�r sonras� bir sonraki blo�a ��k�� i�in
			{
				break;
			}
			
			
		}
		if(f==2)	//Son olarak while d�ng�s�nden ��karmak i�in
			{
				break;
			}
		
		y++;	//While d�ng�s�n�n tekrar de�i�keni
	}
	
	

}	
	
	
		else		//Oyuncu say�s� uygun de�erlerde de�ilse
		{	
			cout<<"\n";
			cout<<"Oyun min 2 , max 5 kisi ile oynanmaktadir. \nLutfen bu aralikta oyuncu seciniz"<<endl;
			q=1;	
			break;
		}
		
		if(q==1) break;	//Oyuncu say�s� uygun de�erlerde olmad���nda program�n sonlanmas� i�in
		
		
	
}	
	if(q==0)	//Else blo�una girilmediyse yani program normal ak���nda devam ediyorsa
	{
	
	cout<<"\n"<<"Oyun sona erdi.\n\n"<<"--------------------------------------------------"<<endl;
	
	Puanlar(oyuncuSayisi,sonPuanlar);	//Oyun sona erer. Oyunu kazanan oyuncu a��klan�r ve t�m oyuncular�n s�ras�yla puanlar� yazd�r�l�r.
	
	}	
	system("PAUSE");
	
	return 0;
}

void KartlariOlustur(int dizi[][15],int kartsayisi)	//Tombala kartlar�n� olu�turan fonksiyon
{
	
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=14;j++)
		{
			dizi[i][j]=rand()%90+1;		//Tombala kartlar�n�n tutuldu�u diziye random say�lar�n atanmas�
		}
	}
	for(int k=0;k<=9;k++)
	{	cout<<k+1<<".Kart :";
		for(int l=0;l<=14;l++)		//Yazd�rma i�lemleri (198-207)
		{	cout<<" ";
			cout<<dizi[k][l];
			
		}
		
		cout<<"\n";
	}
}

void KartAtamalari(int dizi[][15],int dizi1[][15],int length)	//Oyunculara kart atamas�n� yapan fonksiyon
{	int m=0;
	m=0;
	for(int i=1;i<=length;i++)
	{	
		int x=rand()%10;		/*x say�s� random olarak se�ilir ve tombala kartlar�ndan rastgele bir sat�r 
									se�ilmesi i�in yani dizinin sat�r indisini belirlemesi i�in kullan�l�r (221.sat�r)*/
		cout<<i<<". Oyuncunun Karti : ";
	
	for(int j=0;j<=14;j++)
	{	
		dizi[m][j]=dizi1[x][j];	//Tombala kartlar�ndan rastgele se�ilen bir kart oyuncuya atan�r
		cout<<dizi[m][j]<<" ";
	}
	
		cout<<"\n";
		m++;
	}
}

void TorbaIcerigi(int dizi[])	//Tombala torbas�n� olu�turan fonksiyon

{	
	
	
	for(int i=1;i<=90;i++)	//Torbaya 1-90 say�lar� random ve eksiksiz bir �ekilde atan�r
	{	
	while(true)
	
	{
		int z=rand()%90;		//z random se�ilir. Dizinin sat�r indisini belirler. 
		
		if(dizi[z]==0)
		{
		
		dizi[z]=i;	//For d�ng�s�nden s�ras�yla gelen de�er torba dizisinin rastgele se�ilen sat�r�na atan�r
		break;
		
		}
	}
		
	}
	

	cout<<"Torbadan Cekilen sayilar..."<<endl<<"-----------------------------------------------";
	for(int j=0;j<=89;j++)
	{	if(j%10==0) cout<<"\n";
																		//Torban�n i�eri�ini yazd�rma (254-261)
		cout<<" "<<dizi[j]<<" ";
		
	}
	cout<<"\n"<<"-----------------------------------------------"<<endl;
}

void Puanlar(int length,int dizi[][2])	//Oyuncular�n puanlar�n� ve s�ralamalar�n� tutan ve bunlar� de�erlerine g�re s�ralayan fonksiyon
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
        dizi[i][1]=dizi[i+1][1]; 				//Bubble Sort y�ntemi ile puanlar� b�y�kten k����e s�ralama (280-282)
        dizi[i+1][1]=gecici; 				//ve o puana sahip olan oyuncunun hangi numaral� oyuncu oldu�unu s�ras�yla yazd�rma (283-285)							
        geciciSira=dizi[i][0];
        dizi[i][0]=dizi[i+1][0];
        dizi[i+1][0]=geciciSira;
        }
		}	
	}
	
	cout<<"Kazanan "<<dizi[0][1]<<" puan ile "<<dizi[0][0]<<". oyuncu\n\n"<<"Sonuclar:\n"<<endl;
	
	for(int i=0;i<length;i++)															//Sonu�lar� a��klama (290-295)
	{
		cout<<dizi[i][0]<<".Oyuncu "<<dizi[i][1]<<" P"<<endl;
	}
}
