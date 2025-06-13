
# Credit Card Validation Utility

## Overview

This C++ project provides a utility for **credit card number validation** using the [Luhn algorithm](https://en.wikipedia.org/wiki/Luhn_algorithm). It includes logic to:
- **Validate card number structure and length**
- **Identify card issuer (Visa, MasterCard, Discover, American Express)**
- **Calculate Luhn checksum using even/odd position logic**

The program is modularized across **three files** and encapsulated in a custom **namespace** for clarity and reusability.

---

## File Structure

### `CreditCardUtil.h`
Header file containing:
- Constant definitions for card prefixes, validation thresholds, and formatting
- Function declarations for credit card utilities

### `CreditCardUtil.cpp`
Implementation file for the functions declared in the header. Contains:
- Input handling
- Size and prefix extraction
- Card type determination
- Luhn checksum components (sum of even/odd positions)

### `main.cpp`
Test driver to run the utility logic. Can be modified to validate user input or test specific card numbers.

---

## Program Flow

1. **Prompt user (optional)** for a credit card number
   ```cpp
   long long cc = GetCreditCardNumber("Enter a credit card number > ");
   ```

2. **Validate card length** and prefix using:
   ```cpp
   int size = GetSize(cc);
   string type = GetCardType(cc);
   ```

3. **Apply Luhn Algorithm**:
    - Double every second digit from the right and sum:
      ```cpp
      int evenSum = SumOfDoubleEvenPlace(cc);
      ```
    - Sum all digits in the odd places from the right:
      ```cpp
      int oddSum = SumOfOddPlace(cc);
      ```
    - Total the two:
      ```cpp
      int total = evenSum + oddSum;
      bool isValid = (total % 10 == 0);
      ```

4. **Display results** including validity and card type.

---

## Example Usage

### Sample Test in `main.cpp`

```cpp
int cardSumEven = SumOfDoubleEvenPlace(4388576018402626);
cout << "Even Sum: " << cardSumEven << endl;

int cardSumOdd = SumOfOddPlace(4388576018402626);
cout << "Odd Sum: " << cardSumOdd << endl;

int total = cardSumEven + cardSumOdd;
cout << "Total: " << total << endl;

if (total % 10 == 0) {
    cout << "Credit card number is valid!" << endl;
} else {
    cout << "Credit card number is invalid!" << endl;
}
```

### Output
```
Even Sum: 37
Odd Sum: 38
Total: 75
Credit card number is invalid!
```

---

## Constants Reference

| Constant Name               | Value         | Purpose                                  |
|----------------------------|---------------|------------------------------------------|
| `kVisaPrefix`              | `4`           | Visa cards start with 4                  |
| `kMasterCardPrefix`        | `5`           | MasterCards start with 5                 |
| `kAmericanExpPrefix`       | `37`          | AmEx cards start with 37                 |
| `kDiscoverCardPrefix`      | `6`           | Discover cards start with 6              |
| `kMinCreditCardSize`       | `13 digits`   | Minimum allowed digits in a card number  |
| `kMaxCreditCardSize`       | `16 digits`   | Maximum allowed digits in a card number  |
| `kDecimalDividend`         | `10`          | Used to extract digits via division      |

---

## How It Works

This utility implements the **Luhn algorithm**:

> - Starting from the **rightmost digit**, double every **second digit**.
> - If doubling a digit results in a **two-digit number**, add the digits of the product (e.g., `18 → 1 + 8 = 9`).
> - Add all these doubled digits (**even positions**) and all other digits (**odd positions**).
> - If the **total modulo 10** is `0`, the number is **valid**.

---

## Future Enhancements

- ✅ Full `IsValid()` method integration (commented in header but not implemented).
- ⌨️ Add a loop to accept multiple card numbers from user input.
- 🧾 Store card validation results in a file (e.g., `results.txt`).
- 🧪 Add unit tests for each utility method.
- 🌍 Add locale-aware formatting and currency detection.
- 🧰 Convert into a reusable class or object-oriented design.
- 📦 Package as a C++ static/shared library for integration in other systems.

---

## License

Provided for educational and demonstration purposes. No commercial use without permission.

---
