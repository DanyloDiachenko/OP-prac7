#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void getAndValidateEquationType(enum EquationType *equationType);
void getAndValidateEquationSolingMethod(enum SolveEquationMethod *solvingMethod);
void getAndValidateRange(int *leftRangeValue, int *rightRangeValue);
void getAndValidateEpsilon(double *epsilon);
bool askToContinue();
double truncateNumber(double value, int decimalPlaces);
int getDecimalPlaces(double epsilon);

#endif // FUNCTIONS_H
