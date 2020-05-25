#include <stdio.h>

typedef struct student
{
    char name[50];
    int age;
    int id;
    float score;
} t_student;

typedef struct node
{
    t_student data;
    struct node * next;
} t_node;

typedef struct list
{
    t_node * head;
    t_node * tail;
} t_list;

/*
 Decription: function to creata head and tail for list.
 Input: an empty list
 Output: create for list a head and a tail
 */
void createList (t_list * list)
{
    list->head = list->tail = NULL;
}

/*
 Decription: function to add node at last of list
 Input: node and list
 Output: node to be become a tail of list
 No return
 */
void addLast ( t_list * list , t_node * node )
{
    if(list->head == NULL)
    {
        list->head = list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
}

/*
 Decription: function to add student's information
 Input: student's score, student's name , student's age, student's id
 ouput: a data contain student's information
 No return
 */
void enterData(t_student * student )
{
    printf("Enter name: ");
    scanf("\n");
    for( int i = 0 ; i < 50 ; i++ )
    {
        scanf("%c", &student->name[i]);
        if ( student->name[i] == '\n')
        {
            student->name[i] = 0;
            break;
        }
    }
    printf("Enter age: ");
    scanf("%d", &student->age);
    printf("Enter id: ");
    scanf("%d", &student->id);
    printf("Enter score: ");
    scanf("%f", &student->score);
}

/*
 Decription: function to create a node with data is student's information
 Input: student's information
 Output: a node contain student's information
 No return
 */
t_node * creatNode ( t_student student )
{
    t_node * temp;
    temp = ( t_node* )malloc( sizeof(struct node) );
    temp->data = student ;
    temp->next = NULL;
    return temp;
}

/*
 Decription: function to print 1 student's information into screen
 Input: student's information
 Output: print student's information into screen
 No return
 */
void exportData( t_student student )
{
    printf("Name: ");
    for(int i = 0; i < strlen(student.name) ; i++ )
    {
        printf("%c", student.name[i]);
    }
    printf("\n");
    printf("Age: %d\n", student.age);
    printf("ID: %d\n", student.id);
    printf("Score: %.1f\n", student.score);
}

/*
 Decription: function to print list of student's information into screen
 Input: list of student's information
 Output: print list of student's information into screen
 No return
 */
void output (t_list list)
{
    t_node * node;
    node = list.head;
    int k = 1;
    while( node != NULL )
    {
        printf("Information of student %d\n", k);
        k++;
        exportData( node->data );
        node = node->next;
    }
}

/*
 Decription: Function to classify student rely on score
 Input: score of student
 Output: classification of student
 No return
 */
void classifyStudent ( t_list  list)
{
    t_node * p;
    t_student student;
    p = list.head;
    do
    {
        student = p->data;
        for ( int i = 0 ; i < strlen(student.name); i++ )
        {
            printf("%c", student.name[i]);
        }
        if ( student.score >= 8 )
        {
            printf("\tGOOD");
        }
        if ( ( student.score >= 6.5 ) && ( student.score < 8 ) )
        {
            printf("\tFair");

        }
        if ( ( student.score  < 6.5 ) && ( student.score >= 5 ) )
        {
            printf("\tPoor");
        }
        if ( student.score < 5  )
        {
            printf("\tVery poor");
        }
        printf("\n");
    
        p = p->next;
        
    }while ( p != NULL );
}

/*
 Decription: Function to export list of student into a file
 Input: list of student
 Output: a file contain list of student
 No return
 */
void exportFile ( t_list list )
{
    t_node * p;
    t_student student;
    p = list.head;
    FILE * fptr;
    fptr = fopen ( "DANHSACH.TXT", "w");
    fprintf(fptr, "Name\tAge\tId\tScore\n");
    do
    {
        student = p->data;
        fprintf( fptr, "%s %d %d %1.f\n", student.name, student.age , student.id, student.score );
        p = p->next;
        
    }while ( p != NULL );
    fclose( fptr );
}

/*
 Decription: Function to sort student from low to high rely on score
 Input: list of student
 Output: list of student from low to high rely on score
 No return
 */
void sortList (t_list list)
{
    t_node * p,* q,* min;
    p = list.head;
    t_student temp;
    while (p != list.tail)
    {
        min = p;
        q = p->next;
        while ( q != NULL )
        {
            if( q->data.score < min->data.score )
            {
                min = q;
            }
            q = q->next;
        }
        temp = p->data;
        p->data = min->data;
        min->data = temp;
        p = p->next;
    }
}

int main()
{
    t_student student;
    t_node * node;
    t_list list;

    createList( &list );
   
    int entered = 0;
    int choose;

    do
    {
    printf("Please enter number with your statement you want\n");
    printf("0. Exit the programm\n");
    printf("1. Enter student's information ( If you want to add after enter, this key too\n");
    printf("2. Print student's information on screen\n");
    printf("3. Sort students rely on score from low to high\n");
    printf("4. Classify student\n");
    printf("5. Export file\n");
    printf("Your choose is: ");
    scanf("%d", &choose);
    switch (choose)
    {
        case 0:
            break;
        case 1:
        {
            entered = 1;
            printf("Enter the number of student: ");
            int number;
            scanf("%d", &number);
            for(int i = 0 ; i < number ; i++ )
            {
            printf("Enter information of student\n");
            enterData( &student );
            node = creatNode( student );
            addLast ( &list, node );
            }
            break;
        }
        case 2:
        {
            if( entered == 0 )
            {
                printf("Please enter student's information FIRST\n");
                break;
            }
            output( list );
        }
        case 3:
        {
            if( entered == 0 )
            {
                printf("Please enter student's information FIRST\n");
                break;
            }
            sortList ( list );
            break;
        }
        case 4:
        {
            if( entered == 0 )
            {
                printf("Please enter student's information FIRST\n");
                break;
            }
            classifyStudent ( list );
            break;
        }
        case 5:
        {
            if( entered == 0 )
            {
                printf("Please enter student's information FIRST\n");
                break;
            }
            exportFile( list );
            break;
        }
        default:
        {
            printf("Don't have your statement\n");
            break;
        }
    }
    } while ( choose != 0 );
}

    
    
    

