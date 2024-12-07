void getAndValidateEquationType(enum EquationType *equationType) {
    do {
        printf("Enter the equation type to solve: '1' - 1) '2' - 2): ");

        char equationTypeInput = getchar();
        fflush(stdin);

        switch(equationTypeInput) {
            case '1': {
                *equationType = TRIGONOMETRIC_FRACTIONS;
                break;
            }
            case '2': {
                *equationType = TRIGONOMETRIC_LOGARITHM;
                break;
            }
            default: {
                printf("Invalid value for equation type. Please enter '1' or '2'.\n");
            }
        }
    } while (*equationType == 0);
}

void getAndValidateEquationSolvingMethod(enum SolveEquationMethod *solvingMethod) {
    do {
        printf("Enter the equation solving method '1' - Half Dividing, '2' - Newton method: ");

        char solvingMethodInput = getchar();
        fflush(stdin);

        switch(solvingMethodInput) {
            case '1': {
                *solvingMethod = HALF_DIVIDING;
                break;
            }
            case '2': {
                *solvingMethod = NEWTON;
                break;
            }
            default: {
                printf("Invalid value for solving method. Please enter '1' or '2'.\n");
            }
        }
    } while (*solvingMethod == 0);
}

void getAndValidateRange(double *leftRangeValue, double *rightRangeValue)
{
    bool isValid = false;

    do
    {
        printf("Enter the left range value, less than right (between %d and %d): ", MIN_RANGE_LIMIT, MAX_RANGE_LIMIT);
        isValid = scanf("%lf", leftRangeValue);
        fflush(stdin);

        if (!isValid)
        {
            printf("Invalid input for left range value. Please enter an integer.\n");

            continue;
        }

        if (*leftRangeValue < MIN_RANGE_LIMIT || *leftRangeValue > MAX_RANGE_LIMIT)
        {
            printf("Left range value is out of range. Please enter a value between %d and %d.\n", MIN_RANGE_LIMIT, MAX_RANGE_LIMIT);

            isValid = false;
        }
    } while (!isValid);

    do
    {
        printf("Enter the right range value, greater than left (between %d and %d): ", MIN_RANGE_LIMIT, MAX_RANGE_LIMIT);
        isValid = scanf("%lf", rightRangeValue);
        fflush(stdin);

        if (!isValid)
        {
            printf("Invalid input for right range value. Please enter an integer.\n");

            continue;
        }

        if (*rightRangeValue <= *leftRangeValue)
        {
            printf("Invalid input for right range value. It must be greater than left range value.\n");

            isValid = false;
        }
        else if (*rightRangeValue < MIN_RANGE_LIMIT || *rightRangeValue > MAX_RANGE_LIMIT)
        {
            printf("Right range value is out of range. Please enter a value between %d and %d.\n", MIN_RANGE_LIMIT, MAX_RANGE_LIMIT);

            isValid = false;
        }

    } while (!isValid);
}

void getAndValidateEpsilon(double *epsilon)
{
    do
    {
        printf("Enter the accuracy from %.0e to %.0e (e.g., 0.0001): ", MIN_EPSILON, MAX_EPSILON);
        if (scanf("%lf", epsilon) != 1)
        {
            printf("Invalid input for accuracy. Please enter a valid number.\n");
            fflush(stdin);

            continue;
        }
        fflush(stdin);

        if (*epsilon < MIN_EPSILON || *epsilon > MAX_EPSILON)
        {
            printf("Accuracy value is out of range. Please enter a value between %.0e and %.0e.\n", MIN_EPSILON, MAX_EPSILON);
        }
    } while (*epsilon < MIN_EPSILON || *epsilon > MAX_EPSILON);
}

bool askToContinue()
{
    printf("Do you want to run program again? Press 'y' to continue or any other key to exit: ");

    int key = getchar();
    fflush(stdin);

    return key == 'y';
}

double truncateNumber(double value, int decimalPlaces)
{
    double factor = pow(10.0, (double)decimalPlaces);

    return trunc(value * factor) / factor;
}

int getDecimalPlaces(double epsilon)
{
    int decimalPlaces = 0;

    while (epsilon < 1.0 && decimalPlaces < 15)
    {
        epsilon *= 10.0;
        decimalPlaces++;
    }

    return decimalPlaces;
}

double getTrigonometricFraction(double x) {
    return cos(1.0 / x) - 2 * sin(1.0 / x) + 1.0 / x;
}

double getTrigonometricLogarithm(double x) {
    return sin(log(x)) - cos(log(x)) + log(x);
}

double getResultByHalDividing(double (*solveEquation)(double), double left, double right, double epsilon) {
    do {
        double middle = (left + right) / 2.0;
        double fLeft = solveEquation(left);
        double fMiddle = solveEquation(middle);

        if (fLeft * fMiddle <= 0) {
            right = middle;
        } else {
            left = middle;
        }
    } while (fabs(right - left) > epsilon);

    return (left + right) / 2.0;
}

double derivative(double (*function)(double), double x) {
    return (function(x + EPSILON_FOR_NEWTON) - function(x)) / EPSILON_FOR_NEWTON;
}

double getResultByNewton(double (*function)(double), double start, double epsilon) {
    double x = start;
    double delta = 0.0;

    do {
        double fValue = function(x);
        double fDerivative = derivative(function, x);

        if (fabs(fDerivative) < 1e-10) {
            printf("Derivative is too small. Method cannot proceed.\n");
            return NAN;
        }

        delta = fValue / fDerivative;
        x = x - delta;

    } while (fabs(delta) > epsilon);

    return x;
}