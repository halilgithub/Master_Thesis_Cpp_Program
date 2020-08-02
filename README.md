# Master_Thesis_Cpp_Program
In my master thesis, I had developed a demo application. It consists of two parts: C program and C++ Qt program. This repo contains the **C++ Qt** program source code.

| **User Interface on Touch Panel** |
|:----:|
| ![User Interface on Touch Panel](https://github.com/halilgithub/Master_Thesis_Cpp_Program/blob/master/screen_shots/interface.jpg "User Interface on Touch Panel") |

## Fuctionality

The second part of the demo application is C++ Qt program which is executed on linux side. It is the user interface of the
whole demo application as seen below. It basically sends a trivial message to Arm Cortex M4 side and makes it send sensor data
as answer back. Then it gets the sensor data and outputs them on the touch screen every 0.75 seconds.
It includes also the second part of the logic for "Low Power".

Whenever the user presses the "Low Power" button on touch screen, C++ Qt program sends a "*delay" message to Arm Cortex M4
and brings linux system to sleep (It actually brings Arm Dual Core A7 from CRun to CStop) by means of a bash script.
After then, the touch screen goes off.

On Arm Cortex M4 side, our C program receives this message over UART1 and triggers a trivial message which will be sent after 20 seconds for demonstration porpose. This message comes to the linux console on the other side and wakes the system up. Then touch screen comes back and our C++ Qt program continues to output sensor data every 0.75 seconds.






