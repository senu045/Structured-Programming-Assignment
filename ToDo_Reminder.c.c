#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Todo
{
  int id;
  char description[100];
  char reminder[50];
  int mask;			// 0 - Unmasked, 1 - Masked
};

void
interface ()
{


  printf ("\n\n\n\n");


  printf ("\t~~~~~~~~~~~~~~~~~~~~~"
	  "~~~~~~~~~~~~~~~~~~~~~~~~"
	  "~~~~~~~~~~~~~~~~~~~~~~~~"
	  "~~~~~~~~~~~~~~~~~~~~~~~" "~~~~~~~~~~\n");


  printf ("\t~~~~~~~~~~~~~~~~~~~~~~"
	  "~~~~~~~~~~~~~~~~~~~~~~~"
	  "~~~~~~~~~~~~~~~~~~~~~~~"
	  "~~~~~~~~~~~~~~~~~~~~~~~~" "~~~~~~~~~~\n\n");


  printf ("\t} : } : } : } : } : } "
	  ": } : } : } : "
	  "WELCOME TO the TODO APP "
	  "	 : { : { : { : { : { " ": { : { : { : {\n\n");


  printf ("\t~~~~~~~~~~~~~~~~~~~~~"
	  "~~~~~~~~~~~~~~~~~~~~~~~~"
	  "~~~~~~~~~~~~~~~~~~~~~~~~~"
	  "~~~~~~~~~~~~~~~~~~~~~~" "~~~~~~~~~~\n");


  printf ("\t~~~~~~~~~~~~~~~~~~~~~~"
	  "~~~~~~~~~~~~~~~~~~~~~~~"
	  "~~~~~~~~~~~~~~~~~~~~~~~"
	  "~~~~~~~~~~~~~~~~~~~~~~~~" "~~~~~~~~~~\n");


  printf ("\n\n\n\t\t\t\t\t\t\t" "\t\t\t\t	 " "\n\n\n\t");




}

void
viewTodoList (struct Todo todo[], int count)  //The view ToDo function///
{
  printf ("\nTodo List:\n");
  printf ("ID\tDescription\tReminder\n");
  printf ("--------------------------------\n");
  for (int i = 0; i < count; i++)
    {
      printf ("%d\t", todo[i].id);

      if (todo[i].mask)
	{
	  char maskedDescription[100] = ""; //Will hide the words like in passwords ,by leaving only the first letter.//
	  char *word = strtok (todo[i].description, " ");
	  while (word != NULL)
	    {
	      if (isalpha (word[0]))
		{
		  strncpy (maskedDescription + strlen (maskedDescription), word, 1);	// Keep the first letter
		  strcat (maskedDescription, "**** ");	// Add asterisks for the remaining letters
		}
	      else
		{
		  strcat (maskedDescription, word);
		  strcat (maskedDescription, " ");
		}
	      word = strtok (NULL, " ");
	    }
	  printf ("%s\t\t", maskedDescription);
	}
      else
	{
	  printf ("%s\t\t", todo[i].description);
	}

      if (todo[i].mask)
	{
	  char maskedReminder[50] = "";
	  char *word = strtok (todo[i].reminder, " ");
	  while (word != NULL)
	    {
	      if (isalpha (word[0]))
		{
		  strncpy (maskedReminder + strlen (maskedReminder), word, 1);	// Keep the first letter
		  strcat (maskedReminder, "**** ");	// Add asterisks for the remaining letters
		}
	      else
		{
		  strcat (maskedReminder, word);
		  strcat (maskedReminder, " ");
		}
	      word = strtok (NULL, " ");
	    }
	  printf ("%s\n", maskedReminder);
	}
      else
	{
	  printf ("%s\n", todo[i].reminder);
	}
    }
  printf ("--------------------------------\n");
}

int
createTodo (struct Todo todo[], int count)  //The createToDo function//
{
  int id;
  char maskChoice;

  printf ("\nEnter the todo ID: ");
  scanf ("%d", &id);

  printf ("Enter the todo description: ");
  scanf (" %[^\n]", todo[count].description);

  printf ("Enter the reminder (if any): ");
  scanf (" %[^\n]", todo[count].reminder);

  printf ("Do you want to mask the todo and reminder? (Y/N): ");
  scanf (" %c", &maskChoice);
  if (maskChoice == 'Y' || maskChoice == 'y')
    {
      todo[count].mask = 1;
    }
  else
    {
      todo[count].mask = 0;
    }

  todo[count].id = id;
  count++;

  printf ("Todo created successfully!\n");
  return count;
}




int
deleteTodo (struct Todo todo[], int count) //Delete ToDo function//
{


  int id, found = 0;


  printf ("\nEnter the todo ID to delete: ");


  scanf ("%d", &id);


  for (int i = 0; i < count; i++)

    {


      if (todo[i].id == id)

	{


	  for (int j = i; j < count - 1; j++)

	    {


	      todo[j] = todo[j + 1];


	    }
	  count--;


	  found = 1;


	  printf ("Todo with ID %d deleted successfully!\n", id);


	  break;


	}


    }


  if (found == 0)

    {


      printf ("Todo with ID %d not found!\n", id);


    }


  return count;


}





void
setReminder (struct Todo todo[], int count)   //Set Reminder function //
{


  int id;


  char reminder[50];


  printf ("\nEnter the todo ID to set a reminder: ");


  scanf ("%d", &id);


  printf ("Enter the reminder: ");


  scanf (" %[^\n]", reminder);


  for (int i = 0; i < count; i++)

    {


      if (todo[i].id == id)

	{


	  strcpy (todo[i].reminder, reminder);


	  printf ("Reminder for Todo ID %d set successfully!\n", id);


	  return;


	}


    }


  printf ("Todo with ID %d not found!\n", id);


}





int
main ()
{


  struct Todo todo[100];


  int count = 0, choice;


  interface ();

  while (1)

    {


      printf ("\n--- Todo List Application ---\n");


      printf ("1. View Todo List\n");


      printf ("2. Create New Todo\n");


      printf ("3. Delete Todo\n");


      printf ("4. Set Reminder\n");


      printf ("5. Exit\n");


      printf ("Enter your choice: ");


      scanf ("%d", &choice);



      switch (choice)

	{


	case 1:


	  viewTodoList (todo, count);


	  break;


	case 2:


	  count = createTodo (todo, count);


	  break;


	case 3:


	  count = deleteTodo (todo, count);


	  break;


	case 4:


	  setReminder (todo, count);


	  break;


	case 5:

	  printf
	    ("\n\n\n                                    Thanks for choosing the ToDo Application!!");

	  printf
	    ("                                                                                         Good Bye!!!!!!!!!\n\n\n");

	  exit (0);

	default:


	  printf ("Invalid choice! Please try again.\n");


	  break;


	}


    }



  return 0;


}
