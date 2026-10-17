#include <bits/stdc++.h>

using namespace std;
#define ll long long

class Array
{
private:
  int size;
  int length;
  int *items;

public:
  Array(int arrsize)
  {
    size = arrsize;
    length = 0;
    items = new int[arrsize];
  }

  void Fill()
  {

    int no_of_items;
    cout << "How many items you want to fill ? \n";
    cin >> no_of_items;
    if (no_of_items > size)
    {
      cout << "you cannot exceed the array size \n";
      return;
    }
    else
    {
      for (int i = 0; i < no_of_items; i++)
      {
        cout << "Enter item no " << i << '\n';
        cin >> items[i];
        length++;
      }
    }
  }

  void Display()
  {
    cout << "Display array content \n";
    for (int i = 0; i < length; i++)
    {
      cout << items[i] << "\t";
    }
    cout << '\n';
  }

  int getSize()
  {
    return size;
  }

  int getLength()
  {
    return length;
  }

  int Search(int key)
  {
    for (int i = 0; i < length; i++)
    {
      if (key == items[i])
      {
        return i;
      }
    }
    return -1;
  }

  void Append(int newItem)
  {
    if (size > length)
    {

      items[length] = newItem;
      length++;
    }
    else
      cout << "Array is full\n";
  }

  void Insert(int index, int newitem)
  {
    if (index >= 0 && index < length)
    {

      //  we will sift array to right to insert
      for (int i = length; i >= 0; i--)
      {
        if (i == index)
        {
          items[i] = newitem;
          break;
        }
        items[i] = items[i - 1];
      }
      length++;
    }
    else
      cout << "index out of range \n";
  }

  void Delete(int index)
  {
    if (index >= 0 && index < length)
    {
      //  we will sift array to left to delete
      for (int i = index; i < length - 1; i++)
      {
        items[i] = items[i + 1];
      }

      length--;
    }
    else
      cout << "Index out of range \n";
  }

  void Enlarge(int newsize)
  {
    // this method resize to be bigger    (newsize > size )
    if (newsize <= size)
    {
      cout << "New size must be larger thn current size \n";
      return;
    }
    else
    {

      size = newsize;
      int *old = items;
      items = new int[newsize];

      for (int i = 0; i < length; i++)
      {
        items[i] = old[i];
      }
      delete[] old;
    }
  }

  void Merge(Array other)
  {
    // Mrege two array

    int newsize = size + other.getSize();
    size = newsize;
    int *old = items;
    items = new int[size];
    int i;
    for (i = 0; i < length; i++)
    {
      items[i] = old[i];
    }
    delete[] old;
    int j = i;
    for (i = 0; i < other.getLength(); i++)
    {

      items[j++] = other.items[i];
      length++;
    }
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);

  cout << "Hello this is array ADT demo \n";
  int arraysize;
  cout << "Enter the Array size \n";
  cin >> arraysize;

  Array myarray(arraysize);
  myarray.Fill();
  myarray.Display();

  cout << "Array size = " << myarray.getSize() << " while length = " << myarray.getLength() << '\n';

  int index;
  int newitem;

  cout << "Enter the valye to search for \n";
  int Key;
  cin >> Key;
  index = myarray.Search(Key);

  if (index == -1)
    cout << "Item not founded  \n";
  else
    cout << "Item found @ position " << index << '\n';

  cout << "Enter newItem to the Array \n";

  cin >> newitem;
  myarray.Append(newitem);
  myarray.Display();

  cout << "Insert newitem to the array \n";
  cout << " Enter index to newitem \n";

  cin >> index;
  cout << "Enter the newitem \n";

  cin >> newitem;
  myarray.Insert(index, newitem);
  myarray.Display();
  cout << "Array size = " << myarray.getSize() << " while length = " << myarray.getLength() << '\n';

  cout << "Enter index to delet it \n";
  cin >> index;
  myarray.Delete(index);
  myarray.Display();
  cout << "Array size = " << myarray.getSize() << " while length = " << myarray.getLength() << '\n';
  int newsize;
  cout << "Enter new size \n";
  cin >> newsize;
  myarray.Enlarge(newsize);
  cout << "Array size = " << myarray.getSize() << " while length = " << myarray.getLength() << '\n';
  myarray.Display();

  Array other(3);
  other.Fill();
  myarray.Merge(other);
  cout << "Array size = " << myarray.getSize() << " while length = " << myarray.getLength() << '\n';
  myarray.Display();
  return 0;
}