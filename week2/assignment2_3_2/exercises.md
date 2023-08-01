/*
In an industrial setting, various sensors are used to monitor equipment health, environmental conditions, etc.
Suppose you are receiving sensor data that includes a timestamp, sensor ID, and the sensor reading.

Exercise 1:

Develop a function to simulate data ingestion.
This function should generate a list of sensor readings.
Each reading is an object that includes
a timestamp (use integers for simplicity), a sensor ID (string), and a sensor value (float).

Exercise 2:

Implement a function that accepts the sensor data list and a sensor ID as parameters.
This function should filter out the readings from the specified sensor and return them as a new list.

Exercise 3:

Develop a function that sorts the filtered sensor data based on the timestamp in ascending order.
This can help in understanding the time series behavior of a particular sensor.

Exercise 4:

Develop a function to detect outliers in sensor readings.
An outlier can be defined as a value that deviates by more than a fixed amount from the mean sensor value.

Exercise 5:

Develop a function to find the sensor that has the highest frequency of readings.
This might indicate that this sensor's data is crucial or the equipment it's monitoring is critical.
*/
