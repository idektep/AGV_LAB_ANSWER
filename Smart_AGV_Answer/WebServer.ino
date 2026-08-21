#include <WiFi.h>
#include <WebServer.h>

// ----------------------
// Access Point Settings
// ----------------------
const char* ssid = "AGV_WEEK12";
const char* password = "12345678";

// Create Web Server
WebServer server(80);

// ----------------------
// HTML Page : Advanced Hold Control
// ----------------------
String webpage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>AGV Hold Controller</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body{
      font-family: Arial, sans-serif;
      text-align:center;
      background:#f2f6ff;
      margin:0;
      padding:30px 10px;
      user-select:none;
      -webkit-user-select:none;
      touch-action:none;
    }
    h1{ color:#1f3c88; }
    p{ color:#333; }
    .controller{
      display:grid;
      grid-template-columns:90px 90px 90px;
      gap:12px;
      justify-content:center;
      margin-top:25px;
    }
    .btn{
      height:70px;
      border:none;
      border-radius:14px;
      font-size:18px;
      font-weight:bold;
      color:white;
      background:#1f7aec;
      box-shadow:0 5px 0 #1556a8;
    }
    .btn:active{
      transform:translateY(4px);
      box-shadow:0 1px 0 #1556a8;
      background:#145bd1;
    }
    .stop{
      background:#e63946;
      box-shadow:0 5px 0 #a8202b;
    }
    .empty{ visibility:hidden; }
    #status{
      margin-top:25px;
      font-size:20px;
      font-weight:bold;
      color:#1f3c88;
    }
  </style>
</head>
<body>
  <h1>AGV Hold Controller</h1>
  <p>Press and hold a button to move. Release to stop.</p>

  <div class="controller">
    <div class="empty"></div>
    <button class="btn" onmousedown="startCmd('forward')" onmouseup="stopCmd()" onmouseleave="stopCmd()" ontouchstart="startCmd('forward')" ontouchend="stopCmd()" ontouchcancel="stopCmd()">Forward</button>
    <div class="empty"></div>

    <button class="btn" onmousedown="startCmd('left')" onmouseup="stopCmd()" onmouseleave="stopCmd()" ontouchstart="startCmd('left')" ontouchend="stopCmd()" ontouchcancel="stopCmd()">Left</button>
    <button class="btn stop" onclick="stopCmd()">Stop</button>
    <button class="btn" onmousedown="startCmd('right')" onmouseup="stopCmd()" onmouseleave="stopCmd()" ontouchstart="startCmd('right')" ontouchend="stopCmd()" ontouchcancel="stopCmd()">Right</button>

    <div class="empty"></div>
    <button class="btn" onmousedown="startCmd('backward')" onmouseup="stopCmd()" onmouseleave="stopCmd()" ontouchstart="startCmd('backward')" ontouchend="stopCmd()" ontouchcancel="stopCmd()">Backward</button>
    <div class="empty"></div>
  </div>

  <div id="status">Status: Ready</div>

  <h2>Distance</h2>

  <div id="distance"
  style="
  font-size:40px;
  font-weight:bold;
  color:#1f7aec;
  margin-top:10px;">
  -- cm
  </div>

  <script>

function startCmd(cmd){
  event.preventDefault();
  fetch('/' + cmd);
  document.getElementById('status').innerHTML =
  'Status: ' + cmd;
}

function stopCmd(){
  event.preventDefault();
  fetch('/stop');
  document.getElementById('status').innerHTML =
  'Status: stop';
}

setInterval(function(){

  fetch("/distance")

  .then(response => response.text())

  .then(data => {

    document.getElementById("distance").innerHTML =
    data + " cm";

  });

},500);

</script>
</body>
</html>
)rawliteral";

// ----------------------
// Route Functions
// ----------------------
void handleRoot() {
  server.send(200, "text/html", webpage);
}

void handleForward() {
  forward(0);
  server.send(200, "text/plain", "Forward");
}

void handleBackward() {
  backward(0);
  server.send(200, "text/plain", "Backward");
}

void handleLeft() {
  turn_left(0);
  server.send(200, "text/plain", "Left");
}

void handleRight() {
  turn_right(0);
  server.send(200, "text/plain", "Right");
}

void handleStop() {
  stop(0);
  server.send(200, "text/plain", "Stop");
}

void handleDistance()
{
  server.send(
    200,
    "text/plain",
    String(readDistance())
  );
}

// ----------------------
// Start WiFi AP + WebServer
// ----------------------
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
  server.on("/distance", handleDistance);

  server.begin();
  Serial.println("Web Server Started");
}

// ----------------------
// Handle Client
// ----------------------
void updateWebServer() {
  server.handleClient();
}
