# Julio's Store - Receipt Generator

## Overview

This C++ program simulates a basic receipt-printing system for a small retail store named **Julio's Store**. It reads item information from a file (`Items.txt`), calculates totals and tax, prompts the user for payment, and writes a formatted receipt to `Receipt.txt`.

## Key Features

- **Reads item data** (name, price, category) for three products from an input file.
- **Calculates subtotal, tax (9%), and total amount due**.
- **Prompts user for amount tendered** and computes **change due**.
- **Generates a formatted receipt** as a text file (`Receipt.txt`) including:
    - Items purchased with prices and categories
    - Subtotal, tax, total, amount paid, and change due
    - A closing thank-you message

## File Structure

- **Input File**: `Items.txt`
    - Each item has:
        - A line for the **item name**
        - A line for the **item price**
        - A line for the **item category** (`F`, `N`, or `X`)

- **Output File**: `Receipt.txt`
    - Contains a formatted receipt including all calculated and printed details.

## Constants Used

- `kLineLength = 512` — Used to manage buffer limits for reading lines.
- `kTaxRate = 0.09` — Sales tax applied to subtotal (9%).
- `kStandardPrecision = 2` — Decimal precision for monetary values.
- `kSetWidthLeft = 37` / `kSetWidthRight = 5` — Width settings for receipt formatting.

## Program Flow

1. **Open and Read Items**  
   Reads the names, prices, and categories of three items from `Items.txt`.

2. **Calculate Totals**
    - Subtotal = sum of item prices
    - Tax = `subtotal * 9%`
    - Total Due = `subtotal + tax`

3. **Prompt for Payment**  
   Asks the user to input the amount tendered and calculates change due.

4. **Generate Receipt**  
   Writes all item details, tax, totals, payment, and change into `Receipt.txt` with proper formatting.

## Example Receipt Output (from `Receipt.txt`)

```plaintext
Julio's Store

Apple                                $1.50 - F
Notebook                             $2.00 - N
Charger                              $1.95 - X
Subtotal                             $5.45
Tax @ 9%                             $0.49
Total                                $5.94
Debit Tendered                       $10.00
Change Due                           $4.06
Number of items sold: 3
Thank you for shopping @ Julio's Store!
