# Ultrasonic_with_thermometer_DHT11
Ultrasonic with thermometer DHT11

Design a Parking Assist System (倒車雷達) by using ultrasonic sensor, speaker, and RGB LED
– Divide the detecting distance into three parts: a) Safe; b) Be careful; and c) Dangerous.
– Use the RGB LED to show Green, Yellow, and Red for a) Safe; b) Be careful; and c) Dangerous, respectively.
– Use the speaker to reminder the driver. • Safe: no sound
• Be careful: two beeps per second
• Dangerous: four beeps per second

In processing industry, high accurate distance detection approach is needed.
The speed of sound is affected by temperature and humidity.
Please try to use the temperature to make ultrasonic sensor more precisely.

• Theapproximatespeedofsoundindry(0%humidity) air, in meters per second (m/s), at temperatures near 0 °C, can be calculated from:
where theta is the temperature in degrees Celsius (°C).
• Humidityhasasmallbutmeasurableeffectonsound speed (causing it to increase by about 0.1%-0.6%), because oxygen and nitrogen molecules of the air are replaced by lighter molecules of water. So we will ignore this factor.
