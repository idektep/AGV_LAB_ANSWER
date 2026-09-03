#include <WiFi.h>
#include <WebServer.h>

// ----------------------
// Access Point Settings
// ----------------------
const char* ssid = "AGV_WEEK14";
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
  <title>Smart AGV Dashboard</title>
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

    h1{
      color:#1f3c88;
      margin-bottom:5px;
    }

    p{
      color:#333;
    }

    /* -------------------------
       Dashboard
    ------------------------- */

    .dashboard{
      max-width:500px;
      margin:auto;
    }

    .card{
      background:white;
      border-radius:18px;
      padding:20px;
      margin:15px 0;
      box-shadow:0 4px 10px rgba(0,0,0,0.1);
    }

    .card h2{
      margin-top:0;
      color:#1f3c88;
    }

    /* -------------------------
       Current Command
    ------------------------- */

    #status{
      font-size:28px;
      font-weight:bold;
      color:#1f3c88;
      margin-top:10px;
    }

    /* -------------------------
       Controller
    ------------------------- */

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

    .empty{
      visibility:hidden;
    }

    /* -------------------------
       Distance
    ------------------------- */

    #distance{
      font-size:40px;
      font-weight:bold;
      color:#1f7aec;
      margin-top:10px;
    }

    /* -------------------------
       AGV Status
    ------------------------- */

    #statusCard{
      width:220px;
      margin:auto;
      padding:20px;
      border-radius:15px;
      background:#4CAF50;
      color:white;
      font-size:30px;
      font-weight:bold;
    }

    #statusText{
      font-size:20px;
      margin-top:15px;
    }

    /* -------------------------
       Last Update
    ------------------------- */

    #lastUpdate{
      font-size:20px;
      font-weight:bold;
      color:#333;
      margin-top:10px;
    }

  </style>
</head>

<body>

  <div class="dashboard">

    <h1>SMART AGV DASHBOARD</h1>

    <p>Control & Monitoring System</p>


    <!-- =========================
         Current Command
    ========================== -->

    <div class="card">

      <h2>Current Command</h2>

      <div id="status">
        READY
      </div>

    </div>


    <!-- =========================
         Controller
    ========================== -->

    <div class="card">

      <h2>Controller</h2>

      <p>
        Press and hold a button to move.
        Release to stop.
      </p>

      <div class="controller">

        <div class="empty"></div>

        <button
          class="btn"
          onmousedown="startCmd('forward')"
          onmouseup="stopCmd()"
          onmouseleave="stopCmd()"
          ontouchstart="startCmd('forward')"
          ontouchend="stopCmd()"
          ontouchcancel="stopCmd()">
          Forward
        </button>

        <div class="empty"></div>


        <button
          class="btn"
          onmousedown="startCmd('left')"
          onmouseup="stopCmd()"
          onmouseleave="stopCmd()"
          ontouchstart="startCmd('left')"
          ontouchend="stopCmd()"
          ontouchcancel="stopCmd()">
          Left
        </button>


        <button
          class="btn stop"
          onclick="stopCmd()">
          Stop
        </button>


        <button
          class="btn"
          onmousedown="startCmd('right')"
          onmouseup="stopCmd()"
          onmouseleave="stopCmd()"
          ontouchstart="startCmd('right')"
          ontouchend="stopCmd()"
          ontouchcancel="stopCmd()">
          Right
        </button>


        <div class="empty"></div>


        <button
          class="btn"
          onmousedown="startCmd('backward')"
          onmouseup="stopCmd()"
          onmouseleave="stopCmd()"
          ontouchstart="startCmd('backward')"
          ontouchend="stopCmd()"
          ontouchcancel="stopCmd()">
          Backward
        </button>

        <div class="empty"></div>

      </div>

    </div>


    <!-- =========================
         Distance
    ========================== -->

    <div class="card">

      <h2>Distance</h2>

      <div id="distance">
        -- cm
      </div>

    </div>


    <!-- =========================
         AGV Status
    ========================== -->

    <div class="card">

      <h2>AGV Status</h2>

      <div id="statusCard">

        SAFE

      </div>

      <p id="statusText">

        No obstacle detected.

      </p>

    </div>


    <!-- =========================
         Last Update
    ========================== -->

    <div class="card">

      <h2>Last Update</h2>

      <div id="lastUpdate">

        --:--:--

      </div>

    </div>

  </div>


  <!-- =========================
       JavaScript
  ========================== -->

  <script>


    // --------------------------------
    // Start Command
    // --------------------------------

    function startCmd(cmd){

      event.preventDefault();

      fetch('/' + cmd);

      document.getElementById("status").innerHTML =
        cmd.toUpperCase();

    }


    // --------------------------------
    // Stop Command
    // --------------------------------

    function stopCmd(){

      event.preventDefault();

      fetch('/stop');

      document.getElementById("status").innerHTML =
        "STOP";

    }


    // --------------------------------
    // Real-Time Dashboard
    // --------------------------------

    setInterval(function(){

      fetch("/distance")

      .then(response => response.text())

      .then(data => {

        // ----------------------------
        // Convert Distance
        // ----------------------------

        let distance = Number(data);


        // ----------------------------
        // Display Distance
        // ----------------------------

        document.getElementById("distance").innerHTML =
          distance + " cm";


        // ----------------------------
        // Update Last Update
        // ----------------------------

        let now = new Date();

        document.getElementById("lastUpdate").innerHTML =
          now.toLocaleTimeString();


        // ----------------------------
        // Smart Dashboard
        // ----------------------------

        if(distance > 50)
        {

          document.getElementById("statusCard").innerHTML =
            "SAFE";

          document.getElementById("statusCard").style.background =
            "#4CAF50";

          document.getElementById("statusText").innerHTML =
            "No obstacle detected.";

        }

        else if(distance > 20)
        {

          document.getElementById("statusCard").innerHTML =
            "WARNING";

          document.getElementById("statusCard").style.background =
            "#FF9800";

          document.getElementById("statusText").innerHTML =
            "Obstacle is nearby.";

        }

        else
        {

          document.getElementById("statusCard").innerHTML =
            "DANGER";

          document.getElementById("statusCard").style.background =
            "#F44336";

          document.getElementById("statusText").innerHTML =
            "Stop the AGV immediately!";

        }

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
