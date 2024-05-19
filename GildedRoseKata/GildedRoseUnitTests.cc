#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTestExt/MockSupport.h>

extern "C" {
#include "GildedRose.h"
}

static int USE_NEW_FUNCTION = 1;

void update_func(Item items[], int size)
{
    if (USE_NEW_FUNCTION)
    {
        update_items(items, size);
    }
    else
    {
        update_quality(items, size);
    }
}

TEST_GROUP(TestGildedRoseGroup)
{

  void setup() {
  }
  void teardown() {
  }


};

TEST(TestGildedRoseGroup, TestSingleFooItem)
{
    Item items[1];
    init_item(items, "Foo", 0, 0);
    update_func(items, 1);
    STRCMP_EQUAL("Foo", items[0].name);
    LONGS_EQUAL(-1, items[0].sellIn);
    LONGS_EQUAL(0, items[0].quality);
}

TEST(TestGildedRoseGroup, TestMultipleItemsOverThreeDays)
{
    Item items[6];
    int last = 0;

    init_item(items + last++, "+5 Dexterity Vest", 10, 20);
    init_item(items + last++, "Aged Brie", 2, 0);
    init_item(items + last++, "Elixir of the Mongoose", 5, 7);
    init_item(items + last++, "Sulfuras, Hand of Ragnaros", 0, 80);
    init_item(items + last++, "Backstage passes to a TAFKAL80ETC concert", 15, 20);
    init_item(items + last++, "Conjured Mana Cake", 3, 6);

    // Check names
    STRCMP_EQUAL("+5 Dexterity Vest", items[0].name);
    STRCMP_EQUAL("Aged Brie", items[1].name);
    STRCMP_EQUAL("Elixir of the Mongoose", items[2].name);
    STRCMP_EQUAL("Sulfuras, Hand of Ragnaros", items[3].name);
    STRCMP_EQUAL("Backstage passes to a TAFKAL80ETC concert", items[4].name);
    STRCMP_EQUAL("Conjured Mana Cake", items[5].name);

    // Day 1
    update_func(items, last);
    LONGS_EQUAL(9, items[0].sellIn);
    LONGS_EQUAL(19, items[0].quality);
    LONGS_EQUAL(1, items[1].sellIn);
    LONGS_EQUAL(1, items[1].quality);
    LONGS_EQUAL(4, items[2].sellIn);
    LONGS_EQUAL(6, items[2].quality);
    LONGS_EQUAL(0, items[3].sellIn);
    LONGS_EQUAL(80, items[3].quality);
    LONGS_EQUAL(14, items[4].sellIn);
    LONGS_EQUAL(21, items[4].quality);
    LONGS_EQUAL(2, items[5].sellIn);
    LONGS_EQUAL(4, items[5].quality);

    // Day 2
    update_func(items, last);
    LONGS_EQUAL(8, items[0].sellIn);
    LONGS_EQUAL(18, items[0].quality);
    LONGS_EQUAL(0, items[1].sellIn);
    LONGS_EQUAL(2, items[1].quality);
    LONGS_EQUAL(3, items[2].sellIn);
    LONGS_EQUAL(5, items[2].quality);
    LONGS_EQUAL(0, items[3].sellIn);
    LONGS_EQUAL(80, items[3].quality);
    LONGS_EQUAL(13, items[4].sellIn);
    LONGS_EQUAL(22, items[4].quality);
    LONGS_EQUAL(1, items[5].sellIn);
    LONGS_EQUAL(2, items[5].quality);

    // Day 3
    update_func(items, last);
    LONGS_EQUAL(7, items[0].sellIn);
    LONGS_EQUAL(17, items[0].quality);
    LONGS_EQUAL(-1, items[1].sellIn);
    LONGS_EQUAL(4, items[1].quality);
    LONGS_EQUAL(2, items[2].sellIn);
    LONGS_EQUAL(4, items[2].quality);
    LONGS_EQUAL(0, items[3].sellIn);
    LONGS_EQUAL(80, items[3].quality);
    LONGS_EQUAL(12, items[4].sellIn);
    LONGS_EQUAL(23, items[4].quality);
    LONGS_EQUAL(0, items[5].sellIn);
    LONGS_EQUAL(0, items[5].quality);
}

TEST(TestGildedRoseGroup, TestSingleBackstagePasses)
{
    Item items[1];
    init_item(items, "Backstage passes to a TAFKAL80ETC concert", 15, 20);
    STRCMP_EQUAL("Backstage passes to a TAFKAL80ETC concert", items[0].name);

    LONGS_EQUAL(15, items[0].sellIn);
    LONGS_EQUAL(20, items[0].quality);
    for (int day = 0; day < 4; day++)
    {
        update_func(items, 1);
    }
    LONGS_EQUAL(11, items[0].sellIn);
    LONGS_EQUAL(24, items[0].quality);
    update_func(items, 1);
    LONGS_EQUAL(10, items[0].sellIn);
    LONGS_EQUAL(25, items[0].quality);
    update_func(items, 1);
    LONGS_EQUAL(9, items[0].sellIn);
    LONGS_EQUAL(27, items[0].quality);
    for (int day = 0; day < 3; day++)
    {
        update_func(items, 1);
    }
    LONGS_EQUAL(6, items[0].sellIn);
    LONGS_EQUAL(33, items[0].quality);
    update_func(items, 1);
    LONGS_EQUAL(5, items[0].sellIn);
    LONGS_EQUAL(35, items[0].quality);
    update_func(items, 1);
    LONGS_EQUAL(4, items[0].sellIn);
    LONGS_EQUAL(38, items[0].quality);
    for (int day = 0; day < 4; day++)
    {
        update_func(items, 1);
    }
    LONGS_EQUAL(0, items[0].sellIn);
    LONGS_EQUAL(50, items[0].quality);
    update_func(items, 1);
    LONGS_EQUAL(-1, items[0].sellIn);
    LONGS_EQUAL(0, items[0].quality);
}

TEST(TestGildedRoseGroup, TestSingleAgedBrie)
{
    Item items[1];
    init_item(items, "Aged Brie", 3, 48);
    STRCMP_EQUAL("Aged Brie", items[0].name);
    for (int day = 0; day < 3; day++)
    {
        update_func(items, 1);
    }
    LONGS_EQUAL(0, items[0].sellIn);
    LONGS_EQUAL(50, items[0].quality);
}

TEST(TestGildedRoseGroup, TestSingleConjuredManaCake)
{
    Item items[1];
    init_item(items, "Conjured Mana Cake", 2, 10);
    STRCMP_EQUAL("Conjured Mana Cake", items[0].name);
    update_func(items, 1);
    LONGS_EQUAL(1, items[0].sellIn);
    LONGS_EQUAL(8, items[0].quality);
    update_func(items, 1);
    update_func(items, 1);
    LONGS_EQUAL(-1, items[0].sellIn);
    LONGS_EQUAL(2, items[0].quality);
}

void example()
{
    Item items[6];
    int last = 0;
    
    init_item(items + last++, "+5 Dexterity Vest", 10, 20);
    init_item(items + last++, "Aged Brie", 2, 0);
    init_item(items + last++, "Elixir of the Mongoose", 5, 7);
    init_item(items + last++, "Sulfuras, Hand of Ragnaros", 0, 80);
    init_item(items + last++, "Backstage passes to a TAFKAL80ETC concert", 15, 20);
    init_item(items + last++, "Conjured Mana Cake", 3, 6);
    update_func(items, last);
}

int
main(int ac, char** av)
{
  return CommandLineTestRunner::RunAllTests(ac, av);
}
