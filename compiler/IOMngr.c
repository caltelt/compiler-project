
#include "IOMngr.h"

FILE* sourceFile = NULL;
FILE* listingFile = NULL;

char currentLine[MAXLINE];
int currentLineNumber = 1;
int currentLineLength = 0;
int prevLineLength = 0;
bool newline = true;

//open files passed in
bool OpenFiles(const char * ASourceName,  const char * AListingName)
{
        //assume ASourceName is valid
        sourceFile = fopen(ASourceName, "r");
        if(NULL == sourceFile)
        {
                printf("Failed to open source file.\n");
                return false;
        }
        
        if(NULL == AListingName)
        {
                listingFile = stdout;
                return true;
        }
        else
        {
                listingFile = fopen(AListingName, "w");
        }
        
        if(NULL == listingFile)
        {
                printf("Failed to open listing file.\n");
                return false;
        }

        //HOW DID YOU GET HERE
        return false;
}

//close all files
void CloseFiles()
{
        fputc('\n', listingFile);
        if(NULL != sourceFile)
        {
                if(0 != fclose(sourceFile))
                {
                        printf("%d\tSource File not closed properly.\n", currentLineNumber);
                        currentLineNumber++;
                }
        }
        if(NULL != listingFile && stdout != listingFile)
        {
                if(0 != fclose(listingFile))
                {
                        printf("%d\tListing File not closed properly.\n", currentLineNumber);
                        currentLineNumber++;
                }
        }

        listingFile = NULL;
}

char GetSourceChar()
{
        if(newline)
        {
                fprintf(listingFile, "%d\t", currentLineNumber);
                newline = false;
        }

        if(NULL == sourceFile)
        {
                printf("%d\tSource file is null, can not get char from.\n", currentLineNumber);
                exit(-1);
        }

        currentLineLength++;

        char c = fgetc(sourceFile);
        currentLine[GetCurrentColumn()] = c;

        //if newline, wrap and line number
        if('\n' == c)
        {
                currentLine[GetCurrentColumn()] = '\0';
                currentLineNumber++;

                if(EOF == fputc(c, listingFile))
                {
                        printf("%d\t\nError writing to listing file.\n", currentLineNumber);
                        exit(-1);
                }

                //keep track of previous line length for debug
                //should be prev--, as '\n' is *invis*
                prevLineLength = currentLineLength - 1;
                currentLineLength = 0;

                newline = true;
                return c;
        }
        if(EOF != c)
        {
                fputc(c, listingFile);
        }
        else
        {
                fputc('\n', listingFile);
        }
        
        return c;
}

void WriteIndicator(int AColumn)
{
        if(newline)
        {
                fprintf(listingFile, "\t");
        }
        else
        {
                fprintf(listingFile, "\n\t");
        }
        
        int i;
        for(i = 1; i < AColumn; i++)
        {
                if(EOF == fputc(' ', listingFile))
                {
                        printf("\n%d\tError writing spaces to Listing file for error\n", currentLineNumber);
                }
        }

        if( EOF == fputc('^', listingFile))
        {
                printf("\n%d\tError writing '^' to listing file\n", currentLineNumber);
                exit(-1);
        }

        fprintf(listingFile, "\n");
        currentLineLength = 0;        

        newline = true;
}

void WriteMessage(const char * AMessage)
{
        if(newline)
        {
                fprintf(listingFile, "\t");
        }
        
        fprintf(listingFile, "%s\n", AMessage);
        prevLineLength =  strlen(AMessage);

        newline = true;
}

int GetCurrentLine()
{
        if(newline)
        {
                return currentLineNumber - 1;
        }
        return currentLineNumber;
}

int GetCurrentColumn()
{
        return currentLineLength;
}

int GetPastColumn()
{
        return prevLineLength;
}





/*
int main(void)
{
        OpenFiles("SourceFile.txt", "ListingFile.txt");

        char currentChar = GetSourceChar();

        WriteMessage("Therr is an error");
        WriteIndicator(5);
          
        while(EOF != currentChar)
        {
                if(currentChar == '\t')
                {
                        fputc(currentChar, listingFile);
                        WriteMessage("nother arror");
                        WriteIndicator(4);
                }
                else
                {
                        fputc(currentChar, listingFile);
                }
                currentChar = GetSourceChar();                        
        }
        WriteMessage("Therr is an error");
//                        ^ here
        WriteIndicator(5);

        CloseFiles();
        exit(0);
}
*/
