#include "Sequence.hpp"
#include "ArraySequence.hpp"
using namespace std;
template <class T,class V>
struct TableElement
{
    T key;
    V value;
    bool isUsed;
    bool isDeleted;
};
template<class T,class V>
class Dictionary
{
private:
    Sequence<TableElement<T,V>>* data;
    int size;
    int HashFunction(T key)
    {
        int h = hash<T>()(key);
        if(h < 0)
            h*=-1;
        h = h%this->size;
        return h;
    }
    V& Get(T key)
    {
        if(!this->IsEmpty(HashFunction(key)))
            return this->data->Get(HashFunction(key)).value;
    }
    void AddInside(TableElement<T,V> element, int index)
    {
        if(this->IsEmpty(index))
        {
            this->data->Set(element,index);
            return;
        }
        if(!this->IsEmpty(index) && this->data->Get(index).key == element.key)
        {
            this->data->Set(element,index);
            return;
        }
        if(this->GetSize() - index > 1)
        {
            AddInside(element,index+1);
            return;
        }
        if(this->GetSize() - index == 1)
        {
            AddInside(element,0);
            return;
        }

    }
    void Resize()
    {
        int newSize;
        if(this->size == 0)
            newSize = 10;
        else newSize = this->size * 10;
        Sequence<TableElement<T,V>>* newSequence = new ArraySequence<TableElement<T,V>>(newSize);
        this->size = newSize;
        for(int i = 0; i < this->data->GetLength(); i++)
        {
            if(!this->IsEmpty(i))
            {
                newSequence->Set(this->data->Get(i),this->HashFunction(this->data->Get(i).key));
            }
        }
        this->data = newSequence;
    }
public:
    V& operator [](T key)
    {
        return this->Get(key);
    }
    Dictionary()
    {
        this->size = 0;
        this->data = new ArraySequence<TableElement<T,V>>(0);
    }
    const int& GetSize()
    {
        return this->size;
    }
    int GetValuesCount()
    {
        int count = 0;
        for(int i = 0; i < this->GetSize(); i++)
        {
            if(!IsEmpty(i))
                count++;
        }
        return count;
    }
    bool IsEmpty(int index)
    {
        if(this->data->Get(index).isDeleted)
            return true;
        if(!this->data->Get(index).isUsed)
            return true;
        return false;
    }
    void Add(T key,V value)
    {
        TableElement<T,V> element;
        element.key = key;
        element.value = value;
        element.isUsed = true;
        element.isDeleted = false;
        if(this->size == 0)
            this->Resize();
        if(this->GetSize()*0.5 < this->GetValuesCount())
            this->Resize();
        this->AddInside(element,this->HashFunction(key));
    }
    void Delete(T key)
    {
        TableElement<T,V> element;
        element.key = key;
        element.value = this->Get(key);
        element.isUsed = true;
        element.isDeleted = true;
        this->data->Set(element,HashFunction(key));
    }
    void Print()
    {
        for(int i = 0; i < this->size;i++)
        {
            cout << i<<" key = "<< this->data->Get(i).key<< "           value = " <<this->data->Get(i).value << " used = " <<this->data->Get(i).isUsed << " deleted = " <<this->data->Get(i).isDeleted << endl;
            cout<<endl;
        }
    }
};