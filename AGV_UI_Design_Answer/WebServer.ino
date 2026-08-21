#include <WiFi.h>
#include <WebServer.h>

// ----------------------
// Access Point Settings
// ----------------------
const char* ssid = "AGV";
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
  <title>AGV Hold Controller - IDEKTEP</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    :root{
      /* ==== (Unicorn Theme) ==== */
      --unicorn-purple:#a78bfa;
      --unicorn-pink:#f9a8d4;
      --unicorn-blue:#93c5fd;
      --unicorn-deep:#7c3aed;
      --unicorn-accent:#ec4899;
      --unicorn-accent-dark:#be185d;
      --unicorn-stop:#f43f5e;
      --unicorn-stop-dark:#be123c;
      --unicorn-bg1:#fdf2ff;
      --unicorn-bg2:#eef4ff;
    }
    body{
      font-family: Arial, sans-serif;
      text-align:center;
      background:linear-gradient(160deg, var(--unicorn-bg1), var(--unicorn-bg2) 60%, #fff);
      margin:0;
      padding:20px 10px 30px;
      user-select:none;
      -webkit-user-select:none;
      touch-action:none;
    }
    .header{
      background:linear-gradient(90deg, var(--unicorn-purple), var(--unicorn-pink), var(--unicorn-blue));
      color:#fff;
      padding:16px 10px 20px;
      border-radius:0 0 22px 22px;
      margin:-20px -10px 10px;
      box-shadow:0 4px 14px rgba(167,139,250,.35);
    }
    .team-name{
      font-size:14px;
      letter-spacing:1.5px;
      opacity:.95;
      margin:0 0 2px;
      text-transform:uppercase;
      text-shadow:0 1px 2px rgba(0,0,0,.15);
    }
    h1{
      margin:0;
      font-size:23px;
      text-shadow:0 1px 3px rgba(0,0,0,.15);
    }
    .system-name{
      margin:4px 0 0;
      font-size:13px;
      opacity:.9;
    }
    p.hint{ color:#5b21b6; font-size:14px; }

    .controller{
      display:grid;
      grid-template-columns:90px 90px 90px;
      gap:12px;
      justify-content:center;
      margin-top:20px;
    }
    .btn{
      height:70px;
      border:none;
      border-radius:14px;
      font-size:18px;
      font-weight:bold;
      color:white;
      background:linear-gradient(180deg, var(--unicorn-pink), var(--unicorn-accent));
      box-shadow:0 5px 0 var(--unicorn-accent-dark);
    }
    .btn:active{
      transform:translateY(4px);
      box-shadow:0 1px 0 var(--unicorn-accent-dark);
      background:linear-gradient(180deg, var(--unicorn-accent), var(--unicorn-accent-dark));
    }
    .stop{
      background:linear-gradient(180deg, #fb7185, var(--unicorn-stop));
      box-shadow:0 5px 0 var(--unicorn-stop-dark);
    }
    .stop:active{
      box-shadow:0 1px 0 var(--unicorn-stop-dark);
      background:linear-gradient(180deg, var(--unicorn-stop), var(--unicorn-stop-dark));
    }
    .empty{ visibility:hidden; }

    #status-box{
      margin-top:25px;
      display:inline-flex;
      align-items:center;
      gap:8px;
      background:#fff;
      padding:10px 18px;
      border-radius:30px;
      box-shadow:0 2px 10px rgba(124,58,237,.18);
      font-size:18px;
      font-weight:bold;
      color:var(--unicorn-deep);
      border:1px solid #f0e3ff;
    }
    #status-dot{
      width:12px;
      height:12px;
      border-radius:50%;
      background:#c4c4c4;
      transition:background .2s;
    }
    #status-dot.active{ background:#34d399; box-shadow:0 0 8px #34d399; }
    #status-dot.stopped{ background:var(--unicorn-stop); }
  </style>
</head>
<body>
  <div class="header">
    <p class="team-name">ทีม: IDEKTEP</p>
    <h1>🦄 AGV Hold Controller</h1>
    <p class="system-name">ระบบ: AGV Controller</p>
  </div>

  <p class="hint">กดค้างปุ่มเพื่อเคลื่อนที่ ปล่อยปุ่มเพื่อหยุด</p>

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

  <div id="status-box">
    <span id="status-dot"></span>
    <span id="status-text">Status: Ready</span>
  </div>

  <script>
    function startCmd(cmd){
      event.preventDefault();
      fetch('/' + cmd);
      setStatus(cmd, true);
    }

    function stopCmd(){
      event.preventDefault();
      fetch('/stop');
      setStatus('stop', false);
    }

    function setStatus(cmd, isActive){
      const dot = document.getElementById('status-dot');
      const text = document.getElementById('status-text');
      text.innerHTML = 'Status: ' + cmd;
      dot.classList.remove('active','stopped');
      dot.classList.add(isActive ? 'active' : 'stopped');
    }
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

  server.begin();
  Serial.println("Web Server Started");
}

// ----------------------
// Handle Client
// ----------------------
void updateWebServer() {
  server.handleClient();
}
