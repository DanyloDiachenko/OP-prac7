#include "./includes.h"

int main()
{
    bool continueProgram = true;

    printf("Welcome! This program solves equations equations!\n"
           "1) cos(y/x) - 2sin(1/x) + 1/x = 0\n"
           "2) sin[ln(x)] - cos[ln(x)] + yln(x) = 0\n"
           "\n"
           );

    do
    {
        int leftRangeValue = 0;
        int rightRangeValue = 0;
        double epsilon = 0.0;
        enum SolveEquationMethod solvingMethod = 0;
        enum EquationType equationType = 0;

        getAndValidateEpsilon(&epsilon);
        getAndValidateEquationType(&equationType);
        getAndValidateEquationSolvingMethod(&solvingMethod);
        getAndValidateRange(&leftRangeValue, &rightRangeValue);


        continueProgram = askToContinue();
    } while (continueProgram);

    return 0;
}
