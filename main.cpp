#include "TSPSA.h"

int main(int argc,char** argv){
    int Iteration = atoi(argv[1]);
    int Run = atoi(argv[2]);
    int Temperature = atoi(argv[3]);

    TSPSA sa(Iteration,Run,Temperature);
    sa.SA();

    return 0;
}