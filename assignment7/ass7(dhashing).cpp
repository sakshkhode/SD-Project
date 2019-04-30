//NAME:SAKSHI KHODE  ROLL NO:223031  BATCH:C2

//Insert the keys into a hash table of length m using open addressing using double hashing with h(k)=1+(k mod(m-1)).
#include<iostream>
using namespace std;
struct hashtable
{
    int key;
    string value;
}arr[10];
void insert(int occupied[10])
{
    int index,size=10,i,j;
    int key;
    string value;
    cout<<"Enter key:";
    cin>>key;
    cout<<"Enter value:";
    cin>>value;
    for(j=0;j<size;j++)
    {

    index=key%size;++++
   // cout<<index;
    if(occupied[index]==0)
    {
        arr[index].key=key;
        arr[index].value=value;
        occupied[index]=1;
       // cout<<occupied[index];
        break;
    }
    else
    {
        for(i=1;i<size;i++)
        {
          int index1=7-(key %7);

          if(occupied[index1]==0)
          {
              arr[index1].key=key;
              arr[index1].value=value;
              occupied[index]=1;
              break;
          }
        }

    }
    }
}
void display()
{
    for(int i=0;i<10;i++)
    {

        cout<<i<<" Key:"<<arr[i].key<<endl;
        cout<<" Value:"<<arr[i].value<<endl;
    }
}
void search()
{
    int search,i;
    cout<<"Enter the key to be searched:";
    cin>>search;
    for(i=0;i<10;i++)
    {
        if(search==arr[i].key)
        {
            cout<<"For key "<<arr[i].key<<" value is :"<<arr[i].value;
        }
    }
}
int main()
{
  int ch,occupied[10]={0};
  char choice='y';
  while(choice=='y')
  {
  cout<<"\tMENU"<<endl;
  cout<<"\t1.Insert"<<endl;
  cout<<"\t2.Display"<<endl;
  cin>>ch;
  switch(ch)
  {
  case 1:
    insert(occupied);
    break;
    case 2:
    display();
    break;
    default:
        cout<<"Invalid choice";
        break;
  }
  cout<<"\nDo you want to continue?";
  cin>>choice;

}
return 0;
}

