// The library used are listed below
#include <Wire.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>
// the datatype of variables

const byte ROWS = 4;
const byte COLS = 4;
int count = 0;
int password[4]= {123,456,789,222};
int ask;
char key;
int choice;
int amount;
int pos;
int balance = 10000;

// character hexaKeys is a multidimensional array 0f 4*4
char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Declaring the keypad keys as an input

byte rowPins[ROWS] = {7, 6, 5, 4};
byte colPins[COLS] = {3, 2, A4, A5};

Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
Servo servo;

// for the lcd pins
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{	
    Serial.begin(9600);
  	servo.attach(A0);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.setCursor(0, 0);
    lcd.print("Welcome to ATM Machine");
  
    lcd.setCursor(0, 0);

    // for the scrolling effect of text on the lcd
    for (int scrollCounter = 0; scrollCounter < 12; scrollCounter++)
    {
        lcd.scrollDisplayLeft();
        delay(500);
    }
    lcd.clear();
}

// main loop
void loop()
{
	ask = 0;
    // ask is the number of times for transaction to be made
    while (ask = 1)
    {
        lcd.setCursor(0, 0);
        lcd.print("Enter your Pin");
        delay(100);
        lcd.setCursor(0,1);
        int pin=GetNumber();
        
          
            // checking pin length
                // password validation
      if(pin==password[0]||pin==password[1]||pin==password[2]||pin==password[3])
                {
                    lcd.clear();
        			lcd.setCursor(0,0);
                    lcd.print("Welcome");
                    delay(1000);
                    lcd.clear();
                    lcd.setCursor(0, 0);
                    if(pin==password[0])
                    {
                        lcd.setCursor(1, 0);
                        lcd.print("Muskaan");
                        delay(1000);
                    }
        			else if(pin==password[1])
                    {
                        lcd.setCursor(1, 0);
                        lcd.print("Ananya");
                        delay(1000);
                    }
        			else if(pin==password[2])
                    {
                        lcd.setCursor(1, 0);
                        lcd.print("Akshara");
                        delay(1000);
                    }
        			else if(pin==password[3])
                    {
                        lcd.setCursor(1, 0);
                        lcd.print("Akash");
                        delay(1000);
                    }
                    
 
                    lcd.clear();
                    lcd.print("1- Withdraw ");
                    lcd.setCursor(0,1);
                    lcd.print("2- Deposit");
                    delay(1000);
                    lcd.clear();
                    lcd.setCursor(0,0);
                    lcd.print("3- Balance ");
                    lcd.setCursor(0,1);
                    lcd.print("4- Exit");
                    delay(1000);

                    lcd.setCursor(0, 0);
                    delay(1000);
                    int take = 0;
                    while(take<=1)
                    {
                        char key = keypad.getKey();
                        if(key)
                        {
                            if(key!=NO_KEY)
                            {
                              //--------------------1-WITHDRAW-----------------------------//
                                if(key=='1')
                                {
                                    int amount;
                                    
                                    lcd.clear();
                                    lcd.setCursor(0, 0);
                                    lcd.print("Options");
                                    lcd.clear();
                                    delay(1000);
                                    lcd.setCursor(0, 0);
                                    lcd.print("1- #1000");
                                    lcd.setCursor(0, 1);
                                    lcd.print("2- #2000");
                                    delay(500);
                                    lcd.setCursor(0, 0);
                                    lcd.print("3- #5000");
                                    lcd.setCursor(0, 1);
                                    lcd.print("4- #10000");
                                    delay(500);
                                    lcd.setCursor(0, 0);
                                    lcd.print("5- #20000");
                                    lcd.setCursor(0, 1);
                                    lcd.print("6- Other");
                                    delay(1000);
                                    
                                    //added next 2 lines to make sure comp knows to take ip
                                  	lcd.setCursor(0, 0);
                    				delay(2000);
                                    int i = 0;

                                    while(i<=1)
                                    {
                                        char key = keypad.getKey();
                                        if (key)
                                        {
                                            if(key!=NO_KEY)
                                            {
                                                int wit_cash;
                                                //changed key>0 to key>'0'
                                                if((key>'0')&&(key<='5'))
                                                {
                                                 switch(key){
                                                  	case '1':
                                                    	wit_cash = 1000;
                                                    	break;
                                                    case '2':
                                                    	wit_cash = 2000;
                                                    	break;
                                                    case '3':
                                                    	wit_cash = 5000;
                                                    	break;
                                                    case '4':
                                                    	wit_cash = 10000;
                                                    	break;
                                                    case '5':
                                                    	wit_cash = 20000;
                                                    	break;
                                                  }
                                                  //added amount entered to be printed on screen
                                                  lcd.clear();
                                                  lcd.setCursor(0, 0);
                                                  lcd.print("Amount Entered: ");
                                                  delay(2000);
                                                  lcd.setCursor(0, 1);
                                                  lcd.print(wit_cash);
                                                  delay(1000);
                                                  //
                                                }

                                                else if(key=='6')
                                                {
                                                   lcd.clear();
                                                   lcd.setCursor(0, 0);
                                                   lcd.print("Enter the Amount");
                                                   lcd.setCursor(0, 1);
                                                   wit_cash = GetNumber();
                                                  
                                                   lcd.setCursor(0, 0);
                                                   lcd.print("Amount Entered: ");
                                                   lcd.setCursor(0, 1);
                                                   lcd.print(wit_cash);
                                                   delay(2000);
                                                   lcd.clear();
                                                }
                                              	//
                                                lcd.clear();
                                              	if(wit_cash>balance){
                                                  lcd.setCursor(0, 0);
                                                  lcd.print("Insufficient Balance");
                                                  
                                                }
                                                else
                                                {
                                                    for(pos=0;pos<=180;pos++)
                                                    {
                                                      servo.write(pos);
                                                      delay(15);
                                                    }
                                                delay(1000);
                                              	balance = balance - wit_cash;
                                                lcd.setCursor(0, 0);
                                                lcd.print("Your Account Balance is");
                                                delay(3000);
                                                lcd.setCursor(0, 1);
                                                lcd.print(balance);
                                                break;
                                                
                                                }
                                            }//if no key
                                        }//if key
                                    }//while i<=1
                                  delay(3000);
                                  lcd.clear();
                                  break;
                                }//if key = 1
                            }//if no key = 1 main
                              
                            
                                if (key != NO_KEY)
                                {
                                  //--------------------2-DEPOSIT-----------------------------//
                                    if (key == '2')
                                    {
                                        int dep_cash = 0;
                                      
                                        lcd.clear();
                                        lcd.setCursor(0, 0);
                                        lcd.print("Enter the Amount");
                                        lcd.setCursor(0, 1);
                                        dep_cash = GetNumber();
                                        lcd.clear();
                                      
                                      	lcd.setCursor(0, 0);
                                        lcd.print("Amount Entered: ");
                                        lcd.setCursor(0, 1);
                                        lcd.print(dep_cash);
                                        delay(1000);
                                        lcd.clear();
                                      
                                      	balance = balance + dep_cash;
                                        lcd.setCursor(0, 0);
                                        lcd.print("Your Account Bal");
                                        delay(3000);
                                        lcd.setCursor(0, 1);
                                        lcd.print(balance);
                                        delay(3000);
                                        lcd.clear();
                                        break;                                   	
                                    }
                                }//no key = 2

                                    if (key != NO_KEY)
                                    {
                                      //--------------------3-ACCOUNT BALANCE---------------------//
                                        if (key == '3')
                                        {
                                            lcd.clear();
                                            lcd.setCursor(0, 0);
                                            lcd.print("Please wait");
                                            delay(2000);
                                            lcd.clear();
                                            lcd.setCursor(0, 0);
                                            lcd.print("Your Account Balance is");
                                            delay(3000);
                                            lcd.setCursor(0, 1);
                                            lcd.print(balance);
                                            delay(1000);
                                            lcd.clear();
                                            delay(2000);
                                            break;
                                        }
                                    }// no key 3

                                    if (key != NO_KEY)
                                    {
                                      //--------------------4-EXIT-----------------------------//
                                        if (key == '4')
                                        {
                                            lcd.clear();
                                            lcd.setCursor(0, 0);
                                            delay(1000);
                                            lcd.print("Take your Card");
                                            delay(1000);
                                            lcd.clear();
                                            lcd.setCursor(0, 0);
                                            lcd.print("Thank You");
                                            delay(2000);
                                            break;
                                        }
                                    }//no key 4
                             }// if(key)
                    }//while(take<=1)
                }//checking pin 

                else
                {
                    lcd.print(" Incorrect pin");
                    delay(1000);
                    lcd.clear();
                    lcd.setCursor(0, 0);
                    count = 0;
                }  
            //}//if(count=3)
         //}//if(key)  
    }//while(ask=1)
}//void loop

int GetNumber()
{
   int num = 0;
   char key = keypad.getKey();
   while(key != '#')
   {
      switch (key)
      {
         case NO_KEY:
            break;

         case '0': case '1': case '2': case '3': case '4':
         case '5': case '6': case '7': case '8': case '9':
            lcd.print(key);
            num = num * 10 + (key - '0');
            break;

         case '*':
            num = 0;
            lcd.clear();
            break;
      }

      key = keypad.getKey();
   }

   return num;
}