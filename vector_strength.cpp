/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
constexpr double TWO_PI = 2 * M_PI;
// Define a struct to represent a single spike event
struct Spike {
    double time1; // time of occurrence
    double phase; // phase of occurrence (in radians)
};
// Function to compute the Rayleigh test statistic
double compute_rayleigh_value(const vector<Spike>& spikes) {
    double x = 0.0;
    double y = 0.0;
    for (const Spike& spike : spikes) {
        x += cos(spike.phase);
        y += sin(spike.phase);
    }
    double r = sqrt(x * x + y * y) / spikes.size();
    double rayleigh = 2*spikes.size() * r * r;
    return rayleigh;
}
pair<double, double> compute_mean_vector(const vector<Spike>& spikes, double p) {
    double x = 0.0;
    double y = 0.0;
    double phase_sum_x = 0.0;
    double phase_sum_y = 0.0;
    vector <double> vs;
    for (size_t i = 0; i < spikes.size(); i++) {
        const Spike& spike = spikes[i];
        double phase = TWO_PI * fmod(spike.time1, p) / p;
        x += cos(phase);
        y += sin(phase);
        double vectorstrength = sqrt(x * x + y * y);
        vs.push_back(vectorstrength);
        
        phase_sum_x += cos(spike.phase);
        phase_sum_y += sin(spike.phase);
    }
    
    
    double vector_strength = sqrt(x * x + y * y) / spikes.size();
    double mean_phase = atan2(y, x);
    double mean_phase_all_trials = atan2(phase_sum_y, phase_sum_x);
    double phase_diff = mean_phase - mean_phase_all_trials;
    double vector_strength_phase_projected = vector_strength * cos(phase_diff);
    return make_pair(vector_strength, vector_strength_phase_projected);
    
    
    
}

/*double avg_vectorstrength(const vector<Spike>& spikes)
{   
    double x = 0.0;
    double y = 0.0;
    double p = 500.0;
    vector <double> xi;
    vector <double> yi;
    vector <double> vs;
    
    
    for (size_t i = 0; i < spikes.size(); i++) {
        x = 0;
        y = 0;
        const Spike& spike = spikes[i];
        double phase = TWO_PI * fmod(spike.time1, p) / p;
        x += cos(phase);
        y += sin(phase);
        double vectorstrength = sqrt(x * x + y * y);
        vs.push_back(vectorstrength);
        
    }
    
    double avg_vs = 0;
    
    for(auto it : vs)
    {
        avg_vs += it;
    }
    
    //double xii = x/spikes.size();
    //double yii = y/spikes.size();
    
    
    return avg_vs / spikes.size();
}*/



int main() {
    // define the sample spike times
    //vector <double> spike_times = {10,44,72,12,10,105,449,13,183,11,57,293,10,74,16,74,213,12,28};
    // define the frequency of the oscillation
    std::vector<int> spike_times = {-1, -1, 7, -1, -1, 257, -1, 161, -1, -1, 242, 276, -1, 4, 19, 280, -1, 267, -1};

    // Replace -1 with 0 in the vector
    for (int &val : spike_times) {
        if (val == -1) {
            val = 0;
        }
    }
    double p = 500.0;
    double freq = 4.0;  // Hz
    // calculate the reference time
    double t0 = spike_times[0];
    // calculate the phase angle for each spike
    vector<double> phase_angles;
    for (int i = 0; i < spike_times.size(); i++) {
        double t = spike_times[i];
        //double phase = (2 * 3.14 * ((int) t%(int) p))/p;
        double phase = (TWO_PI * fmod(t, p)) / p;
        phase_angles.push_back(phase);
    }
    // create vector of Spike structs with spike times and phase angles
    vector<Spike> spikes;
    for (int i = 0; i < spike_times.size(); i++) {
        double time1 = spike_times[i];
        double phase = phase_angles[i];
        spikes.push_back({time1, phase});
    }
    // calculate the mean vector and vector strength
     // period of the oscillation
    auto [vector_strength, vector_strength_phase_projected] = compute_mean_vector(spikes, p);
    // calculate the Rayleigh test statistic
    double rayleigh = compute_rayleigh_value(spikes);
    // print the results
    //double avg = avg_vectorstrength(spikes);
    std::cout << "Mean phase: " << vector_strength_phase_projected << " radians\n";
    std::cout << "Vector strength: " << vector_strength << "\n";
    std::cout << "Rayleigh value: " << rayleigh << "\n";
    //std::cout << "Avg VS: " << avg << "\n";
    cout<<"The k value is : "<<new_expo(spikes)<<endl;
    
    return 0;
}



