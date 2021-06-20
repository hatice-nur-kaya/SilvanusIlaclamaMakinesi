#define  sagmotorhiz 11   
#define  solmotorhiz  6   
#define  sagmotoron  12
#define  sagmotorarka  10
#define  solmotoron  8
#define  solmotorarka  9
#include <Servo.h>
Servo servodeneme;
Servo servopipet;
#define trig 4
#define echo 2
int sure=0;
int mesafe=0;
int x;
int y;
int far1 =A0;
int far2 = 13;
String komut;
void setup() 
{
  Serial.begin(9600);
  pinMode(sagmotorhiz, OUTPUT); 
  pinMode(solmotorhiz, OUTPUT);  
  pinMode(sagmotoron, OUTPUT);
  pinMode(sagmotorarka, OUTPUT);
  pinMode(solmotoron, OUTPUT);
  pinMode(solmotorarka, OUTPUT);
  pinMode(far1, OUTPUT);
  pinMode(far2, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servodeneme.attach(5);
  servopipet.attach(3);
  Serial.begin(9600);
}
 
void loop() 
{
  while  (Serial.available())
{
  delay(10);
  char oku=Serial.read();
  if(oku=='#'){break;}
    komut += oku;
}
  if(komut.length() > 0){
    
    Serial.println(komut);
    if(komut=="ileri" ||komut=="ileri git"||komut=="silvanus ileri git "||komut=="silvanus ileri "||komut=="İleri" ||komut=="İleri git"){ileri();}
    else if (komut=="geri" ||komut=="geri git"||komut=="silvanus geri git "||komut=="silvanus geri "){geri();}
    else if (komut=="sağ" ||komut=="sağa dön"||komut=="silvanus sağ git "||komut=="silvanus sağa git "){sag(); delay(500); ileri();}
    else if (komut=="sol" ||komut=="sola dön"||komut=="silvanus sol git "||komut=="silvanus sola git "){sol(); delay(500); ileri();}
    else if (komut=="dur" ||komut==" motarları durdur"||komut=="silvanus dur "||komut=="silvanus motorları durdur "){dur();}
    else if (komut=="far yak" ||komut=="sivanus far yak"||komut=="silvanus farları yak "||komut=="farları yak "||komut==" aç "||komut=="yak "){ac();}
    else if (komut=="far kapat" ||komut=="sivanus far kapat"||komut=="silvanus farları kapat "||komut=="farları kapat "||komut==" kapat "){kapat();}
    komut = "";
    }
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  sure = pulseIn(echo, HIGH);
  mesafe = (sure/2) / 29.1;
  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");
  delay(250);
  for(x=0 ; x<=180 ;x += 5)
  {
    servodeneme.write(x);
    delay(50); 
    }
    for(y=180 ; y>=0 ; y -= 5 )
   {
    servodeneme.write(y);
    delay(50); 
    }  
   if (mesafe<=30)
  {
  servopipet.write(90);
  delay(500);
  }
  else
  {
  servopipet.write(0); 
  delay(500);
  }
}
void ileri()
{
analogWrite(sagmotorhiz,200);// motor hızı
digitalWrite(sagmotoron,HIGH );//motor öne gitmesi
digitalWrite(sagmotorarka, LOW );//motor arkaya dönmesi engel
analogWrite(solmotorhiz,200);// motor hızı
digitalWrite(solmotoron,HIGH );//motor öne gitmesi
digitalWrite(solmotorarka, LOW );//motor arkaya dönmesi engel
  }
 void geri()
{
analogWrite(sagmotorhiz,200);// motor hızı
digitalWrite(sagmotoron,0 );//motor öne gitmesi
digitalWrite(sagmotorarka, 1 );//motor arkaya dönmesi engel
analogWrite(solmotorhiz,200);// motor hızı
digitalWrite(solmotoron, 0);//motor öne gitmesi
digitalWrite(solmotorarka, 1 );//motor arkaya dönmesi engel
  }
  void sag()
{
analogWrite(sagmotorhiz,150);// motor hızı
digitalWrite(sagmotoron,0 );//motor öne gitmesi
digitalWrite(sagmotorarka, 1 );//motor arkaya dönmesi engel
analogWrite(solmotorhiz,150);// motor hızı
digitalWrite(solmotoron,1 );//motor öne gitmesi
digitalWrite(solmotorarka, 0 );//motor arkaya dönmesi engel
  }
  void sol()
{
analogWrite(sagmotorhiz,150);// motor hızı
digitalWrite(sagmotoron,1 );//motor öne gitmesi
digitalWrite(sagmotorarka, 0 );//motor arkaya dönmesi engel
analogWrite(solmotorhiz,150);// motor hızı
digitalWrite(solmotoron,0 );//motor öne gitmesi
digitalWrite(solmotorarka, 1 );//motor arkaya dönmesi engel
  }
  void dur ()
  {
analogWrite(sagmotorhiz,0);// motor hızı
digitalWrite(sagmotoron,0 );//motor öne gitmesi
digitalWrite(sagmotorarka, 0 );//motor arkaya dönmesi engel
analogWrite(solmotorhiz,0);// motor hızı
digitalWrite(solmotoron,0 );//motor öne gitmesi
digitalWrite(solmotorarka, 0);//motor arkaya dönmesi engel
    }
    void ac ()
{
  digitalWrite(A0, HIGH);
  digitalWrite(13, HIGH);
}
void kapat ()
{
  digitalWrite(A0, LOW);
  digitalWrite(13, LOW);
}
