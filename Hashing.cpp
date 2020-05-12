#include<iostream>
using namespace std;
class Student
{
private:
        int RollNo;
        string Name;
        double PhoneNo;
public:
        Student(int RollNo,string Name,double PhoneNo)
        {
            this->RollNo=RollNo;
            this->Name=Name;
            this->PhoneNo=PhoneNo;
        }
};
class Hashing
{
private:
        Student* Arr[10];
        int i;
public:
        Hashing()
        {
            i=0;
            Arr[10]={0};
        }
        int HashFunction(int key)
        {
            return (key%10);
        }
        void HashTable(int RollNo,string Name,double PhoneNo)
        {

        }
        void Mapping()
        {
            cout<<"Enter the Roll NO and name and Phone No"<<endl;
            int Rollno;
            string name;
            double phoneno;
            cin>>Rollno>>name>>phoneno;
            HashTable(Rollno,name,phoneno);
        }
};
