# Captive-Portal
This captive portal utilizes ESP8266 Specifically and its a captive portal so when users connect to the device it will redirect them to a page to enter their details in and will prompt them to enter their details and please this is for educational purposes only and all actions will be on you if you damage other peoples data or device using this thx


WARNING THIS IS FOR EDUCATIONAL PURPOSES ONLY AND THIS IS ILLEGAL IF USED WITHOUT CONCENT IM NOT RESPONSIBLE FOR ANY DAMAGE TO USERS DATA IT IS ALL ON YOU IF YOU DECIDE TO USE IT IN THIS WAY!!!! 


COMPILING GUIDE

1. USE ARDUINO IDE (INSTALL IT WITH ALL THE REQUIRED LIBRARIES FOR IT TO WORK FOR ESP8266 NODEMCU IT WONT WORK STRAIGHT OUT OF THE BOX)
2. OPEN THE FILE WITH ARDUINO OR COPY AND PASTE IT IN DOESNT MATTER ASLONG AS ITS IN THE IDE 





3. SET UPLOAD SPEED TO : 115200

   SET DEBUG PORT TO : DISABLED
   
   SET FLASH SIZE TO : 4MB (FS:2MB OTA:~1019KB)
   
   SET C++ EXCEPTIONS TO : DISABLED 
   
   SET IwIP VARIENT TO : V2 LOWER MEMORY
   
   SET BUILTIN LED TO : 2
   
   SET DEBUG LEVEL TO : NONE
   
   SET MMU TO : 32B CACHE + 32KB IRAM (BALANCED)
   
   SET NON-32-BIT ACCESS TO : USE PGM_READ MACROS FOR IRAM/PROGMEM
   
   SET SSL SUPPORT TO : ALL SSL CIPHERS(MOST COMPATIBLE)
   
   SET STACK PROTECTION TO :  DISABLED 
   
   SET VTABLES TO : FLASH
   
   SET ERASE FLASH TO : ONLY SKETCH (OPTIONAL: CAN CHOOSE ALL FLASH CONTENT)
   
   SET CPU FREQUENCY TO : 160MHZ

4.
once its completed its compiling using the settings above 
head to serial monitor on the IDE 
it should tell you the IP address that the webpage is on and all you would need to do is 
connect using your phone or laptop anything that has wifi head to the ip and you should be greated with the login page
what i done is anything you enter in to the Username & Password sections it will just now output it to the serial monitor 
but its up to you from their on what you wanna do with it.
