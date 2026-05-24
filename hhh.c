#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LEN  50

typedef struct {
    int    id;
    char   name[NAME_LEN];
    int    quantity;
    float  price;
} Item;

Item inventory[MAX_ITEMS];
int  itemCount = 0;

/* ── helpers ── */
int findById(int id) {
    for (int i = 0; i < itemCount; i++)
        if (inventory[i].id == id) return i;
    return -1;
}

/* ── CRUD ── */
void addItem() {
    if (itemCount >= MAX_ITEMS) { puts("Inventory full!"); return; }
    Item it;
    printf("ID: ");       scanf("%d",  &it.id);
    if (findById(it.id) != -1) { puts("ID already exists."); return; }
    printf("Name: ");     scanf("%49s", it.name);
    printf("Quantity: "); scanf("%d",  &it.quantity);
    printf("Price: ");    scanf("%f",  &it.price);
    inventory[itemCount++] = it;
    puts("Item added.");
}

void displayAll() {
    if (!itemCount) { puts("No items in inventory."); return; }
    printf("\n%-6s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    puts("--------------------------------------------------");
    for (int i = 0; i < itemCount; i++)
        printf("%-6d %-20s %-10d $%-9.2f\n",
               inventory[i].id, inventory[i].name,
               inventory[i].quantity, inventory[i].price);
}

void searchItem() {
    int id; printf("Enter ID to search: "); scanf("%d", &id);
    int i = findById(id);
    if (i == -1) { puts("Item not found."); return; }
    printf("ID: %d | Name: %s | Qty: %d | Price: $%.2f\n",
           inventory[i].id, inventory[i].name,
           inventory[i].quantity, inventory[i].price);
}
