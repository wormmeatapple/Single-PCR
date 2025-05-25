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

//temp control variables
const int heaterPin = D1;
const int fanPin = D2;

int read_temp()
{
  int sensorValue = analogRead(analogPin);
  float resistance = resistorValue / ((1023.0 / sensorValue) - 1.0);
  float temp = log(resistance / 10000.0) / 3950.0 + 1.0 / (25 + 273.15);
  return temp;
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
void handle_graph()
{
server.send(200, "text/html", SendGraph());
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
  server.on("/graph", handle_graph);
  server.onNotFound(handle_404);

  server.begin();
  Serial.println("we bootin");

  pinMode()
}

void loop()
{
  server.handleClient();

}

String SendGraph()
{
  String ptr = "<!DOCTYPE html><html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>Graph</title>\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; text-align: center; }\n";
  ptr += "body{margin-top: 50px;} h2 {color: #444444;}\n";
  ptr += "</style>\n";
  ptr += "<script>\n";
  ptr += "function fetchTemp() {\n";
  ptr += "var xhttp = new XMLHttpRequest();\n";
  ptr += "xhttp.onreadystatechange = function() {\n";
  ptr += "if (this.readyState == 4 && this.status == 200) {\n";
  ptr += "document.getElementById(\"tempValue\").innerHTML = this.responseText + \" &deg;C\";\n";
  ptr += "}\n";
  ptr += "};\n";
  ptr += "xhttp.open(\"GET\", \"/temp\", true);\n";
  ptr += "xhttp.send();\n";
  ptr += "}\n";
  ptr += "setInterval(fetchTemp, 1000); \n";
  ptr += "</script>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<h2>Temperature: <span id=\"tempValue\">Loading...</span></h2>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}

String SendHome()
{
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>Single PCR</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>Single PCR</h1>\n";
  ptr +="<h3>Rancid inc. Making things Rancid since 1893</h3>\n";
  ptr += "<a href=\"http://" + local_ip.toString() + "/graph\">read temp data (i think)</a>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}