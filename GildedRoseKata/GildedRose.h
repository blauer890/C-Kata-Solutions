#ifndef ROSE_INCLUDED
#define ROSE_INCLUDED

typedef struct
{
    char *name;
    int sellIn;
    int quality;
} Item;

Item* init_item(Item* item, const char *name, int sellIn, int quality);
void update_items(Item items[], int size);
void update_quality(Item items[], int size);
#endif
