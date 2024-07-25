#ifndef PLANET_H
#define PLANET_H

#include <string>

using namespace std;

class Planet {
    private:
        string name;
        double distance;
        int numMoons;

    public:
        Planet() {
            name = "";
            distance = 0.0;
            numMoons = 0;
        }
        Planet(string name, double distance, int numMoons) {
            this->name = name;
            this->distance = distance;
            this->numMoons = numMoons;
        }

        //getters
        string getName() {
            return name;
        }
        double getDistance() {
            return distance;
        }
        int getNumMoons() {
            return numMoons;
        }

        //setters
        void setName(string name) {
            this->name = name;
        }
        void setDistance(double distance) {
            this->distance = distance;
        }
        void setNumMoons(int numMoons) {
            this->numMoons = numMoons;
        }

        double calcDistance() {
            return distance * 150000000;
        }
};

#endif