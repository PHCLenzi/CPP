#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <typeinfo>

using namespace std;

const int g = 9.81;

void calculate_attitude_estimation(vector<int>* accel_vect_input,vector<float>* attitude_vect_output){
    //attitude_vect_output = <millis, roll, pitch>

    //millis
    (*attitude_vect_output)[0] = (*accel_vect_input)[0];
    // roll
    (*attitude_vect_output)[1] = (atan2((*accel_vect_input)[2], (*accel_vect_input)[3]));// atan2(a_y, a_)
    //pitch
    (*attitude_vect_output)[2] = (asin((*accel_vect_input)[1]/ g));// asin(a_x/g)
    
}

void print(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}


int main()
{

    vector <int> millis,x_accel,y_accel,z_accel;
    // vector <string> millis,x_accel,y_accel,z_accel;

    const int g = 9.81;
   

    
    // Open the .log file for reading
    std::ifstream logfile("C:/Users/pedro/Desktop/CPP_Codes/CPP/Accelerometer_reader/attitude_exam.log");

    // Check if the file was opened successfully
    if (!logfile.is_open())
    {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    // Read the contents of the file line by line
    std::string line;
    size_t pos = 0;
    vector <int> info_input(4); //millis, input_x_accel, input_y_accel, input_z_accel
    vector <float> info_output(3); //millis, output_x_attitude, output_y_attitude

    while (std::getline(logfile, line))
    {
        cout <<" line = " << line << endl;
       // for each ";" put int vector
        while ((pos = line.find(";")) != std::string::npos) {
            // for millis
            pos = line.find(";");
            // millis.push_back(stoi(line.substr(0, pos)));
            info_input[0] = (stoi(line.substr(0, pos)));
            line.erase(0,pos+1);

            // for x_accel
            pos = line.find(";");
            info_input[1] = (stoi(line.substr(0, pos)));
            // x_accel.push_back(stoi(line.substr(0, pos)));
            line.erase(0,pos+1);

            // for y_accel
            pos = line.find(";");
            info_input[2] = (stoi(line.substr(0, pos)));
            // y_accel.push_back(stoi(line.substr(0, pos)));
            line.erase(0,pos+1);

            // for z_accel
            pos = line.find(";");
            info_input[3] = (stoi(line.substr(0, pos)));
            // z_accel.push_back(stoi(line.substr(0, pos)));
        }
        // print(info_input);
        calculate_attitude_estimation(&info_input, &info_output);
        cout << "info_output[0] = " << info_output[0] << ", info_output[1] = " <<info_output[1] << \
        ", info_output[2] = " <<info_output[2] << endl;
    }   
    // Close the file
    logfile.close();


    return 0;
}
