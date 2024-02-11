#include <iostream>
#include <fstream>
#include <sstream> // For stringstream
#include <string>
#include <vector>

using namespace std;

// Define Student class
class Student {
private:
    string name;
    int id;
    vector<int> notes; // Assuming notes are integers for simplicity
public:
    // Constructor
    Student(string n, int i) : name(n), id(i) {}

    // Functions to get/set student information
    string getName() const { return name; }
    int getId() const { return id; }
    void addNote(int note) { notes.push_back(note); }
    vector<int> getNotes() const { return notes; }

    // Function to calculate average note
    double calculateAverageNote() const {
        double sum = 0.0;
        for (int note : notes) {
            sum += note;
        }
        return notes.empty() ? 0.0 : sum / notes.size();
    }
};

// Function to read student data from file
vector<Student> readStudentData(const string& filename) {
    vector<Student> students;
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            stringstream ss(line);
            string name, noteStr;
            int id;
            if (getline(ss, name, ',')) {
                ss >> id;
                Student student(name, id);
                while (getline(ss, noteStr, ',')) {
                    stringstream noteStream(noteStr);
                    int note;
                    if (noteStream >> note) {
                        student.addNote(note);
                    }
                }
                students.push_back(student);
            }
        }
        inputFile.close();
    } else {
        cout << "Unable to open file " << filename << endl;
    }
    return students;
}

// Function to generate bulletin for each student
void generateBulletin(const vector<Student>& students, const string& outputFilename) {
    ofstream outputFile(outputFilename);
    if (outputFile.is_open()) {
        for (const auto& student : students) {
            outputFile << "Student Name: " << student.getName() << ", ID: " << student.getId() << ", Notes: ";
            vector<int> notes = student.getNotes();
            for (size_t i = 0; i < notes.size(); ++i) {
                outputFile << notes[i];
                if (i != notes.size() - 1) outputFile << ", ";
            }
            outputFile << ", Average Note: " << student.calculateAverageNote() << endl;
        }
        outputFile.close();
    } else {
        cout << "Unable to create output file " << outputFilename << endl;
    }
}

int main() {
    // Read student data from input file
    vector<Student> students = readStudentData("student_data.txt");

    // Generate bulletin for each student
    generateBulletin(students, "bulletin.txt");

    return 0;
}

