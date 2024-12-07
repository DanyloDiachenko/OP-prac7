#include "./includes.h"

int main()
{
    bool continueProgram = true;

    printf("Welcome! This program solves equations equations!\n"
           "1) cos(1/x) - 2sin(1/x) + 1/x = 0\n"
           "2) sin[ln(x)] - cos[ln(x)] + ln(x) = 0\n"
           "\n"
           );

    do
    {
        double leftRangeValue = 0;
        double rightRangeValue = 0;
        double epsilon = 0.0;
        enum SolveEquationMethod solvingMethod = 0;
        enum EquationType equationType = 0;
        double result = 0.0;

        getAndValidateEquationType(&equationType);
        getAndValidateEquationSolvingMethod(&solvingMethod);
        getAndValidateRange(&leftRangeValue, &rightRangeValue);
        getAndValidateEpsilon(&epsilon);

        switch (solvingMethod) {
            case HALF_DIVIDING: {
                switch (equationType) {
                    case TRIGONOMETRIC_FRACTIONS: {
                        result = getResultByHalDividing(getTrigonometricFraction, leftRangeValue,
                            rightRangeValue, epsilon);
                        break;
                    }
                    case TRIGONOMETRIC_LOGARITHM: {
                        result = getResultByHalDividing(getTrigonometricLogarithm, leftRangeValue,
                            rightRangeValue, epsilon);
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
                        result = getResultByNewton(getTrigonometricFraction, rightRangeValue, epsilon);
                        break;
                    }
                    case TRIGONOMETRIC_LOGARITHM: {
                        result = getResultByNewton(getTrigonometricLogarithm, rightRangeValue, epsilon);
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
            printf("Result x=%.10f\n", result);
        } else {
            printf("Failed to find solution. Check your inputs or try another method.\n");
        }

        continueProgram = askToContinue();
    } while (continueProgram);

    return 0;
}
