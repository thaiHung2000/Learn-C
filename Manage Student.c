#include <stdio.h>

struct student
{
    int id;
    int age;
    char name[50];
    float score;
};

typedef struct student t_student;

void enterData ( int numOfStudent , t_student student[numOfStudent]);
void exportData( int numOfStudent , t_student student[numOfStudent]);
void classifyData (int numOfStudent , t_student student[numOfStudent]);
void sortRelyOnScore(int numOfStudent , t_student student[numOfStudent] );


int main()
{
    int numOfStudent;
    int entered = 0;
    int choose;
    t_student * student;
    
    do
    {
    printf("Please enter number with your statement you want\n");
    printf("0. Exit the programm\n");
    printf("1. Enter student's information\n");
    printf("2. Print student's information on screen\n");
    printf("3. Sort students rely on score from low to high\n");
    printf("4. Classify student\n");
    printf("Your choose is: ");
    scanf("%d", &choose);
    switch (choose)
    {
        case 0:
            break;
        case 1:
        {
            printf("Enter number of student: ");
            scanf("%d", &numOfStudent);
            student = (t_student * ) malloc (numOfStudent * sizeof(t_student));
            enterData(numOfStudent, student);
            entered = 1;
            
            break;
            
        }
        case 2:
        {
            if(entered == 0 )
            {
                printf("Plese enter student'information FIRST\n");
                break;
            }
            exportData ( numOfStudent, student);
            break;
        }
        case 3:
        {
            if(entered == 0 )
            {
                printf("Plese enter student'information FIRST\n");
                break;
            }
            sortRelyOnScore(numOfStudent, student);
            
            
            break;
        
        }
        case 4:
        {
            if(entered == 0 )
            {
                printf("Plese enter student'information FIRST\n");
                break;
            }
            classifyData ( numOfStudent, student) ;
            
            break;
        }
        default:
        {
            printf("Don't have your statement");
            break;
        }
        
            
    }
    } while (choose != 0 );
    
    
    
}


/*
 Decription: Function to enter student's information.
 Input: student's name, student's score, student's age, student's id.
 No output and no return.
 */
void enterData ( int numOfStudent , t_student student[numOfStudent])
{
    for(int i = 0 ; i < numOfStudent ; i++ )
    {
        printf("Enter name of student number %d: ", i + 1);
        scanf("\n");
        for(int j = 0 ; j < 50 ; j ++ )
        {
            scanf("%c", &student[i].name[j]);
            if( student[i].name[j] == '\n' )
            {
                student[i].name[j] = NULL;
                break;
            }
        }
        printf("Enter score of student number %d: ", i + 1);
        scanf("%f", &student[i].score);
        printf("Enter age of student number %d: ", i + 1 );
        scanf("%d", &student[i].age);
        printf("Enter id of student number %d: ", i + 1);
        scanf("%d", &student[i].id);
        
    }
    
    
}

/*
 Decription: Function to print student's information on screen.
 No input.
 Output: Student's information on screen.
 No return.
 */
void exportData ( int numOfStudent , t_student student[numOfStudent])
{
    for(int i = 0 ; i < numOfStudent ; i++ )
    {
        printf("Name of student number %d is: ", i + 1);
        for(int j = 0 ; j < strlen(student[i].name); j++ )
        {
            printf("%c", student[i].name[j]);
                   
        }
        printf("\n");
        
        printf("Score of student number %d is: %.1f\n",i+1 , student[i].score);
        printf("Age of student number %d is: %d\n",i+ 1, student[i].age);
        printf("ID of student number %d is: %d\n",i+1 , student[i].id);
       
    }
    
}


/*
 Decription: Function to classify student rely on score and print it on screen.
 Input : student's score.
 Output: Classify student and print it on screen.
 No return.
 */
void classifyData (int numOfStudent , t_student student[numOfStudent])
{
    for(int i = 0 ; i < numOfStudent ; i++ )
    {
        if(student[i].score >= 8 )
        {
            printf("Good\n");
        }
        if(student[i].score < 8 && student[i].score >= 6.5)
        {
            printf("Fair\n");
        }
        if(student[i].score < 6.5 && student[i].score >=5 )
        {
            printf("Poor\n");
        }
        if(student[i].score < 5  )
        {
            printf("Very poor\n");
        }
    }
    
}

/*
 Decription: Function to sort student rely on score from low to high and print it on screen.
 Input: students' score.
 Ouput: Compare studens' score then sort them from low to high and print them on screen.
 No return.
 
 */
void sortRelyOnScore(int numOfStudent , t_student student[numOfStudent] )
{
    t_student tmp;
    for(int j = 0 ; j < numOfStudent ; j ++)
    {
        for(int i = 0 ; i < numOfStudent - j ; i++ )
        {
            if(i == numOfStudent - 1)
            {
                    break;
            }
            if(student[i].score > student[i+1].score )
            {
                tmp = student[i];
                student[i] = student[i+1];
                student[i+1] = tmp;
            }
        }
    }
    for(int i = 0; i < numOfStudent ; i++ )
    {
        for(int j = 0 ; j < strlen(student[i].name) ; j ++)
        {
            printf("%c", student[i].name[j]);
        }
        printf("\n");
    }
    
}

