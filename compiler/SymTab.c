#ifndef __LIBS__
#define __LIBS__
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#endif

#include "SymTab.h"

#define DEBUG false


/* 	CreateSymTab:    create and return a reference to a symbol table of 
         approximately Size many entries.
*/
struct SymTab* CreateSymTab(int size)
{
	//create SymTab pointer
	struct SymTab *symbolTable;
	//malloc mem for it
	symbolTable = malloc(sizeof(struct SymTab));
	if(NULL == symbolTable) exit(1);
	//set size 
	symbolTable->Size = size;

        //malloc for 2d array of SymEntrys
        symbolTable->Contents = (struct SymEntry**) malloc(size * sizeof(struct SymEntry*));
        if(symbolTable->Contents == NULL) { exit(1); }

        int i;
        //make every pointer null
        for(i = 0; i < size; i++)
        {
                symbolTable->Contents[i] = NULL;
        }

	return symbolTable;
}


/*
   	DestroySymTab:  destroy all storage associated with a Symbol Table which 
         is under the table's control. This does not include the attributes
*/
void DestroySymTab(struct SymTab *ATable)
{
	int size = ATable->Size;
	struct SymEntry* entry;
	struct SymEntry* nextEntry;

	int i;
	//loop over every content in SymTab
	for(i = 0; i < size; i++)
	{
		//set entry equal to first SymEntry in each Content
		entry = ATable->Contents[i];
		//while there are more entries in this content
		while(NULL != entry)
		{
			//set the next entry, free the current one, iterate
			nextEntry = entry->Next;
			if(NULL != entry->Name)
                        {
                                free(entry->Name);
                                entry->Name = NULL;
                        }
                        
			free(entry);
                        entry = NULL;

			entry = nextEntry;
		}
	}
        
        free(ATable->Contents);
        ATable->Contents = NULL;
        free(ATable);
        ATable = NULL;
}

//Hash the string to a value (primitive)
int hashString(const char* name, int size)
{
        int length = strlen(name);

        int i;
        int sum = 0;
        for(i = 0; i < length; i++)
        {
                sum += name[i];
        }

        return (sum % size);
}


/* 	EnterName:      enter a Name into a symbol table. Passes back an argument
                   		 containing an entry reference for the name. Return true if the 
				  name was not already in the symbol table, otherwise return
 				 false. EnterName must allocate space for the Name and copy
				  the contents the parameter Name.
*/
bool EnterName(struct SymTab *ATable, const char *Name, struct SymEntry* *AnEntry)
{
	int size = ATable->Size;

        //hash the Name to decide where to put the token
        int hash = hashString(Name, size);
        if(DEBUG) printf("strhash: %d\n", hash);

        //get the head node in the list
        struct SymEntry* next = ATable->Contents[hash];
        struct SymEntry* prev = next;

        //iterate over list
        while(next != NULL)
        {
                //if it already exists in list
                if(DEBUG) //printf("strhash: %d", hash)
                {
                        printf("hash: %d\n", hash);
                }
                if(0 == strcmp(next->Name, Name))
                {
                        //name is already in table, return false
                        *AnEntry = next;
                        return false;
                }
                prev = next;
                next = next->Next;
        }


        //create new node since not in list
        (*AnEntry) = (struct SymEntry*) malloc(sizeof(struct SymEntry));
        

        (*AnEntry)->Name = strdup(Name);
        if((*AnEntry)->Name == NULL) { exit(1); }

        (*AnEntry)->Attributes = NULL;
        (*AnEntry)->Next = NULL;

        //if the list is empty, then the head should be set to next
        if(NULL == ATable->Contents[hash])
        {
                ATable->Contents[hash] = (*AnEntry);
        }
        //else the previous node's next should be set to the new next node
        else
        {
                prev->Next = (*AnEntry);
        }

        //node was not in table, was added, return true
        return true;
}


/*   	FindName:        find a Name in a symbol table. Return an entry reference 
                   		  or NULL depending on whether the Name was found.
*/
struct SymEntry* FindName(struct SymTab *ATable, const char *Name)
{
	int size = ATable->Size;

        //node used to iterate over lists
        struct SymEntry* node;

        //loop over every (if necessary) content, its lists, check for match
	int i = 0;
        //for every content
	for(i = 0; i < size; i++)
	{
                node = ATable->Contents[i];
                //for every symentry in this list
                while(NULL != node)
                {
                        if(0 == strcmp(node->Name, Name))
                        {
                                return node;
                        }
                        
                        node = node->Next;
                }
        }

        return node;
}

//set a symEntry's attribute
void SetAttr(struct SymEntry *AnEntry, void *Attributes)
{
        AnEntry->Attributes = Attributes;
}

//get a symentry's attribute
void* GetAttr(struct SymEntry *AnEntry)
{
        return AnEntry->Attributes;
}

//get name
const char* GetName(struct SymEntry *AnEntry)
{
        return AnEntry->Name;
}

//get first entry in table
struct SymEntry* FirstEntry(struct SymTab *ATable)
{
        int i;
        for(i = 0; i < ATable->Size; i++)
        {
                if(NULL != ATable->Contents[i]) return ATable->Contents[i];
        }
        return NULL;
}

//get next entry
struct SymEntry* NextEntry(struct SymTab *ATable, struct SymEntry *AnEntry)
{
        struct SymEntry* node = AnEntry->Next;

        //if the next in the list isnt null, return it
        if(NULL != node) return node;

        int i; 
        //else just return the first node that isnt null
        for(i = (hashString(AnEntry->Name, ATable->Size) + 1); i < ATable->Size; i++)
        {
                node = ATable->Contents[i];
                if(NULL != node) return node;
        }

        return NULL;
}
/*
//TESTING SYMTABLE
int main(void)
{
        //struct SymTab *ATable, const char *Name, struct SymEntry* *AnEntry)
	struct SymTab *symbolTable;
	symbolTable = CreateSymTab(5);

        printf("TableSize %d\n", symbolTable->Size);
        
        const char* name1 = "Hello";
        const char* name2 = "Goodbye";
        struct SymEntry* *entry = (struct SymEntry**) malloc(sizeof (struct SymEntry*));

        if(EnterName(symbolTable, name1, entry))
        {
                printf("Added %s\n", (*entry)->Name);
        }
        if(EnterName(symbolTable, name2, entry))
        {
                printf("Added %s\n", (*entry)->Name);
        }

        if(EnterName(symbolTable, name1, entry))
        {
                printf("DONT ADD THIS ONE %s\n", (*entry)->Name);
        }

        (*entry) = FindName(symbolTable, name1);
        if(NULL != (*entry)) printf("FindName %s\n",(*entry)->Name);

        const char* voidStr = "Void String";
        void *voidStar = voidStr;
        

        //test setAttr
        SetAttr((*entry), voidStar);
        const char* voidEntry = (char*) GetAttr((*entry));
        printf("Set/GetAttr %s\n", voidEntry);

        //test getname
        printf("GetName %s\n", (*entry)->Name);

        //test FirstEntry
        (*entry) = FirstEntry(symbolTable);

        //test next entry
        (*entry) = NextEntry(symbolTable, (*entry));
        printf("NextEntry %s\n", (*entry)->Name);

        DestroySymTab(symbolTable);
        printf("DestroyTable %p\n", symbolTable);
        free(entry);
	return 0;
}*/
