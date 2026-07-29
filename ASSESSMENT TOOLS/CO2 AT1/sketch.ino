#include <Arduino.h>

// Structure for Robotic Arm Joint State
typedef struct {
  int joint_id;
  float target_angle;
  float current_angle;
  bool moving;
} JointCommand;

JointCommand joint1, joint2;
bool emergency_stop = false;
unsigned long lastUpdate = 0;

void setup() {
  Serial.begin(9600);

  // Initialize joints
  joint1 = {1, 90.0f, 0.0f, true};
  joint2 = {2, 45.0f, 0.0f, true};

  Serial.println("--- Starting Robotic Arm Simulation ---");
}

void loop() {
  // Emergency stop check
  if (emergency_stop) {
    joint1.moving = false;
    joint2.moving = false;
    Serial.println("[CRITICAL] Emergency Stop asserted! Halting all axes.");
    delay(1000);
    return;
  }

  // Update every 100 ms
  if (millis() - lastUpdate >= 100) {
    lastUpdate = millis();

    // Joint 1 motion
    if (joint1.moving && joint1.current_angle < joint1.target_angle) {
      joint1.current_angle += 15.0f;
      Serial.print("[TASK 1] Joint 1 Position: ");
      Serial.print(joint1.current_angle);
      Serial.println(" deg");
      if (joint1.current_angle >= joint1.target_angle) {
        joint1.moving = false;
        Serial.println("[SUPERVISOR] Joint 1 reached target safely.");
      }
    }

    // Joint 2 motion
    if (joint2.moving && joint2.current_angle < joint2.target_angle) {
      joint2.current_angle += 9.0f;
      Serial.print("[TASK 2] Joint 2 Position: ");
      Serial.print(joint2.current_angle);
      Serial.println(" deg");
      if (joint2.current_angle >= joint2.target_angle) {
        joint2.moving = false;
      }
    }
  }

  // Example: trigger emergency stop after 5 seconds
  if (millis() > 5000 && !emergency_stop) {
    emergency_stop = true;
    Serial.println("--- Injecting Emergency Stop ---");
  }
}
