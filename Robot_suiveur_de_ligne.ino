int CG;
int CM;
int CD;
int MG;
int MD;
#define CG A0
#define CM A1
#define CD A2
#define MG1 8
#define MG2 11
#define ENA 10
#define MD1 4
#define MD2 6
#define ENB 5
int initD;
int initM;
int initG;

int VD;
int VM;
int VG;

  int vitesse=180;

void setup() {
Serial.begin(9600);

  pinMode(MG1, OUTPUT);
  pinMode(MG2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(MD1, OUTPUT);
  pinMode(MD2, OUTPUT);
  pinMode(ENB, OUTPUT);

}

void loop() {

  VG=analogRead(CG);
  VM=analogRead(CM);
  VD=analogRead(CD);

  digitalWrite(MG1, HIGH);
  digitalWrite(MG2, LOW);
  digitalWrite(MD1, LOW);
  digitalWrite(MD2, HIGH);


      if(VM>100 && VG>100 && VD>100){
        analogWrite(ENA,vitesse);
        analogWrite(ENB,vitesse);
        Serial.println("avant");
        }
      if(VM>100 && VG>100 && VD<100){
        analogWrite(ENA,vitesse-190);
        analogWrite(ENB,vitesse+20);
        Serial.println("Droite");
        }
      if(VM>100 && VG<100 && VD>100){
        analogWrite(ENA,vitesse+20);
        analogWrite(ENB,vitesse-190);
        Serial.println("Gauche");
        }

}
