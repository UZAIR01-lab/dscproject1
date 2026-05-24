void updateItem() {
    int id; printf("Enter ID to update: "); scanf("%d", &id);
    int i = findById(id);
    if (i == -1) { puts("Item not found."); return; }
    printf("New Name (current: %s): ",     inventory[i].name);
    scanf("%49s", inventory[i].name);
    printf("New Quantity (current: %d): ", inventory[i].quantity);
    scanf("%d", &inventory[i].quantity);
    printf("New Price (current: %.2f): ",  inventory[i].price);
    scanf("%f", &inventory[i].price);
    puts("Item updated.");
}