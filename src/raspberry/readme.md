# Raspberry

We build up the Raspberry Pi 3 with BT, Wlan and now also ROS
There is a image located on a server 
**Promissed to do this**

If you want to do this by your sefl or want to know what we did just look here:
http://wiki.ros.org/ROSberryPi/Installing%20ROS%20Indigo%20on%20Raspberry%20Pi

Testing the first listener

precondition:
Runnuing Roscore

To start Arduino serial:
rosrun rosserial_python serial_node.py /dev/ttyACM0

nice to have/see:
rostopic echo /robotron --> when the app is started
rostopic list

when you will connect from a different PC use:
export ROS_MASTER_URI://raspberrypi:11311 
to connect checkt out the with rostopic list if it is working

**Thanks to the ROS-WIKI**

Webcam: https://www.raspberrypi.org/documentation/usage/webcams/

The microsoft webcam "fill in the type" is not working with the easy driver

luckily a different package is availble just use this as intermediat solution
The soure for the image is /dev/video0 




