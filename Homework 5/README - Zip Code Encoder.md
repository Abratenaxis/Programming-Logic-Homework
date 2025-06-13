# Zip Code Encoder

## Overview

This project provides a utility for encoding 5-digit zip codes into POSTNET barcode representations. It consists of functions to:

- Accept and validate user-input zip codes
- Calculate a checksum digit to ensure barcode integrity
- Generate a barcode string using POSTNET-style encoding for each digit
- Output the resulting barcode with framing bars

The encoding follows the POSTNET barcode system used by the USPS, where each digit (0-9) is represented by a series of five bars.

---

## File Structure

### 1. `ZipCodeUtil.h`

Contains function declarations and constants for zip code handling and barcode generation. Defines the `zipcode_encoder_util` namespace.

### 2. `ZipCodeUtil.cpp`

Contains implementations of utility functions including:

- `getUserPrompt()` – prompts user and reads zip code input
- `isValidSize()` – checks if zip code is 5 digits long
- `GenerateZipCodeChecksum()` – computes checksum digit
- `generateBarcode()` – encodes each digit of zip code + checksum into barcode
- `GetEncoding()` – converts a single digit to POSTNET encoding string
- `OutputToUser()` – prints the encoded barcode

### 3. `main.cpp`

Provides a basic command-line interface to drive the encoding process. Prompts the user, validates input, and performs checksum generation (barcode generation pending).

---

## Program Flow

1. **User Prompt**

    - The user is asked to enter a 5-digit zip code.
    - `getUserPrompt("enter zipcode > ")` reads and stores this value.

2. **Validation**

    - `isValidSize()` checks if the number is between 10000 and 99999.

3. **Checksum Calculation**

    - `GenerateZipCodeChecksum()` calculates a checksum such that the sum of all digits (including the checksum) is divisible by 10.

4. **Barcode Generation** *(in development)*

    - Once the zip code and checksum are available, the barcode will be constructed using `generateBarcode()` and displayed with `OutputToUser()`.

---

## Example Usage

```
> enter zipcode > 12345
> [internally] zip code is validated, checksum is calculated
> barcode: |::|::|:|::||::|:|::||::|:
```

Each digit in `12345` and the checksum digit are individually encoded into POSTNET format.

---

## Future Enhancements

- **Complete Barcode Output**:

    - Add calls to `generateBarcode()` and `OutputToUser()` in `main.cpp`.

- **Decode Functionality**:

    - Implement `barCodeToZipCode()` to allow decoding barcodes back into zip codes.

- **Checksum Verification**:

    - Check if a given barcode's checksum is valid before decoding.

- **Input Error Handling**:

    - Add checks for non-integer and malformed inputs.

- **Unit Tests**:

    - Create test cases for all utility functions to ensure correctness.

- **CLI Parameters**:

    - Allow zip codes to be passed in as command-line arguments for scripting.

---

## License

MIT License – Feel free to use, modify, and share this code.

---

## Author

Developed by [Your Name Here]

