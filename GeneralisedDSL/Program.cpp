#include<iostream>
using namespace std;

//structure for singly linkedlist
template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

//structure for doubly linkedlist

template <class T>
struct nodeD
{
    T data;
    struct nodeD<T> *next;
    struct nodeD<T> *prev;
};



template <class T>
class SinglyLL
{
    public:
        int iCount ;
        struct nodeS<T> * First;

        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no ,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);


        void Display();
        int Count();
};

template <class T>
SinglyLL <T> :: SinglyLL()
{
    int iCount = 0;
    First = NULL;
}

template <class T>
void SinglyLL <T> :: InsertFirst(T no)
{
    struct nodeS<T> * newn = new struct nodeS<T>;  

    newn -> data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }
    else
    {
        newn->next = First;
        First = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL <T> :: InsertLast(T no)
{
    // Step1 : Allocate memory for node
    struct nodeS<T> * newn = new struct nodeS<T>;

    // Step2 : Initialise node
    newn->data = no;
    newn->next =  NULL;

    // Step3 : Check if LL is empty or not
    if(First == NULL)   // if(iCount == 0)
    {
        First = newn;
        iCount++;
    }
    else    // If LL contains atleast one node
    {
        struct nodeS<T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL <T> :: InsertAtPos(T no, int ipos)
{
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeS<T> * newn = new struct nodeS<T>;

        newn->data = no;
        newn->next = NULL;

        struct nodeS<T> * temp = First;
        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL <T> :: DeleteFirst()
{
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct nodeS<T> * temp = First;
        First = First -> next;
        delete temp;
        iCount--;
    }
}

template <class T>
void SinglyLL <T> :: DeleteLast()
{    
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct nodeS<T> * temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

        iCount--;
    }
}

template <class T>
void SinglyLL <T> :: DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T> * temp1 = First;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        struct nodeS<T> * temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}


template <class T>
void SinglyLL <T> :: Display()
{
    struct nodeS<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp -> next;
    }
    cout<<" NULL"<<"\n";
}

template <class T>
int SinglyLL <T> :: Count()
{
    struct nodeS<T> * temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    return iCnt;
}

// class for singly circular linkedlist

template <class T>
class SinglyCL
{
    public:
        struct nodeS<T> * First;
        struct nodeS<T> * Last;

        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};
template <class T>
SinglyCL <T> ::SinglyCL()
{
    First = NULL;
    Last = NULL;
}
template <class T>
void SinglyCL <T> ::InsertFirst(T no)
{
    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}
template <class T>
void SinglyCL <T> ::InsertLast(T no)
{
    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}
template <class T>
void SinglyCL <T> ::Display()
{
    struct nodeS<T> * temp = First;

    cout<<"Elements of Linked list are : "<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}
template <class T>
int SinglyCL <T> ::Count()
{
    struct nodeS<T> * temp = First;

    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}
template <class T>
void SinglyCL <T> ::DeleteFirst()
{
    struct nodeS<T> * temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node in LL
    {
        //free(*First);
        delete First;

        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1 node
    {
        First = (First)->next;
        //free(temp);
        delete temp;

        (Last) ->next = First;
    }
}
template <class T>
void SinglyCL <T> ::DeleteLast()
{
    struct nodeS<T> * temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node in LL
    { 
        delete First;

        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1 node
    {
        while(temp->next != (Last))
        {
            temp = temp -> next;
        }

        delete temp->next;

        Last = temp; 
        (Last) ->next = First;
    }
}
template <class T>
void SinglyCL <T> ::InsertAtPos(T no, int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct nodeS<T> * newn = NULL;
    struct nodeS<T> * temp = First;

    if((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct nodeS<T>;

        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}
template <class T>
void SinglyCL <T> ::DeleteAtPos(int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct nodeS<T> * temp1 = First;
    struct nodeS<T> * temp2 = NULL;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }   
        temp2 = temp1 ->next;

        temp1->next = temp2->next;
        delete temp2;
    }
}

//class for doubly linear linkedlist


template <class T>
class DoublyLL
{
    public:
        struct nodeD<T> * First;
        struct nodeD<T> * Last;

        DoublyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

template <class T>
DoublyLL <T> :: DoublyLL()  // Default constructor
{
    First = NULL;
    Last = NULL;
}
template <class T>
void DoublyLL <T> :: InsertFirst(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn; 
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template <class T>
void DoublyLL <T> :: InsertLast(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        (Last) -> next = newn;
        newn->prev = Last;
        Last = newn;
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template <class T>
void DoublyLL <T> :: Display()
{
    struct nodeD<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked list are : "<<"\n";
    do
    {
        cout<<"| " <<temp->data<<"|<=> ";
        temp = temp -> next;
    }while(temp != Last->next);

    cout<<" NULL"<<"\n";
}

template <class T>
int DoublyLL <T> :: Count()
{
    int iCnt = 0;
    struct nodeD<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);

    return iCnt;
}

template <class T>
void DoublyLL <T> :: DeleteFirst()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        (First) = (First) ->next;
        delete (Last)->next;        // free((*First)->prev);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template <class T>
void DoublyLL <T> :: DeleteLast()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        Last = (Last) -> prev;
        delete (First)->prev;       // free((*Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template <class T>
void DoublyLL <T> :: InsertAtPos(T no, int ipos)
{
    int iNodeCnt = Count();
    struct nodeD<T> * newn = NULL;
    struct nodeD<T> * temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct nodeD<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

template <class T>
void DoublyLL <T> :: DeleteAtPos(int ipos)
{
    int iNodeCnt = Count();
    struct nodeD<T> * temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt <(ipos-1); iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}

//class for doubly circular linkedlist

template <class T>
class DoublyCL
{
    public:
        struct nodeD<T> * First;
        struct nodeD<T> * Last;

        DoublyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

template <class T>
DoublyCL <T> :: DoublyCL()  // Default constructor
{
    First = NULL;
    Last = NULL;
}
template <class T>
void DoublyCL <T> :: InsertFirst(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn; 
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template <class T>
void DoublyCL <T> :: InsertLast(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        (Last) -> next = newn;
        newn->prev = Last;
        Last = newn;
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template <class T>
void DoublyCL <T> :: Display()
{
    struct nodeD<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked list are : "<<"\n";
    do
    {
        cout<<"| " <<temp->data<<"|<=> ";
        temp = temp -> next;
    }while(temp != Last->next);

    cout<<"\n";
}

template <class T>
int DoublyCL <T> :: Count()
{
    int iCnt = 0;
    struct nodeD<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);

    return iCnt;
}

template <class T>
void DoublyCL <T> :: DeleteFirst()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        (First) = (First) ->next;
        delete (Last)->next;        // free((*First)->prev);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template <class T>
void DoublyCL <T> :: DeleteLast()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        Last = (Last) -> prev;
        delete (First)->prev;       // free((*Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template <class T>
void DoublyCL <T> :: InsertAtPos(T no, int ipos)
{
    int iNodeCnt = Count();
    struct nodeD<T> * newn = NULL;
    struct nodeD<T> * temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct nodeD<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

template <class T>
void DoublyCL <T> :: DeleteAtPos(int ipos)
{
    int iNodeCnt = Count();
    struct nodeD<T> * temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}

//class for stack

template<class T>
class Stack
{
    public:
    struct nodeS<T> *First;
    int iCount;

    Stack();

    bool IsStackEmpty();
    void Push(T no);       //Insert
    T Pop();               //Delete
    void Display();
};

template<class T>
Stack <T> :: Stack()
{
    First = NULL;
    iCount = 0;
}

template<class T>
bool Stack <T> :: IsStackEmpty()
{
if(iCount == 0)
{
    return true;
}
else
{
    return false;
}
}

template <class T>
void Stack <T> :: Push(T no)    //InsertFirst
{
    struct nodeS<T> *newn = new nodeS<T>;

    newn->data = no;
    newn->next = NULL;
    
    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
    cout<<no<<"gets pushed in the stack successfully"<<"\n";

}

template<class T>

T Stack <T> :: Pop()            //DeleteFirst
{
    if(First == NULL)
    {
        cout<<"Unable to pop the element as Stack is empty."<<"\n";
        return -1;
    }
    else
    {
        T value = First->data;
        struct nodeS<T> *temp = First;

        First = First->next;
        delete temp;
        cout<<temp->data<<"deleted sucessfully"<<"\n";
        iCount--;
        return value;

    }
} 
template<class T>

void Stack <T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is empty."<<"\n";
    }
    else
    {
        cout<<"Elements of stack are :"<<"\n";

        struct nodeS<T> *temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |->";
            temp = temp->next;
        }
        cout<<" NULL"<<"\n";
    }
}
 
// class for queue

template <class T>
class Queue
{
    public:
    struct nodeS<T> *First;
    int iCount;

    Queue();

    bool IsQueueEmpty();
    void EnQueue(T no);       //Insert
    T DeQueue();               //Delete
    void Display();
};

template <class T>
Queue <T> :: Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
bool Queue <T> :: IsQueueEmpty()
{
if(iCount == 0)
{
    return true;
}
else
{
    return false;
}
}

template <class T>
void Queue <T> :: EnQueue(T no)    //InsertLast
{
    struct nodeS<T> *newn = new nodeS<T>;

    newn->data = no;
    newn->next = NULL;
    
    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeS<T> *temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
    cout<<no<<"gets pushed in the stack successfully"<<"\n";

}

template <class T>
T Queue <T> :: DeQueue()            //DeleteFirst
{
    if(First == NULL)
    {
        cout<<"Unable to pop the element as Stack is empty."<<"\n";
        return -1;
    }
    else
    {
        int value = First->data;
        struct nodeS<T> *temp = First;

        First = First->next;
        delete temp;
        iCount--;
        return value;

    }
} 

template <class T>
void Queue <T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is empty."<<"\n";
    }
    else
    {
        cout<<"Elements of stack are :"<<"\n";

        struct nodeS<T> *temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |->";
            temp = temp->next;
        }
        cout<<" NULL"<<"\n";
    }
}

int main()
{
    int iRet = 0;
    cout<<"-----------------------------------------SINGLY LINEAR LINKEDLIST-----------------------------------------"<<"\n";
    SinglyLL <int> iobj;
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);
    iobj.InsertAtPos(7,2);
    iobj.DeleteFirst();
iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    cout<<"__________________________________________________________________________________________________________"<<"\n";

    cout<<"-----------------------------------------DOUBLY LINEAR LINKEDLIST-----------------------------------------"<<"\n";
    DoublyLL <char> dobj;
    dobj.InsertFirst('e');
    dobj.InsertFirst('d');
    dobj.InsertFirst('c');
    dobj.InsertFirst('b');
    dobj.InsertFirst('a');
    dobj.InsertAtPos('x',3);
    dobj.DeleteLast();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    cout<<"__________________________________________________________________________________________________________"<<"\n";

    cout<<"-------------------------------------------SINGLY CIRCULAR LINKEDLIST-------------------------------------"<<"\n";
  
    SinglyCL <int> scobj;
    scobj.InsertFirst(51);
    scobj.InsertFirst(31);
    scobj.InsertFirst(21);
    scobj.InsertFirst(11);
    scobj.InsertFirst(1);
    scobj.InsertAtPos(41,5);
    scobj.DeleteAtPos(3);
    scobj.Display();
    iRet = scobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    cout<<"__________________________________________________________________________________________________________"<<"\n";

    cout<<"-------------------------------------------DOUBLY CIRCULAR LINKEDLIST-------------------------------------"<<"\n";
  
    DoublyCL <char> dcobj;
    dcobj.InsertFirst('h');
    dcobj.InsertFirst('g');
    dcobj.InsertFirst('f');
    dcobj.InsertFirst('e');
    dcobj.InsertFirst('d');
    dcobj.InsertAtPos('z',4);
    dcobj.DeleteAtPos(2);
    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    cout<<"__________________________________________________________________________________________________________"<<"\n";

    cout<<"-----------------------------------------------------STACK------------------------------------------------"<<"\n";
  
    Stack <int> sobj;
    sobj.Push(10);
    sobj.Push(20);
    sobj.Push(30);
    sobj.Push(40);
    sobj.Push(50);
    sobj.Pop();
    sobj.Display();
    cout<<"__________________________________________________________________________________________________________"<<"\n";

    cout<<"-----------------------------------------------------QUEUE------------------------------------------------"<<"\n";
  
    Queue <int>qobj;
    qobj.EnQueue(11);
    qobj.EnQueue(21);
    qobj.EnQueue(51);
    qobj.EnQueue(101);
    qobj.Display();
    iRet = qobj.DeQueue();
    cout<<"poped element is :"<<iRet<<"\n";
    iRet = qobj.DeQueue();
    cout<<"poped element is :"<<iRet<<"\n";
    qobj.Display();
        cout<<"__________________________________________________________________________________________________________"<<"\n";


    return 0;
}