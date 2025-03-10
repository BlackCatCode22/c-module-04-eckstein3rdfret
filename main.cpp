#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

//Function prototypes, all might not be used
void file_reading_func();
void file_output_func(const map<string, int>&, const vector<class Animal> &);

//global map to store animal counts
//stores {{"Hyenas",0},{"Bears",0},{"Lions",0},{"Tigers",0}}
map<string, int> Animals = {{"Bears", 0},{"Hyenas",0},{"Lions",0},{"Tigers",0}};

//global vector to store lines read from file, not all might be used
vector<string> line_vector;
vector<vector<string>> lines;

//global vector to store animal class objects
vector<Animal> Zoo_Animals;

class Animal {
    public:
        string name;
        int age;
        string species;

        string getName() const {
            return name;
        }
        int getAge() const {
            return age;
        }
        string getSpecies() const {
            return species;
        }
        Animal(const string &x, const int y, const string &z) {
            name = x;
            age = y;
            species = z;
        }
};

//I don't like the idea of coding out each subclass for the animal, maybe I can find a workaround eventually
class Bear: public Animal {
    public:
        static void someMethod1() {
            cout << "I'm a Bear!";
        }
};

class Hyena: public Animal {
    public:
        static void someMethod2() {
            cout << "I'm a Hyena!";
        }
};

class Lion: public Animal {
    public:
        static void someMethod3() {
            cout << "I'm a Lion!";
        }
};

class Tiger: public Animal {
    public:
        static void someMethod4() {
            cout << "I'm a Tiger!";
        }
};

int main() {

    //The Goal of the reading function is the following:
    //Read arrivingAnimals.txt line by line, Create a new Animal object, store object in Zoo_Animals Vector...
    //Then update Map of Animal counts
    file_reading_func();

    //The Goal of the output function is the following:
    //Take Map of Animal Counts and Zoo_Animals Vector as input
    //Use Map to dictate which Species to search in Zoo_Animals Vector, Print Animal count
    //When Correct Species is found, Print new line using object methods to call object data
    file_output_func(Animals, Zoo_Animals);

    return 0;
}

void file_reading_func() {
    //TODO
    fstream myFile;
    //Below opens a file to READ from it
    myFile.open("C:/Users/eckst/Desktop/arrivingAnimals.txt", ios::in);//read mode

    //need to check if the file opened successfully
    if (myFile.is_open()) {
        string line_of_txt;
        //getline(A,B) reads a line of data from A and stores it in variable B
        while (getline(myFile,line_of_txt)) {

            //This is where the code for parsing each line will go
            //The goal is to filter through "arriving Animals.txt" for the following
            //Age & Species, name will be manually added to the object
            //Most brute force method of parsing would be to take advantage of known file format
            //all needed data is in same spot of each line, so store all words excluding commas and spaces in vector
            //then Directly reference vector position for needed data
            //vector[0] gets age, vector [4] gets species
            //Finally call animal object creation
            string Animal_Name;
            int Animal_Age = 0;
            string Animal_Species;
            Animal AnimalObj(Animal_Name, Animal_Age, Animal_Species);

            //Once Object is created append to the Zoo_Animals Vector
            Zoo_Animals.push_back(AnimalObj);
            //Continue with next line until all lines are read and all objects created
        }
        //Don't forget to close the file you opened when finished.
        myFile.close();
    }
}

void file_output_func(const map<string, int>& Animals, const vector<class Animal> &Zoo_Animals) {
    //TODO

    fstream myFile;

    //Below opens a file to WRITE to it
    //myFile.open("C:/Users/eckst/Desktop/newAnimals.txt", ios::out);//write mode(overrides existing file content)

    //Below opens a file to APPEND to it
    myFile.open("C:/Users/eckst/Desktop/newAnimals.txt", ios::app);//Appends to the end of existing file content)

    //need to check if the file opened successfully
    if (myFile.is_open()) {
        //This loops through the Animal MAP
        //It prints Animal type and #
        for (const auto&[fst, snd] : Animals) {
            myFile << "Number of " << fst << "Value: " << snd << "\n";
            myFile << "\n";
        //This loops through animal objects vector
        //Looking for a match to current Animal MAP
            for (const auto& obj : Zoo_Animals) {
        //If a match is found, print the objects within that vector spot, and look at next vector spot
                if (obj.getSpecies() == fst) {
                    myFile << "Name: " << obj.getName() << "Age: " << obj.getAge() << "\n";
                }

            }

        }
        //close file when done
        myFile.close();
    }
}


