#include <iostream>
#include <initializer_list>

class MyVector{
private:
	int *m_ptr;
	size_t m_size;
	size_t m_capacity;
public:
	MyVector() : m_ptr(nullptr), m_size(0), m_capacity(0){
	}

	MyVector(size_t size): MyVector(size, 0){
		}
	MyVector(size_t size, int val) : m_size(size), m_capacity(size){
		m_ptr = new int[m_capacity];
		for(int i = 0; i<size; ++i){
			m_ptr[i] = val;
		}
	}

	MyVector(const MyVector &other) : m_size(other.m_size), m_capacity(other.m_capacity){
		m_ptr = new int[other.m_capacity];
		for(int i = 0; i<other.m_size; i++){
			m_ptr[i] = other.m_ptr[i];
		}
	}
		
	MyVector(std::initializer_list<int> il) : m_size(il.size()), m_capacity(il.size()){
		m_ptr = new int[m_capacity];
		size_t i = 0;
		for(auto val : il){
			m_ptr[i++] = val;
		}
	}

	MyVector &operator=(const MyVector& other){
		if(this == &other){
			return *this;
		}	
		if(m_ptr) delete[] m_ptr;
		m_ptr = new int[other.m_capacity];	
		m_size = other.m_size;
		m_capacity = other.m_capacity;
			for(int i = 0; i<other.m_size; ++i){			
				m_ptr[i] = other.m_ptr[i];
			}
		return *this;
		
	}

	size_t size() const{
		return m_size;
	}

	int &operator[](size_t index){
		return m_ptr[index];
	}

	const int &operator[](size_t index) const{
		return m_ptr[index];	
	}

	int &front() {
		return m_ptr[0];
	}

	const int &front() const{
		return m_ptr[0];
	}

	int &back(){
		return m_ptr[m_size-1];
	}

	const int &back() const{
		return m_ptr[m_size-1];
	}

	bool empty() const{
		return m_size == 0;
	}

	void reserve(size_t new_cap){
		if(new_cap <=m_capacity) return;
		int* new_ptr = new int[new_cap];
			for(int i = 0; i<m_size; ++i){
				new_ptr[i] = m_ptr[i]; 
		}

		delete[] m_ptr;
		m_ptr = new_ptr;
		m_capacity = new_cap;
	}
	
	size_t capacity() const {
		return m_capacity;
	}

	void shrink_to_fit() {
		if(m_size == 0){
			delete[] m_ptr;
		}

		if(m_capacity>m_size){
			int *ptr1 = new int[m_size];
			for(int i = 0; i<m_size; i++){
				ptr1[i] = m_ptr[i];
			}

			delete[] m_ptr;
			m_ptr = ptr1;
			m_capacity = m_size;

		}
	}

	void clear() {
		m_size = 0;
	}	
 	
	size_t insert(size_t pos, int val){
		if(pos > m_size){
			std::cout<<"I cannot insert for that position"<<std::endl;
		}
	
		if(m_size == m_capacity){
			if(m_capacity == 0){
				size_t new_cap = 1;
				reserve(new_cap);
			} else{
				size_t new_cap = m_capacity * 2;
				reserve(new_cap);
			  }
		}

		for(size_t i = m_size; i>pos; --i){
			m_ptr[i] = m_ptr[i-1];
		}

		m_ptr[pos] = val;
		++m_size;
	
		return pos;
	}

	size_t insert(size_t pos, size_t count, int val){
			if(pos>m_size){
				std::cout<<"I cannot insert for that position"<<std::endl;
			}

			if(m_size == m_capacity){
				if(m_capacity == 0){
					size_t new_cap = 1;
					reserve(new_cap);
				} else{
					size_t new_cap = m_capacity * 2;
					reserve(new_cap);
				  }
			}
	
			for(size_t i = m_size; i>pos; --i){
				m_ptr[i+ count -1] = m_ptr[i-1];
			}
		
			for(size_t i = 0; i<count; ++i){
				m_ptr[pos+i] = val;
			}

			m_size+=count;

			return pos;
	}

	size_t erase(size_t pos){
		if(pos>=m_size){
			std::cout<<"I cannot erase that position"<<std::endl;
		}

		for (size_t i = pos; i < m_size - 1; ++i) {
     			   m_ptr[i] = m_ptr[i + 1];
    		}

		--m_size;
		return pos;
	}

	void push_back(int val){
		if(m_size == m_capacity){
			if(m_capacity == 0){
				size_t new_cap = 1;
				reserve(new_cap);	
			} else{
				size_t new_cap = m_capacity *2;
				reserve(new_cap);
			 }
		}

		m_ptr[m_size] = val;
		++m_size;
	}

	void pop_back(){
		--m_size;
	}

	void resize(size_t count, int val){
		if(count>m_capacity){
			if(m_capacity == 0){
				size_t new_cap = 1;
				reserve(new_cap);
			} 	else{
				size_t new_cap = m_capacity * 2;
				reserve(new_cap);
			  }
		}	
    
		if(count<m_size){
       		       m_size = count;
    }

    if(count>m_size){
     	for(size_t i = m_size; i<count; i++){
               	m_ptr[i] = val;
     }
      m_size = count;
    }
	}

	void resize(size_t count){
		resize(count, 0);
	}	
			
	~MyVector(){
		delete[] m_ptr;
	}
};

