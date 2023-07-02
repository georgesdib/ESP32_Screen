void initWiFi();
void mqttReconnect();
void mqttCallback(char *topic, unsigned char *message, unsigned int length);
void mqtt_loop();
void disarm_alarm(const char* pinCode);