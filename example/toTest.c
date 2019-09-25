#define ASCII_DIGIT_OFFSET 48
#define ASCII_LETTER_OFFSET 55
#define SMALLEST_BASE 2
#define MAX_ALPHA_NUMERIC_SYMBOLS 36

int radixIsInvalid(int radix);
int valueIsInvalid(int value, int radix);

// Converts an int into the corresponding character in the
// specified base.
char int2char (int radix, int value) {
  if (radixIsInvalid(radix) || valueIsInvalid(value, radix)) {
    return '?';
  }

  int offset = value < 10 ? ASCII_DIGIT_OFFSET : ASCII_LETTER_OFFSET;
  return (char) (value + offset);
}

int radixIsInvalid(int radix) {
  return radix < SMALLEST_BASE || radix > MAX_ALPHA_NUMERIC_SYMBOLS;
}

int valueIsInvalid(int value, int radix) {
  return value < 0 || value > radix - 1;
}
