#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

#define THRESHOLD 600

int main() {
    std::cout << "Industrial Fault Detection System (Simulation)" << std::endl;

    while (true) {
        // Simulate sensor value (random 0–1023 like Arduino ADC)
        int sensorValue = rand() % 1024;

        std::cout << "Sensor Value : " << sensorValue << std::endl;

        if (sensorValue > THRESHOLD) {
            std::cout << "FAULT DETECTED - LED ON, BUZZER ON" << std::endl;
        } else {
            std::cout << "SYSTEM NORMAL - LED OFF, BUZZER OFF" << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
