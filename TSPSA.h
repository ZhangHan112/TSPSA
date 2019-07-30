#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<string>
#include<fstream>
#include<cmath>
using namespace std;

class TSPSA{
public: 
    int iter;
    int run;
    int T;
    double t;
    double turnaround;


    int size;
    double fit1;
    double fit2;
    double Best;

    vector<int> X;
    vector<int> Y;
    vector<int> alternation;
    vector<int> neighbor;

    TSPSA(int Iteration,int Run,int Temperature);
    void SA();
    void Initialize();
    vector<int> Transition(vector<int> arr);
    double Fitness(vector<int> arr);
    void Determination();
    void updateT();
    void ReadFile();
    
};