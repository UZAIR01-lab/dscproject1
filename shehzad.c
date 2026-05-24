void deleteItem() {
    int id; printf("Enter ID to delete: "); scanf("%d", &id);
    int i = findById(id);
    if (i == -1) { puts("Item not found."); return; }
    inventory[i] = inventory[--itemCount];   /* swap with last */
    puts("Item deleted.");
}