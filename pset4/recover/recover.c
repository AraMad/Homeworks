/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    FILE* inptr = fopen(argv[1], "r");
    
    if (inptr == NULL)
    {
        fprintf(stderr, "Forensic image cannot be opened for reading\n");
        return 2;
    }
    
    //outfile name
    char outfile[] = "000.jpg";
    
    int i = -1;
    FILE* outptr = NULL;
    unsigned char buf[512];
   
    while (fread(&buf, sizeof(buf), 1, inptr))
    {
        //JPEGs "signatures" found - create new image (write buf to file)
        if (((buf[0]==0xff) && (buf[1]==0xd8) && (buf[2]==0xff)) && ((buf[3]==0xe0) || (buf[3]==0xe1)))
        {
            //for first image
            if (outptr == NULL)
            {
                outptr = fopen(outfile, "w");
                fwrite(&buf, sizeof(buf), 1, outptr);
            }
            else
            {
                fclose(outptr);
                i++;
                
                //modify name of file
                if (i < 10)
                {
                    outfile[2] = i + '0';
                }
                else 
                {
                    if (i >= 10 && i < 100)
                    {
                        outfile[1] = (round(i/10) + '0');
                        outfile[2] = (i - (10*(round(i/10)))) + '0';
                    }
                }
                
                outptr = fopen(outfile, "w");
                fwrite(&buf, sizeof(buf), 1, outptr);
            }
        }
        else 
        {
            if (outptr == NULL)
            {
                outptr = fopen(outfile, "w");
                fwrite(&buf, sizeof(buf), 1, outptr);
            } else
            {
                fwrite(&buf, sizeof(buf), 1, outptr);
            }
        }
    }
   
   fclose(inptr);
   fclose(outptr);
   
   return 0;
}