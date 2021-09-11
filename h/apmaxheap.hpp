template<class T>
APMaxHeap<T>::APMaxHeap()
{
    arr={};
}

template<class T>
APMaxHeap<T>::APMaxHeap(const APMaxHeap<T> &h)
{
    arr.clear();
    for(size_t i{};i<h.arr.size();i++)
    {
        std::cout << "coping\n";
        T *arri{new T[1]};
        arri[0]=*h.arr[i];
        arr.push_back(&arri[0]);
    }  
}

template<class T>
APMaxHeap<T>::~APMaxHeap()
{
    arr.clear();
    for (size_t i{};i<arr.size();i++)
    {
        delete[] arr[i];
    }    
}

template<class T>
APMaxHeap<T>& APMaxHeap<T>::push(T elem)
{
    std::cout << arr.size() << " " << elem << " " << &elem << " before\n";
    
    T *arri{new T[1]};
    arri[0]=elem;
    arr.push_back(&arri[0]);
    ind = arr.size();

    std::cout << arr.size() << " after\n";
    
    if(arr.size()>1)
    {
        std::cout << arr.size() << " " << ind << " " << ind/2 << " size value\n";
        while(ind>1)
        {
            std::cout << ind << " i1 value\n";
            if(*arr[ind/2-1]<*arr[ind-1])
            {
                std::cout << *arr[ind/2-1];
                std::swap(arr[ind/2-1],arr[ind-1]); 
                std::cout << *arr[ind/2-1];
            }
            ind = ind/2;
            std::cout << ind << " i value\n";
        }     
    }
    return *this;    
}

template<class T>
APMaxHeap<T>& APMaxHeap<T>::pop()
{
    /* if you swap by the value any changes on copy object will change the main object too, so swap by address
    std::swap(*arr[0],*arr[arr.size()-1]);
    */
    std::swap(arr[0],arr[arr.size()-1]);

    arr.pop_back();
    std::cout << arr.size() << " " << *arr[0] << " " << *arr[1] << " out if\n";

    ind = 1;
    popMax(ind);

    return *this;    
}

template<class T>
void APMaxHeap<T>::popMax(size_t ind)
{
    bool l = 1;
    bool r = 1;
    if(2*ind>arr.size())
    {
        std::cout << "no child\n";
        // r = 0;
        // l = 0;
        return;
    }
    else if(2*ind+1>arr.size())
    {
        std::cout << 2*ind+1 << " " << arr.size() << " no right\n";
        r=0;            
    }

    if (r && l)
    {
        std::cout << "in-if\n";
        if( (*arr[2*ind-1] < *arr[ind-1] ) && (*arr[2*ind+1-1] < *arr[ind-1]) )
        {
            // std::cout << "no change\n";
            return;
        }
        else if((*arr[ind-1]<*arr[2*ind-1] && *arr[2*ind-1]<*arr[2*ind+1-1]) || (*arr[ind-1]<*arr[2*ind+1-1] && *arr[2*ind-1]<*arr[2*ind+1-1]))
        {
            std::cout << "swap right\n";
            std::swap(arr[ind-1],arr[2*ind+1-1]);
            popMax(2*ind+1);            
        }
        else if((*arr[ind-1]<*arr[2*ind+1-1] && *arr[2*ind+1-1]<*arr[2*ind-1]) || (*arr[ind-1]<*arr[2*ind-1] && *arr[2*ind+1-1]<*arr[2*ind-1]))
        {
            std::cout << "swap left\n";
            std::swap(arr[ind-1],arr[2*ind-1]);
            popMax(2*ind);
        }
    }
    else if (l)
    {
        if(*arr[ind-1] < *arr[2*ind-1])
        {
            std::cout << "swap left no right\n";
            std::swap(arr[ind-1],arr[2*ind-1]);
        }
    }
}

template<class T>
std::vector<T> APMaxHeap<T>::show()
{
    arr_sh.clear();
    std::cout << "APMaxHEAP:\n" ;
    for (size_t i{};i<arr.size();i++)
    {
        std::cout << *arr[i] << ", ";
        arr_sh.push_back(*arr[i]);
    }
    std::cout << std::endl;
    return arr_sh;
}

template<class T>
int APMaxHeap<T>::operator[](size_t ind)
{
    return *arr[ind-1];
}

template<class T>
APMaxHeap<T> APMaxHeap<T>::operator+(T elem)
{
    APMaxHeap<T> h = *this;
    h.push(elem);
    return h;
}

