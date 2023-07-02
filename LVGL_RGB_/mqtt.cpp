#include "mqtt.h"
#include <WiFi.h>
#include <PubSubClient.h>
#include "ui.h"
#include "secrets.h"

WiFiClient espClient;
PubSubClient mqttClient(espClient);

const char mqtt_command_topic[] = "alarmo/command";
const char mqtt_state_topic[] = "alarmo/state";

void initWiFi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());

  mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
  mqttClient.setCallback(mqttCallback);
}

void mqttReconnect()
{
  // Loop until we're reconnected
  while (!mqttClient.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (mqttClient.connect("ESP32TouchScreen"))
    {
      Serial.println("connected");
      // Subscribe to get updates on states
      mqttClient.subscribe(mqtt_state_topic);
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void mqttCallback(char *topic, unsigned char *message, unsigned int length)
{
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++)
  {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // Feel free to add more if statements to control more GPIOs with MQTT

  // If a message is received on the topic esp32/output, you check if the message is either "on" or "off".
  // Changes the output state according to the message
  if (String(topic) == mqtt_state_topic)
  {
    if (messageTemp == "disarmed")
    {
      Serial.println("System is disarmed, changing screens");
      _ui_screen_change(ui_LockScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
      _ui_label_set_property(ui_StatusLabel, _UI_LABEL_PROPERTY_TEXT, "");
    }
    else
    {
      Serial.println("System is armed, changing screens");
      _ui_screen_change(ui_UnlockScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
  }
}

void mqtt_loop()
{
  if (!mqttClient.connected())
  {
    mqttReconnect();
  }
  mqttClient.loop();
}

void disarm_alarm(const char *pinCode)
{
  // Check length of pinCode to avoid buffer overrun
  if (strlen(pinCode) <= 10)
  {
    char message[50]; // allocate a bit extra
    sprintf(message,
            "{\"command\": \"DISARM\", \"code\": \"%s\"}",
            pinCode);
    mqttClient.publish(mqtt_command_topic, message);
  }
  else
  {
    Serial.println("Entered PIN Code is too long, should be less than or equal to 10.");
  }
}

void arm_home(lv_event_t *e)
{
  Serial.println("Arming Home");
  mqttClient.publish(mqtt_command_topic, "ARM_HOME");
}

void arm_night(lv_event_t *e)
{
  Serial.println("Arming Night");
  mqttClient.publish(mqtt_command_topic, "ARM_NIGHT");
}

void arm_away(lv_event_t *e)
{
  Serial.println("Arming Away");
  mqttClient.publish(mqtt_command_topic, "ARM_AWAY");
}