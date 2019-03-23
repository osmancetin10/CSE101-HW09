						/***************************/
						/*                         */
						/*      Osman Çetin        */
						/*       161044069         */
						/*          HW-9           */
						/*                         */
						/***************************/
#include <stdio.h>
#include <time.h>/*bu kütüphane random sayı almaya yarar*/
#include <stdlib.h>/*bu kütüphane random sayı almaya yarar*/
#include <math.h>/*bu kütüphane matematiksel terimleri kullanmaya yarar*/
int main(){
/* Bu kodumuzda 20 elemanlı, elemanları random atanan, iki vektörün L0 normunu hesaplayan, iki vektörü toplayan, ve iki vektörün kosinüs benzerliğini(cosine similarity) hesaplayan işlemler vardır*/ 
	printf("***************************************************\n");
	int v1[20],v2[20],v3[20];
	int i,j,k=0,l,m,iccarpim=1,havuz=0,pay=0,payda1=0,kare1=0,kare2=0,payda2=0;
	double payda3,payda4,sonuc,payda;
	srand(time(NULL));/*random sayı fonksiyonu*/
	for(i=0;i<20;i++){/*bu döngümüz vektörlerimize random sayı atmaya yarıyor*/
		v1[i]=rand()%10;/*10 ile modunu almamızın sebebi 0ile 10 arasında bir sayı elde etmek*/
		v2[i]=rand()%10;
	}

	printf("Vektörler:\n");
	printf("v1:");
	for(j=0;j<19;j++){/*bu döngümüzde v1 vektörümüzü yazdırıyoruz*/
		printf("%d,",v1[j]);
	}
	printf("%d\n",v1[19]);
	printf("v2:");
	for(j=0;j<19;j++){/*bu döngümüzde v2 vektörümüzü yazdırıyoruz*/
		printf("%d,",v2[j]);
	}
	printf("%d\n\n",v2[19]);
	
	for(i=0;i<20;i++){/*bu döngüde iki vektöründe L0 normu hesaplanıyor*/
		if(v1[i]!=0){/*v1 vektörünün bütün elemanları gözden geçerilir. 0 olmayan her eleman için integer 1 artırılır*/
			k++;
		}
		if(v2[i]!=0){/*v2 vektörünün bütün elemanları gözden geçerilir. 0 olmayan her eleman için integer 1 artırılır*/
			l++;
		}
	}

	
	printf("v1 L0 norm:%d\n",k);/*daha sonra her seferinde 1 artırdığımız integerlerimiz yazdırılır*/
	printf("v2 L0 norm:%d\n",l);/*daha sonra her seferinde 1 artırdığımız integerlerimiz yazdırılır*/
	printf("\n");	
	for(i=0;i<20;i++){/*bu döngümüz iki vektörümüzü toplayıp yeni bir vektöre atıyor*/
		v3[i]=v1[i]+v2[i];
	}
	printf("v1+v2=");/*daha sonra bu yeni vektörümüzü yazdırırız*/
	for(j=0;j<19;j++){
		printf("%d,",v3[j]);
	}	
	printf("%d\n\n",v3[19]);
	
	/*Cosine Similarity Hesabı*/
	
	for(i=0;i<20;i++){/*bu döngümüzde pay kısmında bulunan iç çarpım kısmını hesaplarız*/ 
		iccarpim=v1[i]*v2[i];
		pay=pay+iccarpim;
		iccarpim=1;
	}
	
	for(i=0;i<20;i++){/*bu döngüde v1 vektörümüzdeki her bir elemanımızın karesini alırız*/
		kare1=pow(v1[i],2);/*pow fonksiyonu math kütüphenesinde bulunur ve üs almayı sağlar*/
		payda1=payda1+kare1;
		kare1=0;
	}
	payda3=sqrt(payda1);/*bu fonksiyon math kütüphanesinde bulunur ve karekök almayı sağlar ve birinci vektörümüzün normunu hesaplamış oluruz*/
	
	for(i=0;i<20;i++){/*bu döngüde v2 vektörümüzdeki her bir elemanımızın karesini alırız*/
		kare2=pow(v2[i],2);/*pow fonksiyonu üs almamızı sağlar*/
		payda2=payda2+kare2;
		kare2=0;
	}
	payda4=sqrt(payda2);/*sqrt fonksiyonu sayesinde v2 vektörümüzün normunu hesaplamış oluyoruz*/
	
	payda=payda3*payda4;/*v1 ve v2 vektörlerimizin normunu birbiri ile çarpıyoruz*/	
	
	sonuc=pay/payda;/*pay ve paydadan gelecek değerler yani paydaki iç çarpım ve paydadaki norm çarpımlarını birbirine bölüyoruz*/
	printf("sim(v1,v2):%lf\n",sonuc); /*ve son olarak sonucu ekrana yazdırıyoruz*/
	printf("***************************************************\n");
return 0;
}
