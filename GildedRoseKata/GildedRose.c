#include <string.h>
#include "GildedRose.h"
#include <stdio.h>

Item*
init_item(Item* item, const char *name, int sellIn, int quality)
{
    item->sellIn = sellIn;
    item->quality = quality;
    item->name = strdup(name);
    
    return item;
}

static void
subtract_quality(Item* item, int quality)
{
    if ((item->quality - quality) > 0)
    {
        item->quality -= quality;
    }
    else
    {
        item->quality = 0;
    }
}

static void
add_quality(Item* item, int quality)
{
    if ((item->quality + quality) < 50)
    {
        item->quality += quality;
    }
    else
    {
        item->quality = 50;
    }
}

static void
update_quality_single(Item* item)
{
    if (!strcmp(item->name, "Aged Brie")) // is Aged Brie
    {
        add_quality(item, 1);
        if (item->sellIn < 0)
        {
            add_quality(item, 1);
        }
    }
    else if (!strcmp(item->name, "Backstage passes to a TAFKAL80ETC concert")) // is backstage pass
    {
        if (item->sellIn < 0)
        {
            item->quality = 0;
        }
        else
        {
            add_quality(item, 1);

            if (item->sellIn < 11)
            {
                add_quality(item, 1);
            }

            if (item->sellIn < 5)
            {
                add_quality(item, 1);
            }
        }
    }
    else if (!strcmp(item->name, "Conjured Mana Cake"))
    {
        if (item->sellIn < 0)
        {
            subtract_quality(item, 4);
        }
        else
        {
            subtract_quality(item, 2);
        }
    }
    else if (strcmp(item->name, "Sulfuras, Hand of Ragnaros")) // not Sulfuras
    {
        if (item->sellIn < 0)
        {
            subtract_quality(item, 2);
        }
        else
        {
            subtract_quality(item, 1);
        }
    }
}

static void
update_sellin_single(Item* item)
{
    if (strcmp(item->name, "Sulfuras, Hand of Ragnaros"))
    {
        item->sellIn -= 1;
    }
}

void
update_items(Item items[], int size)
{
    for (int i = 0; i < size; i++)
    {
        update_sellin_single(&items[i]);
        update_quality_single(&items[i]);
    }
}


void 
update_quality(Item items[], int size) 
{
    int i;
    
    for (i = 0; i < size; i++)
    {
        if (strcmp(items[i].name, "Aged Brie") && strcmp(items[i].name, "Backstage passes to a TAFKAL80ETC concert"))
        {
            if (items[i].quality > 0)
            {
                if (strcmp(items[i].name, "Sulfuras, Hand of Ragnaros"))
                {
                    items[i].quality = items[i].quality - 1;
                }
            }
            if (items[i].quality > 0)
            {
                if (!strcmp(items[i].name, "Conjured Mana Cake"))
                {
                    items[i].quality = items[i].quality - 1;
                }
            }
        }
        else
        {
            if (items[i].quality < 50)
            {
                items[i].quality = items[i].quality + 1;

                if (!strcmp(items[i].name, "Backstage passes to a TAFKAL80ETC concert"))
                {
                    if (items[i].sellIn < 11)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }

                    if (items[i].sellIn < 6)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }
                }
            }
        }

        if (strcmp(items[i].name, "Sulfuras, Hand of Ragnaros"))
        {
            items[i].sellIn = items[i].sellIn - 1;
        }

        if (items[i].sellIn < 0)
        {
            if (strcmp(items[i].name, "Aged Brie"))
            {
                if (strcmp(items[i].name, "Backstage passes to a TAFKAL80ETC concert"))
                {
                    if (items[i].quality > 0)
                    {
                        if (strcmp(items[i].name, "Sulfuras, Hand of Ragnaros"))
                        {
                            items[i].quality = items[i].quality - 1;
                        }
                    }
                    if (items[i].quality > 0)
                    {
                        if (!strcmp(items[i].name, "Conjured Mana Cake"))
                        {
                            items[i].quality = items[i].quality - 1;
                        }
                    }
                }
                else
                {
                    items[i].quality = items[i].quality - items[i].quality;
                }
            }
            else
            {
                if (items[i].quality < 50)
                {
                    items[i].quality = items[i].quality + 1;
                }
            }
        }
    }
}

