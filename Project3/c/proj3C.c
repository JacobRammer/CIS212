
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 30 // change rear to 10

typedef struct
{
    int back;
    int front;
    int priority;
    char* elements[QUEUE_SIZE];
} Queue;

void InitializeQueue(Queue *q)
{
    for(int i = 0; i < QUEUE_SIZE; i++)
        q->elements[i] = NULL;
    q->front = 0;
    q->back = 0;
    q->priority = 0;

}

void Enqueue(Queue *q, char* val)
{
    if (q->back + 1 >= QUEUE_SIZE)
    {
        printf("Enqueue failed\n");
        exit(EXIT_FAILURE);
    }
    q->elements[q->back] = val;
    q->back++;
    q->priority++;
}

char* Dequeue(Queue *q)
{
    if (q->front < 0)
    {
        printf("At beginning of queue\n");
        return 0;
    }
    char* beforeDequeue = q->elements[q->front];
    q->front++;
    q->priority = 0;
    return beforeDequeue;
}

void PrintQueue(Queue *q)
{
    int i;
    printf("Printing queue %p\n", q);
    printf("\tThe rear for the front of the queue is %d\n", q->front);
    printf("\tThe rear for the rear of the queue is %d\n", q->back);
    if (q->front == q->back)
    {
        printf("\tThe queue is empty.\n");
        return;
    }
    int back = q->back;
    if (q->back < q->front)
    {
        // wrapped around, so modify indexing 
        back += QUEUE_SIZE;
    }

    for (i = q->front ; i < back ; i++)
    {
        printf("\t\tEntry[%d] = \"%s\"\n", i%QUEUE_SIZE, q->elements[i%QUEUE_SIZE]);
    }
}



void PrettyPrintQueue(Queue *q, char *type)
{
    if (q->elements[q->front] == NULL)
    {
        printf("No unmatched entries for %s\n", type);
    }
    else
    {
        char *s;
        printf("Unmatched %s:\n", type);
        while ((s = Dequeue(q)))
        {
            printf("%s\n", s);
        }
    }
}


char *NewString(char *s)
{
    int len = strlen(s);
    char *rv = malloc(len+1);
    strcpy(rv, s);
    rv[len-1] = '\0'; /* take out newline */
    return rv;
}




void placeInCorrectQueue(char* line, Queue *md, Queue *mr, Queue *fd, Queue *fr, Queue *h)
{
    if (line[0] == 'R'  && line[2] == 'F')  // recipient
    {
        Enqueue(fr, line + 4);
    }
    if (line[0] == 'D'  && line[2] == 'F')  // donor
    {
        Enqueue(fd, line + 4);
    }
    if (line[0] == 'R'  && line[2] == 'M')
    {
        Enqueue(mr, line + 4);
    }
    if (line[0] == 'D'  && line[2] == 'M')
    {
        Enqueue(md, line + 4);
    }
    if (line[0] == 'H')
    {
        Enqueue(h, line + 2);
    }
}



int main(int argc, char *argv[])
{
/***  STEP #1: Test your queue code.  ***/



    char line[256];  //array that holds each line
    int lineNum = 0;  // the present line in the file stream
    int setLines = 0;  // will be the total number of lines in the file

    Queue maleDonors;
    Queue maleRecipients;
    Queue femaleDonors;
    Queue femaleRecipients;
    Queue hospital;
    InitializeQueue(&maleDonors);
    InitializeQueue(&maleRecipients);
    InitializeQueue(&femaleDonors);
    InitializeQueue(&femaleRecipients);
    InitializeQueue(&hospital);


    if (argc < 2)
    {
        printf("Invalid number of inputs.\n");
        exit(EXIT_FAILURE);
    }

    FILE *donorList = fopen(argv[1], "r");
    if (donorList == NULL)
    {
       printf("%s is not a valid file", argv[1]);
       exit(EXIT_FAILURE);
    }
    /*
     Dynamically find number of lines
     */
    while(fgets(line, 256, donorList))
        setLines++;
    char *buff[setLines];  // you have to set this after the loop ya derp


    fseek(donorList, 0, SEEK_SET);  // if i remove this it breaks?

    while(fgets(line, 256, donorList))
    {
        buff[lineNum] = NewString(line);
        lineNum++;
    }

    for(int i = 0; i < setLines; i++)
    {
        placeInCorrectQueue(buff[i], &maleDonors, &maleRecipients, &femaleDonors, &femaleRecipients, &hospital);
            for(int j = 0; j <= i; j++)
            {
                if(hospital.elements[hospital.front] != NULL)
                {
                    if(femaleDonors.elements[femaleDonors.front] != NULL && femaleRecipients.elements[femaleRecipients.front] != NULL)
                    {
                        printf("MATCH: %s donates to %s at hospital %s\n", Dequeue(&femaleDonors), Dequeue(&femaleRecipients), Dequeue(&hospital));
                        buff[j] = NULL;
                        break;
                    }else if(maleDonors.elements[maleDonors.front] != NULL && maleRecipients.elements[maleRecipients.front] != NULL)
                    {
                        printf("MATCH: %s donates to %s at hospital %s\n", Dequeue(&maleDonors), Dequeue(&maleRecipients), Dequeue(&hospital));
                        buff[j] = NULL;
                        break;
                    }

                }
            }
    }


    PrettyPrintQueue(&femaleDonors, "female donors");
    PrettyPrintQueue(&femaleRecipients, "female recipients");
    PrettyPrintQueue(&maleDonors, "male donors");
    PrettyPrintQueue(&maleRecipients, "male recipients");
    PrettyPrintQueue(&hospital, "hospitals");


}
