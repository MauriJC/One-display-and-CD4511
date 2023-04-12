// C++ code
// This code works with an CD4511 and a display 
//The connection for the pines is specified in the setup

//Vamos a probar conectando el pin 5 del chip a GND y 5V para ver que pasa

int contador =0;

int numeros[10][4]= {
  {0,0,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,1,1},
  {0,1,0,0},
  {0,1,0,1},
  {0,1,1,0},
  {0,1,1,1},
  {1,0,0,0},
  {1,0,0,1}
};

void dibujarNumero(){
	for(int i=0;i<4;i++){
      if(numeros[contador][i]==1){
        digitalWrite(i+1,HIGH);
      } else {
      	digitalWrite(i+1,LOW);
      }
    	
    }
  delay(500);
}


void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(5,INPUT_PULLUP); //Aumentar
  pinMode(6,INPUT_PULLUP); //Decrementar
  
  pinMode(4,OUTPUT); //A
  pinMode(3,OUTPUT); //B
  pinMode(2,OUTPUT); //C
  pinMode(1,OUTPUT); //D
  //D => C => B => A
  
  
}

void loop()
{

  if(contador==0){
 	dibujarNumero();
    }
  
  
  if(contador==9 && digitalRead(5)==LOW){
    contador=-1;
  }
 
  if(digitalRead(5)==LOW){
    contador++;
    dibujarNumero();
  
  }
  
  if(contador==0 && digitalRead(6)==LOW){
  	contador=10;
  }
  
  
  if(digitalRead(6)==LOW){
    contador--;
    dibujarNumero();
  }
   

  
}
















