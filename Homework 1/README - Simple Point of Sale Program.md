# Simple Point-of-Sale Program

## Overview

This C++ program simulates a basic point-of-sale (POS) terminal. It prompts the user to enter details for three purchased items, calculates the subtotal, applies a fixed tax rate, computes the total amount due, accepts payment input, and calculates the change to be returned.

## Key Features

- Accepts **description, price, and category** for each of three items.
- Applies a **fixed sales tax rate of 8.25%**.
- Displays **subtotal, tax amount, total due**, and **change due**.
- Uses `getline` and `cin` for mixed input (strings and numeric values).
- Applies basic **input validation** via `cin.ignore()` and **output formatting** using `iomanip`.

## Program Flow

1. **Prompt for Item Details**  
   The user is asked to input the name, price, and category (`F`, `N`, or `X`) for each of three items. The program uses `cin.ignore()` to handle newline characters properly between inputs.

2. **Calculate Subtotal**  
   The prices of all three items are added to get the subtotal.

3. **Calculate Tax and Total Due**  
   A fixed tax rate (8.25%) is applied to the subtotal to compute the total amount due.

4. **Accept Payment and Calculate Change**  
   The user enters the amount tendered. The program then calculates and displays the change due to the customer.

## Constants Used

- `kLineLength = 512` — Used to limit how much the input stream ignores after reading character data.
- `kTaxRate = 0.0825` — Fixed tax rate applied to the subtotal.

## Example Output

```plaintext
Please enter your first item's description ==> Apple
Please enter Apple's price ==> $1.50
Please enter category (F, N, or X) for Apple ==> F

Please enter your second item's description ==> Notebook
Please enter Notebook's price ==> $2.00
Please enter category (F, N, or X) for Notebook ==> N

Please enter your last item's description ==> Charger
Please enter Charger's price ==> $1.95
Please enter category (F, N, or X) for Charger ==> X

Your Subtotal is ==> $5.45
The current Tax Rate is 8.25%
Your Total amount due is ==> $5.90
Please enter amount tendered ==> $10.00
Your change is ==> $4.10
