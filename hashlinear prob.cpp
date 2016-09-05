#include<iostream>
using namespace std;
class hashtable
{
public:
    int *table;
    int tablesize;
    int hashcode;
    int element;
    hashtable();
    void get_size();
    int calculate_code(int element);
    void insert();
    void display();
};
hashtable::hashtable()
{
    table=new int[tablesize];
    for(int i=0;i<tablesize;i++)
    {
        table[i]=0;
    }
    tablesize=0;
    hashcode=0;
    element=0;
}
void hashtable :: get_size()
{
    cout<<"enter size of the hashtable";
    cin>>tablesize;
}
int hashtable ::calculate_code(int element)
{
    hashcode=element%tablesize;
    return hashcode;
}
void hashtable :: insert()
{
    cout<<"Enter the element";
    cin>>element;
    int hashvalue=calculate_code(element);
    if(table[hashvalue]==0)
    {
        table[hashvalue]=element;
    }
    else
    {
        int i=0;
        while(i<hashvalue+tablesize)
        {
            int temp=(hashvalue+i)%tablesize;
            if(table[temp]==0)
            {
                table[temp]=element;
                break;
            }
            else
            {
                i++;
            }
        }
    }
}
void hashtable :: display()
{
    for (int i=0;i<tablesize;i++)
    {
        cout<<table[i]<<"\t";
    }
    cout<<"\n";
}
int main(void)
{
    hashtable H;
    H.get_size();
    H.insert();
    H.insert();
    H.insert();
    H.insert();
    H.display();
}
