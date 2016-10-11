/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"

 node* root = NULL;
 int SIZE = 0;

//calculate index of element in the node
int index_m(char a)
{
    return isalpha(a)?(tolower(a)-97):26;
}

// unload dictionary from memory 
void rec_unload (node *p)
{
    for (int i = 0; i < 27; i++) 
    {
        if (p->children[i] != NULL)
        {
            rec_unload(p->children[i]);
        }
    }

    if (p != root)
    {
        p = realloc(p, 0 );
    }
    else
    {
        root = realloc(root, 0 );
    }
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    node *p = root;

    for (int i = 0, l = strlen(word); i < l; i++)
    {
        if (p->children[index_m(word[i])] != NULL)
        {
            p = p->children[index_m(word[i])];
        }
        else
        {
            return 0;
        }
    }
    
    if (p->is_word == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    FILE *diction = fopen(dictionary,"r");
    
    if (!diction)
    {
        return 0;
    }
    
	root = malloc(sizeof(node));
	root->is_word = 1;
	
	char ch;
	node *p = root;
	
	while (fread(&ch, sizeof(ch), 1, diction))
	{
	    if (ch != '\n')
	    {
	        if (p->children[index_m(ch)] == NULL)
	        {
		        p->children[index_m(ch)] = malloc(sizeof(node));
		        p = p->children[index_m(ch)];
	        }
	        else
	        {
	            p = p->children[index_m(ch)];
	        }
	    }
	    else 
	    {
		    p->is_word = 1;
		    SIZE++;
		    p = root;
	    }
	}
    
    fclose(diction);
    
    return 1;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return SIZE;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    rec_unload(root);
    if (root == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
