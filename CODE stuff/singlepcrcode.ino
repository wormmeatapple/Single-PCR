#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


//wifi variables
const char* ssid = "Single_PCR";
const char* password = "admin";
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);
ESP8266WebServer server(80); //port 80

//sensor variables
const int analogPin = A0;
const int resistorValue = 10000; //read therm res and change when it arrives

//pcr specific variables
bool on = false;
int extensionDur = 0;
int extensionTemp = 0;
int denatureDur = 0;
int annealDur = 0;
int annealTemp = 0;
int cycleNum = 0;


//temp control variables
const int heaterPin = D1;
const int fanPin = D2;

float read_temp()
{
  int sensorValue = analogRead(analogPin);
  float resistance = resistorValue / ((1023.0 / sensorValue) - 1.0);
  float temp = log(resistance / 10000.0) / 3950.0 + 1.0 / (25 + 273.15);
  return temp;
}

int cycle(int duration, int idealTemp)
{
  unsigned long startTime = millis();
  long elapsed = millis() - startTime;

  while (elapsed < duration)
  {
    float currentTemp = read_temp();
    if(currentTemp < idealTemp)
    {
      digitalWrite(heaterPin, HIGH);
      delay(100);
      digitalWrite(heaterPin, LOW);
    }
    else if (currentTemp > idealTemp)
    {
      digitalWrite(fanPin, HIGH);
      delay(100);
      digitalWrite(fanPin, LOW);
    }
    elapsed = millis() - startTime;
  }
  return 1;
}

//handle different links
void handle_connect()
{
  server.send(200, "text/html", SendHome());
}
void handle_data()
{
  float temp = read_temp();
  server.send(200, "text/html", String(temp));
}
void handle_start()
{
  on = true;

  if (server.hasArg("extensionDur")) {
    extensionDur = (server.arg("extensionDur").toInt()) * 10;
  }
  if (server.hasArg("extensionTemp")) {
    extensionTemp = (server.arg("extensionTemp").toInt()) * 10;
  }
  if (server.hasArg("denatureDur")) {
    denatureDur = (server.arg("denatureDur").toInt()) * 10;
  }
  if (server.hasArg("annealDur")) {
    annealDur = (server.arg("annealDur").toInt()) * 10;
  }
  if (server.hasArg("annealTemp")) {
    annealTemp = (server.arg("annealTemp").toInt()) * 10;
  }
  if (server.hasArg("cycleNum")) {
    cycleNum = server.arg("cycleNum").toInt();
  }

}
void handle_404()
{
  server.send(404, "text/html", "Send a real link dingus");
}

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
 
  //link directory
  server.on("/", handle_connect);
  server.on("/data", handle_data);
  server.on("/start", handle_start);
  server.onNotFound(handle_404);

  server.begin();
  Serial.println("we bootin");

  pinMode(heaterPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
}

void loop()
{
  server.handleClient();

  if(on)
  {
    cycle(300, 95); //inital denature
    for(int i = 0; i < cycleNum + 1; i++)
    {
      cycle(denatureDur, 95); //cycle denaturing
      cycle(annealDur, annealTemp); //cycle annealing
      cycle(extensionDur, extensionTemp); //cycle extension
    }
    cycle(300000, extensionTemp); //final extension
    on = false;
  }
}

String SendHome()
{
String html = "<!DOCTYPE html> <html>\n";
  html +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  html +="<title>Single PCR</title>\n";
  html +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  html +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  html +="</style>\n";
  html +="</head>\n";
  html +="<body>\n";
  html +="<h1>Single PCR</h1>\n";
  html +="<h3>Rancid inc. Making things Rancid since 1893</h3>\n";
  html +="<form action='/start'>";
  html +="Duration of extension: <input type='text' name='extensionDur'><br>";
  html +="Temperature of extension: <input type='text' name='extensionTemp'><br>";
  html +="Duration of denaturing: <input type='text' name='denatureDur'><br>";
  html +="Duration of annealing: <input type='text' name='annealDur'><br>";
  html +="Temperatur of annealing: <input type='text' name='annealTemp'><br>";
  html +="Amount of cycles: <input type='number' name='cycleNum'><br>";
  html +="<input type='submit' value='Submit'>";
  html +="</form>";
  html +="</body>\n";
  html +="</html>\n";
  return html;
}