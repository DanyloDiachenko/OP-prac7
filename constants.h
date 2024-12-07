#ifndef CONSTANTS_H
#define CONSTANTS_H

#define MIN_RANGE_LIMIT -1000
#define MAX_RANGE_LIMIT 1000

#define MIN_EPSILON 1e-12
#define MAX_EPSILON 1e-1

enum SolveEquationMethod {
    HALF_DIVIDING = 1,
    NEWTON = 2,
};
enum EquationType {
    TRIGONOMETRIC_FRACTIONS = 1,
    TRIGONOMETRIC_LOGARITHM = 2,
};

#endif // CONSTANTS_H
