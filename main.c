//Write your code in this file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Student {
    char name[11];
    int scores[13];
    int averageScore;
};

int compare(const void *a, const void *b) 
{
    return ( *(int*)a - *(int*)b );
}


int main() {

    struct Student students[5];
    int bestStudentID = 0;
    int medianValue = 0;
    int sortingScoresArray[5];
    
    //Input Student Data
    for (int i = 0; i < 5; i++) 
    {
        //Name
        int sum = 0;
        scanf("%10s", students[i].name);

        //Scores
        for (int j = 0; j < 13; j++) 
        {
            scanf("%d", &students[i].scores[j]);
            sum += students[i].scores[j];
        }

        students[i].averageScore = sum / 13;

        students[i].name[0] = toupper(students[i].name[0]); 
    }

    //Sort the average scores to find the median
    for (int i = 0; i < 5; i++) 
    {
        sortingScoresArray[i] = students[i].averageScore;
    }
    qsort(sortingScoresArray, 5, sizeof(int), compare);
    medianValue = sortingScoresArray[2];

    //Find the best student and print their name
    for(int i = 0; i < 5; i++)
    {
        if(students[i].averageScore > students[bestStudentID].averageScore)
        {
            bestStudentID = i;      
        }
    };

    printf("%s\n", students[bestStudentID].name);

    //Print the names of students with an average score below the median
    for (int i = 0; i < 5; i++) {
        if(students[i].averageScore < medianValue)
        {
            printf("%s\n", students[i].name);
        }
    }
   

    return 0;


}