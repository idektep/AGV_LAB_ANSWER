#include <WiFi.h>
#include <WebServer.h>

// ----------------------
// Access Point Settings
// ----------------------
const char* ssid = "AGV";
const char* password = "12345678";

// Create Web Server
WebServer server(80);

// HTML Page
String webpage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>AGV Online</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body{
      font-family: Arial;
      text-align:center;
      margin-top:50px;
    }
    h1{ 
      color:#333;
    }
  </style>
</head>
<body>
  <h1>AGV Online</h1>
  <p>ESP32 Web Server Connected Successfully</p>
</body>
</html>
)rawliteral";

// Home Page
void handleRoot() {
  server.send(200, "text/html", webpage);
}

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("Starting Access Point...");

  // Create WiFi AP
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();

  Serial.print("AP IP Address: ");
  Serial.println(IP);

  // Route
  server.on("/", handleRoot);

  // Start Server
  server.begin();

  Serial.println("Web Server Started");
}

void loop() {
  server.handleClient();
}



