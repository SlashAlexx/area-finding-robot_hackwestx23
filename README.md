
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