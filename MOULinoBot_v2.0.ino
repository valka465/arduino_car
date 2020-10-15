   ////////////////////////////////////////////////////////
  //                LinoBot v1.0                        //             
 //               By Dorosh      A.C.                  //
////////////////////////////////////////////////////////


//Подключение библиотеки датчиков и шилда
//#include <AFMotor.h>
//#include <iarduino_HC_SR04_int.h>  

//(defining pins and variables) задаём пины
#define lefts D10
#define middle D11 
#define rights D12

//(defining motors)задаем двигатели их номера и сторану
#define R 4 // Вывод I1 подключен к пину 4
#define RS 6
#define L 7 // Вывод I1 подключен к пину 4
#define LS 5
pinMode (4, OUTPUT); // Задаем работу выводов в качестве выходов
  pinMode (, OUTPUT);
pinMode (7, OUTPUT); // Задаем работу выводов в качестве выходов
  pinMode (5, OUTPUT);

//AF_DCMotor motorL(3, MOTOR12_8KHZ); 
//AF_DCMotor motorR(4, MOTOR12_8KHZ);
/*
AF_DCMotor motor1(1, MOTOR12_8KHZ); 
AF_DCMotor motor2(2, MOTOR12_8KHZ);
 */

void setup() {
  //(setting the speed of motors) настройки скорости моторов левый и правый
  L.setSpeed(LS);
  R.setSpeed(RS);
  //declaring pin types
 // pinMode(lefts,INPUT);
   //pinMode(middle,INPUT);
  //pinMode(rights,INPUT);
  //begin serial communication
  Serial.begin(9600);
  while(!Serial){}                            // Инициируем передачу данных по последовательному порту       (на скорости 9600 бит/сек)
Serial.println(analogRead(lefts));                     // Выводим показания датчиков линии                (для указания значений константам valSensor0 и valSensor1)
   Serial.println(analogRead(middle)); 
    Serial.println(analogRead(rights));
    //  Устанавливаем задержку и обновляем время совершения последней операции
    delay(20);
   { delay(1500);

 motorL.run(FORWARD);
   motorR.run(FORWARD);
}
    
}

void loop(){
  //printing values of the sensors to the serial monitor
//Serial.println(analogRead(lefts));
//Serial.println(analogRead(middle ));
 // Serial.println(analogRead(rights));
  //line detected by both
  
 if  (analogRead(lefts)<=250 && analogRead(middle)<=250 && analogRead(rights)<=250){  //000
    //stop
    L.run(FORWARD);
   R.run(FORWARD);
    /*
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
     */
  
  
    
  }
  else if(analogRead(lefts)<=250 && analogRead(middle)<=250 && analogRead(rights)>=250){  //001
    
    //turn right
    L.run(FORWARD);//Вперёд
    R.run(BACKWARD);//Назад
    /*
    motor1.run(FORWARD);
    motor2.run(RELEASE);
     */
  }
   else if(analogRead(lefts)<=250 && analogRead(middle)>=250 && analogRead(rights)>=250){ //011
    //turn left
    motorL.run(FORWARD); //Вперёд
    motorR.run(RELEASE);  //остановка
    /*
    motor1.run(RELEASE);
    motor2.run(FORWARD);
     */
  }
 else if(analogRead(lefts)<=250&&analogRead(middle)>=250&&analogRead(rights)<=250){  //010 при таком паказании робот движется по лиии
    //stop
    L.run(FORWARD);//Вперёд
    R.run(FORWARD);//Вперёд
}
  else if(analogRead(lefts)>=250 && analogRead(middle)<=250 && analogRead(rights)<=250){   //100
    //turn right
    R.run(FORWARD);//Вперед
    L.run(BACKWARD);//НАЗАД
    /*
    motor1.run(FORWARD);
    motor2.run(RELEASE);
     */
      }
       else if(analogRead(lefts)>=250 && analogRead(middle)>=250 && analogRead(rights)<=250){   //110
    //turn right
    L.run(RELEASE);//Остановка
    R.run(FORWARD);//Вперёд
    /*
    motor1.run(FORWARD);
    motor2.run(RELEASE);
     */
  }
  if(analogRead(lefts)>=250&&analogRead(middle)<=250&&analogRead(rights)>=250){  //101 при таком паказании робот движется по лиии
    //stop
    
    L.run(FORWARD);//Вперёд
    R.run(FORWARD);//Вперёд
    
}


    

 else if(analogRead(lefts)>=250 && analogRead(middle)>=250 && analogRead(rights)>=250){   //111
    //stop
   L.run(FORWARD);
   R.run(FORWARD);
    /*
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
     */
 }
   
//Инверсия трассы  

 
// else if(analogRead(lefts)>=250 && analogRead(middle)<=250 && analogRead(rights)>=250){ //101
    //turn left
  //  motorL.run(FORWARD); //Вперёд
  //  motorR.run(FORWARD);  //Вперед
    /*
  //  motor1.run(RELEASE);
  //  motor2.run(FORWARD);
     */
 
 
 //}
 
}
 
