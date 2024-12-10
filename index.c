#include "./includes.h"

static int globalY;

double getTrigonometricFractionWrapper(double x) {
    return getTrigonometricFraction(x, globalY);
}

double getTrigonometricLogarithmWrapper(double x) {
    return getTrigonometricLogarithm(x, globalY);
}

int main() {
    bool continueProgram = true;

    printf("Welcome! This program solves equations!\n"
           "1) cos(y/x) - 2sin(1/x) + 1/x = 0\n"
           "2) sin[ln(x)] - cos[ln(x)] + y*ln(x) = 0\n\n");

    do {
        int y = 0;
        double leftRangeValue = 0;
        double rightRangeValue = 0;
        double epsilon = 0.0;
        enum SolveEquationMethod solvingMethod = 0;
        enum EquationType equationType = 0;
        double result = 0.0;

        getAndValidateEquationType(&equationType);
        getAndValidateEquationSolvingMethod(&solvingMethod);
        getAndValidateY(&y);
        getAndValidateRange(&leftRangeValue, &rightRangeValue);
        getAndValidateEpsilon(&epsilon);

        globalY = y;

        switch (solvingMethod) {
            case HALF_DIVIDING: {
                switch (equationType) {
                    case TRIGONOMETRIC_FRACTIONS: {
                        result = getResultByHalDividing(getTrigonometricFractionWrapper, leftRangeValue, rightRangeValue, epsilon);
                        break;
                    }
                    case TRIGONOMETRIC_LOGARITHM: {
                        result = getResultByHalDividing(getTrigonometricLogarithmWrapper, leftRangeValue, rightRangeValue, epsilon);
                        break;
                    }
                    default: {
                        printf("Invalid equation type!\n");
                        continue;
                    }
                }
                break;
            }

            case NEWTON: {
                switch (equationType) {
                    case TRIGONOMETRIC_FRACTIONS: {
                        result = getResultByNewton(getTrigonometricFractionWrapper, rightRangeValue, epsilon);
                        break;
                    }
                    case TRIGONOMETRIC_LOGARITHM: {
                        result = getResultByNewton(getTrigonometricLogarithmWrapper, rightRangeValue, epsilon);
                        break;
                    }
                    default: {
                        printf("Invalid equation type!\n");
                        continue;
                    }
                }
                break;
            }

            default: {
                printf("Invalid solving method!\n");
                continue;
            }
        }

        if (!isnan(result)) {
            printf("Result x=%.*lf\n", getDecimalPlaces(epsilon), result);
        } else {
            printf("Failed to find solution. Check your inputs or try another method.\n");
        }

        continueProgram = askToContinue();
    } while (continueProgram);

    return 0;
}
