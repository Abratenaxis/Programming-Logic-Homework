# Julio's Store - Advanced Receipt Generator

## Overview

This C++ program simulates a dynamic point-of-sale receipt generation system for **Julio's Store**. It processes a list of items from an input file (`ItemList.txt`), applies **category-specific tax rates**, and generates a formatted receipt in `Receipt.txt`. The program also includes **input validation** to ensure correct customer payment.

## Key Features

- **Reads a variable number of items** from an input file.
- Applies **category-specific tax rates**:
    - `N` (Normal): 8.25%
    - `X` (Special): 12.5%
    - `F` (Food): 0%
- Calculates **itemized subtotals**, **taxes per category**, and the **grand total**.
- **Prompts for payment** and validates the amount tendered.
- **Outputs a formatted receipt** to a text file with:
    - Item list
    - Subtotals and taxes
    - Total, payment, change
    - Item count and thank-you message

## File Structure

- **Input File**: `ItemList.txt`
    - Format (repeats per item):
      ```
      <Item Name>
      <Item Price>
      <Item Category>
      ```
      Example:
      ```
      Apple
      1.50
      F
      Charger
      19.99
      X
      Notebook
      5.00
      N
      ```

- **Output File**: `Receipt.txt`
    - Sample output:
      ```
      Julio's Store
  
      Apple                                $1.50 - F
      Charger                             $19.99 - X
      Notebook                             $5.00 - N
      Subtotal                            $26.49
      N Tax @ 8.25%                        $0.41
      X Tax @ 12.50%                       $2.50
      F Tax @ 0.00%                        $0.00
      Total                               $29.40
      Debit Tendered                      $30.00
      Change Due                           $0.60
      Number of items sold: 3
      Thank you for shopping @ Julio's Store!
      ```

## Constants Used

| Constant            | Value     | Purpose                             |
|---------------------|-----------|-------------------------------------|
| `kNTaxRate`         | `0.0825`  | Normal items tax (8.25%)            |
| `kXTaxRate`         | `0.125`   | Special items tax (12.5%)           |
| `kFTaxRate`         | `0.0`     | Food items tax (0%)                 |
| `kStandardPrecision`| `2`       | Display monetary values to 2 decimals |
| `kSetWidthLeft`     | `37`      | Formatting for left-justified text  |
| `kSetWidthRight`    | `5`       | Formatting for right-justified text |
| `kLineLength`       | `512`     | Input buffer line length            |

## Program Flow

1. **Read Input File**  
   Continuously reads items (name, price, category) until EOF from `ItemList.txt`.

2. **Track Subtotals**  
   Adds prices to category-specific subtotals (`N`, `X`, `F`).

3. **Calculate Totals and Taxes**
    - Subtotal = sum of all items
    - Tax = individual subtotals * their respective tax rate
    - Total Due = subtotal + all taxes

4. **Prompt and Validate Payment**
    - Ensures amount tendered is numeric and ≥ total due.
    - Displays an error message and re-prompts if invalid.

5. **Generate Receipt**  
   Prints all item data, taxes, total, and change into `Receipt.txt`.

## Input Validation

- Checks that the **amount tendered** is not less than the total due.
- Handles invalid (non-numeric) input using `cin.fail()` and `cin.clear()`.

## Possible Enhancements

- Allow tax rates to be set via configuration.
- Implement discount codes or loyalty pricing.
- Improve formatting with currency symbols or locale support.
- Add more robust file error handling (e.g. file not found, bad format).
- Replace parallel variables with a data structure like a class or struct for each item.

---

**License:** Provided for educational use and personal practice.
