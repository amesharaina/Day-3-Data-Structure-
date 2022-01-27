#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


struct table
{
  int key;
  int value;
};
struct table *array;
int vol = 10;
int size = 0;

void insert(int key, int value)
{
  int index = hashFunction(key);
  if (array[index].value == 0)
  {
  array[index].key = key;
  array[index].value = value;
  size++;
  printf("\n Key (%d) has been inserted \n", key);
  }
  else if (array[index].key == key)
  {
  array[index].value = value;
  }
  else
  {
  printf("\n Collision occured  \n");
  }
}

void remove_element(int key)
{
  int index = hashFunction(key);
  if (array[index].value == 0)
  {
  printf("\n Key does not exist \n");
  }
  else
  {
  array[index].key = 0;
  array[index].value = 0;
  size--;
  printf("\n Key (%d) has been removed \n", key);
  }
}
void display()
{
  int i;
  for (i = 0; i < vol; i++)
  {
  if (array[i].value == 0)
  {
    printf("\n array[%d]: / ", i);
  }
  else
  {
    printf("\n key: %d array[%d]: %d \t", array[i].key, i, array[i].value);
  }
  }
}

int hashFunction(int key)
{
  return (key % vol);
}

void init_array()
{

  array = (struct table *)malloc(vol * sizeof(struct table));
  for (int i = 0; i < vol; i++)
  {
  array[i].key = 0;
  array[i].value = 0;
  }
}
int hashtable_size()
{
  return size;
}

int main()
{
  int ch, key, value, n;
  int c = 0;
  init_array();

  do
  {
  printf("1.Insert item in the Hash Table"
     "\n2.Remove item from the Hash Table"
     "\n3.Check  size of Hash Table"
     "\n4.Display Hash Table"
     "\n\n Please enter your choice: ");

  scanf("%d", &ch);
  switch (ch)
  {
  case 1:

    printf("Enter key -:\t");
    scanf("%d", &key);
    printf("Enter data -:\t");
    scanf("%d", &value);
    insert(key, value);

    break;

  case 2:

    printf("Enter the key to delete-:");
    scanf("%d", &key);
    remove_element(key);

    break;

  case 3:

    n = hashtable_size();
    printf("Size of Hash Table is-:%d\n", n);

    break;

  case 4:

    display();

    break;

  default:

    printf("Invalid Input\n");
  }

  printf("\nDo you want to continue (Press 1 for yes): ");
  scanf("%d", &c);

  } while (c == 1);
}
