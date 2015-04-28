#include "TableSortedList.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;
#include "Text.h"
using CSC2110::String;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   delete iter;
}

int main()
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int num_items = cds->size();
   cout << num_items << endl;

   TableSortedList<CD>* slt = new TableSortedList<CD>(&CD::compare_items, &CD::compare_keys);

   //DO THIS
   //thoroughly test your table

   ListArrayIterator<CD>* iter = cds->iterator();
   
   
	if(slt->tableIsEmpty())
	{
		int count = 0;
		while(iter->hasNext() && count != 10)
		{
		CD* cd = iter->next();
		slt->tableInsert(cd);
		count++;
		}
	}

	ListDoublyLinkedIterator<CD>* iter2 = slt->iterator();
	
	/*while(iter2->hasNext())
	{
		CD* myCD = iter2->next();
		myCD->getKey()->displayString();
		cout << endl;
		
	}*/

	String* title = new String("Manifesto");
	
	
	bool rem = slt->tableRemove(title);
	if (rem)
		cout << "Removed item" << endl;
	
	while(iter2->hasNext())
	{
		CD* myCD = iter2->next();
		myCD->getKey()->displayString();
		cout << endl;
	}
	
	cout << slt->tableSize() << endl;
	
	delete title;
   deleteCDs(cds);
   delete cds;
   delete slt;
   return 0;
}
