#ifndef AWDS_HPP
#define AWDS_HPP
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

class Sensor {
public:
    virtual std::string detect() = 0;
};

class MotionSensor : public Sensor {
public:
    std::string detect() override {
        int r = rand() % 4;
        if (r == 0) return "Human";
        else if (r == 1) return "Livestock";
        else if (r == 2) return "Wild Animal";
        return "No Intrusion";
    }
};

class Deterrent {
public:
    void activate(const std::string &type) {
        if (type == "Wild Animal") {
            std::cout << "Deterrent Activated: Ultrasonic + Flashing Lights + Alarm!\n";
        } else {
            std::cout << "No deterrent needed.\n";
        }
    }
};

class AWDSSystem {
    MotionSensor sensor;
    Deterrent deterrent;
    std::vector<std::string> logs;
public:
    void detectIntrusion() {
        std::string result = sensor.detect();
        std::cout << "Sensor Detected: " << result << "\n";
        deterrent.activate(result);
        logs.push_back(result);
    }

    void analyzeData() {
        int wildCount = 0;
        for (auto &l : logs) if (l == "Wild Animal") wildCount++;
        std::cout << "Analytics: " << wildCount << " wild animal intrusions so far.\n";
    }
};

#endif
