# Inventory Management System

A simple command-line **Inventory Management System** written in C. It supports full CRUD operations on items stored in an in-memory array, along with a low-stock alert feature.

---

## Features

- Add new inventory items
- Display all items in a formatted table
- Search for an item by ID
- Update an existing item's details
- Delete an item
- Low-stock alert based on a configurable quantity threshold

---

## Project Structure

```
inventory.c    # Single-file implementation
```

---

## Data Model

Each item holds the following fields:

| Field      | Type    | Description              |
|------------|---------|--------------------------|
| `id`       | `int`   | Unique item identifier   |
| `name`     | `char[]`| Item name (max 49 chars) |
| `quantity` | `int`   | Stock quantity           |
| `price`    | `float` | Unit price               |

Maximum inventory capacity: **100 items** (defined by `MAX_ITEMS`).

---

## Getting Started

### Prerequisites

- GCC or any C99-compatible compiler

### Build

```bash
gcc -o inventory inventory.c
```

### Run

```bash
./inventory
```

---

## Usage

On launch, the program presents an interactive menu:

```
=== Inventory Management ===
1. Add Item
2. Display All
3. Search Item
4. Update Item
5. Delete Item
6. Low Stock Alert
0. Exit
Choice:
```

### Menu Options

#### 1. Add Item
Prompts for ID, name, quantity, and price. Duplicate IDs are rejected.

#### 2. Display All
Prints all items in a tabular format:
```
ID     Name                 Quantity   Price
--------------------------------------------------
101    Widget A             50         $4.99
102    Widget B             5          $12.50
```

#### 3. Search Item
Looks up a single item by its ID and prints its details.

#### 4. Update Item
Finds an item by ID and prompts for new name, quantity, and price.

#### 5. Delete Item
Removes an item by ID. The last item in the array is swapped into the deleted slot to keep the array compact.

#### 6. Low Stock Alert
Prompts for a threshold and lists all items whose quantity is at or below that value.

---

## Limitations

- Data is **not persisted** — all items are lost when the program exits.
- The inventory is capped at **100 items**.
- Item names cannot contain spaces (read via `scanf("%49s", ...)`).
- No input validation beyond duplicate ID checking.

---

## Potential Improvements

- File-based persistence (CSV or binary)
- Space-tolerant name input using `fgets`
- Dynamic memory allocation to remove the fixed-size cap
- Sorting and pagination for `Display All`
- Input sanitization and error recovery for invalid entries

---

## License

This project is released for educational purposes. Feel free to use and modify it.
