//
//  vehicle.hpp
//  Behavioural Planner
//
//  Adapted vehicle class from Udacity
//

#ifndef vehicle_hpp
#define vehicle_hpp

#include <stdio.h>
#include <iostream>
#include <random>
#include <sstream>
#include <fstream>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <iterator>

using namespace std;

class Vehicle {
public:
    
    map<string, int> lane_direction = {{"PLCL", -1}, {"LCL", -1}, {"LCR", 1}, {"PLCR", 1}};
    
    struct collider{
        
        bool collision ; // is there a collision?
        int  time; // time collision happens
        
    };
    
    int id;
    
    int L = 1;
    
    int preferred_buffer = 6; // impacts "keep lane" behavior.
    
    int lane;
    
    double s;
    
    double d;
    
    double v;
    
    double a;
    
    double target_speed;
    
    int lanes_available;
    
    double max_acceleration;
    
    int goal_lane;
    
    int goal_s;
    
    double MAX_ACCEL = 10;
    
    double MAX_JERK = 10;
    
    float dt = 0.02;
    
    int prev_points = 1;
    
    string state;
    
    /**
     * Constructor
     */
    Vehicle();
    Vehicle(int lane, float s, float d, float v, float a,string state="CS");
    
    /**
     * Destructor
     */
    virtual ~Vehicle();
    
    vector<Vehicle> choose_next_state(map<int, vector<Vehicle>> predictions);
    
    vector<string> successor_states();
    
    vector<Vehicle> generate_trajectory(string state, map<int, vector<Vehicle>> predictions);
    
    vector<double> get_kinematics(map<int, vector<Vehicle>> predictions, int lane);
    
    vector<Vehicle> constant_speed_trajectory();
    
    vector<Vehicle> keep_lane_trajectory(map<int, vector<Vehicle>> predictions);
    
    vector<Vehicle> lane_change_trajectory(string state, map<int, vector<Vehicle>> predictions);
    
    vector<Vehicle> prep_lane_change_trajectory(string state, map<int, vector<Vehicle>> predictions);
    
    void increment(int dt);
    
    double position_at(int t);
    
    bool get_vehicle_behind(map<int, vector<Vehicle>> predictions, int lane, Vehicle & rVehicle);
    
    bool get_vehicle_ahead(map<int, vector<Vehicle>> predictions, int lane, Vehicle & rVehicle);
    
    vector<Vehicle> generate_predictions(int horizon=2);
    
    void realize_next_state(vector<Vehicle> trajectory);
    
    void configure(int s,float max_acc, int lane);
    
    float max_accel_cost(Vehicle vehicle, vector<Vehicle> trajectory, map<int, vector<Vehicle>> predictions, map<string, float> data);
    
    float max_jerk_cost(Vehicle vehicle, vector<Vehicle> trajectory, map<int, vector<Vehicle>> predictions, map<string, float> data);
    
};



#endif /* vehicle_hpp */
