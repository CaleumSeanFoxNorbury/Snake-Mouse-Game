#include "GridItem.h"

GridItem::GridItem(char symbol): symbol_(symbol)
{
}

GridItem::~GridItem()
{
}

char GridItem::get_symbol() const
{
	return symbol_;
}
