

#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    //    int c;
    //    FILE *fptr;
    char *mode = "r+";
    
    //
    //    fptr = fopen("/Users/Cannon/Documents/Newbee.c", mode);
    
    
    
    // the file we want to read from
    char filename[] = "/Users/Cannon/Documents/Newbee.c";
    
    // open the file for reading
    FILE *file = fopen("/Users/Cannon/Documents/Newbee.c", mode);
    FILE *out = fopen("/Users/Cannon/Documents/NewbOut.c", "w");
    
    // make sure the file opened properly
    if(NULL == file)
    {
        fprintf(stderr, "Cannot open file: %s\n", filename);
        return 1;
    }
    
    size_t buffer_size = 80;
    char *buffer = malloc(buffer_size * sizeof(char));
    
    // read each line and print it to the screen
    int line_number = 0;
    while(-1 != getline(&buffer, &buffer_size, file))
    {
        //printf("%d: %s", ++line_number, buffer);
        fprintf(out, "%d: %s", ++line_number, buffer);
    }
    fflush(stdout);
    
    // make sure we close the file and clean up the buffer when we're
    // finished
    fclose(file);
    free(buffer);
    
    
    
    
    return 0;
}
