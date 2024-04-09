#ifndef LAB1_H
#define LAB1_H

void discardIntegerPart(float* number);
void discardIntegerPart(float& number);
void invertFloat(float* number);
void invertFloat(float& number);
void moveSquare(float* square, float vector);
void moveSquare(float& square, float vector);
void swapRows(int* matrix, int size, int row1, int row2);
void swapRows(int (&matrix)[3][3], int row1, int row2);

#endif // LAB1_H
