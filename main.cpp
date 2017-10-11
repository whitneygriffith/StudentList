#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class studentType
{

public:
    string lastName;
    string firstName;
    int ID;
    string city;
};

struct nodeType
{
    nodeType *next;
    studentType info;
};

class UnsortedListType //This holds the linked List of students
{

public:
    UnsortedListType();
    void insertEnd(studentType student);
    void insertFront(studentType student);
    void insertMid(studentType student);
    void printList();
    nodeType *head;
    ~UnsortedListType()
};

UnsortedListType::UnsortedListType()
{
    head = NULL;
}

UnsortedListType::~UnsortedListType()
{
    while (head->next != NULL) {
        nodeType *temp = head->next;
        delete head;
        head = temp;
    }
    delete head;
    cout << "Destructor was called" << endl;

}

void UnsortedListType::insertEnd(studentType student){

    nodeType *current;
    current = head;

    if (head == NULL)
    {
        head -> info = student;
        head -> next = NULL;
        //this->insertFront(student);
    }

    else{
        while (current != NULL)
        {
            if (current -> next == NULL )
            {
                current -> next -> info = student;
                current -> next -> next = NULL;
            }
            current = current -> next;
        }
    }


}

void UnsortedListType::insertFront(studentType student)
{
        nodeType *hold = head;
        head = new nodeType;
        head -> info = student;
        head -> next = hold;
}

void UnsortedListType::insertMid(studentType student)
{

    int count = 0; //counts how many students in the list
    int mid; // midpoint
    nodeType *current;
    current = head;
    while (current != NULL){
        ++count;
        current = current -> next;
    }

    cout << count << "count is" << endl;

    mid = count / 2;

    //reset variables
    current = head;
    count = 0;

    while (current != NULL){
        ++count;
        if (count == mid)
        {
            nodeType *hold;
            //save the current next
            hold = current -> next;
            //insert this new student
            current -> next -> info = student;
            current -> next -> next = hold;
            break;
        }
        current = current -> next;
    }




}
void UnsortedListType::printList()
{
    nodeType *current = head;

    while (current != NULL)
    {
        cout << current ->info.lastName << " " << current ->info.firstName << "       \t";
        cout << current -> info.ID << "\t" << current -> info.city << endl;
        current = current -> next;
    }
}


int main() {

    //temporary student type
    studentType student;
    UnsortedListType *studentList;

    string firstName, lastName, city;
    int ID;

    ifstream myfile;
    myfile.open("infile.txt");

    while(!myfile.eof()){
        myfile >> student.lastName >> student.firstName >> student.ID >> student.city;
        if (studentList->head == NULL )
        {
            studentList -> insertEnd(student);
        }
        else if(student.ID == 20 and student.lastName == "Keeling" and student.firstName == "Harry" and student.city == "Dallas" )
        {
            studentList -> insertMid(student);
        }

        else if (student.ID % 2 == 0)
        {
            studentList -> insertFront(student);
        }
        else if (student.ID % 2 != 0)
        {
            studentList -> insertEnd(student);
        }

    }


    studentList->printList();
    myfile.close();




    cout << "yes" << endl;
    return 0;
}