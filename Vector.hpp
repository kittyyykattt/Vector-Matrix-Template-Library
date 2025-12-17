
template <typename T>

    Vector<T>::Vector() : theSize(0), theCapacity(0), array(nullptr) {}

    template <typename T>
    Vector<T>::Vector(const Vector &rhs): theSize(rhs.theSize), theCapacity(rhs.theCapacity), array(nullptr)// copy constructor
        {   
            if(theCapacity > 0){
                array = new T[theCapacity];

                for(int i = 0; i < theSize; ++i)
                    array[i]  = rhs.array[i];
            }
        }

    template <typename T>
    Vector<T>::Vector(Vector &&rhs): theSize(rhs.theSize), theCapacity(rhs.theCapacity), array(rhs.array ){ // move constructor
    // num elements with value of val
    rhs.theSize = 0;
    rhs.theCapacity = 0;
    rhs.array = nullptr; 
}
    
    template <typename T>
    Vector<T>:: Vector(int num, const T& val): theSize(num < 0 ? 0 : num), theCapacity(num < 0 ? 0 : num), array(nullptr){
        if (theCapacity > 0){
            array = new T[theCapacity];
        for(int i = 0; i < theSize; ++i)
            array[i] = val;
    }
}
    
    // constructs with elements [start, end)
    template <typename T>
    Vector<T>::Vector(const_iterator start, const_iterator end): theSize(0), theCapacity(0), array(nullptr){
        int n = static_cast<int>(end - start);
        if(n < 0)
            n = 0;
        
        theSize = theCapacity = n;
        
        if(n > 0){
        array = new T[theCapacity];
        
        for(int i = 0; i < n; ++i)
            array[i] = start[i];
    }
}
    
    template <typename T>
    Vector<T>::~Vector(){ // destructor
        delete [] array;
        array = nullptr;
        theSize = theCapacity = 0;
    }


    // index operator
    template <typename T>
    T& Vector<T>::operator[](int index){
        return array[index];
    }
    
    template <typename T>
    const T& Vector<T>::operator[](int index) const{
        return array[index];
    }

    template <typename T>
    const Vector<T>& Vector<T>::operator=(const Vector &rhs){
        if(this != &rhs) {
            if(rhs.theSize <= theCapacity){
                for(int i = 0; i < rhs.theSize; ++i)
                    array[i] = rhs.array[i];
                
                theSize = rhs.theSize;
            }
            else{
                T* newArray = (rhs.theCapacity > 0 ? new T[rhs.theCapacity] : nullptr);
                for(int i = 0; i < rhs.theSize; ++i)
                    newArray[i] = rhs.array[i];
                
                delete [] array;
                array = newArray;
                theSize = rhs.theSize;
                theCapacity = rhs.theCapacity;
        }
    }
    return *this;
}


    // move assignment operator
    template <typename T>
    Vector<T> &Vector<T>::operator=(Vector &&rhs){
        if(this != &rhs){
            delete [] array; 
            array = rhs.array;
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            rhs.array = nullptr;
            rhs.theSize = 0;
            rhs.theCapacity = 0;
        }
        return *this;
    }

    template <typename T>
    T& Vector<T>::at(int loc ){
        if (loc < 0 || loc >= theSize) throw std::out_of_range("Vector::at out_of_range");
            return array[loc];
    }

    template <typename T>
    const T& Vector<T>::at(int loc ) const{
        if (loc < 0 || loc >= theSize) throw std::out_of_range("Vector::at out_of_range");
            return array[loc];
    }

    template <typename T>
    T& Vector<T>::front(){ // reference to the first element
        return array[0];
    }

    template <typename T>
    const T& Vector<T>::front() const{
        return array[0];
    }

    template <typename T>
    T& Vector<T>::back(){ // reference to the last element
        return(array[theSize -1]);
    }

    template <typename T>
    const T& Vector<T>::back() const{
        return (array[theSize -1]);
    }

    // accessor member functions
    template <typename T>
    int Vector<T>:: size() const{ // number of elements
        return theSize;
    }

    template <typename T>
    int Vector<T>::capacity() const{ // capacity of vector
        return theCapacity;
    }
    
    template <typename T>
    bool Vector<T>::empty() const{
        return theSize == 0;
    }// check if list is empty

    // mutator member functions
    template <typename T>
    void Vector<T>::clear(){
        theSize = 0;
    } // delete all elements
    
    template <typename T>
    void Vector<T>::push_back(const T & val){ // insert to the end
        if(theSize == theCapacity)
            doubleCapacity();

        array[theSize++] = val;
    }

    template <typename T>
    void Vector<T>::pop_back(){// delete last element
        if(theSize > 0)
            --theSize;
    }

    template <typename T>
    void Vector<T>::resize(int num, T val){ // resize vector
        if(num > theCapacity)
            reserve(num);

        if(num > theSize){
            for(int i = theSize; i < num; ++i)
                array[i] = val;
        }
        theSize = num;
    }

    template <typename T>
    void Vector<T>::reserve(int newCapacity){ // reserve memory
        if(newCapacity <= theCapacity)
            return;

        T *newArray = new T[newCapacity];

        for(int i = 0; i < theSize; ++i){
            newArray[i] = std::move(array[i]);
        }

        delete [] array;
        array = newArray;
        theCapacity = newCapacity;
    }

    // print out all elements. ofc is deliminitor
    template <typename T>
    void Vector<T>::print(std::ostream& os, char ofc) const{
        for(int i = 0; i < theSize; ++i){
            if(i) os << ofc;
                os << array[i];

        }
    }

    // iterator support
    template <typename T>
    typename Vector<T>::iterator Vector<T>::begin(){ // iterator to first element
    return array;
    }
    
    template <typename T>
    typename Vector<T>::const_iterator Vector<T>::begin() const{
        return array; 
    }
    
    template <typename T>
    typename Vector<T>::iterator Vector<T>::end(){
        return array + theSize; 
    }

    template <typename T>
    typename Vector<T>::const_iterator Vector<T>::end() const{
        return array + theSize; 
    }

    template <typename T>
    typename Vector<T>::iterator Vector<T>::insert(iterator itr, const T & val){ // insert val ahead of itr
        int index = static_cast<int>(itr - begin());

        if(index < 0 || index > theSize)
            index = theSize;
        
        if(theSize == theCapacity){
            int oldIndex = index;

            doubleCapacity();
            itr = begin() + oldIndex;
        }
        for(int i = theSize; i > index; --i){
            array[i] = std::move(array[i-1]);
        }
        array[index] = val; 
        ++theSize;

        return begin() + index;
    }

    template <typename T>
    typename Vector<T>::iterator Vector<T>::erase(iterator itr){
        int index = static_cast<int>(itr - begin());
        if(index < 0 || index >= theSize)
            return end();

        for(int i = index; i < theSize - 1; ++i)
            array[i] = std::move(array[i+1]);
        
        --theSize;
            
        return begin() + index;
}

    template <typename T>
    typename Vector<T>::iterator Vector<T>::erase(iterator start, iterator endItr){
        int star = static_cast<int>(start - begin());
        int en = static_cast<int>(endItr - begin());

        if(star < 0)
            star = 0;

        if(en > theSize)
            en = theSize;

        if(star >= en)
            return begin() + star;
        
        int diff = en - star;
        
        for(int i = star; i + diff < theSize; ++i)
            array[i] = std::move(array[i + diff]);
        
        theSize -= diff;
            
        return begin() + star;
}
    

    template <typename T>
    void Vector<T>::doubleCapacity(){
        int capacity = (theCapacity == 0) ? 1 : theCapacity *2;

        reserve(capacity);
    }


// overloading comparison operators
template <typename T>
bool operator==(const Vector<T> & lhs, const Vector<T> &rhs){
    if(lhs.size() != rhs.size()){
        return false;
    }
    for(int i = 0; i < lhs.size(); ++i)
        if(!(lhs[i] == rhs[i]))
            return false;
    return true;
}


template <typename T>
bool operator!=(const Vector<T> & lhs, const Vector<T> &rhs){
    return !(lhs == rhs); 
}

// overloading output operator
template <typename T>
std::ostream & operator<<(std::ostream &os, const Vector<T> &v){
    v.print(os);
    return os;
}


