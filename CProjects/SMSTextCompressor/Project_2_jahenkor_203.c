//Julius Ahenkora G00835346:
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Preprocessor Directives

//Defines size of unpacked and packed array
#define UNPACKEDSIZE 160
#define PACKEDSIZE 120
#define "SMS.h"
//Byte to Binary macro
#define BYTETOBINARYPATTERN "Binary Val: %d%d%d%d%d%d%d%d\n"
#define PRINTBIN(x) printf(BYTETOBINARYPATTERN,BYTETOBINARY(x));
#define BYTETOBINARY(byte) \
   (byte & 0x80 ? 1 : 0), \
      (byte & 0x40 ? 1 : 0), \
         (byte & 0x20 ? 1 : 0), \
            (byte & 0x10 ? 1 : 0), \
               (byte & 0x08 ? 1 : 0), \                  (byte & 0x04 ? 1 : 0), \
                     (byte & 0x02 ? 1 : 0), \
                        (byte & 0x01 ? 1 : 0)

			//Function prototypes
void PrintByte (unsigned char x);
void PackArray (unsigned char *packed, size_t packedSize,
		unsigned char *unpacked, size_t unpackedSize);
void UnpackArray (unsigned char *unpacked, size_t unpackedSize,
		  unsigned char *packed, size_t packedSize);


//PPO
void Pack ();
void Unpack ();


int
main ()
{

  char buffer[MAXBUFFERSIZE];
  char userOption = '0';

//Program Functionality
  while (1)
    {
      printf ("Choose an Option\n");
      printf ("Type P to pack and save text\n");
      printf ("Type U to Unpack and print text\n");
      fgets (buffer, sizeof (buffer), stdin);
      sscanf (buffer, "%c", &userOption);

      switch (userOption)
	{
	case ('U'):
	case ('u'):
	  //debuf
	  printf ("u");
	  break;
	  //Pack
	case ('P'):
	case ('p'):
	  //debug
	  Pack ();
	  break;
	case ('Q'):
	case ('q'):
	  exit (0);
	  break;

	}
    }


  return 0;
}

void
Pack ()
{
  unsigned char userText[MAXBUFFERSIZE];
  char filename[MAXBUFFERSIZE] = "";
  char buffer[MAXBUFFERSIZE] = "";
  char *token;

  int i;

  printf ("Enter filename to save array");
  fgets (filename, sizeof (filename), stdin);
  printf ("Enter text less than 160 characters (inclusive)");
  printf (" to pack and save");

//Saves user text, truncates when past 160 characters.
  fgets (buffer, sizeof (buffer), stdin);
  sscanf (buffer, "%s", userText);

  userText[strlen (userText) - 1] = 0;
  filename[strlen (filename) - 1] = 0;

//Use sscanf to truncate string, and flush stdin.


  FILE *fp = fopen (filename, "wb");
  if (fp == NULL)
    {
      printf ("File cannot be open or created\n");
      return;
    }

//CharToSMS Conversion



  for (i = 0; i < UNPACKEDSIZE; i++)
    {
      printf ("%c", (unsigned) buffer[i]);
      userText[i] = CharToSMS ((unsigned) buffer[i]);
    }
  printf ("UserText: %s", userText);
//Packing Functionality CharToSMS SMSToChar
//strtok




  fclose (fp);


}

//void Unpack (U) and print text
void
Unpack ()
{

  char buffer[MAXBUFFERSIZE];

  printf ("Enter file to unpack");
  fgets (buffer, sizeof (buffer), stdin);

  FILE *fp = fopen (buffer, "r");

  if (fp == NULL)
    {
      printf ("Error opening file");
      return;
    }
//Use fscanf to acquire individual characters then unpack?





  fclose (fp);
}
