void getAndValidateEquationNumber(int *equationNumber)
{
    do
    {
        printf("Enter the equation number (between %d and %d): ", MIN_EQUATION_NUMBER, MAX_EQUATION_NUMBER);
        if (scanf("%d", equationNumber) != 1)
        {
            printf("Invalid input for equation number. Please enter an integer.\n");
            fflush(stdin);

            continue;
        }
        fflush(stdin);

        if (*equationNumber < MIN_EQUATION_NUMBER || *equationNumber > MAX_EQUATION_NUMBER)
        {
            printf("Equation number value is out of range. Please enter a value between %d and %d.\n", MIN_EQUATION_NUMBER, MAX_EQUATION_NUMBER);
        }
    } while (*equationNumber < MIN_EQUATION_NUMBER || *equationNumber > MAX_EQUATION_NUMBER);
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