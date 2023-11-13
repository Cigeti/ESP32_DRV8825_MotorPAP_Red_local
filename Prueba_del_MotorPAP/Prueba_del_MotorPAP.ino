// Prueba , Driver, Motores de Pasos y ESP32
// By: www.dinastiatecnologica.com
//
#define x_paso 15    // Define el Pin de STEP para Motor de eje X
#define x_dire 2    // Define el Pin de DIR  para Motor de eje X
#define x_habi 4    // Define el Pin de ENABLE  para Motor de eje X

int retardo = 3000;   // Menor número el giro, más rápido se detiene el motor
int tiempo = 100;   // durante cuanto tiempo da el giro el motor (vueltas)

void setup() {
pinMode(x_paso, OUTPUT); pinMode(x_dire, OUTPUT); pinMode(x_habi, OUTPUT);     
}    

void loop() {
  giro(x_paso,x_dire,x_habi,1);
  delay(500);
  
giro(x_paso,x_dire,x_habi,0);
  delay(500);
}

void giro(int paso_,int dire_,int habi_,int dir) {
   digitalWrite(habi_, LOW);  // Habilita el Driver
  if( dir==0){ 
   digitalWrite(dire_, LOW);   // dirección de giro 0
   for(int i=0;i<tiempo;i++){  // da  pasos por un tiempo  
    digitalWrite(paso_, HIGH);      
    delayMicroseconds(retardo);          
    digitalWrite(paso_, LOW);       
    delayMicroseconds(retardo); 
   }
  }
  if( dir==1){ 
  digitalWrite(dire_, HIGH);   // dirección de giro 1
  for(int i=0;i<tiempo;i++){   // da  pasos por un tiempo  
    digitalWrite(paso_, HIGH);      
    delayMicroseconds(retardo);          
    digitalWrite(paso_, LOW);       
    delayMicroseconds(retardo);  
   }
  }
  digitalWrite(habi_, HIGH);   // quita la habilitación del Driver

}
