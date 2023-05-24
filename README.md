
# Room Area Finding Robot

Repository for HackWesTX: Spring '23 project. A rover that scans, finds, and uploads the area of a given room to a webapp.

Our 6-man team, designed a rover / tank-style robot operated autonomously by an Arduino UNO. The function is to scan the perimiter of a given room by tracing the walls, and uploading its collected data to create a visual representation of the room based on its corners.


## Overview

The Ardunio UNO, combined with a microcontroller for the rover's movement system, it can use ultrasonic sensor data to detect the distance travelled along a given wall. Detecting corners alows the rover to make turns, scanning the perimeter of an entire room. 

Using an ESP8266 module, a python script can recive the sensor data from a local flask network, and calculate a visual graph of the corner points in the room. Therefore, outlining the room.

Once this data has been generated, it is uploaded to a webapp, displaying the graph, along with any other relevant data associated.
## In-Progress

#### Rover Corner Detection:
- Configuring rover movement to detect a right hand turn and making adjustments if too close to the wall.

#### ngrok and flask integration with ESP8266
- Transferring ultrasonic sensor data from ESP8266 into local ngrok server.

## Images

<img src="https://github.com/SlashAlexx/area-finding-robot_hackwestx23/assets/119014375/3d652f11-5fb5-4431-bf11-4e66459cea06" width="500">
<img src="https://github.com/SlashAlexx/area-finding-robot_hackwestx23/assets/119014375/b3e5c768-8682-4547-8180-bc51a5ce6b50" width="500">


## Contributors

- Bryson Deweese: Arduino and microcontroller programming, hardware and design logicistics, and debugging.
- Samir Hossain: Ardino and ESP8266 programming and debugging, design logistics, and network testing and implementation.
- Austin Ladd: Hardware logistics, microcontroller debugging, and user testing.
- Nick Rethans: Movement and corner detection calculations, HTML webapp design, design logistics, and network testing.
- Alex Roberts: Movement and corner detection calculations, python programming, and network testing and implementation.
