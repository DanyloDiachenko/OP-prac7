#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void getAndValidateEquationType(enum EquationType *equationType);
void getAndValidateY(int *y);
void getAndValidateEquationSolingMethod(enum SolveEquationMethod *solvingMethod);
void getAndValidateRange(double *leftRangeValue, double *rightRangeValue);
void getAndValidateEpsilon(double *epsilon);
double getResultByHalDividing();
bool askToContinue();
double truncateNumber(double value, int decimalPlaces);
int getDecimalPlaces(double epsilon);
double getResultByHalDividing(double (*solveEquation)(double), double left, double right, double epsilon);
double derivative(double (*function)(double), double x);
double getResultByNewton(double (*function)(double), double start, double epsilon);
double getTrigonometricFraction(double x, int y);
double getTrigonometricLogarithm(double x, int y);
double getTrigonometricFractionWrapper(double x);
double getTrigonometricLogarithmWrapper(double x);

#endif // FUNCTIONS_H
