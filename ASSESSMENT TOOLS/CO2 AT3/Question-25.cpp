#include <iostream>
#include <thread>
#include <chrono>

#define LED 13
#define BUTTON 2

volatile bool interruptFlag = false;

void buttonISR() {
    interruptFlag = true;
}

int main() {
    std::cout << "Polling vs Interrupt Demo" << std::endl;

    while (true) {
        // Polling simulation
        std::cout << "Polling Method Running..." << std::endl;
        std::cout << "LED ON" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "LED OFF" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Interrupt simulation
        if (interruptFlag) {
            std::cout << "Interrupt Triggered! Toggle LED" << std::endl;
            interruptFlag = false;
        }

        // Simulate button press after 5 seconds
        static int counter = 0;
        counter++;
        if (counter == 5) buttonISR();
    }
}
