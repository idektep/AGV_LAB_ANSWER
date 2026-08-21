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
  <button onclick="sendCmd('forward')">
  Forward
  </button>

  <button onclick="sendCmd('backward')">
  Backward
  </button>

  <button onclick="sendCmd('left')">
  Left
  </button>

  <button onclick="sendCmd('right')">
  Right
  </button>

  <button onclick="sendCmd('stop')">
  Stop
  </button>

<script>
  function sendCmd(cmd)
  {
    fetch("/" + cmd);
  }
</script>

</body>
</html>
)rawliteral";

// Home Page
void handleRoot() {
  server.send(200, "text/html", webpage);

}

// Start WiFi AP + WebServer
void initWebServer() {

  Serial.println();
  Serial.println("Starting Access Point...");

  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();

  Serial.print("AP IP Address: ");
  Serial.println(IP);

  server.on("/", handleRoot);

  server.on("/forward", handleForward);
  server.on("/backward", handleBackward);
  server.on("/left", handleLeft);
  server.on("/right", handleRight);
  server.on("/stop", handleStop);

  server.begin();

  Serial.println("Web Server Started");
}

void handleForward() {

  forward(1000);

  server.send(
    200,
    "text/plain",
    "Forward"
  );
}

void handleBackward() {

  backward(1000);

  server.send(
    200,
    "text/plain",
    "Backward"
  );
}

void handleLeft() {

  turn_left(500);

  server.send(
    200,
    "text/plain",
    "Left"
  );
}

void handleRight() {

  turn_right(500);

  server.send(
    200,
    "text/plain",
    "Right"
  );
}

void handleStop() {

  stop(100);

  server.send(
    200,
    "text/plain",
    "Stop"
  );
}
// Handle Client
void updateWebServer() {
  server.handleClient();
}