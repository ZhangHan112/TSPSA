#include "TSPSA.h"

TSPSA::TSPSA(int Iteration,int Run,int Temperature){
    iter = Iteration;
    run = Run;
    T = Temperature;
    
    srand(time(NULL));
}

void TSPSA::SA(){
    string s = "output1.dat";

    ReadFile();
    for(int r=0;r<run;r++){
        Initialize();
        if(r<10)
            s.replace(6,1,to_string(r+1));
        else
            s.replace(6,2,to_string(r+1));
         ofstream file(s);

        for(int i=0;i<iter;i++){
            if(i%1000)
                t = T;
            neighbor = Transition(alternation);
            fit1 = Fitness(alternation);
            fit2 = Fitness(neighbor);
            Determination();
            file << i+1 << " " << Best << endl;
        }
        file.close();
        cout << "Best: " << Best <<endl;
    }
    

    
}

void TSPSA::Initialize(){
    Best = 100000;
    t = T;
    alternation = vector<int> (size,0);
    neighbor = vector<int> (size,0);
    vector<int> temp;
    temp.clear();
    for(int i=0;i<size;i++)
        temp.push_back(i);
    
    for(int i=0;i<size;i++){
        int random = rand()%temp.size();
        alternation[i] = temp[random];
        temp.erase(temp.begin()+random);
    }

    neighbor = alternation;

}

vector<int> TSPSA::Transition(vector<int> arr){
    int pos1 = rand()%size;
    int pos2;

    while(true){
        pos2 = rand()%size;
        if(pos1==pos2)
            continue;
        break;
    }

    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;

    return arr;
}

double TSPSA::Fitness(vector<int> arr){
    double sum=0;
    int p1,p2;
    for(int i=0;i<size;i++){
        p1=i;
        p2=(i+1)%size;
        sum += sqrt( pow(arr[p1]-arr[p2],2)+pow(arr[p1]-arr[p2],2) );

    }
    return sum;
}

void TSPSA::Determination(){
    double random = (double)(rand()%100+1)/100;
    if(fit2<fit1){
        if(fit2<Best)
            Best = fit2;
        alternation = neighbor;
    }
    else{
        turnaround = (double) exp( (fit1-fit2)/t );
        //cout << "turnaround: " << turnaround << endl;
        if(random < turnaround)
            alternation = neighbor;
    }
}

void TSPSA::updateT(){
    t *= 0.9;
}

void TSPSA::ReadFile(){
    ifstream inputFile("input.txt");
    int temp,x,y;
    string s;
    X.clear();
    Y.clear();
    while(!inputFile.eof()){
        inputFile>>temp>>x>>y;
        X.push_back(x);
        Y.push_back(y);
    }
    inputFile.close();
   
    size = X.size();

}