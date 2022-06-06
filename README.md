
The smart water quality system using AR project is created to demonstrate how actual sensor data is displayed on AR dashboard via Wi-Fi. 
 
Video link:  https://youtu.be/cBpQnGSOgQ4




Introduction
The smart water quality system analyzes data from the sensor to determine the pH of the water, which is then presented in Augmented Reality (AR) on a smartphone or laptop. Along with the advancement of Virtual Reality (VR) technology, Augmented Reality (AR) is quickly gaining traction. As a result, a smart water quality system incorporating AR was created to illustrate AR. To view the system's output, the user just needs to place the PH sensor in the water and the DHT11 sensor nearby, while supplying the Arduino and NodeMCU with the bare minimum of power. Data starts to appear in the system on its own. The data is then shown in an android software called Blynk, and subsequently in augmented reality on an Android phone using the Android Package (APK) format.






Pin configuration
The pin connectors for various devices are shown below.


pH Sensor and Arduino
The table shown below shows connection between pH sensor and Arduino.
![image](https://user-images.githubusercontent.com/57608136/172221422-6a4c89c1-a4ab-4a14-89cb-a48ef4e649b0.png)

 

DHT11 Sensor and NodeMCU
The table shown below shows connection between DHT11 sensor and NodeMCU.
![image](https://user-images.githubusercontent.com/57608136/172221455-0cd01944-26de-40e1-9097-6c44e9a3d0e7.png)

 

Arduino and NodeMCU
The table shown below shows connection between Arduino and NodeMCU.
 
![image](https://user-images.githubusercontent.com/57608136/172221464-ec5ea595-a183-498a-b90e-dd561ebe046c.png)



How does it Works?
The digital, ground, and analog pins of Arduino are linked to the pH sensor pins. Using the serial communication protocol, Arduino receives the pH value from the pH sensor and sends it to NodeMCU in JSON format.
DHT11 pins are linked to D2, GNT, and 3V pins on the NodeMCU. The temperature and humidity values from the DHT11 sensor are delivered to NodeMCU. NodeMCU receives previously provided JSON data from Arduino. The information gathered is subsequently sent to the Blynk server.
From NodeMCU’ s source the authorization token, Wi-Fi name, and password are all provided during the Blynk setup process. This enables you to set up a local server using a shared Wi-Fi network. Temperature, humidity, and pH are all assigned to virtual pins in the Blynk configuration. Data is subsequently uploaded to the Blynk cloud on the local network. As seen in the image, data from the Blynk cloud is transferred to the Blynk mobile.
The Unity program is used to make AR pictures. A virtual 3D dashboard is created using the Unity program. The pH value and temperature value are input text areas on the dashboard. For the virtual button to operate, unity is given a set of code. When the virtual button is pressed, the Blynk server sends the pH and temperature values to the AR dashboard.



Here is the final output of the project.
 
![image](https://user-images.githubusercontent.com/57608136/172221537-b2742f2b-b251-48bb-bc96-5f9b31a22b95.png)





Circuit diagram
The sketch shown below is a circuit diagram of smart IoT water quality system
 
 
Figure 12: circuit diagram
![image](https://user-images.githubusercontent.com/57608136/172221631-c0fe8f68-4802-4c65-9330-dc964936d07e.png)



Block diagram
The sketch shown below is a block diagram shows flow of system 
Figure 13: Block diagram
![image](https://user-images.githubusercontent.com/57608136/172221740-694f11c1-f1a2-4e9f-854b-748dfc410dd6.png)







Flowchart
 ![image](https://user-images.githubusercontent.com/57608136/172221770-1cd5a198-cc42-49ae-87f7-9c4a2090515d.png)

 
 
Schematic diagram
 
Figure 14: Schematic diagram

![image](https://user-images.githubusercontent.com/57608136/172221825-fb262ca5-1f55-43cd-a024-dd978165fd58.png)





For Unity (AR)
The code shown below is for the virtual button, which on pressed sends request signal to Blynk server and receives data and later displayed on AR dashboard. 
 ![image](https://user-images.githubusercontent.com/57608136/172221914-25195a85-0154-48b0-a7e1-789ea03651d4.png)
![image](https://user-images.githubusercontent.com/57608136/172221929-b04daf97-d906-4785-828a-97f77d1c36ef.png)

 
