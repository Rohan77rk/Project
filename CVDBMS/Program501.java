import java.util.*;

class Student
{
    public String Sname;
    public int Marks;
    public int Rollno;

    public static int Generator;

    static
    {
        Generator = 0;
    }

    public Student(String str, int no)
    {
        this.Sname = str;
        this.Marks = no;
        Generator++;
        this.Rollno = Generator;
    }
    public void Display()
    {
        System.out.println("Roll No : "+Rollno+"  Name : "+Sname+" Marks : "+Marks);
    }
}

class DBMS
{
    public LinkedList <Student> lobj;

    public DBMS()
    {
        lobj = new LinkedList();
    }

    public void StartDBMS()
    {
        System.out.println("Marvellous Customised DBMS started sucessfully...");

        Scanner sobj = new Scanner(System.in);
        String Query = " ";
        int QuerySize = 0;

        while(true)
        {
            System.out.print("Marvellous DBMS :>");

            Query = sobj.nextLine();

            String Tokens[] = Query.split(" ");
            QuerySize = Tokens.length;

            if(QuerySize == 1)
            {
                if("help".equals(Tokens[0]))
                {
                    System.out.println("This Application is used to demonstrate the features of customised dbms.");
                    System.out.println("Display all data : select * from student");
                    System.out.println("Insert new record : insert into student values Name Marks");
                    System.out.println("Display Specific record : select * from student where name/rollno = value");
                    System.out.println("Delete Record : delete from student where rollno/name = value");
                    System.out.println("Sum : select sum (marks) from student");
                    System.out.println("Average : select avg (marks) from student");
                    System.out.println("Minimum marks : select min (marks) from student");
                    System.out.println("Maximum marks : select max (marks) from student");
                    System.out.println("Count total number of records : select count (marks) from student");
                    System.out.println("Update :update student set marks = int where name = string");
                    System.out.println("Between :select * from student where name between minimum_marks to maximum_marks");
                    System.out.println("Terminate the project : exit");
                    
                    //add more
                }
                else if("exit".equals(Tokens[0]))
                    {
                        System.out.println("Thank you for using our customised DBMS.");
                        break;
                    }
                    
                }
                else if(QuerySize == 2)
                {

                }
                 else if(QuerySize == 3)
                {
                    
                }
                 else if(QuerySize == 4)
                {
                    if("select".equals(Tokens[0]))
                    {
                        if("*".equals(Tokens[1]))
                        {
                            DisplayAll();
                        }
                    }
                }
                else if (QuerySize == 5)
                {
                    if("select".equals(Tokens[0]))
                    {
                        if("sum".equals(Tokens[1]))
                        {
                            if("(marks)".equals(Tokens[2]))
                            {
                                if("student".equals(Tokens[4]))
                                {
                                    Sum();
                                }
                                
                            }
                        
                        }
                        else if("avg".equals(Tokens[1]))
                        {
                            if("(marks)".equals(Tokens[2]))
                            {
                                if("student".equals(Tokens[4]))
                                {
                                    Avg();
                                }
                                
                            }
                        
                        } 
                         else if("min".equals(Tokens[1]))
                        {
                            if("(marks)".equals(Tokens[2]))
                            {
                                if("student".equals(Tokens[4]))
                                {
                                    Min();
                                }
                                
                            }
                        
                        }
                        else if("max".equals(Tokens[1]))
                        {
                            if("(marks)".equals(Tokens[2]))
                            {
                                if("student".equals(Tokens[4]))
                                {
                                    Max();
                                }
                                
                            }
                        
                        }
                        else if("count".equals(Tokens[1]))
                        {
                            if("(marks)".equals(Tokens[2]))
                            {
                                if("student".equals(Tokens[4]))
                                {
                                    Count();
                                }
                                
                            }
                        
                        }
                    }
                }
                 else if(QuerySize == 6)
                {
                    if("insert".equals(Tokens[0]))
                    {
                        if("student".equals(Tokens[2]))
                        {
                            Insert(Tokens[4],Integer.parseInt(Tokens[5]));
                        }
                    }
                }
                else if(QuerySize == 7)
                {
                    if("delete".equals(Tokens[0]))
                    {
                        if("student".equals(Tokens[2]))
                        {
                            if("where".equals(Tokens[3]))
                            {
                                if("rollno".equals(Tokens[4]))
                                {
                                    Delete(Integer.parseInt(Tokens[6]));
                                }
                                else if("name".equals(Tokens[4]))
                                {
                                    Delete(Tokens[6]);
                                }
                            }
                        }
                    }
                }
                else if(QuerySize == 8)
                {
                    if("select".equals(Tokens[0]))
                    {
                        if("*".equals(Tokens[1]))
                        {
                            if("student".equals(Tokens[3]))
                            {
                                if("where".equals(Tokens[4]))
                                {
                                    if("rollno".equals(Tokens[5]))
                                    {
                                        DisplaySpecific(Integer.parseInt(Tokens[7]));
                                    }
                                    else if("name".equals(Tokens[5]))
                                    {
                                        DisplaySpecific(Tokens[7]);
                                    }
                                }
                            }
                        }
                    }
                    
                    
                }
                else if(QuerySize == 9)
                {
                    if("select".equals(Tokens[0]))
                    {
                        if("*".equals(Tokens[1]))
                        {
                            if("student".equals(Tokens[3]))
                            {
                                if("where".equals(Tokens[4]))
                                {
                                    if("name".equals(Tokens[5]))
                                    {
                                        if("like".equals(Tokens[6]))
                                        {
                                            if("%".equals(Tokens[7]))
                                            {

                                            LikeLast(Tokens[8]);
                                            }
                                            else if("%".equals(Tokens[8]))
                                            {
                                                Like(Tokens[7]);
                                            }
                                        }
                                    }
                                }
                            }
                            
                        }
                    }
                }
                else if(QuerySize == 10)
                {
                    if("update".equals(Tokens[0]))
                    {
                        if("student".equals(Tokens[1]))
                        {
                            if("marks".equals(Tokens[3]))
                            {
                                if("name".equals(Tokens[7]))
                                {
                                    Update(Tokens[9],Integer.parseInt(Tokens[5]));
                                }
                                else if("rollno".equals(Tokens[7]))
                                {
                                    Update(Integer.parseInt(Tokens[9]),Integer.parseInt(Tokens[5]));
                                }
                            }
                        }
                    }
                    else if("select".equals(Tokens[0]))
                    {
                        if("*".equals(Tokens[1]))
                        {
                            if("student".equals(Tokens[3]))
                            {
                                if("where".equals(Tokens[4]))
                                {
                                    if("marks".equals(Tokens[5]))
                                    {
                                        if("between".equals(Tokens[6]))
                                        {
                                            Between(Integer.parseInt(Tokens[7]),Integer.parseInt(Tokens[9]));
                                        }
                                    }
                                }
                            }
                            
                        }
                    }
                }
            }
        }//end of while
    //endof start DBMS

    // All SQL queries should be implemented here

    //insert into student values(_________,___________);
    public void Insert(String str, int no)
    {
        Student sobj = new Student(str,no);
        lobj.add(sobj);
    }
    // select * from student;
    public void DisplayAll()
    {
        for(Student sref : lobj)
        {
            sref.Display();
        }
    }

    //Select * from student where rollno = 3
    public void DisplaySpecific(int Value)
    {
        for(Student sref : lobj)
        {
            if(sref.Rollno == Value)
            {
                System.out.println();
                sref.Display();
                break;
            }
        }
    }

    //Select * from student where Name = 'Rutuja';
    public void DisplaySpecific(String str)
    {
        for(Student sref : lobj)
        {
            if(str.equals(sref.Sname))
            {
                System.out.println();
                sref.Display();
                break;
            }
        }
    }

    //delete from student where Rollno = 3;
    public void Delete(int no)
    {
        int index = 0;

        for(Student sref : lobj)
        {
            if(sref.Rollno == no)
            {
                lobj.remove(index);
                break;
            }
            index++;
        }
    }

    //delete from student where Sname = 'Ram';
    public void Delete(String str)
    {
        int index = 0;

        for(Student sref : lobj)
        {
            if(str.equals(sref.Sname))
            {
                lobj.remove(index);
                break;
            }
            index++;
        }
    }

    public void Sum()
    {
        int iSum = 0;
        for(Student sref : lobj)
        {
            iSum = iSum +(sref.Marks);
        }

        System.out.println("Sum of marks : "+iSum);
    }

    public void Avg()
    {
        int iSum = 0;
        for(Student sref : lobj)
        {
            iSum = iSum +(sref.Marks);
        }

        System.out.println("Average of marks : "+(iSum / lobj.size()));
    }

    public void Max()
    {
        int iMax = 0;
        for(Student sref : lobj)
        {
            if(iMax < sref.Marks)
            {
                iMax = sref.Marks;
            }

        }
            System.out.println("Maximum marks are :"+iMax);
    }

    public void Min()
    {
        Student s = lobj.get(0);
        int iMin = s.Marks;
        for(Student sref : lobj)
        {
            if(iMin > sref.Marks)
            {
                iMin = sref.Marks;
            }

        }
            System.out.println("Minimum marks are :"+iMin);
    }

    public void Count()
    {
        int iCnt = 0;
        for(Student sref : lobj)
        {
            iCnt++;
        }

    System.out.println("Total numbers of records :"+iCnt);
    }

    public void Update(String str,int no)
    {
        

        for(Student sref: lobj)
        {
        if(str.equals(sref.Sname))
        {
            sref.Marks = no;
            break;
        }
    
        
        }
    }

    public void Update(int no1,int no2)
    {
        

        for(Student sref: lobj)
        {
        if(no1 == sref.Rollno)
        {
        
            sref.Rollno = no1;
            sref.Marks = no2;
        }
        }
    }

    public void Like(String str)
    {
    
    for(Student sref : lobj)
    {
        String temp = sref.Sname;
        
        
        
        if(temp.charAt(0) == str.charAt(0))
        {
            
            // sref.Display();
            DisplaySpecific(temp);
        }
    }
    }
    

    public void LikeLast(String str)
    {
        for(Student sref : lobj)
    {
        String temp = sref.Sname;
    
        if((temp.charAt(temp.length()-1)) == str.charAt(0))
        {

                DisplaySpecific(temp);
        }

    }
        
    }
    

    public void Between(int no1,int no2)
    {
        for(Student sref : lobj)
        {
            if((sref.Marks >= no1) && (sref.Marks <= no2))
            {

            sref.Display();
            }
        }
    }
}

class Program501
{
    public static void main(String Arg[])
    {
        DBMS dobj = new DBMS();

        dobj.StartDBMS();

        
 
    }
}