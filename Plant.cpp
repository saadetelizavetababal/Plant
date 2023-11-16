
#include <iostream>
#include <vector>

class Plant {
private:
    std::string name;
    int sunlightExposure;
    int irrigationAmount;

public:
    Plant(std::string plantName) : name(plantName), sunlightExposure(1), irrigationAmount(1) {}

    void water() {
        std::cout << "The plant has been watered!" << std::endl;
        irrigationAmount++;
    }

    void exposeToSunlight() {
        std::cout << "The plant is getting sunlight!" << std::endl;
        sunlightExposure++;
    }

    void displayInfo() {
        std::cout << name << std::endl;
        std::cout << "The sunlight exposure time: " << sunlightExposure << std::endl;
        std::cout << "The amount of irrigation: " << irrigationAmount << std::endl;
    }
};

class Garden {
private:
    std::string name;
    std::vector<Plant> plants;

public:
    Garden() {
        std::cout << "Garden Default Constructor" << std::endl;
        std::cout << "Enter your garden name: ";
        std::cin >> name;
        std::cout << "Garden " << name << ": Number of Flowers: 3" << std::endl;
    }

    void addPlant(const std::string& plantName) {
        if (plants.size() < 5) {
            Plant newPlant(plantName);
            plants.push_back(newPlant);
            std::cout << plantName << " has been successfully added to the garden." << std::endl;
        }
        else {
            std::cout << "Cannot add more plants. Garden is full." << std::endl;
        }
    }
    void displayGardenInfo() {
        std::cout << "Garden " << name << ": Number of Flowers: " << plants.size() << std::endl;
        for (Plant& plant : plants) {
            plant.displayInfo();
            plant.water();
            plant.exposeToSunlight();
        }
    }



    ~Garden() {
        std::cout << "Destructor" << std::endl;
    }
};

int main() {
    Garden myGarden;
    myGarden.addPlant("Rose");
    myGarden.addPlant("Daisy");
    myGarden.addPlant("Lavender");
    myGarden.displayGardenInfo();

    return 0;
}