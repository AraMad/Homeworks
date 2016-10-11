/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize coefficient infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    
    // remember coefficient
    int coefficient = atoi(argv[1]);
    if (coefficient < 1 | coefficient > 100)
    {
        fprintf(stderr, "Usage: ./resize 1 <= coefficient < 100 infile outfile\n");
        return 1;
    }

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding_out = (4 - (bi.biWidth*coefficient* sizeof(RGBTRIPLE)) % 4) % 4;
    
    //plus sizes of headers to size of file
    bf.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    //scip headers (write it later, after calculate new sizes)
    fseek(outptr, bf.bfSize, SEEK_SET);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int z = 0; z < coefficient; z++)
        {
            if (z != 0)
            {
                //return to begin of scanline if num of scanlines > 1
                fseek(inptr, -bi.biWidth*sizeof(RGBTRIPLE), SEEK_CUR);
            }
            
            //iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                //temporary storage
                RGBTRIPLE triple;

                //read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int g = 0; g < coefficient; g++)
                {//write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                //change size of file
                bf.bfSize+=sizeof(RGBTRIPLE);
                }
            }
            //add padding
            for (int k = 0; k < padding_out; k++)
            {
                fputc(0x00, outptr);
                bf.bfSize+=sizeof(char);
            }
        }
        
        //skip over padding
        fseek(inptr, padding, SEEK_CUR);
    }

    //modify headers of file
    bi.biWidth*=coefficient;
    bi.biHeight*=coefficient;
    bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + padding_out) * abs(bi.biHeight); 
   
    //write outfile's BITMAPFILEHEADER and BITMAPINFOHEADER
    fseek(outptr, 0, SEEK_SET); 
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    //close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}